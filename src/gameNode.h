#pragma once

#include <irrlicht.h>
#include <ISceneNode.h>

using namespace irr;
namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;

enum GameNodeType{
    GAME_NODE,
    COLLISION_NODE,
    BEHAVIOUR_NODE,
    SCENE_NODE
};

class GameNode : public is::ISceneNode
{
public:
    GameNode(is::ISceneNode *parent, is::ISceneManager *mgr, s32 id=-1,
             const core::vector3df &position=core::vector3df(0, 0, 0),
             const core::vector3df &rotation=core::vector3df(0, 0, 0),
             const core::vector3df &scale=core::vector3df(1.0f, 1.0f, 1.0f)) ;
    virtual void Destroy();
    void render(){}
    const irr::core::aabbox3d<f32>& getBoundingBox() const;

protected:
    core::aabbox3d<f32> bounding_box;
    bool destroy_flag;
};
