/** 
 * @Author: Wufangjie Ma
 * @Date: 2019-03-27 16:17:59 
 * @Desc: This Class is SmartSprite in the example 
 */
#ifndef OBSERVERSPRITE__H
#define OBSERVERSPRITE__H
#include <string>

#include "two-way_multi-frame_sprite_inv.h"

class CollisionStrategy;
class Player;

class ObserverSprite : public TwoWaysMultiSpriteInv{
public:
    ObserverSprite(const ObserverSprite& os);
    ObserverSprite(
        const std::string& name, 
        const std::string&inv, 
        const Vector2f& pos, 
        int width, 
        int height);
    
    virtual ~ObserverSprite(){ }
    //ObserverSprite(const ObserverSprite&) =default;
    ObserverSprite& operator=(const ObserverSprite&) = default;
    virtual void update(Uint32 ticks);
    void setPlayerPos(const Vector2f& pos){
        playerPos = pos;
    }
    int showHealth(){
        return health_observer;
    }

    bool collisionWithPlayer(Player *player);
    void hurt();

    void observerHit(Player*);
    // virtual void explode();
private:
    Vector2f playerPos;
    int playerWidth;
    int playerHeight;
    enum MODE{NORMAL, ATTACH};
    MODE currentMode;
    float safeDistance;
    int health_observer;

    CollisionStrategy* collision;
    // ExplodingSprite *explosion;
    void goLeft();
    void goRight();
    void goDown();
    void goUp();
};

#endif