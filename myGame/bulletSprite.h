#ifndef BULLETSPRITE__H
#define BULLETSPRITE__H
#include <string>
#include "drawable.h"

class BulletSprite : public Drawable
{
public:
    BulletSprite(const std::string &);
    BulletSprite(const std::string &, const Vector2f &pos, const Vector2f &vel,
                 const Image *);
    BulletSprite(const BulletSprite &) = default;
    virtual ~BulletSprite() {}
    BulletSprite &operator=(const BulletSprite &) = default;

    virtual void draw() const;
    virtual void update(Uint32 ticks);

    virtual const Image *getImage() const { return image; }
    virtual const SDL_Surface *getSurface() const
    {
        return image->getSurface();
    }
    int getScaledWidth() const { return getScale() * image->getWidth(); }
    int getScaledHeight() const { return getScale() * image->getHeight(); }

private:

    const Image *image;
    
protected:
    int worldWidth;
    int worldHeight;

    int getDistance(const BulletSprite *) const;
    Vector2f makeVelocity(int, int) const;
};
#endif
