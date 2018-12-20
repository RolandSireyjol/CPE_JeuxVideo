#include "node.h"

using namespace irr;

namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;

Node::Node(is::ISceneNode *parent, is::ISceneManager *mgr, s32 id,
                   const core::vector3df &position,
                   const core::vector3df &rotation,
                   const core::vector3df &scale)
    :is::ISceneNode(parent, mgr,id,position,rotation,scale),destroy_flag(false)
{
}

void Node::Destroy(){
    destroy_flag = true;
}

const core::aabbox3d<f32>& Node::getBoundingBox() const{
    return bounding_box;
}

NodeTypes Node::getType(){
    return NodeTypes::NODE;
}
