#include "two-way_multi-frame_sprite_inv.h"
#include "gameData.h"
#include "imageFactory.h"
#include "explodingSprite.h"

#include <string>
#include<iostream>


void TwoWaysMultiSpriteInv::advanceFrame(Uint32 ticks){
  timeSinceLastFrame += ticks;
  if (timeSinceLastFrame > frameInterval)
  {
    currentFrame = (currentFrame + 1) % numberOfFrames;
    timeSinceLastFrame = 0;
  }
}

TwoWaysMultiSpriteInv::TwoWaysMultiSpriteInv( const std::string& name, const std::string& inv) :
  Drawable(name, 
           Vector2f(Gamedata::getInstance().getXmlInt(name+"/startLoc/x"), 
                    Gamedata::getInstance().getXmlInt(name+"/startLoc/y")), 
           Vector2f(Gamedata::getInstance().getXmlInt(name+"/speedX"),
                    Gamedata::getInstance().getXmlInt(name+"/speedY"))
           ),
  images( ImageFactory::getInstance().getImages(name) ),//change gof singleton to meyers
  explosion(nullptr),
  images_ori( ImageFactory::getInstance().getImages(name) ),
  images_inv(ImageFactory::getInstance().getImages(inv)),
  currentFrame(0),
  numberOfFrames( Gamedata::getInstance().getXmlInt(name+"/frames") ),
  frameInterval( Gamedata::getInstance().getXmlInt(name+"/frameInterval")),
  timeSinceLastFrame( 0 ),
  worldWidth(Gamedata::getInstance().getXmlInt("world/width")),
  worldHeight(Gamedata::getInstance().getXmlInt("world/height"))
{ 
}

TwoWaysMultiSpriteInv::TwoWaysMultiSpriteInv(const TwoWaysMultiSpriteInv& ti):
  Drawable(ti),
  images(ti.images),
  explosion(ti.explosion),
  images_ori(ti.images_ori),
  images_inv(ti.images_inv),
  currentFrame(ti.currentFrame),
  numberOfFrames(ti.numberOfFrames),
  frameInterval(ti.frameInterval),
  timeSinceLastFrame(ti.timeSinceLastFrame),
  worldWidth(ti.worldWidth),
  worldHeight(ti.worldHeight)
{
}

TwoWaysMultiSpriteInv& TwoWaysMultiSpriteInv::operator=(const TwoWaysMultiSpriteInv& ti){
  Drawable::operator=(ti);
  images = (ti.images);
  explosion = (ti.explosion);
  images_ori = (ti.images_ori),
  images_inv = (ti.images_inv),
  currentFrame = (ti.currentFrame);
  numberOfFrames = (ti.numberOfFrames);
  frameInterval  = (ti.frameInterval);
  timeSinceLastFrame = (ti.timeSinceLastFrame);
  worldWidth = (ti.worldWidth);
  worldHeight = (ti.worldHeight);
  return *this;
}

void TwoWaysMultiSpriteInv::draw() const
{
  if (explosion)
  {
    std::cout << "drawing:True" << std::endl;
    explosion->draw();
  }else{
    // std::cout << "Normal Draw" << std::endl;
    images[currentFrame]->draw(getX(), getY(), getScale());
  }
}

void TwoWaysMultiSpriteInv::explode(){
  if (!explosion)
  {
    // std::cout << "explode:False" << std::endl;
    // std::cout<<"no explosion sprite"<<std::endl;
    Sprite
        sprite(getName(), getPosition(), getVelocity(), images[currentFrame]);
    std::cout << "sprite name:" <<sprite.getName()<< std::endl;
    sprite.setScale(getScale());
    explosion = new ExplodingSprite(sprite);
  }
  // std::cout << "Roar!!!" << std::endl;
}

void TwoWaysMultiSpriteInv::update(Uint32 ticks)
{
  if (explosion)
  {
    std::cout<<"Update:True"<<std::endl;
    explosion->update(ticks);
    if (explosion->chunkCount() == 0)
    {
      delete explosion;
      explosion = NULL;
    }
    return;
  }
  advanceFrame(ticks);
  Vector2f decr = getVelocity() * static_cast<float>(ticks) * 0.001;
  setPosition(getPosition() - decr);

  if ( getY() < 0) {
    setVelocityY( fabs( getVelocityY() ) );
  }
  if ( getY() + getScaledHeight() > worldHeight) {
    setVelocityY( -fabs( getVelocityY() ) );
  }

  if ( getX() < 0) {
    // images = images_inv;
    setImages_inv();
    setVelocityX( -fabs( getVelocityX() ) );
  }
  if ( getX() + getScaledWidth() > worldWidth) {
    // images = images_ori;
    setImages_ori();
    setVelocityX( fabs( getVelocityX() ) );
  }  
}
