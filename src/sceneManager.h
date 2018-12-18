#pragma once

#include <irrlicht.h>
#include <list>

#include "player.h"
#include "tir.h"
#include "collidable.h"

using namespace irr;

namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;

class SceneManager
{
public:
    SceneManager(is::ISceneManager *smgr,iv::IVideoDriver  *driver);
    SceneManager(){}
    void draw_scene();
    void manageKeyboardInput(EKEY_CODE key);
    void manageTriggerInput();
    void iteration();
private:
    is::ISceneManager *smgr;
    Player player;
    //is::IAnimatedMeshSceneNode *node_destroyer;
    //is::IAnimatedMesh *mesh_target;
    //std::list<is::IAnimatedMeshSceneNode*> targets;
    std::list<Collidable> collidables;
    is::IAnimatedMesh *mesh_tir;
    std::list<Tir> tirs;
};
