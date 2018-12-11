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
  : node(nullptr), button_pressed(false), current_texture(0)
{
}

/*------------------------------------------------------------------------*\
 * EventReceiver::keyboard                                                *
\*------------------------------------------------------------------------*/
bool EventReceiver::keyboard(const SEvent &event)
{
  if (event.KeyInput.PressedDown)
  {
    ic::vector3df rotation = player->getRotation()* M_PI / 180.0;
    ic::quaternion rotQuat(rotation);
    //ic::vector3df speedOrientation = (cos(rotation.Y),0,0);
    switch (event.KeyInput.Key)
    {
      case KEY_ESCAPE:
        exit(0);
      case KEY_KEY_Z: // Avance
        player->speed += rotQuat* ic::vector3df (0,0,1);
        break;
      case KEY_KEY_S: // Recule
        player->speed -= rotQuat* ic::vector3df (0,0,1);
        break;
    case KEY_KEY_D: // Tourne à droite
      player->speed += rotQuat* ic::vector3df (1,0,0);
      break;
    case KEY_KEY_Q: // Tourne à gauche
      player->speed -= rotQuat* ic::vector3df (1,0,0);
      break;
    case KEY_KEY_A: // Tourne à droite
      player->speed += rotQuat* ic::vector3df (0,1,0);
      break;
    case KEY_KEY_W: // Tourne à gauche
      player->speed -= rotQuat* ic::vector3df (0,1,0);
      break;
    case KEY_KEY_X: // slows down
      player->speed *= 0.8;
      break;
      default:;
    }
    if (player->speed.X >  100) {player->speed.X =100;}
    if (player->speed.Y >  100) {player->speed.Y =100;}
    if (player->speed.Z >  100) {player->speed.Z =100;}
    if (player->speed.X <- 100) {player->speed.X =-100;}
    if (player->speed.Y <- 100) {player->speed.Y =-100;}
    if (player->speed.Z <- 100) {player->speed.Z =-100;}

    if ((player->speed.X < 0.5) &&(player->speed.X >- 0.5)) {player->speed.X =0;}
    if ((player->speed.Y < 0.5) &&(player->speed.Y >- 0.5)) {player->speed.Y =0;}
    if ((player->speed.Z < 0.5) &&(player->speed.Z >- 0.5)) {player->speed.Z =0;}
  }
  std::cout<<"player->speed :"<<std::endl;
  std::cout<<player->speed.X<<std::endl;
  std::cout<<player->speed.Y<<std::endl;
  std::cout<<player->speed.Z<<std::endl;
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
        ic::vector3df rotation = node->getRotation();
        rotation.Y -= (event.MouseInput.X - old_x);        
        old_x = event.MouseInput.X;
        old_y = event.MouseInput.Y;
        node->setRotation(rotation);
      }
      break;
    case EMIE_MOUSE_WHEEL:
      current_texture = (current_texture + 1) % textures.size();
      node->setMaterialTexture(0, textures[current_texture]);
      break;
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
  if (!node) return false;
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

/**************************************************************************\
 * EventReceiver::set_node                                                *
\**************************************************************************/
void EventReceiver::set_node(irr::scene::ISceneNode *n)
{
  node = n;
}
void EventReceiver::set_player(Player *player)
{
  this->player=player;
}
