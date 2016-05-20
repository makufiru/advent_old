#pragma once

#include <iostream>
#include <stdio.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>


class Texture
{
public:
	// con/de structors
	Texture();
	~Texture();

	//loads from file....duh.
	bool loadFromFile(SDL_Renderer* gRenderer, const std::string path);

	//frees texture
	void free();

	//void render(int x, int y, SDL_Rect* clip = nullptr);

	//get image dimension
	int getWidth();
	int getHeight();
	SDL_Texture* getTexture();
	



private:

	SDL_Texture* mTexture;

	int mWidth;
	int mHeight;
};