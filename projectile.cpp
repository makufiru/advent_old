#include "Projectile.h"

Projectile::Projectile(SDL_Renderer *renderer, Vector2 position, Vector2 direction, double angle)
{
	projectileTexture.LoadFromFile(renderer, "resources/bulletSprite_1.png");
	SDLTexture = projectileTexture.GetTexture();

	this->position = position;
	rotation = angle;
	this->direction = direction;
	
	velocity = 0.1;
	ttl = 30;
	lifetime = 0;
	isDead = false;
	
}

Projectile::~Projectile()
{
}

void Projectile::Render(SDL_Renderer *renderer) 
{
	SDL_Rect renderQuad = { position.X, position.Y, 8, 8 };
	SDL_RenderCopyEx(renderer, SDLTexture, NULL, &renderQuad, rotation, NULL, SDL_FLIP_NONE);
}

void Projectile::Update()
{
	position.X += direction.X * velocity; 
	position.Y += direction.Y * velocity;

	lifetime++;
	if (lifetime == ttl) {
		isDead = true;
	}
}

