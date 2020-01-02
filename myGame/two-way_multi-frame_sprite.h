#ifndef TWMULTISPRITE__H
#define TWMULTISPRITE__H

#include <string>
#include <vector>
#include <cmath>
#include "drawable.h"
#include "bulletpool.h"
#include "dyingSprite.h"

class TwoWaysMultiSprite : public Drawable
{
  public:
    TwoWaysMultiSprite(const std::string& ,const std::string &, const std::string &, const std::string&);
    TwoWaysMultiSprite(const TwoWaysMultiSprite &);


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

    void setIsLeftToTrue(){
        isLeft = true;
    }

    void setIsLeftToFalse(){
        isLeft = false;
    }

    void setImages_ori()
    {
        setIsLeftToFalse();
        images = images_ori;
    }
    void setImages_inv()
    {
        setIsLeftToTrue();
        images = images_inv;
    }

    void setImages_Idle(){
        images = images_idle;
    }

    void setImages_Idle_inv(){
        images = images_idle_inv;
    }
    void setImage_Throwing(){
        images = images_throw;
    }
    void setImage_Throwing_inv(){
        images = images_throw_inv;
    }
    bool getIsLeft(){
        return isLeft;
    }

    void shoot();

    virtual void explode();

    virtual bool doneDying() const
    {
        if (deathAnim)
            return deathAnim->doneDying();
        return false;
    }

protected:
    std::vector<Image *> images;
    std::vector<Image *> images_ori;
    std::vector<Image *> images_inv;
    std::vector<Image *> images_idle;
    std::vector<Image *> images_idle_inv;
    std::vector<Image *> images_throw;
    std::vector<Image *> images_throw_inv;
    unsigned currentFrame;
    unsigned numberOfFrames;
    unsigned frameInterval;
    float timeSinceLastFrame;
    bool isLeft;
    DyingSprite *deathAnim;
    int worldWidth;
    int worldHeight;
    TwoWaysMultiSprite &operator=(const TwoWaysMultiSprite &);
    void advanceFrame(Uint32 ticks);
};

#endif