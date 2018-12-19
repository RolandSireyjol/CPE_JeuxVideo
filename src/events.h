// events.h

#ifndef EVENTS_H
#define EVENTS_H

#include <vector>

#include <irrlicht.h>
#include "sceneManager.h"

class EventReceiver : public irr::IEventReceiver
{

  bool button_pressed;
  int  old_x, old_y;
  int current_texture;

  bool keyboard(const irr::SEvent &event);
  bool mouse(const irr::SEvent &event);

  //SceneManager* sceneManager;

public:
  EventReceiver();
  bool OnEvent(const irr::SEvent &event);
  //void setSceneManager(SceneManager* manager);

};

#endif
