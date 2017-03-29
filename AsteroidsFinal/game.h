/*********************************************************************
 * File: game.h
 * Description: Defines the game class for Asteroids
 *
 *********************************************************************/

#ifndef GAME_H
#define GAME_H

#include "point.h"
#include "velocity.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "flying.h"
#include "bullet.h"
#include "rocks.h"
#include "ship.h"
#include "menu.h"

#include <list>
#include <vector>

#define NUMBER_OF_ROCKS 5
#define CLOSE_ENOUGH 15
using namespace std;

class Game
{
private:
    list<Rock*> _rocks;
    vector<Bullet> _bullets;
    Point _topLeft;
    Point _bottomRight;
    Ship _ship;
    Menu _menu;
    bool _isPaused;
    bool _rocksGone;
    
public:
    Game(Point &topLeft, Point &bottomRight)
    {
        _topLeft = topLeft;
        _bottomRight = bottomRight;
        createStartingRock(NUMBER_OF_ROCKS);
        _isPaused = true;
        _rocksGone = false;
    }
    
    float getClosestDistance(const Flying & obj1, const Flying & obj2) const;
    void handleCollisions();
    void createStartingRock(int count);
    void advance();
    void handleInput(const Interface &pUI);
    void draw(const Interface &pUI);
    void cleanUpZombies();
    void killAll();
    void resetGame();
    void pause() {  _isPaused = true; }
    void unpause() { _isPaused = false; }
};



#endif /* GAME_H */


