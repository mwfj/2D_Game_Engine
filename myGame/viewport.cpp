#include <sstream>
#include "viewport.h"
#include "ioMod.h"
#include "clock.h"

Viewport& Viewport::getInstance() {
  static Viewport viewport;
  return viewport;
}
Viewport &Viewport::getInstance(float x, float y){
  static Viewport viewport;
  viewport.setX(x);
  viewport.setY(y);
  return viewport;
}

Viewport::Viewport() : 
  gdata(Gamedata::getInstance()),
  viewPos(0, 0),
  msgPos(
    Vector2f( gdata.getXmlInt("view/loc/x"), gdata.getXmlInt("view/loc/y") )
  ),
  msgPos_fps(// item4: fps position in screen
    Vector2f( gdata.getXmlInt("view/loc_fps/x"), gdata.getXmlInt("view/loc_fps/y") )
  ),
  worldWidth(gdata.getXmlInt("world/width")),
  worldHeight(gdata.getXmlInt("world/height")),
  viewWidth(gdata.getXmlInt("view/width")), 
  viewHeight(gdata.getXmlInt("view/height")),
  objWidth(0), objHeight(0),
  objectToTrack(NULL) 
{}

void Viewport::setObjectToTrack(const Drawable *obj) { 
  objectToTrack = obj; 
  objWidth = objectToTrack->getScaledWidth();
  objHeight = objectToTrack->getScaledHeight();
}

void Viewport::draw() const {
  // IoMod::getInstance().
  //   writeText("Tracking: "+objectToTrack->getName(), msgPos[0], msgPos[1]);
  //item4: getFps();
  std::stringstream fps;
  fps << Clock::getInstance().getFps();
  SDL_Color const fps_font_color = {66,244,170,0};//green
  IoMod::getInstance().writeText("Wufangjie Ma", msgPos_fps[0], msgPos_fps[1], fps_font_color);
}

void Viewport::update() {
  const float x = objectToTrack->getX();
  const float y = objectToTrack->getY();

  viewPos[0] = (x + objWidth/2) - viewWidth/2;
  viewPos[1] = (y + objHeight/2) - viewHeight/2;
  if (viewPos[0] < 0) viewPos[0] = 0;
  if (viewPos[1] < 0) viewPos[1] = 0;
  if (viewPos[0] > (worldWidth - viewWidth)) {
    viewPos[0] = worldWidth-viewWidth;
  }
  if (viewPos[1] > (worldHeight - viewHeight)) {
    viewPos[1] = worldHeight-viewHeight;
  }
}
