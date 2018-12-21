// main.cpp

#include <irrlicht.h>
#include <list>
#include <iostream>

//#include "game.h"
#include "events.h"
#include "ISceneNodeAnimator6D.h"

using namespace irr;

namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;

int main()
{
    IrrlichtDevice *device;
    iv::IVideoDriver  *driver;
    EventReceiver reciever;
    device = createDevice(iv::EDT_OPENGL,
                          ic::dimension2d<u32>(640, 480),
                          16, false, false, false, &reciever);

    driver = device->getVideoDriver();
    is::ISceneManager* smgr = device->getSceneManager();

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

    // MK_RS Ajout de cockpit---------------start
    is::IAnimatedMesh *mesh_cockpit = smgr->getMesh("data/X-Wing/untitled.obj");
    is::IAnimatedMeshSceneNode *node_cockpit = smgr->addAnimatedMeshSceneNode(mesh_cockpit);
    node_cockpit->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    node_cockpit->setScale(ic::vector3df(100, 100, 100));
    node_cockpit->setRotation(ic::vector3df(0, 180, 0));
    node_cockpit->setPosition(ic::vector3df(0, -10, 60));
    //node_cockpit->setParent(camera);
    // MK_RS Ajout de cockpit---------------end


    is::ICameraSceneNode* cameraNode = smgr->addCameraSceneNode();
    cameraNode->bindTargetAndRotation(true);
    //std::cout<<cameraNode->getTargetAndRotationBinding()<<std::endl;
    ISceneNodeAnimator6D animator;
    reciever.camera = &animator;
    animator.animateNode(cameraNode,0);

    while(device->run())
    {
      driver->beginScene(true, true, iv::SColor(0,50,100,255));

      // Dessin de la scène :
      smgr->drawAll();
      //
      driver->endScene();
    }
    device->drop();

    return 0;
}
