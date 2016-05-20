#include "Input.h"
#include "Engine.h"
#include <map>

std::map<InputEvent, bool> key_state_map;

void Input::ProcessInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
		{
			Engine::quit();
		}
		else if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				key_state_map[MOVE_UP] = getKeyDirection(event.type);
				break;
			case SDLK_s:
				key_state_map[MOVE_DOWN] = getKeyDirection(event.type);
				break;
			case SDLK_a:
				key_state_map[MOVE_LEFT] = getKeyDirection(event.type);
				break;
			case SDLK_d:
				key_state_map[MOVE_RIGHT] = getKeyDirection(event.type);
				break;
			default:
				break;
			}
		}
	}
}

bool Input::keyPressed(InputEvent input)
{
	return key_state_map[input];
}

bool Input::getKeyDirection(Uint32 direction)
{
	if (direction == SDL_KEYDOWN)
	{
		return true;
	}
	return false;
}