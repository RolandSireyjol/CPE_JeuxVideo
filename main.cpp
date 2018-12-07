// main.cpp

#include <irrlicht.h>

#include "events.h"
#include "player.h"

using namespace irr;

namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;

int main()
{
  // Le gestionnaire d'événements
  EventReceiver receiver;
  std::vector<iv::ITexture*> textures;

  // Création de la fenêtre et du système de rendu.
  IrrlichtDevice *device = createDevice(iv::EDT_OPENGL,
                                        ic::dimension2d<u32>(640, 480),
                                        16, false, false, false, &receiver);

  iv::IVideoDriver  *driver = device->getVideoDriver();
  is::ISceneManager *smgr = device->getSceneManager();

  // Chargement de notre personnage
  is::IAnimatedMesh *mesh = smgr->getMesh("data/tris.md2");

  // Attachement de notre personnage dans la scène
  is::IAnimatedMeshSceneNode *node = smgr->addAnimatedMeshSceneNode(mesh);
  node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  node->setMD2Animation(irr::scene::EMAT_STAND);
  textures.push_back(driver->getTexture("data/base.pcx"));
  textures.push_back(driver->getTexture("data/red_texture.pcx"));
  textures.push_back(driver->getTexture("data/blue_texture.pcx"));
  node->setMaterialTexture(0, textures[0]);
  receiver.set_node(node);
  receiver.set_textures(textures);

  // MK_RS Ajout de skybox---------------start
  driver->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, false);

  /*scene::ISceneNode* skybox=*/smgr->addSkyBoxSceneNode(
      driver->getTexture(  "data/skybox/top.png"),
      driver->getTexture(  "data/skybox/bot.png"),
      driver->getTexture( "data/skybox/left.png"),
      driver->getTexture("data/skybox/right.png"),
      driver->getTexture("data/skybox/front.png"),
      driver->getTexture( "data/skybox/back.png"));

  driver->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, true);
  // MK_RS Ajout de skybox---------------end

  // Création du player---------------start
  Player player(smgr);
  //receiver.set_player(player);

  // Création du player---------------end
  // Création du triangle selector------start
  scene::ITriangleSelector *selector;
  selector = smgr->createOctreeTriangleSelector(node->getMesh(), node);
  node->setTriangleSelector(selector);
  // Création du triangle selector--------end
  // MK_RS Ajout de destroyer---------------start
  is::IAnimatedMesh *mesh_destroyer = smgr->getMesh("data/destroyer/destroyer.obj");
  is::IAnimatedMeshSceneNode *node_destroyer = smgr->addAnimatedMeshSceneNode(mesh_destroyer);
  node_destroyer->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  node_destroyer->setScale(ic::vector3df(1000, 1000, 1000));
  node_destroyer->setRotation(ic::vector3df(0, 0, 0));
  node_destroyer->setPosition(ic::vector3df(500, -1000, 0));
  // MK_RS Ajout de cockpit---------------end



  //is::ICameraSceneNode *camera = smgr->addCameraSceneNodeMaya();
  //camera->setTarget(node->getPosition());

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
