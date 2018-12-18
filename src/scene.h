#pragma once

#include <string>
#include <irrlicht.h>

using namespace irr;

namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;

class Scene
{
public:
    Scene() {}
    Scene(std::string name);
private:
    std::string name;
};
