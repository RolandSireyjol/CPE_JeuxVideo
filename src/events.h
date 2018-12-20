// events.h

#ifndef EVENTS_H
#define EVENTS_H

#include <map>

#include <irrlicht.h>
using namespace irr;
namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;

class EventReceiver : public irr::IEventReceiver
{

  std::map<EKEY_CODE,bool> keyDowns;
  bool keyboard(const irr::SEvent &event);
  bool mouse(const irr::SEvent &event);

public:
  EventReceiver();
  bool OnEvent(const irr::SEvent &event);
  bool GetKeyDown(EKEY_CODE key);
  void ClearKeyDowns();

};

#endif
