#pragma once

#include <irrlicht.h>
#include <ISceneNode.h>

using namespace irr;
namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;

enum NodeTypes{
    BEHAVIOUR,
    COLLISION,
    NODE,
    GAME_NODE
};

class Node : public is::ISceneNode
{
public:
    Node(is::ISceneNode *parent, is::ISceneManager *mgr, s32 id=-1,
             const core::vector3df &position=core::vector3df(0, 0, 0),
             const core::vector3df &rotation=core::vector3df(0, 0, 0),
             const core::vector3df &scale=core::vector3df(1.0f, 1.0f, 1.0f)) ;
    virtual void Destroy();
    virtual void render(){}
    const irr::core::aabbox3d<f32>& getBoundingBox() const;

    virtual NodeTypes getType();
protected:
    core::aabbox3d<f32> bounding_box;
    bool destroy_flag;
};
