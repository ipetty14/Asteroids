//
//  rocks.h
//  Asteroids1
//
//  Created by Ian Petty on 6/27/16.
//  Copyright © 2016 Ian Petty. All rights reserved.
//

#ifndef rocks_h
#define rocks_h

#include <list>

#include "flying.h"
#include "uiDraw.h"

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

using namespace std;

// Define the following classes here:
//   Rock
class Rock : public Flying
{
protected:
    int _radius;
    int _rotationSpeed;
    
public:
    
    int getRadius() { return _radius; }
    virtual void advance();
    virtual void draw() = 0;
    virtual void breakApart(list <Rock*> &_rocks) = 0;
    
    
};

//   BigRock
class BigRock : public Rock
{
private:
    
public:
    BigRock(Point &startPoint, Velocity &startVelocity)
    {
        _radius = BIG_ROCK_SIZE;
        _rotationSpeed = BIG_ROCK_SPIN;
        _point = startPoint;
        _velocity = startVelocity;
        
    }
    
    void draw();
    void breakApart(list <Rock*> &_rocks);
};

//   MediumRock
class MediumRock : public Rock
{
private:
    
public:
    MediumRock(Point &startPoint, Velocity &startVelocity)
    {
        _radius = MEDIUM_ROCK_SIZE;
        _rotationSpeed = MEDIUM_ROCK_SPIN;
        _point = startPoint;
        _velocity = startVelocity;
        
    }
    
    void draw();
    void breakApart(list <Rock*> &_rocks);

};


//   SmallRock
class SmallRock : public Rock
{
private:
    
public:
    SmallRock(Point &startPoint, Velocity &startVelocity)
    {
        _radius = SMALL_ROCK_SIZE;
        _rotationSpeed = SMALL_ROCK_SPIN;
        _point = startPoint;
        _velocity = startVelocity;
        
    }
    
    void draw();
    void breakApart(list <Rock*> &_rocks);

};


#endif /* rocks_h */
