// player.cpp


#include "player.h"
#include "gameNode.h"
#include <iostream>


/**************************************************************************\
 * class player                                        *
\**************************************************************************/


Player::Player(is::ISceneNode *parent, is::ISceneManager *mgr, s32 id,
               const core::vector3df &position,
               const core::vector3df &rotation,
               const core::vector3df &scale)
    :BehaviourNode(parent, mgr,id,position,rotation,scale)
{}

void Player::Start(){
     scene::ISceneNode * gameObject =getParent();
     camera = getSceneManager()->addCameraSceneNode(gameObject);
     camera->setPosition(ic::vector3df(50, 50, -60));
     camera->setTarget(ic::vector3df(-70, 30, -60));
     camera->setFarValue(50000.);

     is::IAnimatedMesh* mesh = getSceneManager()->getMesh("data/X-Wing/untitled.obj");

     is::IMeshSceneNode* meshNode = getSceneManager()->addMeshSceneNode(mesh,getParent());
     meshNode->setScale(core::vector3df(100,100,100));

     mesh_tir = getSceneManager()->getMesh("data/tir/tir.obj");

}

void Player::OnMouseDown(){
    std::cout<<"Player!!"<<std::endl;
}

void Player::Update(){

    if(input->GetKeyDown(KEY_KEY_Z )){
	GameNode* gameNode = (GameNode*)getParent();
	core::vector3df pos = gameNode->getPosition ();
	pos +=core::vector3df(1.0,1.0,1.0);
	gameNode->setPosition (pos);
	std::cout<<pos.X<<std::endl;
    }
    if(input->GetKeyDown(KEY_KEY_M)){
	GameNode* gn = engine->CreateGameNode();
	Collidable* col = engine->AddComponentToGameNode<Collidable>(gn);
	gn->setPosition(getParent()->getPosition());
	col->mesh = mesh_tir;
    }
}
