#include "InputManager.h"
#include "AI.h"
#include "PlayerOneScene.h"
#include "CentipedeManager.h"
#include "Keyboard.h"
#include "WaveManager.h"
#include "ScoreManager.h"
#include "InputManager.h"
AI::AI()
{
	inputManager = InputManager::GetInstance();
	action =1;
	SetAlarm(1, 1.0f);
}

void AI::Update()
{
	if (action >13)
		action = 0;
	switch (action)
	{
		case 1:
			inputManager->moveLeft();
			inputManager->moveDown();
		break;
		case 2:
			inputManager->moveLeft();
			inputManager->moveUp();
		break;
		case 3:
			inputManager->moveLeft();
			inputManager->moveDown();
		break;
		case 4:
			inputManager->moveLeft();
			inputManager->moveUp();
		break;
		case 5:
			inputManager->moveLeft();
			inputManager->moveDown();
		break;
		case 6:
			inputManager->moveLeft();
			inputManager->moveUp();
		break;
		case 7:
			inputManager->moveRight();
			inputManager->moveDown();
		break;
		case 8:
			inputManager->moveRight();
			inputManager->moveUp();
		break;
		case 9:
			inputManager->moveRight();
			inputManager->moveDown();
		break;
		case 10:
			inputManager->moveRight();
			inputManager->moveUp();
		break;
		case 11:
			inputManager->moveRight();
			inputManager->moveDown();
		break;
		case 12:
			inputManager->moveRight();
			inputManager->moveUp();
		case 13:
			//do nothing
		break;
	}
	
	//Changed from KeyDown, because needs to refire while held.  Is there an event for key being held? need to ask
	inputManager->fire();
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Num1)) 
	{
		//SceneManager::ProcessOneFrame();
		CentipedeManager::GetInstance()->clearCentipede();
		MarkForDestroy();
		WaveManager::GetInstance()->m->newField();
		ScoreManager::GetInstance()->Play();
		InputManager::GetInstance()->setBlaster();
		WaveManager::GetInstance()->makeKeyboard();
	
	}
}

void AI::Alarm1()
{
	action++;
	SetAlarm(1, 0.5f);

}



void AI::Destroy()
{
	DeregisterInput();
	
}