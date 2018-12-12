#include "tir.h"
#include <iostream>


Tir::Tir(is::ISceneManager *smgr, is::IAnimatedMesh *mesh_tir, ic::vector3df pos,ic::vector3df rot, ic::vector3df speed){
    node = smgr->addAnimatedMeshSceneNode(mesh_tir);
    node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    node->setScale(ic::vector3df(100, 100, 100));
    node->setRotation(rot);
    node->setPosition(pos);
    ic::vector3df rotation_rad = rot* M_PI / 180.0;
    ic::quaternion rotQuat(rotation_rad);
    this->speed = rotQuat * ic::vector3df(0,0,400) +  speed;
}

void Tir::iteration(){
    ic::vector3df pos = node->getPosition();
    pos+=speed;
    node->setPosition(pos);
}

Tir::~Tir(){
    if(node!=nullptr)
        node->remove();
    std::cout<<"tir détruit"<<std::endl;
}

int Tir::getAttackPoints(){
    return attack_points;
}

void Tir::setAttackPoints(int points){
    attack_points = points;
}


ic::vector3df Tir::getPosition(){
    return node->getPosition();
}
