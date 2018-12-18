#pragma once

#include <string>
#include <irrlicht.h>

#include "object.h"

using namespace irr;

namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;

class GameObject : public Object
{
public:
    GameObject();
    GameObject(std::string name);
};
