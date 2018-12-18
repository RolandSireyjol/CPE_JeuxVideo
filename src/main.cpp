// main.cpp

#include <irrlicht.h>
#include <list>

/*#include "game.h"
#include "events.h"
#include "player.h"*/

#include "gameEngine.h"

using namespace irr;

namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;

int main()
{
  /*Game game;
  game.run();*/
    GameEngine engine;
    Scene& sc = engine.CreateScene();
  return 0;
}
