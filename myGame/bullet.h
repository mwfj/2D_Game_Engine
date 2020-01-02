#ifndef BULLET__H
#define BULLET__H

#include "bulletSprite.h"

class Bullet: public BulletSprite {
public:
    Bullet(const std::string &name, const Vector2f &position, const Vector2f &velocity);
    virtual void update(Uint32 ticks);
    bool goneToFar() const {
        return tooFar;
    }
    void reset();
    Bullet(const Bullet&) = default;
    Bullet& operator=(const Bullet&) = default;
    ~Bullet() = default;
private:
    bool tooFar;
    float distance;
    float maxDistance;  
};

#endif
