#include "CentipedeSegment.h"
#include "TEAL\CommonElements.h"
#include "Mushroom.h"
#include "Shot.h"
#include "CentipedeManager.h"
#include "ScoreManager.h"
#include "WaveManager.h"
const float gridSpaceWidth = 16;

CentipedeSegment::CentipedeSegment(sf::Vector2f p)
{
	bitmap = ResourceManager::GetTextureBitmap("CentipedeSegment");
	//printf("boop");
	MainSprite = AnimatedSprite(  ResourceManager::GetTexture("CentipedeSegment"), 8, 2);
	MainSprite.SetAnimation(0,7); 

	MainSprite.setOrigin( MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(2,2);
	
	Pos = sf::Vector2f(p);

	MainSprite.setPosition(Pos);
	
	SetCollider(MainSprite, bitmap, true);
	RegisterCollision<CentipedeSegment>(*this);

	leftRight=-1;
	leftRightLast=1;
	upDown = 1;
	setNext(NULL);
	setPrev(NULL);

}

void CentipedeSegment::initialize()//repetitive, but consistently fixes issue.  TODO: Find source of problem
{
	bitmap = ResourceManager::GetTextureBitmap("CentipedeSegment");

	MainSprite = AnimatedSprite(  ResourceManager::GetTexture("CentipedeSegment"), 8, 2);
	MainSprite.SetAnimation(0,7); 

	MainSprite.setOrigin( MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(2,2);
	
	MainSprite.setPosition(Pos);
	
	SetCollider(MainSprite, bitmap, true);
	RegisterCollision<CentipedeSegment>(*this);

	
	leftRight=-1;
	leftRightLast=1;
	upDown = 1;
	setNext(NULL);
	setPrev(NULL);
}



void CentipedeSegment::Destroy()
{
	DeregisterInput();
	DeregisterCollision<CentipedeSegment>(*this);
}

void CentipedeSegment::Update()
{
	MainSprite.Update();

	
	if (moveQ.empty())
		return;
	out=moveQ.front();//retrieve from queue
	lastQ.push(out);//move it to the other queue to be passed to the next segment
	moveQ.pop();//remove from queue
	
	rotation = out.rot;
	Pos=out.newPos;
	upDown = out.upDown;
	leftRight = out.leftRight;
	MainSprite.setPosition(Pos);
	MainSprite.setRotation(rotation);
}

void CentipedeSegment::Collision(Shot *other)
{
	if (!other->fired)
		return;
	int x, y;
	x = (int) Pos.x;
	y = (int) Pos.y;
	y-=(int) gridSpaceWidth;
	x/=(int) gridSpaceWidth;//divide by size of grid space
	y/=(int) gridSpaceWidth;//divide by size of grid space
	
	if (nextSeg)
	{
		nextSeg->setPrev(NULL);
		nextSeg->becomeHead();
	}
	if (prevSeg)
		prevSeg->setNext(NULL);

	setNext(NULL);
	setPrev(NULL);
	other->fired=false;
	new Kill(Pos);
	CentipedeNode* cn =(CentipedeNode* ) this;
	CentipedeManager::GetInstance()->centipedeNodes.remove(cn);
	WaveManager::GetInstance()->m->addMushroomAt(x,y);
	clearQueue();
	MarkForDestroy();
	ScoreManager::GetInstance()->addCentipedeSeg();
}


void CentipedeSegment::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}


