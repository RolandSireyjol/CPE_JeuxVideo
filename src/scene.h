#pragma once

#include <string>
#include <list>
#include <irrlicht.h>

#include "gameObject.h"

using namespace irr;

namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;

class Scene
{
public:
    Scene() {}
    Scene(std::string name);
    GameObject& AddGameObject();
    GameObject& AddGameObject(std::string name);
private:
    std::string name;
    std::list<GameObject> gameObjects;
};
