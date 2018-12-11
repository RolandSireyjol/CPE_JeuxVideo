#pragma once

#include <irrlicht.h>
using namespace irr;
namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;

class Tir
{
public:
    Tir() {}
    ~Tir();
    Tir(is::ISceneManager *smgr, is::IAnimatedMesh *mesh_tir, ic::vector3df pos,ic::vector3df rot,
        ic::vector3df speed);
    void iteration();
private:
    ic::vector3df speed;
    is::IAnimatedMeshSceneNode* node;
};
