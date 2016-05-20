#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include "Texture.h"
#include "player.h"

class Engine
{
public:
	
	//con/de structors
	Engine();
	~Engine();

	static int getScreenWidth();
	static int getScreenHeight();


	void Run(int w, int h);
	
	bool init();
	
public:
	
	double xVelocity;
	double yVelocity;

	std::string path;

private:

	void processInput();
	void gameLoop();
	void draw();
	player *mPlayer;
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	Texture mBackground;
	bool mIsRunning;
	static int mScreenWidth;
	static int mScreenHeight;
};
