
#include "Kill.h"
	
Kill::Kill(sf::Vector2f p)
{
	
	bitmap = ResourceManager::GetTextureBitmap("Death");
	MainSprite = AnimatedSprite(  ResourceManager::GetTexture("Death"), 4,2);
	MainSprite.SetAnimation(0, 7);

	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(1,1);
	SetCollider(MainSprite, bitmap);
	countdown=8;
	Pos = p;
	KillSnd.setBuffer( ResourceManager::GetSound("KillSnd")  );
	KillSnd.setPitch(1);
	KillSnd.setVolume(25);
	KillSnd.play();
}

void Kill::Update()
{
	countdown--;
	if (countdown<=0)
		MarkForDestroy();
	
	//Could use a messenger system to handle this rather than checking each frame, BUT, since there is only ever one bullet in Centipede, the difference is negligable. 
	//Will need such a system later tho
	
	MainSprite.Update();

	MainSprite.setPosition(Pos);
}

void Kill::setSprite(int i)
{
	countdown = 24;
	
	MainSprite = AnimatedSprite(  ResourceManager::GetTexture("SpiderScore"), 1,3);
	MainSprite.setScale(2,2);

	switch (i)
	{
		case 0:
			MainSprite.SetAnimation(0, 0);
			break;
		case 1:
			MainSprite.SetAnimation(1, 1);
			break;
		case 2:
			MainSprite.SetAnimation(2, 2);
			break;
	}
}

void Kill::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}

void Kill::Destroy()
{
	DeregisterCollision<Kill>( *this );
}
