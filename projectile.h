#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "utils.h"
#include "Texture.h"

class Projectile
{
public:
	Projectile(Vector2 position);
	~Projectile();

	//SDL_Texture* getProjectileTexture();
	//void render(SDL_Renderer *renderer);
	
private:
	
	SDL_Renderer *renderer;
	Texture renderTexture;
	int width;
	int height;

	//bullet coords
	Vector2 pos;
	Vector2 vel;
};


