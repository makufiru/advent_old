#pragma once

#include <iostream>
#include <stdio.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>


class Texture
{
public:
	Texture();
	~Texture();

	bool LoadFromFile(SDL_Renderer* gRenderer, const std::string path);
	void Free();
	int GetWidth();
	int GetHeight();
	SDL_Texture* GetTexture();

private:

	SDL_Texture* texture;
	int width;
	int height;
};