#include "Spider.h"
#include "SpiderManager.h"
#include "WaveManager.h"
#include "Shot.h"
const float leftSpawnX = -20;
const float rightSpawnX = 500;

const float gridOffset = 8;
const float speed1 = 4;
const float speed2 = 7;
const float YMax = 512;

Spider::Spider(sf::Vector2f p, float lr, float s)
{
	speed = s;
	bitmap = ResourceManager::GetTextureBitmap("Spider");
	MainSprite = AnimatedSprite(  ResourceManager::GetTexture("Spider"), 4, 2);
	MainSprite.SetAnimation(0,7); 
	
	MainSprite.setOrigin( MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(2,2);
	Pos=p;
	
	leftRight=lr*-1;
	MainSprite.setPosition(Pos);
	SetCollider(MainSprite, bitmap, true);
	RegisterCollision<Spider>(*this);
}

void Spider::fillQueue()
{
	if ((Pos.x>rightSpawnX&&leftRight>0)||(Pos.x<leftSpawnX&&leftRight<0))
	{
		SpiderManager::GetInstance()->spiderActive=NULL;
		MarkForDestroy();
		WaveManager::GetInstance()->setSpiderTimer();
	}
	int Qlength= (rand() % 15)+1;
	float upDown = 0;
	float side = 0;
	sf::Vector2f newPos=Pos;
	
	if (newPos.y<YMax*0.66f)
		upDown = 1;
	else if (newPos.y>YMax-8)
		upDown = -1;
	else
	{
		upDown = rand() % 2;
		if (upDown == 0)
			upDown=-1;
	}
	side = rand() % 2;
	
	while (Qlength>0)
	{
		newPos+= sf::Vector2f( leftRight *side*speed, upDown*speed);

		posQ.push(newPos);
		Qlength--;
	}
}

void Spider::Update()
{
	if(posQ.empty())
		fillQueue();
	Pos=posQ.front();
	posQ.pop();
	MainSprite.Update();
	MainSprite.setPosition(Pos);
}

void Spider::Collision(Shot *other)
{
		
	//TODO: SCORE
}

void Spider::Destroy()
{
	SpiderManager::GetInstance()->spiderActive=NULL;
		//other->fired = false;
	MarkForDestroy();
	WaveManager::GetInstance()->setSpiderTimer();
	DeregisterCollision<Spider>(*this);
}

void Spider::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}


