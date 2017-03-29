###############################################################
# Program:
#     Milestone 12, Asteroids
#     Brother Falin, CS165
# Author:
#     Ian Petty
# Summary:
#     Put your summary code here...
# Above and Beyond
#     When you submit your final project (not for milestones),
#     list anything here that you did to go above and beyond
#     the base requirements for your project.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o velocity.o flying.o ship.o bullet.o rocks.o menu.o
	g++ driver.o game.o uiInteract.o uiDraw.o point.o velocity.o flying.o ship.o bullet.o rocks.o menu.o $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o       Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o   Handles input events
#    point.o        The position on the screen
#    game.o         Handles the game interaction
#    velocity.o     Velocity (speed and direction)
#    flyingObject.o Base class for all flying objects
#    ship.o         The player's ship
#    bullet.o       The bullets fired from the ship
#    rocks.o        Contains all of the Rock classes
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

driver.o: driver.cpp game.h
	g++ -c driver.cpp

game.o: game.cpp game.h uiDraw.h uiInteract.h point.h velocity.h flying.h bullet.h rocks.h ship.h menu.h
	g++ -c game.cpp

velocity.o: velocity.cpp velocity.h point.h
	g++ -c velocity.cpp

flying.o: flying.cpp flying.h point.h velocity.h uiDraw.h
	g++ -c flying.cpp

ship.o: ship.cpp ship.h flying.h point.h velocity.h uiDraw.h
	g++ -c ship.cpp

bullet.o: bullet.cpp bullet.h flying.h point.h velocity.h uiDraw.h
	g++ -c bullet.cpp

rocks.o: rocks.cpp rocks.h flying.h point.h velocity.h uiDraw.h
	g++ -c rocks.cpp

menu.o : menu.cpp menu.h uiDraw.h
    g++ -c menu.cpp
###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
