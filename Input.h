#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include "Texture.h"


enum InputEvent
{
	MOVE_UP = 1,
	MOVE_DOWN,
	MOVE_LEFT,
	MOVE_RIGHT,
	SHOOT
};

class Input
{
public:
	static void ProcessInput();
	static bool keyPressed(InputEvent input);
public: 


private: 
	static bool getKeyDirection(Uint32 direction);

private:

};