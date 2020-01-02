#include "bullet.h"
#include "imageFactory.h"
#include "gameData.h"

#include <cmath>
#include <iostream>

Bullet::Bullet(
    const std::string& name,
    const Vector2f& position,
    const Vector2f& velocity
):
    BulletSprite(
        name,
        position,
        velocity, 
        ImageFactory::getInstance().getImage(name)
        ),
    tooFar(false),
    distance(0),
    maxDistance(Gamedata::getInstance().getXmlInt(name+"/distance"))
{ }

void Bullet::reset(){
    tooFar = false;
    distance = 0;
}

void Bullet::update(Uint32 ticks){
    Vector2f pos = getPosition();
    BulletSprite::update(ticks);
    if (getY() + getScaledHeight() < 0 || getY() > worldHeight)
    {
        tooFar = true;
    }
    if (getX() < 0)
    {
        tooFar = true;
    }
    if (getX() + getScaledWidth() > worldWidth)
    {
        tooFar = true;
    }
    
    distance += (hypot(getX() - pos[0], getY() - pos[1]));
    if (distance > maxDistance)
    {
        tooFar = true;
    }
}