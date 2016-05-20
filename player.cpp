#include "player.h"
#include "Engine.h"
 


player::player(SDL_Renderer* mRenderer)
{
		
		mPlayerTexture.loadFromFile(mRenderer, "resources/playerSprite_2.png");
		mWidth = mPlayerTexture.getWidth();
		mHeight = mPlayerTexture.getHeight();
		mPosX = (Engine::getScreenWidth() / 2) - (mWidth/2);
		mPosY = (Engine::getScreenHeight() / 2) - (mHeight/2);

		mSDLTexture = mPlayerTexture.getTexture();

}

player::~player()
{
	
}


void player::mMovePos(double mPlayerXVel, double mPlayerYVel)
{
	mPosX += mPlayerXVel;
	mPosY += mPlayerYVel;

	if ((mPosX + (mWidth*0.5 ))> Engine::getScreenWidth())
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

double player::mGetPosX(){
	return mPosX;
}

double player::mGetPosY() {
	return mPosY;	
}

SDL_Texture *player::getPlayerTexture()
{

	return mSDLTexture;
}


void player::render(SDL_Renderer *mRenderer)
{

	SDL_Rect renderQuad = { mPosX, mPosY, mWidth, mHeight };
	
	
		
	SDL_RenderCopy(mRenderer, mSDLTexture, NULL, &renderQuad );
}

void player::setVelocity(double xVel, double yVel)
{
	if (xVel > 20)
	{
		xVel = 20;
	}
	else if (xVel < -20)
	{
		xVel = -20;
	}
	if (yVel > 20)
	{
		yVel = 20;
	}
	mMovePos(xVel, yVel);
}