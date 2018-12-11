// main.cpp

#include <irrlicht.h>
#include <list>

#include "game.h"
#include "events.h"
#include "player.h"

using namespace irr;

namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;

int main()
{
  Game game;
  game.run();
  return 0;
}
