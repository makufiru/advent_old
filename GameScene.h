#pragma once

#include <iostream>
#include <stdio.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"
#include "Engine.h"

class GameScene
{

	//vars
public:
	GameScene();
	~GameScene();



private:
	//hardware texture
	SDL_Texture* mTexture;
	SDL_Window* mWindow;
	
	Texture* myTexture;

	Engine* gameEngine;
	
};