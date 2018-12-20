// events.cpp

#include <irrlicht.h>
#include <quaternion.h>
#include <iostream>
#include <cmath>

#include "events.h"

using namespace irr;

namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;

/**************************************************************************\
 * EventReceiver::EventReceiver                                           *
\**************************************************************************/
EventReceiver::EventReceiver()
{
}

/*------------------------------------------------------------------------*\
 * EventReceiver::keyboard                                                *
\*------------------------------------------------------------------------*/
bool EventReceiver::keyboard(const SEvent &event)
{
  if (event.KeyInput.PressedDown)
  {
    EKEY_CODE key_pressed = event.KeyInput.Key;
    keyDowns[key_pressed] = true;
  }

  return false;
}

/*------------------------------------------------------------------------*\
 * EventReceiver::mouse                                                   *
\*------------------------------------------------------------------------*/
bool EventReceiver::mouse(const SEvent &event)
{
  /*switch(event.MouseInput.Event)
  {
    case EMIE_LMOUSE_PRESSED_DOWN:
      button_pressed = true;
      old_x = event.MouseInput.X;
      old_y = event.MouseInput.Y;
      sceneManager->manageTriggerInput();
      break;
    case EMIE_LMOUSE_LEFT_UP:
      button_pressed = false;
      break;
    case EMIE_MOUSE_MOVED:
      if (button_pressed)
      {
        //rotation.Y -= (event.MouseInput.X - old_x);
        old_x = event.MouseInput.X;
        old_y = event.MouseInput.Y;
      }
      break;
    case EMIE_MOUSE_WHEEL:
    default:
      ;
  }*/

  return false;
}

/**************************************************************************\
 * EventReceiver::OnEvent                                                 *
\**************************************************************************/
bool EventReceiver::OnEvent(const SEvent &event)
{

  switch (event.EventType)
  {
    case EET_KEY_INPUT_EVENT:
      return keyboard(event);
    case EET_MOUSE_INPUT_EVENT:
      return mouse(event);
    default:;
  }

  return false;
}

bool EventReceiver::GetKeyDown(EKEY_CODE key){
    auto it = keyDowns.find(key);
    if(it==keyDowns.end())
	return false;
    return it->second;
}

void EventReceiver::ClearKeyDowns(){
    for(auto it = keyDowns.begin(); it!=keyDowns.end();++it){
	it->second = false;
    }
}
