#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include <unordered_map>
#include "Texture.h"

struct MousePosition
{
	int x;
	int y;
};

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
	Input();
	~Input();
	void ProcessInput();
	bool KeyPressed(InputEvent input);
	MousePosition GetMousePosition();
public: 


private: 

private:
	MousePosition mousePosition;
	std::unordered_map<InputEvent, bool> keyStateMap;
};