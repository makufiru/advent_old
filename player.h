#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"
#include "player.h"
#include "SDL.h"
#include "Input.h"

enum Axis {
	X,
	Y
};

class player
{
public:
	player(SDL_Renderer *mRenderer);
	~player();

	SDL_Texture* getPlayerTexture();

	void render(SDL_Renderer *mRenderer);
	void handleInput();

public:
	bool isDead = false;

private:
	int mGetPosX();
	int mGetPosY();
	int getMoveSpeed();
	void movePlayer(Axis axis, int moveAmount);

private:
	double mPlayerHealth;
	Texture mPlayerTexture;
	SDL_Texture *mSDLTexture;
	SDL_Renderer *mRenderer;
	SDL_Rect mSpriteClips[1];
	Texture mRenderTexture;
	int mWidth;
	int mHeight;
	int moveSpeed;

	//player coords
	int mPosX;
	int mPosY;
};