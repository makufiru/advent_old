#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"



class player 
{
public:
	player(SDL_Renderer *mRenderer);
	~player();

	SDL_Texture* getPlayerTexture();

	void render(SDL_Renderer *mRenderer);

	void mMovePos(double mPlayerXVel, double mPlayerYVel);
	
	void setVelocity(double mPlayerXVel, double mPlayerYVel);

public:

	bool isDead = false;


private:
	double mGetPosX();
	double mGetPosY();
	int mGetPlayerRot();

	int mSetPlayerRot();
private:
	double mPlayerHealth;
	Texture mPlayerTexture;
	SDL_Texture *mSDLTexture;
	SDL_Renderer *mRenderer;
	SDL_Rect mSpriteClips[1];
	Texture mRenderTexture;
	int mWidth;
	int mHeight;

	//player coords
	double mPosX;
	double mPosY;

	double xVel;
	double yVel;
	double mPlayerXVel;
	double mPlayerYVel;


	
};