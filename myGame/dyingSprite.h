#pragma once

#include <string>
#include <vector>
#include <cmath>
#include "drawable.h"

class DyingSprite : public Drawable {
public:
  DyingSprite(const std::string&);

  virtual void draw() const;
  virtual void update(Uint32 ticks);

  virtual bool doneDying() const {
    return finishedDying;
  }

  virtual const Image* getImage() const { 
    return images[currentFrame]; 
  }
  int getScaledWidth()  const { 
    return getScale()*images[currentFrame]->getWidth(); 
  } 
  int getScaledHeight()  const { 
    return getScale()*images[currentFrame]->getHeight(); 
  } 
  virtual const SDL_Surface* getSurface() const { 
    return images[currentFrame]->getSurface();
  }
  void setImages_ori()
  {
    images = images_ori;
  }
  void setImages_inv()
  {
    images = images_inv;
  }

protected:
  std::vector<Image *> images;
  std::vector<Image *> images_ori;
  std::vector<Image *> images_inv;

  unsigned currentFrame;
  unsigned numberOfFrames;
  bool finishedDying;
  unsigned frameInterval;
  float timeSinceLastFrame;
  int worldWidth;
  int worldHeight;

  void advanceFrame(Uint32 ticks);
};
