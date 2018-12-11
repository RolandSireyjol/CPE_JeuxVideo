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
    :sceneManager(nullptr)
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
        sceneManager->manageInput(key_pressed);
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
      button_pressed = true;
      old_x = event.MouseInput.X;
      old_y = event.MouseInput.Y;
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
  }

  return false;
}

/**************************************************************************\
 * EventReceiver::OnEvent                                                 *
\**************************************************************************/
bool EventReceiver::OnEvent(const SEvent &event)
{
  if (!sceneManager) return false;
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

void EventReceiver::setSceneManager(SceneManager *manager){
    sceneManager=manager;
}
