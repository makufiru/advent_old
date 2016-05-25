#include "crosshair.h"
#include "Engine.h"

crosshair::crosshair(SDL_Renderer* mRenderer)
{
	MousePosition cursorPosition;
	cursorPosition.x = 0;
	cursorPosition.y = 0;

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
	cursorPosition.x = mousePos.x - (mWidth * 0.5);
	cursorPosition.y = mousePos.y - (mWidth * 0.5);
	//delete &mousePos;
}

SDL_Texture *crosshair::getCrosshairTexture() {
	return mSDLTexture;
}

void crosshair::Render(SDL_Renderer *mRenderer) {
	SDL_Rect renderQuad = { cursorPosition.x, cursorPosition.y, mWidth, mHeight };
	SDL_RenderCopy(mRenderer, mSDLTexture, NULL, &renderQuad );
}
