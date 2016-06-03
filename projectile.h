#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "utilities.h"
#include "Texture.h"





class projectile
{
public:
	projectile(Vector2 position);
	~projectile();

	//SDL_Texture* getProjectileTexture();

	//void render(SDL_Renderer *mRenderer);
	
private:
	
	SDL_Renderer *mRenderer;
	Texture mRenderTexture;
	int mWidth;
	int mHeight;

	//bullet coords
	Vector2 mPos;
	Vector2 mVel;
};


