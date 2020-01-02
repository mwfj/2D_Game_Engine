#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <random>
#include <iomanip>
#include "sprite.h"
#include "multisprite.h"
#include "two-way_multi-frame_sprite.h"
#include "two-way_multi-frame_sprite_inv.h"
#include "collisionStrategy.h"
#include "observerSprite.h"
#include "gameData.h"
#include "engine.h"
#include "frameGenerator.h"

Engine::~Engine() { 

  for (std::vector<ObserverSprite *>::const_iterator it_observer = observers.cbegin(); it_observer != observers.cend(); it_observer++)
  {
    delete *it_observer;
  }

  delete collisionStrategy;
  // for (std::vector<CollisionStrategy *>::const_iterator it_strategies = strategies.cbegin(); it_strategies != strategies.cend(); it_strategies++)
  // {
  //   delete *it_strategies;
  // }
  // std::vector<CollisionStrategy*>().swap(strategies);
  std::vector<ObserverSprite *>().swap(observers);
  delete knight_hb;
  if (knight)
  {
    delete knight;
  }
  std::cout << "Successfully delete polymorphic vector" << std::endl;
  std::cout << "Terminating program" << std::endl;
}

Engine::Engine() :
  rc( RenderContext::getInstance() ),
  io( IoMod::getInstance() ),
  clock( Clock::getInstance() ),
  renderer( rc.getRenderer() ),//change gof singleton to meyers
  world("back", Gamedata::getInstance().getXmlInt("back/factor") ),
  clouds("clouds", Gamedata::getInstance().getXmlInt("clouds/factor"),5.0,-80.0),
  ground("ground", Gamedata::getInstance().getXmlInt("ground/factor")),
  viewport( Viewport::getInstance() ),
  observers(),
  collisionStrategy(new PerPixelCollisionStrategy),
  // strategies(),
  // Project 4 Item1: Incorporate a Player into your animation
  knight(new Player("Knight","Knight-inv", "Knight-idle", "Knight-idle-inv")),
  knight_hb(new HealthBar("HealthBar")),
  currentSprite(0),
  music(),
  makeVideo( false ),
  isDrawingHub(true),
  playerExploding(false),
  score(0)
{
  //Initalize parameters for ObserverSprite
  Vector2f position = knight->getPosition();
  int width = knight -> getScaleWidth();
  int height = knight -> getScaleHeight();

  observers.push_back(new ObserverSprite("Zombie", "Zombie-inv", position, width, height));
  observers.push_back(new ObserverSprite("Zombie", "Zombie-inv", position, width, height));
  observers.push_back(new ObserverSprite("Zombie", "Zombie-inv", position, width, height));
  observers.push_back(new ObserverSprite("Zombie2", "Zombie2-inv", position, width, height));
  observers.push_back(new ObserverSprite("Zombie2", "Zombie2-inv", position, width, height));
  observers.push_back(new ObserverSprite("Zombie2", "Zombie2-inv", position, width, height));

  // Set Characters scales
  knight->setScale(0.25);
  knight_hb->setHealth(knight->showHealth());
  knight_hb->setIncrement(knight->getDamage());
  int maxSpeed = 260;
  int minSpeed = 180;
  for (std::vector<ObserverSprite *>::const_iterator it_observer = observers.cbegin(); it_observer != observers.cend(); it_observer++)
  {
    Vector2f vel( (rand()%(maxSpeed-minSpeed+1)+minSpeed) , 0 );
    knight->attach(*it_observer);
    (*it_observer)->setVelocity(vel);
    (*it_observer)->setScale(0.25);
  }


  Viewport::getInstance().setObjectToTrack(knight->getPlayer());
  std::cout << "Loading complete" << std::endl;
}

