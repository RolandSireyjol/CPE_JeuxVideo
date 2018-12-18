#include "basicObject.h"

BasicObject::BasicObject()
    :destroy_flag(false)
{}

BasicObject::BasicObject(std::string name)
    :destroy_flag(false)
{
    this->name = name;
}

void BasicObject::Destroy(){
    destroy_flag = true;
}

std::string BasicObject::ToString(){
    return name;
}
