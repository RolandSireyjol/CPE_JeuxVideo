#pragma once

#include <irrlicht.h>

using namespace irr;

namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;

#include "events.h"
#include "sceneManager.h"

class Game{
public:
    Game();
    void run();
private:
    EventReceiver receiver;
    IrrlichtDevice *device;
    iv::IVideoDriver  *driver;
    SceneManager scene_manager;
};
