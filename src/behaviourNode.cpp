#include "behaviourNode.h"

BehaviourNode::BehaviourNode(is::ISceneNode *parent, is::ISceneManager *mgr, s32 id,
                             const core::vector3df &position,
                             const core::vector3df &rotation,
                             const core::vector3df &scale)
    :GameNode(parent, mgr,id,position,rotation,scale)
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
