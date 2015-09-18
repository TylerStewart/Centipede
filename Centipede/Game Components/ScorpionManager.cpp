#include "ScorpionManager.h"
#include "Constants.h"
const float leftSpawnX = -20;
const float rightSpawnX = 500;
const float gridSpaceWidth = 16;
const float gridOffset = 8;

ScorpionManager* ScorpionManager::ScorpMan = NULL;

ScorpionManager::ScorpionManager()
{
	scorpionActive=NULL;
	speed = 100;
	//RegisterInput( InputFlags::KeyPressed ); 
}

ScorpionManager* ScorpionManager::GetInstance()
{
	if (ScorpMan== NULL) {
		ScorpMan = new ScorpionManager();
	}
	return ScorpMan;
}

void ScorpionManager::cleanup()
{
	if (scorpionActive)
		scorpionActive->MarkForDestroy();
	scorpionActive=NULL;
}

void ScorpionManager::createScorpion()
{
	float  lr, yspawn;
	sf::Vector2f spawn;
	yspawn =  rand() % 16;
	yspawn = gridOffset + (yspawn * gridSpaceWidth);
	int r = rand() % 1;
	if (r == 1)
	{
		lr = 1;
		spawn = sf::Vector2f(leftSpawnX, yspawn);
	}
	else
	{
		lr = -1;
		spawn = sf::Vector2f(rightSpawnX, yspawn);
	}

	scorpionActive = new Scorpion(spawn, lr);//debug scropion spawn location
}

void ScorpionManager::SetMushroomField(MushroomField* f)
{
	m=f;
}
