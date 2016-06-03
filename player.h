#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "utilities.h"
#include "Texture.h"
#include "Input.h"
#include "weapons.h"
//#include "projectile.h"

enum Axis {
	X,
	Y
};



class player
{
public:
	player(SDL_Renderer *renderer);
	~player();

	void shoot();
	SDL_Texture* getPlayerTexture();

	void Render(SDL_Renderer *mRenderer);
	void HandleInput(Input *input);
	Vector2 getPosition() const;

public:
	bool isDead = false;
	double spriteAngle;
	Uint32 lastShotTime;
	Uint32 currentTime;
	double shotInterval = 250;

private:
	int getMoveSpeed();
	void movePlayer(Axis axis, int moveAmount);
	
private:
	double mPlayerHealth;
	Texture mPlayerTexture;
	SDL_Texture *mSDLTexture;
	SDL_Rect mSpriteClips[1];
	Texture mRenderTexture;
	SDL_Renderer *mRenderer;
	//vector2 to hold position. 
	Vector2 mPosition;
	int mWidth;
	int mHeight;
	int moveSpeed;
	weapons *blaster;

	//Player rotation in degrees
	double mAngle;
};