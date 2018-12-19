#pragma once

#include <irrlicht.h>
#include <list>

#include "gameNode.h"
#include "behaviourNode.h"

using namespace irr;

namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;

class GameEngine : public irr::IEventReceiver
{
public:
    GameEngine();
    void run();
private:
    IrrlichtDevice *device;
    iv::IVideoDriver  *driver;
    is::ISceneManager* smgr;

    std::list<GameNode*> gameNodes;
    std::list<BehaviourNode*> behaviours;

    bool OnEvent(const irr::SEvent &event);

    bool keyboard(const irr::SEvent &event);
    bool mouse(const irr::SEvent &event);

};
