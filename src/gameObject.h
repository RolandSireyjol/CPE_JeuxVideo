#pragma once

#include <list>

#include "basicObject.h"
#include "component.h"

class GameObject : public BasicObject
{
public:
    GameObject() {}
    template <class T>
    T* AddComponent()
protected:
    std::list<Component> components;
};
