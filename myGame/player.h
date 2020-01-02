#ifndef PLAYER__H
#define PLAYER__H
// #include <SDL2/SDL.h>
#include <string.h>
#include <vector>
#include <cmath>
#include <iostream>

#include "subjectSprite.h"
#include "observerSprite.h"
#include "bulletpool.h"

class CollisionStrategy;
class ExplodingSprite;

class Player {
public:

    Player(const Player&);
    Player(const std::string &, const std::string &, const std::string &, const std::string &);
    Player& operator=(const Player&) = delete;
    void draw();
    const TwoWaysMultiSprite* getPlayer() const{
        return &player;
    }

    const std::string& getName() const{
        return player.getName();
    }
    
    int getX() const{
        return player.getX();
    }

    int getY() const{
        return player.getY();
    }

    const Image* getImage() const{
        return player.getImage();
    }
    int getScaledWidth() const{
        return player.getScaledWidth();
    }
    int getScaleHeight() const{
        return player.getScaledHeight();
    }

    int getScaleWidth() const{
        return player.getScaledWidth();
    }

    void setScale(float scale){
        player.setScale(scale);
    }

    Vector2f getPosition() const {
       return player.getPosition();
    }

    Vector2f getVelocity() const
    {
        return player.getVelocity();
    }

    const SDL_Surface* getSurface() const{
        return player.getSurface();
    }
    // the function from SubjectSprite
    //--------------------------------------------
    void update(Uint32 ticks);//notify() in there

    void detach(ObserverSprite* os){
        player.detach(os);
    }

    void attach(ObserverSprite* os){
        player.attach(os);
    }

    void notify(Uint32 ticks){
        player.notify(ticks);
    }
    void shoot();
    bool getShot(const ObserverSprite* ob) const;

    bool collisionWithOb(ObserverSprite* ob);

    //--------------------------------------------

    void explode();
    void resetHealth(){
        health = 660;
    }
    void hurt();
    int showHealth(){
        return health;
    }
    int getDamage();
    void right();
    void left();
    void up();
    void down();
    void stop();
    // void jump(Uint32 ticks);

    unsigned int Current_Bulletlist_Size();
    unsigned int Current_Freelist_Size();
    bool setGodeModeTrue(){
        isGodMode = true;
        return isGodMode;
    }
    bool setGodeModeFalse()
    {
        isGodMode = false;
        return isGodMode;
    }
    bool getGodMode(){
        return isGodMode;
    }

private:
    SubjectSprite player;
    Vector2f initialVelocity;
    Vector2f pos;
    Vector2f jumpPos;

    CollisionStrategy* collisionStrategy;
    ExplodingSprite *explosion;

    unsigned currentFrame;
    unsigned numberOfFrames;
    unsigned frameInterval;
    float timeSinceLastFrame;

    float pos_x;
    float pos_y;
    float jumpHeight;
    bool isJump;
    int worldWidth;
    int worldHeight;
    int health;

    void playerAdvanceFrame(Uint32 ticks);
    const std::string& bulletName;
    BulletPool bullets;
    float bulletSpeed;
    int bulletInterval;
    int timeSinceLastBullet;

    int damage;
    //God Mode
    bool isGodMode;
};
#endif