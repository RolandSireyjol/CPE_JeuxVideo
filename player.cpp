// player.cpp


#include "player.h"



/**************************************************************************\
 * class player                                        *
\**************************************************************************/


Player::Player(is::ISceneManager *smgr)
{
    speed=20.;
    // Création de la caméra--------------start
    camera =
      smgr->addCameraSceneNodeFPS(nullptr,
                                  100,         // Vitesse de rotation
                                  .3,          // Vitesse de déplacement
                                  -1,          // Identifiant
                                  nullptr, 0,  // Table de changement de touches
                                  false,        // Pas de possibilité de voler
                                  3);          // Vitesse saut
    camera->setPosition(ic::vector3df(50, 50, -60));
    camera->setTarget(ic::vector3df(-70, 30, -60));
    // Création de la caméra----------------end
    // MK_RS Ajout de cockpit---------------start
    is::IAnimatedMesh *mesh_cockpit = smgr->getMesh("data/X-Wing/untitled.obj");
    is::IAnimatedMeshSceneNode *node_cockpit = smgr->addAnimatedMeshSceneNode(mesh_cockpit);
    node_cockpit->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    node_cockpit->setScale(ic::vector3df(100, 100, 100));
    node_cockpit->setRotation(ic::vector3df(0, 180, 0));
    node_cockpit->setPosition(ic::vector3df(0, -10, 60));
    node_cockpit->setParent(camera);
    // MK_RS Ajout de cockpit---------------end
}
