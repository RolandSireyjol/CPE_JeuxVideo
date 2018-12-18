#include "object.h"


Object::Object()
    :destroy_flag(false)
{}

Object::Object(std::string name)
    :name(name),destroy_flag(false)
{}

std::string& Object::ToString(){
    return name;
}

void Object::Destroy(){
    destroy_flag = true;
}
