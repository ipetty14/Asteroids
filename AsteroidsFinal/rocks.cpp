//
//  rocks.cpp
//  Asteroids1
//
//  Created by Ian Petty on 6/27/16.
//  Copyright © 2016 Ian Petty. All rights reserved.
//

#include "rocks.h"

void Rock::advance()
{
    Flying::advance();
    _angle += _rotationSpeed;
    
    if(_angle >= 360)
        _angle -= 360;
    
}

void BigRock::draw()
{
    drawLargeAsteroid(_point, _angle);
}

void BigRock::breakApart(list <Rock*> &_rocks)
{
    _velocity.setDy(_velocity.getDy() + 1);
    _rocks.push_back(new MediumRock(_point, _velocity));
    
    _velocity.setDy(_velocity.getDy() - 2);
    _rocks.push_back(new MediumRock(_point, _velocity));
    
    _velocity.setDy(_velocity.getDy() + 1);
    _velocity.setDx(_velocity.getDx() + 2);
    _rocks.push_back(new SmallRock(_point, _velocity));
}

void MediumRock::draw()
{
    drawMediumAsteroid(_point, _angle);
}

void MediumRock::breakApart(list <Rock*> &_rocks)
{
    _velocity.setDx(_velocity.getDx() + 3);
    _rocks.push_back(new SmallRock(_point, _velocity));
    
    _velocity.setDx(_velocity.getDx() - 6);
    _rocks.push_back(new SmallRock(_point, _velocity));
}

void SmallRock::draw()
{
    drawSmallAsteroid(_point, _angle);
}

void SmallRock::breakApart(list <Rock*> &_rocks)
{
    
}