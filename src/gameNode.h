#pragma once

#include <irrlicht.h>
#include <list>
#include "node.h"
//#include "gameEngine.h"

using namespace irr;
namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;


class GameNode : public Node
{
public:
    GameNode(is::ISceneNode *parent, is::ISceneManager *mgr, s32 id=-1,
             const core::vector3df &position=core::vector3df(0, 0, 0),
             const core::vector3df &rotation=core::vector3df(0, 0, 0),
             const core::vector3df &scale=core::vector3df(1.0f, 1.0f, 1.0f)) ;

   // GameNode(is::ISceneNode *parent);

   // GameNode();
    NodeTypes getType();
    void Destroy();
    void AddComponent(Node* component);
private:
    std::list<Node*> components;
};


/*template <class T> T* GameNode::AddComponent(){
    T* t = new T(this,getEngine()->GetSceneManager());
    //engine->AddNode(t);
    components.push_back((Node*)t);
    return t;
}*/
