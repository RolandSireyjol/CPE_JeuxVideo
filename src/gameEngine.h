#pragma once

#include <irrlicht.h>
#include <list>
#include <string>

#include "events.h"
#include "node.h"
#include "gameNode.h"
using namespace irr;

namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;

class GameNode;

class GameEngine
{
public:
    GameEngine();
    void run();
    static EventReceiver input;
    GameNode* CreateGameNode();
    template <class T> T* AddComponentToGameNode(GameNode* node);
    is::ISceneManager* GetSceneManager();
private:
    void AddNode(Node* node);
    IrrlichtDevice *device;
    iv::IVideoDriver  *driver;
    is::ISceneManager* smgr;

    std::list<GameNode*> gameNodes;
    std::list<Node*> behaviours;
};

template <class T> T* GameEngine::AddComponentToGameNode(GameNode* node){
    T* t = new T(node,smgr);
    AddNode(t);
    node->AddComponent((Node*)t);
    return t;
}

