#include "player.h"
#include "Engine.h"

player::player(SDL_Renderer* mRenderer)
{
		mPlayerTexture.loadFromFile(mRenderer, "resources/player_ship_retina.png");
		mWidth = mPlayerTexture.getWidth();
		mHeight = mPlayerTexture.getHeight();

		mPosX = (Engine::getScreenWidth() / 2) - (mWidth / 2);
		mPosY = (Engine::getScreenHeight() /2) - (mHeight / 2);
		moveSpeed = 5;

		mSDLTexture = mPlayerTexture.getTexture();
}

player::~player()
{
	
}

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
	//Calculate the angle to the mouse cursor and set the player rotation accordingly
	MousePosition mousePosition = input->GetMousePosition();
	double playerPosX = mPosX + mWidth / 2;
	double playerPosY = mPosY + mHeight / 2;
	
	double deltaX = mousePosition.x - playerPosX;
	double deltaY = mousePosition.y - playerPosY;
	
	mAngle = atan2(deltaY, deltaX) * 180 / M_PI;
	mAngle += 90.0; //Add 90 to rotate the texture correctly
}

void player::movePlayer(Axis axis, int moveAmount) 
{
	if (axis == X) {
		mPosX += moveAmount;
	}
	else {
		mPosY += moveAmount;
	}
	if ((mPosX + (mWidth*0.5))> Engine::getScreenWidth())
	{
		mPosX = 0 - (mWidth*0.5);
	}
	else if ((mPosX + (mWidth*0.5)) < 0)
	{
		mPosX = Engine::getScreenWidth() - (mWidth*0.5);
	}
	else if ((mPosY + (mHeight*0.5)) > Engine::getScreenHeight())
	{
		mPosY = 0 - (mHeight*0.5);
	}
	else if ((mPosY + (mHeight*0.5)) < 0)
	{
		mPosY = Engine::getScreenHeight() - (mHeight*0.5);
	}
}

int player::getMoveSpeed() {
	return moveSpeed;
}
int player::mGetPosX(){
	return mPosX;
}

int player::mGetPosY() {
	return mPosY;	
}

SDL_Texture *player::getPlayerTexture() {
	return mSDLTexture;
}

void player::Render(SDL_Renderer *mRenderer) {
	SDL_Rect renderQuad = { mPosX, mPosY, mWidth, mHeight };
	SDL_RenderCopyEx(mRenderer, mSDLTexture, NULL, &renderQuad, mAngle, NULL, SDL_FLIP_NONE);
}
