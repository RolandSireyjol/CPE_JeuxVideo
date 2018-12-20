// player.h

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <iostream>

#include <irrlicht.h>
#include "behaviourNode.h"
#include "gameNode.h"
#include "collidable.h"

using namespace irr;
namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;


/**************************************************************************\
 * class player                                        *
\**************************************************************************/
/*class Player
{
    // Moving parameters

    public:
        ic::vector3df speed;
        is::ICameraSceneNode *camera;
        Player(is::ISceneManager *smgr);
        Player(){}
        ic::vector3df getRotation();
        void          setRotation( ic::vector3df rot);


};*/


class Player : public BehaviourNode
{
public:
    Player(is::ISceneNode *parent, is::ISceneManager *mgr, s32 id=-1,
           const core::vector3df &position=core::vector3df(0, 0, 0),
           const core::vector3df &rotation=core::vector3df(0, 0, 0),
           const core::vector3df &scale=core::vector3df(1.0f, 1.0f, 1.0f)) ;



private:
    void Start();
    void Update();
    void OnMouseDown();
    is::IAnimatedMesh* mesh_tir;
    is::ICameraSceneNode *camera;
};

#endif
