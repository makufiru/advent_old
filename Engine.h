#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include <algorithm>
#include "Texture.h"
#include "player.h"
#include "crosshair.h"

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
	void shoot();
	bool init();

public: 
	
	double xVelocity;
	double yVelocity;

	std::string path;
	
private:
	void processInputs();
	void update();
	void gameLoop();
	void draw();
	Input* mInput;
	crosshair* mCrosshair;
	player* mPlayer;
	;
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	Texture mBackground;
	static bool mIsRunning;
	static int mScreenWidth;
	static int mScreenHeight;


};
