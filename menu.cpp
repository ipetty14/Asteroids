//
//  menu.cpp
//  AsteroidsFinal
//
//  Created by Ian Petty on 7/14/16.
//  Copyright © 2016 Ian Petty. All rights reserved.
//

#include "menu.h"

void Menu::draw()
{
    switch(_type)
    {
        case 1:
            drawRect(Point(0, 0), 200, 200, 0);
            drawText(Point(-50, 30) , "     Asteroids    ");
            drawText(Point(-60, -30), "   Press 'P' to play. ");
            break;
        case 2:
            drawRect(Point(0, 0), 200, 250, 0);
            drawText(Point(-45, 100) , "     Controls   ");
            drawText(Point(-65, 80) , "----------------");
            drawText(Point(-60, 60), "   Space bar - Fire! ");
            drawText(Point(-75, 40), "   Up arrow - Accelerate ");
            drawText(Point(-75, -30), "   Down arrow - Reverse ");
            drawText(Point(-75, -50), "   Left arrow - Rotate Left ");
            drawText(Point(-75, -70), "   Right arrow - Rotate Right");
            
            drawText(Point(-75, -100), "   Press 'P' to continue. ");
            break;
        case 3:
            drawRect(Point(0, 0), 200, 200, 0);
            drawText(Point(-50, 30) , "      You won!    ");
            drawText(Point(-70, -30), "   Press 'P' to play again. ");
            break;
        case 4:
            drawRect(Point(0, 0), 200, 200, 0);
            drawText(Point(-50, 30) , "      You lost!    ");
            drawText(Point(-70, -30), "   Press 'P' to play again. ");
            break;
    }
}