#include "Texture.h"




Texture::Texture()
{
	mTexture = nullptr;
	mWidth = 0;
	mHeight = 0;
	
}

Texture::~Texture()
{
	free();
}


bool Texture::loadFromFile(SDL_Renderer* gRenderer, const std::string path) 
{
	free();

	//final texture
	SDL_Texture* finalTexture = nullptr;

	//load the file
	finalTexture = IMG_LoadTexture(gRenderer, path.c_str());
	if (finalTexture == nullptr)
	{
		printf("failed to load image. SDL Error: %s\n", SDL_GetError());
	}
	else
	{
		int w, h;

		if (SDL_QueryTexture(finalTexture, NULL, NULL, &w, &h) != 0)
		{
			printf("failed to query texture. you're not gonna know shit about it.");
		}
		else
		{
			mWidth = w;
			mHeight = h;
		}
	}

	
	//sets our suface turned texture to our member vairable texture.
	mTexture = finalTexture;
	return mTexture != nullptr;


}


void Texture::free()
{
	if (mTexture != nullptr)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = nullptr;

		mWidth = 0;
		mHeight = 0;
	}
}


int Texture::getWidth()
{
	return mWidth;
}

int Texture::getHeight()
{
	return mHeight;
}

SDL_Texture* Texture::getTexture()
{
	return mTexture;
}

