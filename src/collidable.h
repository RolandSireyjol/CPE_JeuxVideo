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
    ~Collidable();
    Collidable(is::ISceneManager *smgr, is::IAnimatedMesh *mesh, ic::vector3df pos,bool destructible,int health_points);
    void setScale(ic::vector3df scale);
    bool getDestructible();
    ic::aabbox3d< f32 > getTransformedBoundingBox ();
    int getHealthPoints();
    void setHealthPoints(int hp);
private:
    is::IAnimatedMeshSceneNode* node;
    bool destructible;
    int health_points;
};
