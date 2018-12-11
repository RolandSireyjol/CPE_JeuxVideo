#include "sceneManager.h"

#include <iostream>

SceneManager::SceneManager(is::ISceneManager *smgr,iv::IVideoDriver  *driver)
    :player(smgr)
{
    this->smgr = smgr;

    // MK_RS Ajout de skybox---------------start
    driver->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, false);

    smgr->addSkyBoxSceneNode(
        driver->getTexture(  "data/skybox/top.png"),
        driver->getTexture(  "data/skybox/bot.png"),
        driver->getTexture( "data/skybox/left.png"),
        driver->getTexture("data/skybox/right.png"),
        driver->getTexture("data/skybox/front.png"),
        driver->getTexture( "data/skybox/back.png"));

    driver->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, true);
    // MK_RS Ajout de skybox---------------end

    // MK_RS Ajout de destroyer---------------start
    is::IAnimatedMesh *mesh_destroyer = smgr->getMesh("data/destroyer/destroyer.obj");
    node_destroyer = smgr->addAnimatedMeshSceneNode(mesh_destroyer);
    node_destroyer->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    node_destroyer->setScale(ic::vector3df(1000, 1000, 1000));
    node_destroyer->setRotation(ic::vector3df(0, 0, 0));
    node_destroyer->setPosition(ic::vector3df(500, -1000, 0));

    // MK_RS Ajout de target---------------start
    mesh_target = smgr->getMesh("data/target/target.obj");
    for(int i=0;i<10;++i){
        is::IAnimatedMeshSceneNode *node_target = smgr->addAnimatedMeshSceneNode(mesh_target);
        node_target->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        node_target->setScale(ic::vector3df(100, 100, 100));
        node_target->setRotation(ic::vector3df(0, 0, 0));
        node_target->setPosition(ic::vector3df(0, -150*i, 0));
        targets.push_back(node_target);
    }

    // MK_RS Ajout de tir---------------start
    mesh_tir = smgr->getMesh("data/tir/tir.obj");
    // MK_RS Ajout de tir---------------end

}

void SceneManager::draw_scene(){
    smgr->drawAll();
}

void SceneManager::manageInput(EKEY_CODE key){
    ic::vector3df rotation = player.getRotation()* M_PI / 180.0;
    ic::quaternion rotQuat(rotation);
    float acceleration =0.2f;
    switch (key)
    {
      case KEY_KEY_Z: // Avance
        player.speed += rotQuat* ic::vector3df (0,0,acceleration);
        break;
      case KEY_KEY_S: // Recule
        player.speed -= rotQuat* ic::vector3df (0,0,acceleration);
        break;
    case KEY_KEY_D: // Tourne à droite
      player.speed += rotQuat* ic::vector3df (acceleration,0,0);
      break;
    case KEY_KEY_Q: // Tourne à gauche
      player.speed -= rotQuat* ic::vector3df (acceleration,0,0);
      break;
    case KEY_KEY_A: // Tourne à droite
      player.speed += rotQuat* ic::vector3df (0,acceleration,0);
      break;
    case KEY_KEY_W: // Tourne à gauche
      player.speed -= rotQuat* ic::vector3df (0,acceleration,0);
      break;
    case KEY_KEY_X: // slows down
      player.speed *= 0.8;
      break;
      default:;
    }
    if (player.speed.X >  100) {player.speed.X =100;}
    if (player.speed.Y >  100) {player.speed.Y =100;}
    if (player.speed.Z >  100) {player.speed.Z =100;}
    if (player.speed.X <- 100) {player.speed.X =-100;}
    if (player.speed.Y <- 100) {player.speed.Y =-100;}
    if (player.speed.Z <- 100) {player.speed.Z =-100;}

    if ((player.speed.X < 0.1) &&(player.speed.X >- 0.1)) {player.speed.X =0;}
    if ((player.speed.Y < 0.1) &&(player.speed.Y >- 0.1)) {player.speed.Y =0;}
    if ((player.speed.Z < 0.1) &&(player.speed.Z >- 0.1)) {player.speed.Z =0;}
  std::cout<<"player.speed :"<<std::endl;
  std::cout<<player.speed.X<<std::endl;
  std::cout<<player.speed.Y<<std::endl;
  std::cout<<player.speed.Z<<std::endl;
  std::cout<<"player.position :"<<std::endl;
  std::cout<<player.camera->getPosition().X<<std::endl;
  std::cout<<player.camera->getPosition().Y<<std::endl;
  std::cout<<player.camera->getPosition().Z<<std::endl;
}


void SceneManager::iteration(){
    // ADDED INERTIA
    player.camera->setPosition(player.camera->getPosition()+player.speed);
}
