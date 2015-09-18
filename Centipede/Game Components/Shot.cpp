#include "ScoreManager.h"
#include "Shot.h"
#include "Flea.h"
#include "Kill.h"

Shot::Shot(sf::Vector2f p, Blaster* b)
{
	SPEED = 700;

	bitmap = ResourceManager::GetTextureBitmap("Shot");
	MainSprite = AnimatedSprite(  ResourceManager::GetTexture("Shot"), 1, 1);
	MainSprite.SetAnimation(0, 0, false, false);

	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(1,1);
	SetCollider(MainSprite, bitmap);
	fired = false;
	Pos = p;
	blaster = b;
	RegisterCollision<Shot>( *this );
}

void Shot::Update()
{
	if (!blaster)
		return;
	if (Pos.y  < 0 ) 
	{
		fired=false;
	}
	//Could use a messenger system to handle this rather than checking each frame, BUT, since there is only ever one bullet in Centipede, the difference is negligable. 
	//Will need such a system later tho
	if (fired)
		Fired();
	else 
		Pos = blaster->getPos()+sf::Vector2f(0, -6);

	MainSprite.Update();

	
	//printf("%f \n", Pos.y);
	MainSprite.setPosition(Pos);
}

void Shot::Collision(Mushroom *other)
{
	if (!blaster)
		return;
	if (!fired)
		return;

	other->TakeDamage();
	//printf("MUSHROOM HIT\n");
	fired=false;
	Pos = sf::Vector2f(-8, -8);
}

bool Shot::returnFired()
{
	return fired;
}

void Shot::Collision(CentipedeHead *other)
{
	if (!blaster)
		return;
	if (!fired)
		return;
	fired=false;
	Pos = sf::Vector2f(-8, -8);
	
}

void Shot::Collision(CentipedeSegment *other)
{
	if (!blaster)
		return;
	if (!fired)
		return;
	fired=false;
	Pos = sf::Vector2f(-8, -8);
	ScoreManager::GetInstance()->addCentipedeSeg();
}

void Shot::Collision(Scorpion* other)
{
	if (!blaster)
		return;
	if (!fired)
		return;
	fired=false;
	Pos = sf::Vector2f(-8, -8);
	ScoreManager::GetInstance()->addScorpion();
}

void Shot::Collision(Flea* other)
{
	if (!blaster)
		return;
	if (!fired)
		return;
	fired=false;
	if (other->hit)
		ScoreManager::GetInstance()->addFlea();
	Pos = sf::Vector2f(-8, -8);
}

void Shot::Collision(Spider* other)
{
	if (!blaster)
		return;
	if (!fired)
		return;
	fired=false;
	sf::Vector2f temp = Pos -blaster->getPos();
	float f = sqrt((temp.x*temp.x)+(temp.y*temp.y));
	Kill* k = new Kill(Pos);
	if (f<60)
	{
		k->setSprite(2);
		ScoreManager::GetInstance()->addSpider(2);
	}
	else if(f>130)
	{
		k->setSprite(0);
		ScoreManager::GetInstance()->addSpider(0);
	}
	else 
	{
		k->setSprite(1);
		ScoreManager::GetInstance()->addSpider(1);
	}
	//SCORE CALC HERE
	other->Destroy();
	Pos = sf::Vector2f(-8, -8);
}

void Shot::Fired()
{
	Pos.y -= Game::FrameTime() * SPEED;
}

void Shot::die()
{
	
	bitmap = ResourceManager::GetTextureBitmap("Shot");
	MainSprite = AnimatedSprite(  ResourceManager::GetTexture("Shot"), 3,1);
	MainSprite.SetAnimation(0, 0);
}

void Shot::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}

void Shot::Destroy()
{
	MarkForDestroy();
	//blaster = NULL;
	DeregisterCollision<Shot>( *this );
}
