#include "Flea.h"
#include "FleaManager.h"
#include "WaveManager.h"
const float leftSpawnX = -20;
const float rightSpawnX = 500;
const float gridSpaceWidth = 16;
const float gridOffset = 8;
const float speed1 = 4;
const float speed2 = 7;
const float YMax = 512;

Flea::Flea(sf::Vector2f p)
{
	counter=0;
	bitmap = ResourceManager::GetTextureBitmap("Flea");
	MainSprite = AnimatedSprite(  ResourceManager::GetTexture("Flea"), 2, 2);
	MainSprite.SetAnimation(0,3); 
	hit=false;
	MainSprite.setOrigin( MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(1,1);
	Pos=p;
	
	speed = speed1;
	MainSprite.setPosition(Pos);
	SetCollider(MainSprite, bitmap, true);
	RegisterCollision<Flea>(*this);

	FleaSnd.setBuffer( ResourceManager::GetSound("FleaSnd")  );
	FleaSnd.setPitch(1);
	FleaSnd.setVolume(25);
	FleaSnd.play();
}

void Flea::spawnMushroom()
{
	counter=0;
	int i=rand() % 4;
	if (i!=3)
		return;
	int x, y;
	x = Pos.x;
	y = Pos.y;
	y-=gridSpaceWidth;	
	x-=gridSpaceWidth;
	x/=gridSpaceWidth;//divide by size of grid space
	y/=gridSpaceWidth;//divide by size of grid space
	if (x<=30&&y<=30)
		WaveManager::GetInstance()->m->addMushroomAt(x,y);
}

void Flea::Destroy()
{
	MarkForDestroy();
	DeregisterInput();
	DeregisterCollision<Flea>(*this);
}

void Flea::Update()
{
	if (Pos.y>YMax)
	{
		FleaManager::GetInstance()->fleaActive = NULL;
		//WaveManager::GetInstance()->spawnFlea();
		MarkForDestroy();
	}
	
	Pos.y+=speed;
	counter+=speed;
	if (counter>=16)
		spawnMushroom();
	MainSprite.Update();
	MainSprite.setPosition(Pos);
}

void Flea::Collision(Shot *other)
{
	if (!hit)
	{
		speed=speed2;
		hit = true;
		return;
	}
	FleaManager::GetInstance()->fleaActive = NULL;
	new Kill(Pos);
	MarkForDestroy();
	//TODO: SCORE
}



void Flea::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}


