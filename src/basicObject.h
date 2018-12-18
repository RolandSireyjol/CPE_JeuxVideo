#pragma once

#include <irrlicht.h>
#include <string>
using namespace irr;
namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;

class BasicObject
{
public:
    BasicObject();
    BasicObject(std::string name);
    std::string ToString();
    void Destroy();
protected:
    std::string name;
    bool destroy_flag;
};
