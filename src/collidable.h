#pragma once

#include <irrlicht.h>
using namespace irr;
namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;



class Collidable
{
public:
    Collidable() {}

    bool& IsDestructible();
    int& AttackPoints();
    int& HealthPoints();

private:
    bool is_destructible;
    int health_points;
    int attack_points;
};
