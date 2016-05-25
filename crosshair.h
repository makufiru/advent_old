#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"
#include "SDL.h"
#include "Input.h"


class crosshair
{
public:
	crosshair(SDL_Renderer *mRenderer);
	~crosshair();

	SDL_Texture* getCrosshairTexture();

	void Render(SDL_Renderer *mRenderer);
	void HandleInput(Input *input);

public:

private:

private:
	Texture mCrosshairTexture;
	SDL_Texture *mSDLTexture;
	SDL_Renderer *mRenderer;
	SDL_Rect mSpriteClips[1];
	Texture mRenderTexture;
	int mWidth;
	int mHeight;

	MousePosition cursorPosition;
};