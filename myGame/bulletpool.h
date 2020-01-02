#ifndef BULLETPOOL__H
#define BULLETPOOL__H

#include <list>
// #include <string>

#include "vector2f.h"
#include "drawable.h"
#include "bullet.h"

class CollisionStrategy;

class BulletPool{
public:
    BulletPool(const std::string&);
    BulletPool(const BulletPool&);
    BulletPool& operator=(const BulletPool&) = default;
    ~BulletPool() = default;

    void draw() const;
    void update(Uint32 ticks);
    bool isShooting() const {
        return !bulletList.empty();
    }
    void shoot(const Vector2f &position, const Vector2f &velocity);

    unsigned int Current_Bulletlist_size(){
        return bulletList.size();
    }

    unsigned int Current_Freelist_size(){
        return freelist.size();
    }

    bool collideWith(const Drawable*) const;
private:
    CollisionStrategy* collisionStrategy;
    std::string name;
    std::list<Bullet> bulletList;
    std::list<Bullet> freelist;
    Vector2f bulletVelocity;
};

#endif