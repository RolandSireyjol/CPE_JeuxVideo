#include "gameEngine.h"

Scene& GameEngine::CreateScene(){
    scenes.emplace_back();
    return scenes.back();
}
