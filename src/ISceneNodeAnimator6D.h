#pragma once

#include <irrlicht.h>

using namespace irr;
namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;

class ISceneNodeAnimator6D : public irr::scene::ISceneNodeAnimator
{
public:
    void animateNode(irr::scene::ISceneNode* node, u32 timeMs);
    irr::scene::ISceneNodeAnimator* createClone(irr::scene::ISceneNode*, irr::scene::ISceneManager*);
    ISceneNodeAnimator6D() {}
    bool OnEvent(const irr::SEvent &event);
private:
    irr::scene::ISceneNode* node;
};
