#include "Weapon.h"


Weapon::Weapon(SDL_Renderer *renderer)
{
	projectileTexture.LoadFromFile(renderer, "resources/bulletSprite_1.png");
	SDLTexture = projectileTexture.GetTexture();

};

void Weapon::Shoot(Vector2 position)
{
	projectiles.emplace_back(position);
	printf("shot stuff. pew pew.");
}


SDL_Texture *Weapon::GetProjectileTexture()
{
	return SDLTexture;
}

void Weapon::Render(SDL_Renderer *renderer)
{
	for (int i = 0; i < projectiles.size(); i++)
	{
		SDL_Rect renderQuad = { position.x, position.y, 32, 32 };
		SDL_RenderCopyEx(renderer, SDLTexture, NULL, &renderQuad, NULL, NULL, SDL_FLIP_NONE);
	}
}
