#include "Blaster.h"
#include "Shot.h"
#include "InputManager.h"
#include "Kill.h"
#include "WaveManager.h"
#include "ScoreManager.h"

Blaster::Blaster()
{
	SPEED = 120;
	HBORDER = 15;
	TBORDER = 600;

	GunOffset = sf::Vector2f(0, MainSprite.getTextureRect().height / 2.0f);
	
	bitmap = ResourceManager::GetTextureBitmap("Blaster");
	MainSprite = AnimatedSprite(  ResourceManager::GetTexture("Blaster"), 1, 1);
	MainSprite.SetAnimation(0,0); 

	MainSprite.setOrigin( MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(1,1);
	
	
	Pos = sf::Vector2f(240 ,  480);
	Impulse = sf::Vector2f(0,0);
	
	inputManager = InputManager::GetInstance();

	MainSprite.setPosition(Pos);

	SetCollider(MainSprite, bitmap, true);
	RegisterCollision<Blaster>(*this);

	FireSnd.setBuffer( ResourceManager::GetSound("FireSnd")  );
	FireSnd.setPitch(1);
	FireSnd.setVolume(25);
	
	SetDrawOrder(1000);

	RegisterInput( InputFlags::KeyPressed ); // Recieve single-presses events

	shot = new Shot(Pos+GunOffset, this);


}

void Blaster::Collision(Mushroom* other)
{
	Pos=lastPos;
}

void Blaster::Collision(CentipedeHead*other)
{
	die();
}
void Blaster::Collision(CentipedeSegment* other)
{
	die();
}

void Blaster::Collision(Spider* other)
{
	die();
}

void Blaster::Collision(Flea* other)
{
	die();
}

void Blaster::die()
{
	new Kill(Pos);
	Pos.x=0;
	Pos.y=0;
	shot->die();
	bitmap = ResourceManager::GetTextureBitmap("Shot");
	MainSprite = AnimatedSprite(  ResourceManager::GetTexture("Shot"), 3,1);
	MainSprite.SetAnimation(0, 0);
	ScoreManager::GetInstance()->loseLife();
	WaveManager::GetInstance()->restartWave();
	
	
}

void Blaster::Destroy()
{
	if (shot)
		shot->Destroy();
	MarkForDestroy();
	DeregisterInput();
	DeregisterCollision<Blaster>(*this);
}

void Blaster::Update()
{

	MainSprite.Update();

	Pos += inputManager->getMoveBy();
	
	Tools::Clamp<float>(Pos.x, (float) MainSprite.getTextureRect().width/2, WindowManager::MainWindow.getView().getSize().x-MainSprite.getTextureRect().width/2 );
	Tools::Clamp<float>(Pos.y,400, 504);	

	MainSprite.setPosition(Pos);
	Impulse=sf::Vector2f(0,0);

}
/*
void Blaster::moveUp()
{
	Impulse = sf::Vector2f(0, -offset);
}

void Blaster::moveDown()
{
	Impulse = sf::Vector2f(0, offset);
}

void Blaster::moveLeft()
{
	Impulse = sf::Vector2f(-offset, 0);
}

void Blaster::moveRight()
{
	Impulse = sf::Vector2f( offset, 0);
} THESE CAUSE TROUBLE WITH MUSHROOM COLLISION - blaster gets stuck inside mushrooms
*/

void Blaster::fire()
{
	if (shot->fired==false)
		{
			FireSnd.play();
			shot->fired=true;
		}
}

sf::Vector2f Blaster::getPos()
{

	return Pos;
}

void Blaster::Draw()
{
	lastPos=Pos;
	WindowManager::MainWindow.draw(MainSprite);
}

