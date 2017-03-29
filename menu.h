//
//  menu.h
//  AsteroidsFinal
//
//  Created by Ian Petty on 7/14/16.
//  Copyright © 2016 Ian Petty. All rights reserved.
//

#ifndef menu_h
#define menu_h

#include <stdio.h>

#include "uiDraw.h"

class Menu
{
private:
    bool _relevant;
    int _type;
    
public:
    Menu() : _relevant(true), _type(1) {}
    
    bool isRelevant() { return _relevant; }
    void setRelevant(bool relevant) { _relevant = relevant; }
    
    int getType() { return _type; }
    void setType(int type) { _type = type; }
    
    void draw();
};

#endif /* menu_h */
