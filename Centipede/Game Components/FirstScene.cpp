// FirstScene
// Andre Berthiaume, Ma crch 2013

#include "FirstScene.h"

#include "KeyEventTest.h"
#include "PlayerOneScene.h"


void FirstScene::Initialize()
{
	printf("\n------------------------------------------------------\nWelcome to Centipede: The Debugging Experience \nThis Console is here for the convenience of the programmer\n------------------------------------------------------");

	SceneManager::ChangeScene( new PlayerOneScene);

}

