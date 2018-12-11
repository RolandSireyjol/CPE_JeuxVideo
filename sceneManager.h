#pragma once

#include <irrlicht.h>
#include <list>

#include "player.h"

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
    void manageInput(EKEY_CODE key);
    void iteration();
private:
    is::ISceneManager *smgr;
    Player player;
    is::IAnimatedMeshSceneNode *node_destroyer;
    is::IAnimatedMesh *mesh_target;
    std::list<is::IAnimatedMeshSceneNode*> targets;
    is::IAnimatedMesh *mesh_tir;
    std::list<is::IAnimatedMeshSceneNode*> tirs;

};
