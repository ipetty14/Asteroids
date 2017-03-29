//
//  ship.cpp
//  Asteroids1
//
//  Created by Ian Petty on 6/27/16.
//  Copyright © 2016 Ian Petty. All rights reserved.
//

#include "ship.h"

void Ship::advance()
{
    Flying::advance();
}

void Ship::draw()
{
    drawShip(_point, _angle - 90, _thrust);
}

void Ship::accelerate()
{
    float dx = SHIP_SPEED * (cos(M_PI / 180.0 * _angle));
    float dy = SHIP_SPEED * (sin(M_PI / 180.0 * _angle));

    setVelocity(getVelocity().getDx() + dx, getVelocity().getDy() + dy);
    _thrust = true;
}

void Ship::reverse()
{
    float dx = SHIP_SPEED * -(cos(M_PI / 180.0 * _angle));
    float dy = SHIP_SPEED * -(sin(M_PI / 180.0 * _angle));
    
    setVelocity(getVelocity().getDx() + dx, getVelocity().getDy() + dy);
 
}

void Ship::turnLeft()
{
    setAngle(getAngle() + 6);
}

void Ship::turnRight()
{
    setAngle(getAngle() - 6);
}

void Ship::masterReset()
{
    _point = Point(0, 0);
    _velocity = Velocity(0, 0);
    _lives = 3;
    _alive = true;
}

void Ship::reset()
{
    _lives--;
    _point = Point(0, 0);
    _velocity = Velocity(0, 0);
    
    if(_lives == 0)
    {
        kill();
    }
}