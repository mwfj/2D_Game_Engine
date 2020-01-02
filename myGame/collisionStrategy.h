#include <cmath>
#include "drawable.h"
#include "player.h"

class CollisionStrategy{
public:
  virtual bool execute(const Player &, const Drawable &) const = 0;
  virtual bool execute(const Drawable &, const Drawable &) const = 0;
  virtual void draw() const = 0;
  virtual ~CollisionStrategy() {}
};

class RectangularCollisionStrategy : public CollisionStrategy
{
  public:
    RectangularCollisionStrategy() {}
    //For checking collision of the main character
    virtual bool execute(const Player &, const Drawable &) const;
    // For other situations
    virtual bool execute(const Drawable &, const Drawable &) const;
    virtual void draw() const;
};

class MidPointCollisionStrategy : public CollisionStrategy
{
  public:
    MidPointCollisionStrategy() {}
    //For checking the collision of the main character
    virtual bool execute(const Player &, const Drawable &) const;
    // For other situations
    virtual bool execute(const Drawable &, const Drawable &) const;
    virtual void draw() const;
    float distance(float, float, float, float) const;
};

class PerPixelCollisionStrategy : public CollisionStrategy
{
  public:
    PerPixelCollisionStrategy() {}
    //For checking the collision of  the main character
    virtual bool execute(const Player &, const Drawable &) const;
    // For other situations
    virtual bool execute(const Drawable &, const Drawable &) const;
    virtual void draw() const;

  private:
    bool isVisible(Uint32, SDL_Surface *) const;
};