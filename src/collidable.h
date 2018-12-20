#pragma once

#include <irrlicht.h>
#include "behaviourNode.h"

using namespace irr;
namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;



class Collidable : public BehaviourNode
{
public:
    Collidable(is::ISceneNode *parent, is::ISceneManager *mgr, s32 id=-1,
               const core::vector3df &position=core::vector3df(0, 0, 0),
               const core::vector3df &rotation=core::vector3df(0, 0, 0),
               const core::vector3df &scale=core::vector3df(1.0f, 1.0f, 1.0f)) ;

    bool is_destructible;
    int health_points;
    int attack_points;
    is::IAnimatedMesh* mesh;

    void Start();
};
