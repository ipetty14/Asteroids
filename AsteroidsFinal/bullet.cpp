//
//  bullet.cpp
//  skeetShooter1
//
//  Created by Ian Petty on 6/11/16.
//  Copyright © 2016 Ian Petty. All rights reserved.
//

#include "bullet.h"

void Bullet::fire(Point point, float angle, Velocity shipVel)
{
    setPoint(point);
    
    float dx = BULLET_SPEED * (cos(M_PI / 180.0 * angle));
    float dy = BULLET_SPEED * (sin(M_PI / 180.0 * angle));
    
    setVelocity(shipVel.getDx() + dx, shipVel.getDy() + dy);
}

void Bullet::bulletLife()
{
    _bulletLife--;
    
    if(_bulletLife < 0)
        kill();
}

void Bullet::draw()
{
    if(isAlive())
        drawDot(getPoint());
    
}