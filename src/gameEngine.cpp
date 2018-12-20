#include <iostream>

#include "gameEngine.h"
#include "gameNode.h"
#include "behaviourNode.h"
#include "player.h"
#include "collidable.h"


EventReceiver GameEngine::input = EventReceiver();
EventReceiver* BehaviourNode::input = &GameEngine::input;

GameEngine::GameEngine(){
    // Création de la fenêtre et du système de rendu.
    device = createDevice(iv::EDT_OPENGL,
                          ic::dimension2d<u32>(640, 480),
                          16, false, false, false, &input);

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

    /*GameNode* player = new GameNode(smgr->getRootSceneNode(), smgr);
    GameNode* destroyer = new GameNode(smgr->getRootSceneNode(), smgr);
    destroyer->AddComponent<Collidable>();
    BehaviourNode* playerBehaviour = new Player(player,smgr);

    is::IAnimatedMesh* mesh = smgr->getMesh("data/X-Wing/untitled.obj");
    is::IAnimatedMesh* mesh_destroyer = smgr->getMesh("data/destroyer/destroyer.obj");

    Collidable* playerCollidable = new Collidable(player,smgr);
    Collidable* destroyerCollidable = new Collidable(destroyer,smgr);

    playerCollidable->mesh = mesh;
    destroyerCollidable->mesh = mesh_destroyer;

    gameNodes.push_back(player);
    gameNodes.push_back(destroyer);
    behaviours.push_back(playerBehaviour);
    behaviours.push_back(destroyerCollidable);*/
}


void GameEngine::run(){

    for(auto node : behaviours){
	BehaviourNode* behaviour = (BehaviourNode*)node;
	behaviour->Start();
	behaviour->start_flag = false;
    }
    while(device->run())
    {
	if(input.GetKeyDown(KEY_ESCAPE)){
	    std::cout<<"quit"<<std::endl;
	    exit(0);
	}
	for(auto node : behaviours){
	    BehaviourNode* behaviour = (BehaviourNode*)node;
	    if(behaviour->start_flag){
		behaviour->Start();
		behaviour->start_flag = false;
	    }
	    behaviour->Update();
	}

      driver->beginScene(true, true, iv::SColor(0,50,100,255));

      // Dessin de la scène :
      smgr->drawAll();
      //
      driver->endScene();
      input.ClearKeyDowns();
    }
    device->drop();
}

void GameEngine::AddNode(Node* node){
    switch (node->getType()) {
    case NodeTypes::BEHAVIOUR:
	std::cout<<behaviours.size()<<std::endl;
	behaviours.push_back(node);
	break;
    case NodeTypes::GAME_NODE:
	break;
	gameNodes.push_back((GameNode*)node);
    default:
	break;
    }
    std::cout<<node->getType()<<std::endl;
}

is::ISceneManager* GameEngine::GetSceneManager(){
    return smgr;
}

GameNode* GameEngine::CreateGameNode(){
    GameNode* node = new GameNode(smgr->getRootSceneNode(), smgr);
    AddNode(node);
    return node;
}
