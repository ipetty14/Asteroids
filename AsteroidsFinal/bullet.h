//
//  bullet.h
//  skeetShooter1
//
//  Created by Ian Petty on 6/11/16.
//  Copyright © 2016 Ian Petty. All rights reserved.
//

#ifndef bullet_h
#define bullet_h

#include <stdio.h>
#include <cmath>
#include "flying.h"
#include "point.h"
#include "uiDraw.h"
#include "ship.h"

#define BULLET_SPEED 5.0
#define BULLET_LIFE 40

class Bullet : public Flying
{
private:
    int _bulletLife;
    
public:
    Bullet() : _bulletLife(BULLET_LIFE), Flying() { _alive = true; }

    void bulletLife();
    void draw(); 
    void fire(Point point, float angle, Velocity shipVel);
};

#endif /* bullet_h */
