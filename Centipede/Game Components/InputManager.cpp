#include "InputManager.h"

InputManager* InputManager::InputMan = NULL;

InputManager::InputManager()
{
	moveBy= sf::Vector2f(0,0);
	blaster = NULL;
}

InputManager* InputManager::GetInstance()
{
	if (InputMan== NULL) {
		InputMan = new InputManager();
	}
	return InputMan;
}

void InputManager::moveUp()
{
	moveBy += sf::Vector2f(0,-1);
}

void InputManager::moveDown()
{
	moveBy += sf::Vector2f(0,1);
}

void InputManager::moveLeft()
{
	moveBy += sf::Vector2f(-1,-0);

}

void InputManager::moveRight()
{
	moveBy += sf::Vector2f(1,0);
}

sf::Vector2f InputManager::getMoveBy()
{
	float SPEED=3;
	sf::Vector2f temp = moveBy*SPEED;
	moveBy = sf::Vector2f(0,0);
	return(temp);
}
void InputManager::fire()
{
	if (blaster)
		blaster->fire();
}

void InputManager::destroyBlaster()
{
	if (blaster)
	{
		blaster->Destroy();
		blaster = NULL;
	}
}

void InputManager::setBlaster()
{
	destroyBlaster();
	blaster=new Blaster();
}

