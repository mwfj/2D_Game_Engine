#include <cmath>
#include <random>
#include <functional>
#include <iostream>
#include "gameData.h"
#include "renderContext.h"
#include "observerSprite.h"
#include "collisionStrategy.h"
#include "player.h"

#define X_AXIS  0
#define Y_AXIS  1

ObserverSprite::ObserverSprite(
    const std::string& name,
    const std::string& inv,
    const Vector2f& pos,
    int width,
    int height
):
    TwoWaysMultiSpriteInv(name,inv),
    playerPos(pos),
    playerWidth(width),
    playerHeight(height),
    currentMode(NORMAL),
    safeDistance(Gamedata::getInstance().getXmlFloat(name+"/safeDistance")),
    health_observer(200),
    collision(new PerPixelCollisionStrategy)
{}

ObserverSprite::ObserverSprite(const ObserverSprite& os):
    TwoWaysMultiSpriteInv(os),
    playerPos(os.playerPos),
    playerWidth(os.playerWidth),
    playerHeight(os.playerHeight),
    currentMode(NORMAL),
    safeDistance(os.safeDistance),
    health_observer(os.health_observer),
    collision(os.collision)
    {}
float distance(float x1, float y1, float x2, float y2){
    float x = x1-x2;
    float y = y1-y2;
    return hypot(x, y);
}

bool ObserverSprite::collisionWithPlayer(Player *player){
    if (collision->execute(*player,*this))
    {
        return true;
    }
    return false;
}

void observerHit(Player* player){
    player->hurt();
}

void ObserverSprite::goLeft(){
    setVelocityX( -abs(getVelocityX()));
}

void ObserverSprite::goRight(){
    setVelocityX( fabs(getVelocityX()) );
}

void ObserverSprite::goDown(){
    setVelocityY( fabs(getVelocityY()) );

}

void ObserverSprite::goUp(){
    setVelocityY( -fabs(getVelocityY()) );
}

void ObserverSprite::hurt(){

    if (health_observer<=10)
    {
        health_observer = 0;
    }else{
        health_observer -= 10;
    }
}

void ObserverSprite::update(Uint32 ticks){
    TwoWaysMultiSpriteInv::update(ticks);
    float x = getX() + getImage()->getWidth()/2;
    float y = getY() + getImage()->getHeight()/2;
    float ex = playerPos[X_AXIS] + playerWidth/2;
    float ey = playerPos[Y_AXIS] + playerHeight/2;
    float distanceToEnemy = ::distance(x, y, ex, ey);

    if (currentMode == NORMAL)
    {
        if (distanceToEnemy < safeDistance)
        {
            currentMode = ATTACH;
        }
    }
    else if (currentMode == ATTACH)
    {
        if (distanceToEnemy > safeDistance)
        {
            currentMode = NORMAL;
        }else{
            if ( x<ex ) {
                setImages_inv();
                goLeft();
                // setImages_ori();
                // goRight();
            }
            if ( x>ex )
            {
                // setImages_inv();
                // goLeft();
                setImages_ori();
                goRight();
            }
            if ( y<ey )
            {
                goUp();
            }
            if ( y>ey )
            {
                goDown();
            }
        }
    }
    
    
}