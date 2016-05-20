#include "Engine.h"
#include "player.h"

int Engine::mScreenWidth = 0;
int Engine::mScreenHeight = 0;

Engine::Engine()
{
	mRenderer = nullptr;
	mWindow = nullptr;

	mIsRunning = true;			
}

Engine::~Engine()
{
	SDL_DestroyWindow(mWindow);
	SDL_DestroyRenderer(mRenderer);
	mPlayer = nullptr;
	SDL_Quit();
}

void Engine::Run(int w, int h)
{
	mScreenWidth = w;
	mScreenHeight = h;

	if (init() == false)
	{
		printf("Failed to init the Engine. SDL Error:  %s\n", SDL_GetError());

	}
	else
	{
		gameLoop();

	}

}

bool Engine::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("SDL failed to init SDL. SDL Error: %s\n", SDL_GetError());
		return false;
	}

	mWindow = SDL_CreateWindow("Advent", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, mScreenWidth, mScreenHeight, SDL_WINDOW_SHOWN);

	if (mWindow == nullptr)
	{
		printf("SDL Failed to create a window. SDL Error:  %s\n", SDL_GetError());
		return false;
	}

	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (mRenderer == nullptr)
	{
		printf("SDL failed to create a renderer. SDL Error:  %s\n", SDL_GetError());
		return false;
	}


	mBackground.loadFromFile(mRenderer, "resources/space_bg.png");

	return true;
	
}


void Engine::gameLoop()
{
	mPlayer = new player(mRenderer);
	while (mIsRunning)
	{
		
		processInput();
		
		if (!mPlayer->isDead )
		{
			mPlayer->setVelocity(xVelocity, yVelocity);
			draw();
		}
	}
}

void Engine::processInput()
{
	
	//printf("im getting ready to process your inputs");

	// keystate pointer points to an array of key states (1 down or 0 up)
	const Uint8* keyState = SDL_GetKeyboardState(nullptr);
	bool keydown = false;
	
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt))
	{
		switch (evnt.type)
		{
			case SDL_QUIT:
			{
				mIsRunning = false;
				break;
			}
			case SDL_KEYDOWN:
			{
				switch (evnt.key.keysym.sym)
				{
				case SDLK_w:
					yVelocity += -5;
					break;
				case SDLK_s:
					yVelocity += 5;
					break;
				case SDLK_a:
					xVelocity += -5;
					break;
				case SDLK_d:
					xVelocity += 5;
					break;
				case SDLK_ESCAPE:
					mIsRunning = false;
					break;

				}
				break;
			}
		
		/*
			case SDL_KEYUP:
			{
				switch (evnt.key.keysym.sym)
				{
					case SDLK_w:
						if (yVelocity < 0)
						{
							yVelocity = 0.0;
						}
						break;
					case SDLK_s:
						if (yVelocity > 0)
						{
							yVelocity = 0.0;
						}
						break;
					case SDLK_a:
						if (xVelocity < 0)
						{
							xVelocity = 0.0;
						}
						break;
					case SDLK_d:
						if (xVelocity > 0)
						{
						xVelocity = 0.0 ;
						}
						break;	
				}
				break;
			}
			*/





		

			
			

		}

		
	}

	



}

void Engine::draw()
{
	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
	SDL_RenderClear(mRenderer);

	SDL_RenderCopy(mRenderer, mBackground.getTexture(), NULL, NULL);
	mPlayer->render(mRenderer);

	SDL_RenderPresent(mRenderer);

}
int Engine::getScreenWidth()
{
	return  mScreenWidth;
}

int Engine::getScreenHeight()
{
	return mScreenHeight;
}
