#include "player.h"
#include "gameData.h"
#include "vector2f.h"
#include "collisionStrategy.h"
#include "explodingSprite.h"
#include "renderContext.h"

#include <iostream>

#define X_AXIS 0
#define Y_AXIS 1

void Player::playerAdvanceFrame(Uint32 ticks)
{
    timeSinceLastFrame += ticks;
    if (timeSinceLastFrame > frameInterval)
    {
        currentFrame = (currentFrame + 1) % numberOfFrames;
        timeSinceLastFrame = 0;
    }
}

Player::Player(const std::string& name, const std::string& inv, const std::string& idle, const std::string& idle_inv):
    player(name, inv, idle,idle_inv),
    initialVelocity(player.getVelocity()),
    pos(player.getPosition()),
    jumpPos(player.getX(),200),
    collisionStrategy(new PerPixelCollisionStrategy),
    explosion(nullptr),
    currentFrame(0),
    numberOfFrames( Gamedata::getInstance().getXmlInt(name+"/frames") ),
    frameInterval( Gamedata::getInstance().getXmlInt(name+"/frameInterval")),
    timeSinceLastFrame(0),
    pos_x(player.getX()),
    pos_y(player.getY()),
    jumpHeight(200.0),
    isJump(false),
    worldWidth(Gamedata::getInstance().getXmlInt("world/width")),
    worldHeight(Gamedata::getInstance().getXmlInt("world/height")),
    health(660),
    bulletName(Gamedata::getInstance().getXmlStr(name+"/bulletName")),
    bullets(bulletName),
    bulletSpeed(Gamedata::getInstance().getXmlInt(bulletName+"/speedX")),
    bulletInterval(Gamedata::getInstance().getXmlInt(bulletName+"/interval")),
    timeSinceLastBullet(0),
    damage(1),
    isGodMode(false)
{
}

void Player::draw()
{
    player.draw();
    bullets.draw();
}


void Player::stop()
{
    if (player.getIsLeft())
    {
        player.setImages_Idle_inv();
    }
    else
    {
        player.setImages_Idle();
    }

    player.setVelocityX(0.33 * player.getVelocityX());
    player.setVelocityY(0);


}
void Player::hurt()
{
    if (health <= damage)
    {
        health = 0;
    }
    else
    {
        health -= damage;
    }
}
int Player::getDamage(){
    return damage;
}
void Player::up(){

    if(player.getY()>0){
        player.setVelocityY(-initialVelocity[Y_AXIS]);
    }
}

void Player::down(){

    if (player.getY() < ( worldHeight - getScaleHeight() ))
    {
        player.setVelocityY( initialVelocity[Y_AXIS] );
    }
    
}

void Player::left(){
    if (player.getX() > 0) {
        player.setVelocityX(-initialVelocity[X_AXIS]);
        player.setImages_inv();
    }
    
}

void Player::right(){
    if (player.getX() < (worldWidth - getScaleWidth()))
    {
        player.setVelocityX(initialVelocity[X_AXIS]);
        player.setImages_ori();
    }
    
}

//I am not use this funciton in my program cause this Function is incompleted
// void Player::jump(Uint32 ticks){
//     std::cout<<player.getVelocityY()<<std::endl;
//     // player.setVelocityY(player.getVelocityY()+100);
//     player.setVelocityY(300);
//     float incr = player.getVelocityY() * static_cast<float>(ticks) * 0.001;
//     if(!isJump){
//         player.setPosition(Vector2f(player.getX()+incr, player.getY() - (incr*5)));
//         if ( player.getY()<=175)
//         {
//             player.setY(175);
//             isJump = true;
//         }
//     }
//     if(isJump){
//         // player.setVelocityY(player.getVelocityY()+400);
//         // float incr = player.getVelocityY() * static_cast<float>(ticks) * 0.01;
//         player.setPosition(Vector2f(player.getX()+incr, player.getY() + (incr*5)));
//         if (player.getY() >= 375){
            
//             player.setY(375);
//             isJump = false;
//         }
//     }
// }

unsigned int Player::Current_Bulletlist_Size(){
    return bullets.Current_Bulletlist_size();
}

unsigned int Player::Current_Freelist_Size(){
    return bullets.Current_Freelist_size();
}


bool Player::collisionWithOb(ObserverSprite* ob){
    if (explosion)
        return false;

    if (collisionStrategy->execute(*this,*ob))
    {
        return true;
    }
    return false;
}

void Player::update(Uint32 ticks){
    playerAdvanceFrame(ticks);
    timeSinceLastBullet += ticks;
    player.notify(ticks);
    bullets.update(ticks);
}

void Player::shoot(){
    // See if it's time to shoot a bullet:
    if (timeSinceLastBullet > bulletInterval)
    {
        Vector2f vel = getVelocity();
        float x;
        float y = getY() + player.getScaledHeight() / 4 + 11;
        if (vel[0] > 0)
        {
            player.setImage_Throwing();
            player.setIsLeftToFalse();
            x = getX() + getScaledWidth() - 10;
            vel[0] += bulletSpeed;
        }
        else
        {
            player.setImage_Throwing_inv();
            player.setIsLeftToTrue();
            x = getX();
            vel[0] -= bulletSpeed;
        }
        bullets.shoot(Vector2f(x, y), vel);
        timeSinceLastBullet = 0;
    }
}

void Player::explode(){
    player.explode();
}
bool Player::getShot(const ObserverSprite* ob) const {
   if(bullets.collideWith(ob)){
       return true;
   }
   return false;
}



