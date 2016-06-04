#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Input.h"
#include "Texture.h"
#include "Utils.h"
#include "Weapon.h"

enum Axis {
	X,
	Y
};



class Player
{
public:
	Player(SDL_Renderer *renderer);
	~Player();

	void Shoot();
	SDL_Texture* GetPlayerTexture();
	void Render(SDL_Renderer *mRenderer);
	void HandleInput(Input *input);
	Vector2 GetPosition() const;
	bool IsDead = false;
	double SpriteAngle;

private:
	Uint32 lastShotTime;
	Uint32 currentTime;
	double shotInterval = 250;
	int getMoveSpeed();
	void movePlayer(Axis axis, int moveAmount);
	double playerHealth;
	Texture playerTexture;
	SDL_Texture *SDLTexture;
	SDL_Rect SpriteClips[1];
	Texture RenderTexture;
	SDL_Renderer *renderer;
	//vector2 to hold position. 
	Vector2 position;
	int width;
	int height;
	int moveSpeed;
	Weapon *blaster;
	void shoot();
	//Player rotation in degrees
	double angle;
};