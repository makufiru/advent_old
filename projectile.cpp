#include "projectile.h"

projectile::projectile(SDL_Renderer *mRenderer, player *mPlayerSource)
{
	mPosX = mPlayerSource->getPosX();
	mPosY = mPlayerSource->getPosY();
	mProjectileTexture.loadFromFile(mRenderer, "resources/bulletSprite_1.png");
	mSDLTexture = mProjectileTexture.getTexture();
}

projectile::~projectile()
{

}

SDL_Texture *projectile::getProjectileTexture()
{
	return mSDLTexture;
}

void projectile::render(SDL_Renderer *mRenderer)
{
	SDL_Rect renderQuad = { mPosX, mPosY, mWidth, mHeight };
	SDL_RenderCopy(mRenderer, mSDLTexture, NULL, &renderQuad);
}
