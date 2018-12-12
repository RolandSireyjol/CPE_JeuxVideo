#pragma once

#include <irrlicht.h>
using namespace irr;
namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;



class Collidable
{
public:
    Collidable() {}
    Collidable(is::ISceneManager *smgr, is::IAnimatedMesh *mesh, ic::vector3df pos,bool destructible,int health_points);
    void setScale(ic::vector3df scale);
private:
    is::IAnimatedMeshSceneNode* node;
    bool destructible;
    int health_points;
};
