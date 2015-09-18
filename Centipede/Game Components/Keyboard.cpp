#include "InputManager.h"
#include "Keyboard.h"

Keyboard::Keyboard()
{
	inputManager = InputManager::GetInstance();
}

void Keyboard::Update()
{
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Left)) inputManager->moveLeft();
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Right)) inputManager->moveRight();
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Up)) inputManager->moveUp();
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Down)) inputManager->moveDown();
	//Changed from KeyDown, because needs to refire while held.  Is there an event for key being held? need to ask
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Space)) inputManager->fire();
}

void Keyboard::Destroy()
{
	//DeregisterInput();
	
}