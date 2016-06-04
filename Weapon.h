#pragma once
#include <vector>
#include "Projectile.h"
#include "Texture.h"

class player;

class Weapon
{
public:
	Weapon(SDL_Renderer *renderer);
	void Render(SDL_Renderer *renderer);
	SDL_Texture* GetProjectileTexture();
	void Shoot(Vector2 position);
	//vector to contain projectiles
	std::vector<Projectile> projectiles;
	double shotInterval = 250;

private:
	Texture projectileTexture;
	SDL_Texture *SDLTexture;
	Vector2 position;
};

