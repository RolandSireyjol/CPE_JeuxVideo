#include "collidable.h"

Collidable::Collidable(is::ISceneManager *smgr, is::IAnimatedMesh *mesh, ic::vector3df pos, bool destructible, int health_points){
    node = smgr->addAnimatedMeshSceneNode(mesh);
    node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    node->setPosition(pos);
    this->destructible=destructible;
    this->health_points=health_points;
}


void Collidable::setScale(ic::vector3df scale){
    node->setScale(scale);
}
