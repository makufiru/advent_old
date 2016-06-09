#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "vector2.h"
#include "Texture.h"

class Projectile
{
public:
	Projectile(SDL_Renderer *renderer, Vector2 position, Vector2 direction, double angle);
	~Projectile();

	void Update();
	void Render(SDL_Renderer *renderer);


	bool isDead;
	//SDL_Texture* getProjectileTexture();
	//void render(SDL_Renderer *renderer);
	
private:

	double rotation;
	Vector2 position;
	Vector2 direction;
	float velocity;
	int width;
	int height;
	int ttl;
	int lifetime;

	//bullet coords
};


