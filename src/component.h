#pragma once

#include "basicObject.h"

class GameObject;

class Component : public BasicObject
{
public:
    Component() {}
    GameObject* gameObject();
protected:
    GameObject* game_object;
};
