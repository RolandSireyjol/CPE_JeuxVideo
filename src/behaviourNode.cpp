#include "behaviourNode.h"

BehaviourNode::BehaviourNode(is::ISceneNode *parent, is::ISceneManager *mgr, s32 id,
                             const core::vector3df &position,
                             const core::vector3df &rotation,
                             const core::vector3df &scale)
    :Node(parent, mgr,id,position,rotation,scale),start_flag(true)
{}

void BehaviourNode::Start(){

}

void BehaviourNode::OnCollisionEnter()
{

}

void BehaviourNode::OnMouseDown(){

}

void BehaviourNode::Update(){

}

NodeTypes BehaviourNode::getType(){
    return NodeTypes::BEHAVIOUR;
}


GameEngine* BehaviourNode::engine;
void BehaviourNode::SetEngine(GameEngine* eng){
    engine = eng;
}
