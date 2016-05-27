#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"
#include "player.h"

class projectile
{
public:
	projectile(SDL_Renderer *mRenderer, player *mPlayerSource);
	~projectile();

	SDL_Texture* getProjectileTexture();

	void render(SDL_Renderer *mRenderer);


private:
	Texture mProjectileTexture;
	SDL_Texture *mSDLTexture;
	SDL_Renderer *mRenderer;
	Texture mRenderTexture;
	int mWidth;
	int mHeight;

	//bullet coords
	int mPosX;
	int mPosY;
};