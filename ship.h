//
//  ship.h
//  Asteroids1
//
//  Created by Ian Petty on 6/27/16.
//  Copyright © 2016 Ian Petty. All rights reserved.
//

#ifndef ship_h
#define ship_h

#include "flying.h"
#include "uiDraw.h"

#define SHIP_SPEED 0.5

class Ship : public Flying
{
private:
    int _angle;
    int _lives;
    
public:
    Ship() : _angle(0), _lives(3) { _alive = true; }
    
    Ship(Point &startPoint, Velocity &startVelocity)
    {
        _point = startPoint;
        _velocity = startVelocity;
        
    }
    
    bool _thrust;
    
    int getAngle() { return _angle; }
    void setAngle(int angle) { _angle = angle % 360; }
    int getLives() { return _lives; }
    void accelerate();
    void reverse();
    void turnLeft();
    void turnRight();
    void advance();
    void draw();
    
    void masterReset();
    void reset();
};

#endif /* ship_h */
