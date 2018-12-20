#include "collidable.h"

Collidable::Collidable(is::ISceneNode *parent, is::ISceneManager *mgr, s32 id,
                       const core::vector3df &position,
                       const core::vector3df &rotation,
                       const core::vector3df &scale)
            :BehaviourNode(parent, mgr,id,position,rotation,scale)
{}

void Collidable::Start(){
   is::IMeshSceneNode* meshNode = getSceneManager()->addMeshSceneNode(mesh,getParent());
    meshNode->setScale(core::vector3df(100,100,100));
}
