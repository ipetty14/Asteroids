/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *
 *********************************************************************/

#include "game.h"

// These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>
using namespace std;

void Game::createStartingRock(int count)
{
    for(int i = 0; i < count; i++)
    {
        Point startPosition;
        startPosition.setX(random(_topLeft.getX(), _bottomRight.getX()));
        startPosition.setY(random(_bottomRight.getY(), _topLeft.getY()));
        
        Velocity startVelocity;
        startVelocity.setDx(random(-1.0, 1.0));
        startVelocity.setDy(random(-1.0, 1.0));
        
        Rock * rock = new BigRock(startPosition, startVelocity);
        
        _rocks.push_back(rock);
    }
}


void Game::advance()
{
    if(!_isPaused)
    {
        _ship.advance();
    
        for(list <Rock*> :: iterator it = _rocks.begin(); it != _rocks.end(); it++)
            (*it)->advance();
    
        for(vector<Bullet>::iterator it = _bullets.begin(); it != _bullets.end(); it++)
        {
            it->advance();
            it->bulletLife();
        }
        
        handleCollisions();
        cleanUpZombies();
    }
   
    if(_rocks.size() == 0)
    {
        _menu.setRelevant(true);
        _menu.setType(3);
    }
    
    
    if(!_ship.isAlive())
    {
        _menu.setRelevant(true);
        _menu.setType(4);
    }
}

void Game::handleInput(const Interface &pUI)
{    
    if(_menu.isRelevant() && _menu.getType() == 1 && pUI.isP())
    {
        _menu.setType(2);
    }
    else if(_menu.isRelevant() && _menu.getType() == 2 && pUI.isP())
    {
        unpause();
        _menu.setRelevant(false);
    }
    
    if(_menu.isRelevant() && _menu.getType() == 3 && pUI.isP())
    {
        resetGame();
        _menu.setRelevant(false);
    }
    
    if(_menu.isRelevant() && _menu.getType() == 4 && pUI.isP())
    {
        resetGame();
        _menu.setRelevant(false);
    }
    
  if(_ship.isAlive())
  {
      if(pUI.isUp())
      {
          _ship.accelerate();
      }
      else
          _ship._thrust = false;
      
      if(pUI.isDown())
      {
          _ship.reverse();
      }
      
      if(pUI.isLeft())
      {
          _ship.turnLeft();
      }
      
      if(pUI.isRight())
      {
          _ship.turnRight();
      }
      
      if(pUI.isSpace())
      {
          Bullet bullet;
          bullet.fire(_ship.getPoint(), _ship.getAngle(), _ship.getVelocity());
          _bullets.push_back(bullet);
      }
  }
    
}

void Game::draw(const Interface &pUI)
{
    Point lives;
    
    lives.setX(_topLeft.getX() + 5);
    lives.setY(_topLeft.getY() - 5);
    
    drawNumber(lives, _ship.getLives());
    
    if(_menu.isRelevant())
        _menu.draw();
    
    if(_ship.isAlive() == true)
        _ship.draw();
    
    for(list <Rock*> :: iterator it = _rocks.begin(); it != _rocks.end(); it++)
    {
        if((*it)->isAlive())
            (*it)->draw();
    }
    
    for(vector<Bullet>::iterator it = _bullets.begin(); it != _bullets.end(); it++)
        it->draw();
}

void Game::cleanUpZombies()
{
    vector<Bullet>::iterator it = _bullets.begin();
    
    while(it != _bullets.end())
    {
        Bullet bullet = *it;
        
        if(!bullet.isAlive())
        {
            it = _bullets.erase(it);
        }
        else
        {
            it++;
        }
   }
    
    for(list <Rock*>::iterator it = _rocks.begin(); it != _rocks.end(); it++)
    {
        if((*it)->isAlive() == false)
        {
            _rocks.erase(it);
            it--;
        }
    }
}

void Game::handleCollisions()
{
    for(list<Rock*>::iterator it = _rocks.begin(); it != _rocks.end(); it++)
    {
        for(int i = 0; i < _bullets.size(); i++)
        {
            if((*it)->isAlive())
            {
                if(_bullets[i].isAlive())
                {
                    if(getClosestDistance((**it), _bullets[i]) < (*it)->getRadius())
                    {
                        (*it)->kill();
                        (*it)->breakApart(_rocks);
                        _bullets[i].kill();
                    }
                        
                }
            }
        }
        
        if(_ship.isAlive() == true && getClosestDistance(_ship, (**it)) < (*it)->getRadius())
        {
            _ship.reset();
            (*it)->breakApart(_rocks);
            (*it)->kill();
        }
    }
    
}

// You may find this function helpful...

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/
 float Game :: getClosestDistance(const Flying &obj1, const Flying &obj2) const
 {
    // find the maximum distance traveled
    float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
    dMax = max(dMax, abs(obj2.getVelocity().getDx()));
    dMax = max(dMax, abs(obj2.getVelocity().getDy()));
    dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.
 
    float distMin = std::numeric_limits<float>::max();
    for (float i = 0.0; i <= dMax; i++)
    {
    Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
    obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
    Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
    obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));
 
    float xDiff = point1.getX() - point2.getX();
    float yDiff = point1.getY() - point2.getY();
 
    float distSquared = (xDiff * xDiff) +(yDiff * yDiff);
    distMin = min(distMin, distSquared);
    }
 
    return sqrt(distMin);
}

void Game::resetGame()
{
    for(list <Rock*>::iterator it = _rocks.begin(); it != _rocks.end(); it++)
    {
            _rocks.erase(it);
            it--;
    }
    
    createStartingRock(NUMBER_OF_ROCKS);
    _ship.masterReset();
}