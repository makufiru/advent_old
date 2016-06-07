#include "Weapon.h"


Weapon::Weapon(SDL_Renderer *renderer)
{
	this->renderer = renderer;
};

void Weapon::Shoot(Vector2 position, Vector2 direction, double angle)
{
	projectiles.emplace_back(renderer, position, direction, angle);

}

void Weapon::Render(SDL_Renderer *renderer)
{
	for (int i = 0; i < projectiles.size(); i++)
	{
		projectiles[i].Render(renderer);
	}
}

void Weapon::Update()
{
	for (int i = 0; i < projectiles.size(); i++) {
		projectiles[i].Update();
		if (projectiles[i].isDead) {
			projectiles.erase(projectiles.begin() + i);
		}
	}
}