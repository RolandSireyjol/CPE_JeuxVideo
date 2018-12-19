#include "gameNode.h"

using namespace irr;

namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;

GameNode::GameNode(is::ISceneNode *parent, is::ISceneManager *mgr, s32 id,
                   const core::vector3df &position,
                   const core::vector3df &rotation,
                   const core::vector3df &scale)
    :is::ISceneNode(parent, mgr,id,position,rotation,scale),destroy_flag(false)
{}

void GameNode::Destroy(){
    destroy_flag = true;
}

const core::aabbox3d<f32>& GameNode::getBoundingBox() const{
    return bounding_box;
}
