#pragma once

#include <irrlicht.h>
#include <list>

#include <scene.h>

using namespace irr;

namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;

class GameEngine
{
public:
    GameEngine() {}
    Scene& CreateScene();
private:
    std::list<Scene> scenes;
};
