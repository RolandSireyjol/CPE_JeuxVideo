// main.cpp

#include <irrlicht.h>
#include <list>
#include <iostream>

/*#include "game.h"
#include "events.h"
#include "player.h"*/

#include "gameEngine.h"
#include "scene.h"

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
    GameObject& go = sc.AddGameObject("Hello There");
    std::cout<<go.ToString()<<std::endl;

  return 0;
}
