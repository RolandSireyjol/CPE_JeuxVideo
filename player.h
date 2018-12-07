// player.h

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

#include <irrlicht.h>
using namespace irr;
namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;


/**************************************************************************\
 * class player                                        *
\**************************************************************************/
class Player
{
    // Moving parameters
    float speed;
    is::ICameraSceneNode *camera;

    public:
        Player(is::ISceneManager *smgr);


};

#endif
