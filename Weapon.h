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
	void Shoot(Vector2 position, Vector2 direction, double angle);
	void Update();
	//vector to contain projectiles
	std::vector<Projectile> projectiles;
	double shotInterval = 250;

private:
	SDL_Renderer *renderer;
};