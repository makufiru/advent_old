#pragma once


#include <vector>
#include "projectile.h"
#include "Texture.h"

class player;

class weapons
{
public:
	
	weapons(SDL_Renderer *renderer);
	
	void render(SDL_Renderer *renderer);
	SDL_Texture* getProjectileTexture();
	void shoot(Vector2 position);

	//vector to contain projectiles
	std::vector<projectile> projectiles;
	
	double shotInterval = 250;

private:

	SDL_Renderer *mRenderer;
	Texture mProjectileTexture;
	SDL_Texture *mSDLTexture;
	Vector2 mPosition;



};