void Engine::hudDraw() const{

  SDL_Rect r;
  r.x = Gamedata::getInstance().getXmlInt("hud/startLoc/x");
  r.y = Gamedata::getInstance().getXmlInt("hud/startLoc/y");
  r.w = Gamedata::getInstance().getXmlInt("hud/width");
  r.h = Gamedata::getInstance().getXmlInt("hud/height");

  SDL_Color fontcolor = {
      (Uint8)Gamedata::getInstance().getXmlInt("hud/fontColor/r"),
      (Uint8)Gamedata::getInstance().getXmlInt("hud/fontColor/g"),
      (Uint8)Gamedata::getInstance().getXmlInt("hud/fontColor/b"),
      (Uint8)Gamedata::getInstance().getXmlInt("hud/fontColor/a")
  };

  SDL_Color sideColor = {
      (Uint8)Gamedata::getInstance().getXmlInt("hud/sideColor/r"),
      (Uint8)Gamedata::getInstance().getXmlInt("hud/sideColor/g"),
      (Uint8)Gamedata::getInstance().getXmlInt("hud/sideColor/b"),
      (Uint8)Gamedata::getInstance().getXmlInt("hud/sideColor/a")};
  SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
  // Now set the color for the hud:
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255 / 2);

  // Render rect
  SDL_RenderFillRect(renderer, &r);

  // Now set the color for the outline of the hud:
  SDL_SetRenderDrawColor(renderer, sideColor.a, sideColor.g, sideColor.b, sideColor.a);
  SDL_RenderDrawRect(renderer, &r);

  std::stringstream fps;
  fps.clear();
  fps.str("");
  std::stringstream freeBulletCount;
  freeBulletCount.clear();
  freeBulletCount.str("");
  std::stringstream currentBulletCount;
  currentBulletCount.clear();
  currentBulletCount.str("");
  fps << Clock::getInstance().getFps();
  freeBulletCount<<knight->Current_Freelist_Size();
  currentBulletCount << knight->Current_Bulletlist_Size();
  IoMod::getInstance().writeText("FPS: "+ fps.str(),20,20, fontcolor);
  IoMod::getInstance().writeText("Freebullet: "+ freeBulletCount.str(), 20, 50, fontcolor);
  IoMod::getInstance().writeText("Bulletlist: " + currentBulletCount.str(), 20, 80, fontcolor);
  IoMod::getInstance().writeText("Press 'A' button to Left", 20, 110, fontcolor);
  IoMod::getInstance().writeText("Press 'D' button to Right", 20, 140, fontcolor);
  IoMod::getInstance().writeText("Press 'F1' button to disable this hub", 20, 170, fontcolor);
  IoMod::getInstance().writeText("Press 'F2' button to mute the music", 20, 200, fontcolor);
  IoMod::getInstance().writeText("Press 'J' button to Shoot", 20, 230, fontcolor);
  IoMod::getInstance().writeText("Press 'G' button to on/off GodMode", 20, 260, fontcolor);
  if(knight->getGodMode()){
    IoMod::getInstance().writeText("God mode: True", 20, 290, fontcolor);
  }else{
    IoMod::getInstance().writeText("God mode: False", 20, 290, fontcolor);
  }
  std::stringstream scoreHud;
  scoreHud << score;
  IoMod::getInstance().writeText("Score: " + scoreHud.str(), 20, 320, fontcolor);
}

void Engine::draw() const {

  world.draw();
  if(observers.size()==0 || playerExploding){
    std::stringstream finalScore;
    finalScore.clear();
    finalScore<<score;
    io.writeText("Game Over", 500, 240,{0,0,0,0});
    io.writeText("Your Final Score is " + finalScore.str(), 500, 270, {0, 0, 0, 0});
    io.writeText("Press R to Restart the game", 500, 300, {0, 0, 0, 0});
    clock.pause();
  }
  clouds.draw();
  knight->draw();
  knight_hb->draw();
  for (std::vector<ObserverSprite *>::const_iterator it_observer = observers.cbegin(); it_observer != observers.cend(); it_observer++)
  {
    (*it_observer)->draw();
  }
  ground.draw();
  viewport.draw();
  if (isDrawingHub)
  {
    hudDraw();
  }
  SDL_RenderPresent(renderer);
}

void Engine::checkForCollisions() {

  std::vector<ObserverSprite*>::iterator it_observer = observers.begin();
  while (it_observer != observers.end())
  {
    ObserverSprite *ob = *it_observer;

    // if (strategies[currenStrategy]->execute(*knight, **it_observer))
    if (collisionStrategy->execute(*knight, **it_observer))
    {   
      //Zombie will automatically attack Knight when they got collision
      if(knight->getGodMode()==false){
        knight->hurt();
        knight_hb->getDamage();
      }
      // std::cout << "Health:" << knight->showHealth() << std::endl;
    }

    if (knight->getShot(ob))
    {
      ob->hurt();
      // std::cout << "Health:" << ob->showHealth() << std::endl;
      if (ob->showHealth() <= 0)
      {
        score++;
        knight->detach(ob);
        std::cout<<ob->getName()<<"exploded"<<std::endl;
        ob->explode();
        music[2];
        delete ob;
        it_observer = observers.erase(it_observer);
      }else{
        it_observer++;
      }
    }else{
      it_observer++;
    }
    if (knight->showHealth() <= 0 && !playerExploding)
    {
      knight->explode();
      music[1];
      playerExploding = true;
      // delete knight;
      // knight->resetHealth();
      std::cout<<"Game Over"<<std::endl;
    }
    
  }
  

}

