#include "gameEngine.h"
#include "gameNode.h"
#include "behaviourNode.h"
#include "player.h"

GameEngine::GameEngine(){
    // Création de la fenêtre et du système de rendu.
    device = createDevice(iv::EDT_OPENGL,
                          ic::dimension2d<u32>(640, 480),
                          16, false, false, false, this);

    driver = device->getVideoDriver();
    smgr = device->getSceneManager();

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

    GameNode* player = new GameNode(smgr->getRootSceneNode(), smgr);
    /*is::ICameraSceneNode *camera =
    smgr->addCameraSceneNodeFPS(player,
				100,         // Vitesse de rotation
				.3,          // Vitesse de déplacement
				-1,          // Identifiant
				nullptr, 0,  // Table de changement de touches
				false,        // Pas de possibilité de voler
				3);          // Vitesse saut
    camera->setPosition(ic::vector3df(50, 50, -60));
    camera->setTarget(ic::vector3df(-70, 30, -60));
    camera->setFarValue(50000.);*/

    BehaviourNode* playerBehaviour = new Player(player,smgr);

    gameNodes.push_back(player);
    behaviours.push_back(playerBehaviour);

}


void GameEngine::run(){

    for(BehaviourNode* behaviour : behaviours){
	behaviour->Start();
    }

    while(device->run())
    {

	for(BehaviourNode* behaviour : behaviours){
	    behaviour->Update();
	}

      driver->beginScene(true, true, iv::SColor(0,50,100,255));

      // Dessin de la scène :
      smgr->drawAll();
      //
      driver->endScene();
    }
    device->drop();
}

bool GameEngine::OnEvent(const irr::SEvent &event){

      switch (event.EventType)
      {
        case EET_KEY_INPUT_EVENT:
	  return keyboard(event);
        case EET_MOUSE_INPUT_EVENT:
	  return mouse(event);
        default:;
      }

    return false;
}

bool GameEngine::mouse(const irr::SEvent &event)
{
  switch(event.MouseInput.Event)
  {
    case EMIE_LMOUSE_PRESSED_DOWN:
      for(BehaviourNode* behaviour : behaviours){
	  behaviour->OnMouseDown();
      }
      break;
    case EMIE_LMOUSE_LEFT_UP:
    case EMIE_MOUSE_MOVED:
    case EMIE_MOUSE_WHEEL:
    default:
      ;
  }

  return false;
}

bool GameEngine::keyboard(const irr::SEvent &event)
{
  if (event.KeyInput.PressedDown)
  {
    EKEY_CODE key_pressed = event.KeyInput.Key;
    switch (key_pressed)
    {
      case KEY_ESCAPE:
	exit(0);
	break;
    case KEY_KEY_Z: // Avance
    case KEY_KEY_S: // Recule
    case KEY_KEY_D: // Tourne à droite
    case KEY_KEY_Q: // Tourne à gauche
    case KEY_KEY_A: // Tourne à droite
    case KEY_KEY_W: // Tourne à gauche
    case KEY_KEY_X: // slows down
      break;
      default:
	break;
    }
  }

  return false;
}
