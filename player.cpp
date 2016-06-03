#include "player.h"
#include "Engine.h"


player::player(SDL_Renderer* renderer)
{
		mRenderer = renderer;
		blaster = new weapons(mRenderer);
		mPlayerTexture.loadFromFile(renderer, "resources/player_ship_retina.png");
		mWidth = mPlayerTexture.getWidth();
		mHeight = mPlayerTexture.getHeight();
		spriteAngle = 0.0;

		mPosition.x = (Engine::getScreenWidth() / 2) - (mWidth / 2);
		mPosition.y = (Engine::getScreenHeight() /2) - (mHeight / 2);
		moveSpeed = 5;

		mSDLTexture = mPlayerTexture.getTexture();
		lastShotTime = 0;
}

player::~player()
{
	
}


//handles key presses and mouse clicks 
void player::HandleInput(Input* input)
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
		printf(" \n key press passed to player object  ");
		//-----------------------------------Do shit here.
		currentTime = SDL_GetTicks();
		
		if ((currentTime - lastShotTime) > shotInterval)
		{
			//------------------------FIX THIS
			player::shoot();
			lastShotTime = SDL_GetTicks();
		}
	
		
	}



	//Calculate the angle to the mouse cursor and set the player rotation accordingly
	MousePosition mousePosition = input->GetMousePosition();
	double playerPosX = mPosition.x + mWidth / 2;
	double playerPosY = mPosition.y + mHeight / 2;


	double deltaX = mousePosition.x - playerPosX;
	double deltaY = mousePosition.y - playerPosY;
	

	mAngle = atan2(deltaY, deltaX) * 180 / M_PI;
	mAngle += 90.0; //Add 90 to rotate the texture correctly
}

void player::movePlayer(Axis axis, int moveAmount) 
{
	if (axis == X) {
		mPosition.x += moveAmount;
	}
	else {
		mPosition.y += moveAmount;
	}
	if ((mPosition.x + (mWidth*0.5))> Engine::getScreenWidth())
	{
		mPosition.x = 0 - (mWidth*0.5);
	}
	else if ((mPosition.x + (mWidth*0.5)) < 0)
	{
		mPosition.x = Engine::getScreenWidth() - (mWidth*0.5);
	}
	else if ((mPosition.y + (mHeight*0.5)) > Engine::getScreenHeight())
	{
		mPosition.y = 0 - (mHeight*0.5);
	}
	else if ((mPosition.y + (mHeight*0.5)) < 0)
	{
		mPosition.y = Engine::getScreenHeight() - (mHeight*0.5);
	}
}

int player::getMoveSpeed() 
{
	return moveSpeed;
}

Vector2 player::getPosition() const 
{
	return mPosition;
}



SDL_Texture *player::getPlayerTexture() 
{
	return mSDLTexture;
}

void player::Render(SDL_Renderer *renderer) 
{
	blaster->render(renderer);
	SDL_Rect renderQuad = { mPosition.x, mPosition.y, mWidth, mHeight };
	SDL_RenderCopyEx(renderer, mSDLTexture, NULL, &renderQuad, mAngle, NULL, SDL_FLIP_NONE);
}

void player::shoot()
{

	 blaster->shoot(mPosition);
}


