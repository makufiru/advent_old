#include "Crosshair.h"
#include "Engine.h"

Crosshair::Crosshair(SDL_Renderer* renderer)
{
	MousePosition cursorPosition = { 0, 0 };
	crosshairTexture.LoadFromFile(renderer, "resources/crosshair.png");
	width = crosshairTexture.GetWidth();
	height = crosshairTexture.GetHeight();
	SDLTexture = crosshairTexture.GetTexture();
}

Crosshair::~Crosshair()
{

}

void Crosshair::HandleInput(Input* input)
{
	MousePosition mousePos = input->GetMousePosition();
	cursorPosition.x = mousePos.x - (width / 2);
	cursorPosition.y = mousePos.y - (height / 2);
}

SDL_Texture *Crosshair::getCrosshairTexture()
{
	return SDLTexture;
}

void Crosshair::Render(SDL_Renderer *renderer) 
{
	SDL_Rect renderQuad = { cursorPosition.x, cursorPosition.y, width, height };
	SDL_RenderCopy(renderer, SDLTexture, NULL, &renderQuad );
}
