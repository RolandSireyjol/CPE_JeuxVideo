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

    public:
        float speed;
        is::ICameraSceneNode *camera;
        Player(is::ISceneManager *smgr);
        ic::vector3df getRotation();
        void          setRotation( ic::vector3df rot);


};

#endif
