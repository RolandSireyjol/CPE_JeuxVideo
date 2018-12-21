#include "ISceneNodeAnimator6D.h"

#include <iostream>

void ISceneNodeAnimator6D::animateNode(irr::scene::ISceneNode* node, u32 timeMs){
    this->node = node;
}

irr::scene::ISceneNodeAnimator* ISceneNodeAnimator6D::createClone(irr::scene::ISceneNode*, irr::scene::ISceneManager*){
    return nullptr;
}


bool ISceneNodeAnimator6D::OnEvent(const irr::SEvent &event){
    if (event.KeyInput.PressedDown)
    {
      ic::vector3df pos = node->getPosition();
      ic::vector3df rot = node->getRotation();
      ic::vector3df addedrot;
      is::ICameraSceneNode* cam = (is::ICameraSceneNode*)node;
      //ic::vector3df up = cam->getUpVector();
      switch (event.KeyInput.Key)
      {
      case KEY_KEY_Z: // pitch+
	  addedrot.X-=0.1;
	  break;
      case KEY_KEY_S: // pitch-
	  addedrot.X+=0.1;
	  break;
      case KEY_KEY_D://yaw+
	  addedrot.Y+=0.1;
	  break;
      case KEY_KEY_Q://yaw-
	  addedrot.Y-=0.1;
	  break;
      case KEY_KEY_A:
	  addedrot.Z+=0.1; //roll+
	  break;
      case KEY_KEY_E:
	  addedrot.Z-=0.1; //roll-
	  break;
      case KEY_KEY_X: // slows down
	break;
        default:
	  return true;
	  break;
      }
      ic::quaternion quat = ic::quaternion(rot*ic::PI/180.0);
      quat = quat * ic::quaternion(quat * addedrot);
      quat.toEuler(rot);
      rot*=180.0/ic::PI;
      node->setPosition(pos);
      node->setRotation(rot);
      cam->setUpVector(quat * ic::vector3df(0.0,1.0,0.0));
      return false;
    }
    return  false;
}
