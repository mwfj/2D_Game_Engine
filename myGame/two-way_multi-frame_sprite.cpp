#include "two-way_multi-frame_sprite.h"
#include "gameData.h"
#include "imageFactory.h"
#include <string>
#include<iostream>
void TwoWaysMultiSprite::advanceFrame(Uint32 ticks)
{
  timeSinceLastFrame += ticks;
	if (timeSinceLastFrame > frameInterval) {
    currentFrame = (currentFrame+1) % numberOfFrames;
		timeSinceLastFrame = 0;
	}
}



TwoWaysMultiSprite::TwoWaysMultiSprite( 
                  const std::string& name, 
                  const std::string& inv, 
                  const std::string& idle,
                  const std::string& idle_inv) :
  Drawable(idle, 
           Vector2f(Gamedata::getInstance().getXmlInt(idle+"/startLoc/x"), 
                    Gamedata::getInstance().getXmlInt(idle+"/startLoc/y")), 
           Vector2f(Gamedata::getInstance().getXmlInt(idle+"/speedX"),
                    Gamedata::getInstance().getXmlInt(idle+"/speedY"))
           ),
  images( ImageFactory::getInstance().getImages(idle) ),//change gof singleton to meyers
  images_ori( ImageFactory::getInstance().getImages(name) ),
  images_inv(ImageFactory::getInstance().getImages(inv)),
  images_idle(ImageFactory::getInstance().getImages(idle)),
  images_idle_inv(ImageFactory::getInstance().getImages(idle_inv)),
  images_throw(ImageFactory::getInstance().getImages("Knight-throwing")),
  images_throw_inv(ImageFactory::getInstance().getImages("Knight-throwing-inv")),
  currentFrame(0),
  numberOfFrames( Gamedata::getInstance().getXmlInt(idle+"/frames") ),
  frameInterval( Gamedata::getInstance().getXmlInt(idle+"/frameInterval")),
  timeSinceLastFrame( 0 ),
  isLeft(false),
  deathAnim(nullptr),
  worldWidth(Gamedata::getInstance().getXmlInt("world/width")),
  worldHeight(Gamedata::getInstance().getXmlInt("world/height"))
{
  
}

TwoWaysMultiSprite::TwoWaysMultiSprite( const TwoWaysMultiSprite& t ) :
  Drawable(t),
  images(t.images),
  images_ori(t.images_ori),
  images_inv(t.images_inv),
  images_idle(t.images_idle),
  images_idle_inv(t.images_idle_inv),
  images_throw(t.images_throw),
  images_throw_inv(t.images_throw_inv),
  currentFrame(t.currentFrame),
  numberOfFrames(t.numberOfFrames),
  frameInterval(t.frameInterval),
  timeSinceLastFrame(t.timeSinceLastFrame),
  isLeft(t.isLeft),
  deathAnim(t.deathAnim),
  worldWidth(t.worldWidth),
  worldHeight(t.worldHeight)
{
  // deathAnim->setScale(0.25);
 }

TwoWaysMultiSprite& TwoWaysMultiSprite::operator=(const TwoWaysMultiSprite& t){
  Drawable::operator=(t);
  images = (t.images);
  images_ori = (t.images_ori);
  images_inv = (t.images_inv);
  images_idle = (t.images_idle);
  images_idle_inv = (t.images_idle_inv);
  images_throw = (t.images_throw);
  images_throw_inv = (t.images_throw_inv);
  currentFrame = (t.currentFrame);
  numberOfFrames = (t.numberOfFrames);
  frameInterval = (t.frameInterval);
  timeSinceLastFrame = (t.timeSinceLastFrame);
  isLeft = (t.isLeft);
  worldWidth = (t.worldWidth);
  worldHeight = (t.worldHeight);
  deathAnim = (t.deathAnim);
  return *this;
}

void TwoWaysMultiSprite::draw() const
{
  if (deathAnim){
    deathAnim->setScale(0.25);
    deathAnim->draw();
  }else
  {
    images[currentFrame]->draw(getX(), getY(), getScale());
  }
  
}

void TwoWaysMultiSprite::update(Uint32 ticks)
{
  if (deathAnim)
  {
    deathAnim->update(ticks);
    if (deathAnim->doneDying())
    {
      delete deathAnim;
      deathAnim = NULL;
    }
    return;
  }
  advanceFrame(ticks);
  Vector2f incr = getVelocity() * static_cast<float>(ticks) * 0.001;
  setPosition(getPosition() + incr);

  if ( getY() < 0) {
    setVelocityY( fabs( getVelocityY() ) );
  }
  if ( getY() + getScaledHeight() > worldHeight) {
    setVelocityY( -fabs( getVelocityY() ) );
  }

  if ( getX() < 0) {

    setImages_ori();
    setVelocityX( fabs( getVelocityX() ) );
  }
  if ( getX() + getScaledWidth() > worldWidth) {

    setImages_inv();
    setVelocityX( -fabs( getVelocityX() ) );
  }  
}

void TwoWaysMultiSprite::explode(){
  if (!deathAnim)
  {
    deathAnim = new DyingSprite(getName() + "Dying");
    if(isLeft){
      deathAnim->setImages_inv();
    }
    else{
      deathAnim->setImages_ori();
    }
    deathAnim->setPosition(getPosition());
  }
}
