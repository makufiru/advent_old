#include "Input.h"
#include "Engine.h"
#include <unordered_map>


Input::Input()
{
	SDL_ShowCursor(SDL_DISABLE);
	MousePosition mousePosition;
	std::unordered_map<InputEvent, bool> keyStateMap;
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
			Engine::quit();
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
	}
	// I moved this outside of event polling, otherwise it's too jerky.
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