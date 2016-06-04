#include "Player.h"
#include "Engine.h"

Player::Player(SDL_Renderer* renderer)
{
		this->renderer = renderer;
		blaster = new Weapon(renderer);
		playerTexture.LoadFromFile(renderer, "resources/player_ship_retina.png");
		width = playerTexture.GetWidth();
		height = playerTexture.GetHeight();
		SpriteAngle = 0.0;

		position.x = (Engine::GetScreenWidth() / 2) - (width / 2);
		position.y = (Engine::GetScreenHeight() /2) - (height / 2);
		moveSpeed = 5;

		SDLTexture = playerTexture.GetTexture();
		lastShotTime = 0;
}

Player::~Player()
{
	
}

//handles key presses and mouse clicks 
void Player::HandleInput(Input* input)
{
	if (input->KeyPressed(MOVE_UP))
	{
		movePlayer(Y, -moveSpeed);
	}
	if (input->KeyPressed(MOVE_DOWN))
	{
		movePlayer(Y, moveSpeed);
	}
	if (input->KeyPressed(MOVE_LEFT))
	{
		movePlayer(X, -moveSpeed);
	}
	if (input->KeyPressed(MOVE_RIGHT))
	{
		movePlayer(X, moveSpeed);
	}
	if (input->KeyPressed(SHOOT))
	{
		currentTime = SDL_GetTicks();
		
		if ((currentTime - lastShotTime) > shotInterval)
		{
			shoot();
			lastShotTime = SDL_GetTicks();
		}
	}
	
	//Calculate the angle to the mouse cursor and set the player rotation accordingly
	MousePosition mousePosition = input->GetMousePosition();
	double playerPosX = position.x + width / 2;
	double playerPosY = position.y + height / 2;
	double deltaX = mousePosition.x - playerPosX;
	double deltaY = mousePosition.y - playerPosY;

	angle = atan2(deltaY, deltaX) * 180 / M_PI;
	angle += 90.0; //Add 90 to rotate the texture correctly
}

void Player::movePlayer(Axis axis, int moveAmount) 
{
	if (axis == X) {
		position.x += moveAmount;
	}
	else {
		position.y += moveAmount;
	}
	if ((position.x + (width*0.5))> Engine::GetScreenWidth())
	{
		position.x = 0 - (width*0.5);
	}
	else if ((position.x + (width*0.5)) < 0)
	{
		position.x = Engine::GetScreenWidth() - (width*0.5);
	}
	else if ((position.y + (height*0.5)) > Engine::GetScreenHeight())
	{
		position.y = 0 - (height*0.5);
	}
	else if ((position.y + (height*0.5)) < 0)
	{
		position.y = Engine::GetScreenHeight() - (height*0.5);
	}
}

int Player::getMoveSpeed() 
{
	return moveSpeed;
}

Vector2 Player::GetPosition() const 
{
	return position;
}

SDL_Texture *Player::GetPlayerTexture() 
{
	return SDLTexture;
}

void Player::Render(SDL_Renderer *renderer) 
{
	blaster->Render(renderer);
	SDL_Rect renderQuad = { position.x, position.y, width, height };
	SDL_RenderCopyEx(renderer, SDLTexture, NULL, &renderQuad, angle, NULL, SDL_FLIP_NONE);
}

void Player::shoot()
{
	 blaster->Shoot(position);
}