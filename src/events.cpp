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
    switch (key_pressed)
    {
      case KEY_ESCAPE:
        exit(0);
        break;
    case KEY_KEY_Z: // Avance
    case KEY_KEY_S: // Recule
    case KEY_KEY_D: // Tourne à droite
    case KEY_KEY_Q: // Tourne à gauche
    case KEY_KEY_A: // Tourne à droite
    case KEY_KEY_W: // Tourne à gauche
    case KEY_KEY_X: // slows down
      break;
      default:
        break;
    }
  }

  return false;
}

/*------------------------------------------------------------------------*\
 * EventReceiver::mouse                                                   *
\*------------------------------------------------------------------------*/
bool EventReceiver::mouse(const SEvent &event)
{
  switch(event.MouseInput.Event)
  {
    case EMIE_LMOUSE_PRESSED_DOWN:
      break;
    case EMIE_LMOUSE_LEFT_UP:
      break;
    case EMIE_MOUSE_MOVED:
      break;
    case EMIE_MOUSE_WHEEL:
    default:
      ;
  }

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
      if(camera->OnEvent(event))
	  return false;
      return keyboard(event);
    case EET_MOUSE_INPUT_EVENT:
      return mouse(event);
    default:;
  }

  return false;
}
