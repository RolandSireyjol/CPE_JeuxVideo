#include "collidable.h"

int& Collidable::AttackPoints(){
    return attack_points;
}

bool& Collidable::IsDestructible(){
    return is_destructible;
}

int& Collidable::HealthPoints(){
    return health_points;
}
