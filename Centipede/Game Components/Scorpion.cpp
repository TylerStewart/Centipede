#include "Scorpion.h"
#include "ScorpionManager.h"
#include "WaveManager.h"

const float leftSpawnX = -20;
const float rightSpawnX = 500;

const float gridOffset = 8;


Scorpion::Scorpion(sf::Vector2f p, float lr)
{
	
	bitmap = ResourceManager::GetTextureBitmap("Scorpion");
	MainSprite = AnimatedSprite(  ResourceManager::GetTexture("Scorpion"), 4, 1);
	MainSprite.SetAnimation(0,3); 

	MainSprite.setOrigin( MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(1,1);
	
	Pos=p;
	leftRight=lr;

	MainSprite.setPosition(Pos);
	SetCollider(MainSprite, bitmap, true);
	RegisterCollision<Scorpion>(*this);
}


void Scorpion::Destroy()
{
	DeregisterInput();
	DeregisterCollision<Scorpion>(*this);
}

void Scorpion::Update()
{
	if ((Pos.x>rightSpawnX&&leftRight>0)||(Pos.x<leftSpawnX&&leftRight<0))//TODO: make this suck less
	{
		ScorpionManager::GetInstance()->scorpionActive = NULL;
		MarkForDestroy();
		WaveManager::GetInstance()->setScorpionTimer();
	}
	Pos += sf::Vector2f(-1, 0);
	MainSprite.Update();
	MainSprite.setPosition(Pos);
}

void Scorpion::Collision(Shot *other)
{
	new Kill(Pos);
	ScorpionManager::GetInstance()->scorpionActive = NULL;

	while(!poisoned.empty())
	{
		poisoned.front()->unPoison();
		poisoned.pop();
	}
	MarkForDestroy();
	WaveManager::GetInstance()->setScorpionTimer();
	//TODO: SCORE
}

void Scorpion::Collision(Mushroom *other)
{
	if (!other)
		return;
	other->poison();
	poisoned.push(other);
}

void Scorpion::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}


