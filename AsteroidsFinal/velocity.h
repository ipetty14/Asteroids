//
//  velocity.h
//  OpenGLTest
//
//  Created by Ian Petty on 5/25/16.
//  Copyright © 2016 Ian Petty. All rights reserved.
//

#ifndef velocity_h
#define velocity_h

#include <stdio.h>
#include "point.h"

class Velocity
{
private:
    Point point;
    
    float _dx;
    float _dy;
    
public:
    Velocity() : _dx(0), _dy(0) {}
    Velocity(float dx, float dy);
    
    float getDx() const { return _dx; }
    float getDy() const { return _dy; }
    
    void setDx(float dx)
    {
        _dx = dx;
    }
    
    void setDy(float dy)
    {
        _dy = dy;
    }
};

#endif /* velocity_h */
