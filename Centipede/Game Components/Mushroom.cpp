
#include "Mushroom.h"
#include "MushroomField.h"

Mushroom::Mushroom(sf::Vector2f p, MushroomField* m, int x, int y)
{
	
	bitmap = ResourceManager::GetTextureBitmap("Mushroom");
	MainSprite = AnimatedSprite(  ResourceManager::GetTexture("Mushroom"), 4, 1);
	MainSprite.SetAnimation(0, 0);

	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(1,1);
	SetCollider(MainSprite, bitmap);
	damage = 0;
	Pos = p;
	RegisterCollision<Mushroom>( *this );
	gridX=x;
	gridY=y;
	Field = m;
	poisoned=false;
	KillSnd.setBuffer( ResourceManager::GetSound("KillSnd")  );
	KillSnd.setPitch(1);
	KillSnd.setVolume(25);
	
}

void Mushroom::poison()
{
	if (poisoned)
		return;
	bitmap = ResourceManager::GetTextureBitmap("Mushroom");
	MainSprite = AnimatedSprite(  ResourceManager::GetTexture("PoisonedMushroom"), 4, 1);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.SetAnimation(0, 0);
	SetCollider(MainSprite, bitmap);
	MainSprite.Update();
	MainSprite.setPosition(Pos);
	poisoned=true;
}

void Mushroom::unPoison()
{
	if (!poisoned)
		return;
	MainSprite = AnimatedSprite(  ResourceManager::GetTexture("Mushroom"), 4, 1);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.SetAnimation(0, 0);
	MainSprite.Update();
	MainSprite.setPosition(Pos);
	poisoned=false;
}

bool Mushroom::returnPoisoned()
{
	return (poisoned);
}

void Mushroom::Update()
{
	MainSprite.Update();
	MainSprite.setPosition(Pos);
}

void Mushroom::TakeDamage()
{
	damage++;
	
	if (damage>3)
	{
		Field->destroyMushroomAt(gridX, gridY);
		MarkForDestroy();
	}
	else
		MainSprite.SetAnimation(damage, damage);
	//TODO - Award one point to the player	
}

void Mushroom::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}

/*void Mushroom::Collision(Shot *other)
{
	TakeDamage();
}*/

void Mushroom::Refresh()
{
	damage = 0;
	MainSprite.SetAnimation(0,0);
	KillSnd.play();
}

void Mushroom::Destroy()
{
	DeregisterCollision<Mushroom>( *this );
}
