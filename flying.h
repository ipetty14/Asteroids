//
//  flying.h
//  skeetShooter1
//
//  Created by Ian Petty on 6/11/16.
//  Copyright © 2016 Ian Petty. All rights reserved.
//

#ifndef flying_h
#define flying_h

#include <stdio.h>
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

class Flying
{
protected:
    Point _point;
    Velocity _velocity;
    bool _alive;
    int _angle;
    
    
public:
    Flying();
    
    Point getPoint() const { return _point; }
    Velocity getVelocity() const { return _velocity; }
    bool isAlive() { return _alive; }
    
    void setPoint(Point point) { _point = point; }
    
    void setVelocity(float dx, float dy)
    {
        _velocity.setDx(dx);
        _velocity.setDy(dy);
    }
    
    void setAlive(bool alive)
    {
        _alive = alive;
    }

    virtual void advance();
    virtual void draw() = 0;
    virtual void kill();
    
};

#endif /* flying_h */
