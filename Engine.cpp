#include "Engine.h"
#include "player.h"
#include "Input.h"
#include "projectile.h"

int Engine::mScreenWidth = 0;
int Engine::mScreenHeight = 0;
bool Engine::mIsRunning = true;

Engine::Engine()
{
	mRenderer = nullptr;
	mWindow = nullptr;

	// if you turn this off you can watch it do ugly antialiasing on rotation
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");
}

Engine::~Engine()
{
	SDL_DestroyWindow(mWindow);
	SDL_DestroyRenderer(mRenderer);
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


//Engine::gameLoop()  Kappa.
void Engine::gameLoop()
{
	mPlayer = new player(mRenderer);
	mCrosshair = new crosshair(mRenderer);
	mInput = new Input();
	
	float dt = 1 / 60.0f;
	float currentTime = SDL_GetTicks() / 1000.0f;


	while (mIsRunning)
	{
		processInputs();
		
		//update stuff
		float newTime = SDL_GetTicks() / 1000.0f;
		float frameTime = newTime - currentTime;
		currentTime = newTime;

		while (frameTime > 0.0f)
		{
			float deltaTime = std::min(frameTime, dt);
			frameTime -= deltaTime;
		}
			update();
	}
}

void Engine::processInputs()
{
	mInput->ProcessInput();
	mCrosshair->HandleInput(mInput);
	mPlayer->HandleInput(mInput);

}
void Engine::update()
{
	if (!mPlayer->isDead)
	{
		draw();
	}
}

void Engine::draw()
{
	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
	SDL_RenderClear(mRenderer);

	SDL_RenderCopy(mRenderer, mBackground.getTexture(), NULL, NULL);
	mPlayer->Render(mRenderer);

	mCrosshair->Render(mRenderer);

	SDL_RenderPresent(mRenderer);

}
int Engine::getScreenWidth()
{
	return mScreenWidth;
}

int Engine::getScreenHeight()
{
	return mScreenHeight;
}

void Engine::quit()
{
	mIsRunning = false;
}


void Engine::shoot()
{
	
}