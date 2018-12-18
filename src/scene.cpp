#include "scene.h"

Scene::Scene(std::string name)
    :name(name)
{}

GameObject& Scene::AddGameObject(){
    gameObjects.emplace_back();
    return gameObjects.back();
}

GameObject& Scene::AddGameObject(std::string name){
    gameObjects.emplace_back(name);
    return gameObjects.back();
}
