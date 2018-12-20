#include "gameNode.h"

using namespace irr;

namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;

GameNode::GameNode(is::ISceneNode *parent, is::ISceneManager *mgr, s32 id,
                   const core::vector3df &position,
                   const core::vector3df &rotation,
                   const core::vector3df &scale)
    :Node(parent, mgr,id,position,rotation,scale)
{
}

/*GameNode::GameNode(is::ISceneNode *parent){
    GameNode(parent, engine->GetSceneManager());
}

GameNode::GameNode(){
    is::ISceneManager mgr = engine->GetSceneManager();
    GameNode(mgr->getRootSceneNode());
}*/

void GameNode::Destroy(){
    destroy_flag = true;
}

/*const core::aabbox3d<f32>& GameNode::getBoundingBox() const{
    return bounding_box;
}*/

NodeTypes GameNode::getType(){
    return NodeTypes::GAME_NODE;
}

void GameNode::AddComponent(Node* component){
    components.push_back(component);
}
