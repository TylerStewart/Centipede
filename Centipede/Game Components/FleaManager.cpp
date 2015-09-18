#include "FleaManager.h"
#include "Constants.h"
const float leftSpawnX = -20;
const float rightSpawnX = 500;
const float gridSpaceWidth = 16;
const float gridOffset = 8;

FleaManager* FleaManager::FleaMan = NULL;

FleaManager::FleaManager()
{
	fleaActive=NULL;
	speed = 100;
	//RegisterInput( InputFlags::KeyPressed ); 
}

FleaManager* FleaManager::GetInstance()
{
	if (FleaMan== NULL) {
		FleaMan = new FleaManager();
	}
	return FleaMan;
}

/*void FleaManager::KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey)
{
	if ( k == sf::Keyboard::Comma)
	{
		createFlea();
		
	}*/

void FleaManager::cleanup()
{
	if (fleaActive)
		fleaActive->MarkForDestroy();
	fleaActive = NULL;
}

void FleaManager::createFlea()
{
	if (fleaActive)
		return;
	float  lr, xspawn;
	sf::Vector2f spawn;
	xspawn =  rand() % 30;
	xspawn = gridOffset + (xspawn * gridSpaceWidth)+8;
	spawn = sf::Vector2f(xspawn, -8);

	fleaActive = new Flea(spawn);//debug scropion spawn location
}

void FleaManager::SetMushroomField(MushroomField* f)
{
	m=f;
}
