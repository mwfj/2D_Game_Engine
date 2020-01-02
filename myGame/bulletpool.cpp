#include "collisionStrategy.h"
#include "bulletpool.h"
#include "imageFactory.h"
#include "bullet.h"

#include <iostream>
#include <cmath>

BulletPool::BulletPool(const std::string& n):
    collisionStrategy(NULL),
    name(n),
    bulletList(),
    freelist(),
    bulletVelocity(
        Gamedata::getInstance().getXmlInt(name+"/speed/x"),
        Gamedata::getInstance().getXmlInt(name+"/speed/y")
    )
{
    const string thisStrategy = Gamedata::getInstance().getXmlStr("collisionStrategy");

    if (thisStrategy == "PerPixel")
    {
        collisionStrategy = new PerPixelCollisionStrategy;
    }
    else if (thisStrategy == "Rectangular")
    {
        collisionStrategy = new RectangularCollisionStrategy;
    }
    else if (thisStrategy == "MidPoint")
    {
        collisionStrategy = new MidPointCollisionStrategy;
    }
}


BulletPool::BulletPool(const BulletPool& b):
    collisionStrategy(b.collisionStrategy),
    name(b.name),
    bulletList(b.bulletList),
    freelist(b.freelist),
    bulletVelocity(b.bulletVelocity)
{
}

void BulletPool::shoot(const Vector2f& position, const Vector2f& velocity){
    if (freelist.empty())
    {
        Bullet* bullet = new Bullet(name, position, velocity);
        bulletList.push_back(*bullet);
    }else{
        Bullet bullet = freelist.front();
        freelist.pop_front();
        bullet.reset();
        bullet.setPosition(position);
        bullet.setVelocity(velocity);
        bulletList.push_back(bullet);
    }
    
}

bool BulletPool::collideWith(const Drawable* obj) const{
    //Note that it cannot be used "auto" in my program, 
    //cause I overload execute function in CollisionStrategy
    std::list<Bullet>::const_iterator ptr = bulletList.begin();
    while (ptr != bulletList.end())
    {
        if (collisionStrategy->execute(*ptr, *obj))
        {
            return true;
        }
        ++ptr;
    }
    return false;
}

void BulletPool::draw() const {
    for(const Drawable& bullet : bulletList){
        bullet.draw();
    }
}

void BulletPool::update(Uint32 ticks){
    std::list<Bullet>::iterator ptr  = bulletList.begin();
    while (ptr != bulletList.end())
    {
        ptr->update(ticks);

        if (ptr->goneToFar())
        {
            freelist.push_back(*ptr);
            ptr = bulletList.erase(ptr);
        }else{
            ++ptr;
        }     
    }
}