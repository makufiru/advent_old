#include "Input.h"
#include "Engine.h"
#include <unordered_map>

Input::Input()
{
	SDL_ShowCursor(SDL_DISABLE);
}

Input::~Input()
{

}

void Input::ProcessInput()
{	
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
		{
			Engine::Quit();
		}
		else if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_w:
				keyStateMap[MOVE_UP] = e.type == SDL_KEYDOWN ? true : false;
				break;
			case SDLK_s:
				keyStateMap[MOVE_DOWN] = e.type == SDL_KEYDOWN ? true : false;
				break;
			case SDLK_a:
				keyStateMap[MOVE_LEFT] = e.type == SDL_KEYDOWN ? true : false;
				break;
			case SDLK_d:
				keyStateMap[MOVE_RIGHT] = e.type == SDL_KEYDOWN ? true : false;
				break;
			default:
				break;
			}
		}
		else if (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
		{
			if (SDL_BUTTON(SDL_BUTTON_LEFT))
			{
				keyStateMap[SHOOT] = e.type == SDL_MOUSEBUTTONDOWN ? true : false;
				printf("captured mouse click");
			}
		}
	}
	SDL_GetMouseState(&mousePosition.x, &mousePosition.y);
	
}

bool Input::KeyPressed(InputEvent input)
{
	return keyStateMap[input];
}

MousePosition Input::GetMousePosition()
{
	return mousePosition;
}