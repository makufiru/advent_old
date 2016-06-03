#include "weapons.h"


weapons::weapons(SDL_Renderer *renderer)
{
	mRenderer = renderer;
	mProjectileTexture.loadFromFile(mRenderer, "resources/bulletSprite_1.png");
	mSDLTexture = mProjectileTexture.getTexture();

};



void weapons::shoot(Vector2 position)
{
	mPosition = position;
	projectiles.emplace_back(mPosition);
	printf("shot stuff. pew pew.");
}


SDL_Texture *weapons::getProjectileTexture()
{
	return mSDLTexture;
}

void weapons::render(SDL_Renderer *renderer)
{
	for (int i = 0; i < projectiles.size(); i++)
	{
	SDL_Rect renderQuad = { mPosition.x, mPosition.y, 32, 32 };
	SDL_RenderCopyEx(renderer, mSDLTexture, NULL, &renderQuad, NULL, NULL, SDL_FLIP_NONE);
	}
}
