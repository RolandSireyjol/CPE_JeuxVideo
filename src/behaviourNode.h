#pragma once

#include <irrlicht.h>
#include <ISceneNode.h>

#include "node.h"
#include "events.h"
#include "gameEngine.h"

using namespace irr;
namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;

class BehaviourNode : public Node
{
public:
    BehaviourNode(is::ISceneNode *parent, is::ISceneManager *mgr, s32 id=-1,
                  const core::vector3df &position=core::vector3df(0, 0, 0),
                  const core::vector3df &rotation=core::vector3df(0, 0, 0),
                  const core::vector3df &scale=core::vector3df(1.0f, 1.0f, 1.0f)) ;
    virtual void Start();
    virtual void Update();
    virtual void OnCollisionEnter();
    virtual void OnMouseDown();

    virtual ~BehaviourNode(){}
    NodeTypes getType();
    void SetEngine(GameEngine* eng);
    bool start_flag;
    static EventReceiver* input;
protected:
    static GameEngine* engine;
private:
};