void Engine::update(Uint32 ticks) {

  // checkForCollisions();
  ground.update();
  if (knight){
    knight->update(ticks);
    knight_hb->update(ticks);
  }
  for (std::vector<ObserverSprite *>::const_iterator it_observer = observers.cbegin(); it_observer != observers.cend(); it_observer++)
  {
    (*it_observer)->update(ticks);
  }
  clouds.update();
  world.update();
  viewport.update(); // always update viewport last
}

void Engine::switchSprite(){
  ++currentSprite;
  currentSprite = currentSprite % 2;
  if ( currentSprite ) {
    Viewport::getInstance().setObjectToTrack(knight->getPlayer());
  }
  else {
    Viewport::getInstance().setObjectToTrack(observers[1]);
  }
}

bool Engine::play() {
  SDL_Event event;
  const Uint8* keystate;
  bool done = false;
  Uint32 ticks = clock.getElapsedTicks();
  FrameGenerator frameGen;

  while ( !done ) {
    // The next loop polls for events, guarding against key bounce:
    while ( SDL_PollEvent(&event) ) {
      keystate = SDL_GetKeyboardState(NULL);
      if (event.type ==  SDL_QUIT) { done = true; break; }
      if(event.type == SDL_KEYDOWN) {
        if (keystate[SDL_SCANCODE_Q] || keystate[SDL_SCANCODE_ESCAPE]) {
          done = true;
          break;
        }
        
        if ( keystate[SDL_SCANCODE_P] ) {
          if ( clock.isPaused() ) clock.unpause();
          else clock.pause();
        }
        // if (keystate[SDL_SCANCODE_M])
        // {
        //   currenStrategy = (currenStrategy+1) % strategies.size();
        // }
        if(keystate[SDL_SCANCODE_R]){
          clock.unpause();
          return true;
        }
        if(keystate[SDL_SCANCODE_F2]){
          music.toggleMusic();
        }
        if ( keystate[SDL_SCANCODE_T] ) {
          switchSprite();
        }
        if (keystate[SDL_SCANCODE_F4] && !makeVideo) {
          std::cout << "Initiating frame capture" << std::endl;
          makeVideo = true;
        }
        else if (keystate[SDL_SCANCODE_F4] && makeVideo) {
          std::cout << "Terminating frame capture" << std::endl;
          makeVideo = false;
        }
        if (keystate[SDL_SCANCODE_G] && knight->getGodMode()==true)
        {
          knight->setGodeModeFalse();
        }
        else if (keystate[SDL_SCANCODE_G] && knight->getGodMode()==false)
        {
          knight->setGodeModeTrue();
        }
        if (keystate[SDL_SCANCODE_F1] && isDrawingHub)
        {
          isDrawingHub = false;
        }
        else if (keystate[SDL_SCANCODE_F1] && !isDrawingHub)
        {
          isDrawingHub = true;
        }
      }
    }

    // In this section of the event loop we allow key bounce:

    ticks = clock.getElapsedTicks();
    if ( ticks > 0 ) {
      clock.incrFrame();
      if (keystate[SDL_SCANCODE_A])
      {
        knight->left();
      }else if (keystate[SDL_SCANCODE_D]) 
      {
        knight->right();
      }else if (keystate[SDL_SCANCODE_W])
      {
        knight->up();
      }else if (keystate[SDL_SCANCODE_S])
      {
        knight->down();
      }else if (keystate[SDL_SCANCODE_J])
      {
        knight->shoot();
        music[0];
      }
      else{ 
        knight->stop();
      }
      checkForCollisions();
      draw();
      update(ticks);
      if ( makeVideo ) {
        frameGen.makeFrame();
      }  
    }
  }
  return false;
}
