#include <vector>
#include <SDL2/SDL.h>
// #include "ioMod.h"
#include "renderContext.h"
// #include "clock.h"
#include "world.h"
#include "viewport.h"
#include "sound.h"
// #include "player.h"
#include "healthBar.h"

class CollisionStrategy;
class SubjectSprite;
class ObserverSprite;
// class RectangularCollisionStrategy;
// class MidPointCollisionStrategy;

class Engine {
public:
  Engine ();
  ~Engine ();
  bool play();
  void switchSprite();

  Engine(const Engine&) = delete;
  Engine& operator=(const Engine&) = delete;
  // Item 7:satisfy Item #11 in Modern Effiective C++
  void printScales() const = delete;
  void checkForCollisions();
  void hudDraw() const;

private:
  const RenderContext &rc; //change gof singleton to meyers
  const IoMod& io;
  Clock& clock;

  SDL_Renderer * const renderer;
  //Item 6: add multi-background
  World world;
  World clouds;
  World ground;
  Viewport& viewport;


  std::vector <ObserverSprite*> observers;
  // std::vector <CollisionStrategy*> strategies;
  CollisionStrategy *collisionStrategy;
 
  Player* knight;
  HealthBar* knight_hb;
  int currentSprite;
  GameSound music;

  // bool isCollosion;
  bool makeVideo;
  bool isDrawingHub;
  bool playerExploding;
  int score;

  void draw() const;
  void update(Uint32);

};
