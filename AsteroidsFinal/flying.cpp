//
//  flying.cpp
//  skeetShooter1
//
//  Created by Ian Petty on 6/11/16.
//  Copyright © 2016 Ian Petty. All rights reserved.
//

#include "flying.h"

Flying::Flying()
{
    _point = Point();
    _velocity = Velocity();
    _alive = true;
}

void Flying::advance()
{
    _point.addX(_velocity.getDx());
    _point.addY(_velocity.getDy());
    
    if(_point.getX() > 200)
        _point.setX(-200);
    if(_point.getY() > 200)
        _point.setY(-200);
    if(_point.getX() < -200)
        _point.setX(200);
    if(_point.getY() < -200)
        _point.setY(200);
}

void Flying::kill()
{
    _alive = false;
}