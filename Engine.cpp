#include "Engine.h"
#include "Player.h"
#include "Input.h"
#include "Projectile.h"

int Engine::screenWidth = 0;
int Engine::screenHeight = 0;
bool Engine::isRunning = true;

Engine::Engine()
{
	renderer = nullptr;
	window = nullptr;
	// if you turn this off you can watch it do ugly antialiasing on rotation
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");
}

Engine::~Engine()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Engine::Run(int w, int h)
{
	screenWidth = w;
	screenHeight = h;

	if (Init() == false)
	{
		printf("Failed to init the Engine. SDL Error:  %s\n", SDL_GetError());
	}
	else
	{
		gameLoop();
	}
}

bool Engine::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("SDL failed to init SDL. SDL Error: %s\n", SDL_GetError());
		return false;
	}

	window = SDL_CreateWindow("Advent", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);

	if (window == nullptr)
	{
		printf("SDL Failed to create a window. SDL Error:  %s\n", SDL_GetError());
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr)
	{
		printf("SDL failed to create a renderer. SDL Error:  %s\n", SDL_GetError());
		return false;
	}

	background.LoadFromFile(renderer, "resources/space_bg.png");
	return true;
	
}

//Engine::gameLoop()  Kappa.
void Engine::gameLoop()
{
	player = new Player(renderer);
	crosshair = new Crosshair(renderer);
	input = new Input();
	float dt = 1 / 60.0f;
	float currentTime = SDL_GetTicks() / 1000.0f;

	while (isRunning)
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
	input->ProcessInput();
	crosshair->HandleInput(input);
	player->HandleInput(input);

}
void Engine::update()
{
	if (!player->IsDead)
	{
		player->Update();
		draw();
	}
}

void Engine::draw()
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, background.GetTexture(), NULL, NULL);
	player->Render(renderer);
	crosshair->Render(renderer);
	SDL_RenderPresent(renderer);
}

int Engine::GetScreenWidth()
{
	return screenWidth;
}

int Engine::GetScreenHeight()
{
	return screenHeight;
}

void Engine::Quit()
{
	isRunning = false;
}