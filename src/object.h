#pragma once

#include <string>
#include <irrlicht.h>

using namespace irr;

namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;

class Object
{
public:
    Object();
    Object(std::string name);
    std::string& ToString();
    virtual void Destroy();
protected:
    std::string name;
    bool destroy_flag;
    //virtual const std::string class_name;
};
