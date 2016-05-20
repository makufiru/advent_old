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
	static void quit();

	void Run(int w, int h);
	
	bool init();

public:
	
	double xVelocity;
	double yVelocity;

	std::string path;

private:

	void update();
	void gameLoop();
	void draw();
	player* mPlayer;
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	Texture mBackground;
	static bool mIsRunning;
	static int mScreenWidth;
	static int mScreenHeight;


};
