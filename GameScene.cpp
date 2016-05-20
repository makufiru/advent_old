#include "GameScene.h"




GameScene::GameScene() {
	
	
	myTexture = new Texture();

	myTexture->loadFromFile(gameEngine->renderer, gameEngine->path);
	
	



}


GameScene::~GameScene()
{
	delete myTexture;
}


