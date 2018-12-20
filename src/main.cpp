// main.cpp

#include <irrlicht.h>
#include <list>
#include <iostream>

/*#include "game.h"
#include "events.h"
#include "player.h"*/

#include "gameEngine.h"
#include "gameNode.h"
#include "player.h"
#include "collidable.h"

using namespace irr;

namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;



int main()
{
  /*Game game;
  game.run();*/
    GameEngine engine;
    GameNode* player = engine.CreateGameNode();
    BehaviourNode* bn = (BehaviourNode*)engine.AddComponentToGameNode<Player>(player);
    bn->SetEngine(&engine);
    engine.run();

  return 0;
}
