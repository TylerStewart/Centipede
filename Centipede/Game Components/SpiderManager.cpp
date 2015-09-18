#include "SpiderManager.h"
#include "WaveManager.h"
#include "Constants.h"
const float leftSpawnX = -20;
const float rightSpawnX = 500;
const float gridSpaceWidth = 16;
const float gridOffset = 8;

SpiderManager* SpiderManager::SpiderMan = NULL;

SpiderManager::SpiderManager()
{
	spiderActive=NULL;
	speed = 100;
	//RegisterInput( InputFlags::KeyPressed ); 
}

SpiderManager* SpiderManager::GetInstance()
{
	if (SpiderMan== NULL) {
		SpiderMan = new SpiderManager();
	}
	return SpiderMan;
}

void SpiderManager::Update()
{
	
}

/*void SpiderManager::KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey)
{
	if ( k == sf::Keyboard::M)
	{
		createSpider();
		
	}
}*/

void SpiderManager::cleanup()
{
	if (spiderActive)
		spiderActive->MarkForDestroy();
	spiderActive=NULL;
}

void SpiderManager::createSpider()
{
	float  lr, yspawn;
	lr =(int)rand() % 2;
	if (lr ==0)
		lr = -1;
	
	sf::Vector2f spawn;
	yspawn =  rand() % 200;
	yspawn+=300;
	spawn = sf::Vector2f(256 + (256*lr), yspawn);


	spiderActive = new Spider(spawn, lr, WaveManager::GetInstance()->currentWave.SpiderSpeed);
}

void SpiderManager::Destroy()
{
	//DeregisterInput();
	
}