#ifndef TWMULTISPRITEINV__H
#define TWMULTISPRITEINV__H

#include <string>
#include <vector>
#include <cmath>
#include "drawable.h"
class ExplodingSprite;
class TwoWaysMultiSpriteInv : public Drawable
{
  public:
    TwoWaysMultiSpriteInv(const std::string &, const std::string &);
    TwoWaysMultiSpriteInv(const TwoWaysMultiSpriteInv &);
    

    virtual void draw() const;
    virtual void update(Uint32 ticks);

    virtual const Image *getImage() const
    {
        return images[currentFrame];
    }
    int getScaledWidth() const
    {
        return getScale() * images[currentFrame]->getWidth();
    }
    int getScaledHeight() const
    {
        return getScale() * images[currentFrame]->getHeight();
    }
    virtual const SDL_Surface *getSurface() const
    {
        return images[currentFrame]->getSurface();
    }
    virtual void explode();
    void setImages_ori(){
        images = images_ori;
    }
    void setImages_inv(){
        images = images_inv;
    }

  protected:
    std::vector<Image *> images;//current image
    ExplodingSprite *explosion;
    std::vector<Image *> images_ori;
    std::vector<Image *> images_inv;
    unsigned currentFrame;
    unsigned numberOfFrames;
    unsigned frameInterval;
    float timeSinceLastFrame;
    int worldWidth;
    int worldHeight;
    TwoWaysMultiSpriteInv& operator=(const TwoWaysMultiSpriteInv&);
    void advanceFrame(Uint32 ticks);
    
};

#endif