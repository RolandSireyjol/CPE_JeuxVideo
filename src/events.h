// events.h

#ifndef EVENTS_H
#define EVENTS_H

#include <vector>

#include <irrlicht.h>
#include "ISceneNodeAnimator6D.h"

class EventReceiver : public irr::IEventReceiver
{

  bool keyboard(const irr::SEvent &event);
  bool mouse(const irr::SEvent &event);

public:
  EventReceiver();
  ISceneNodeAnimator6D* camera;
  bool OnEvent(const irr::SEvent &event);

};

#endif
