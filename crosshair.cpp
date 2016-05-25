#include "crosshair.h"
#include "Engine.h"

crosshair::crosshair(SDL_Renderer* mRenderer)
{
	MousePosition cursorPosition = { 0, 0 };

	mCrosshairTexture.loadFromFile(mRenderer, "resources/crosshair.png");
	mWidth = mCrosshairTexture.getWidth();
	mHeight = mCrosshairTexture.getHeight();
	mSDLTexture = mCrosshairTexture.getTexture();
}

crosshair::~crosshair()
{

}

void crosshair::HandleInput(Input* input)
{
	MousePosition mousePos = input->GetMousePosition();
	cursorPosition.x = mousePos.x - (mWidth / 2);
	cursorPosition.y = mousePos.y - (mWidth / 2);
}

SDL_Texture *crosshair::getCrosshairTexture() {
	return mSDLTexture;
}

void crosshair::Render(SDL_Renderer *mRenderer) {
	SDL_Rect renderQuad = { cursorPosition.x, cursorPosition.y, mWidth, mHeight };
	SDL_RenderCopy(mRenderer, mSDLTexture, NULL, &renderQuad );
}
