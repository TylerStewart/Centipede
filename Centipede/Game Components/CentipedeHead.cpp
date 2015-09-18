#include "CentipedeHead.h"
#include "TEAL\CommonElements.h"
#include "Mushroom.h"
#include "Shot.h"
#include "CentipedeManager.h"
#include "ScoreManager.h"
#include "WaveManager.h"
float gridSpaceWidth = 16;

CentipedeHead::CentipedeHead(sf::Vector2f p, float s)
{
	SPEED = s;
	
	bitmap = ResourceManager::GetTextureBitmap("CentipedeHead");
	MainSprite = AnimatedSprite(  ResourceManager::GetTexture("CentipedeHead"), 8, 2);
	MainSprite.SetAnimation(0,7); 

	MainSprite.setOrigin( MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(2,2);
	
	Pos = sf::Vector2f(p);

	MainSprite.setPosition(Pos);
	
	SetCollider(MainSprite, bitmap, true);
	RegisterCollision<CentipedeHead>(*this);

	diving = false;
	leftRight=-1;
	leftRightLast=1;
	upDown = 1;
	//SetDrawOrder(1000);
	direction = sf::Vector2f(0,2);
	turning = true;
	yLock=p.y;

	in.newPos = Pos;
	in.rot=0;

	setNext(NULL);
	setPrev(NULL);
	
}

void CentipedeHead::initialize()
{
	SPEED = 100;
	bitmap = ResourceManager::GetTextureBitmap("CentipedeHead");
	MainSprite = AnimatedSprite(  ResourceManager::GetTexture("CentipedeHead"), 8, 2);
	MainSprite.SetAnimation(0,7); 

	MainSprite.setOrigin( MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(2,2);

	MainSprite.setPosition(Pos);
	
	SetCollider(MainSprite, bitmap, true);
	RegisterCollision<CentipedeHead>(*this);

	diving = false;
	leftRight=-1;
	leftRightLast=1;
	upDown = 1;
	
	direction = sf::Vector2f(0,2);
	turning = true;
	yLock=Pos.y;

	in.newPos = Pos;
	in.rot=0;

	setNext(NULL);
	setPrev(NULL);
}

int roundNum(int numToRound, int multiple) 
{ 

    if (multiple == 0) 
        return numToRound; 
	if ((abs(numToRound) % multiple) < multiple/2)
	{
		int remainder = abs(numToRound) % multiple;
		if (remainder == 0)
			return numToRound;
		if (numToRound < 0)
			return -(abs(numToRound)/multiple);
		return numToRound;
	}
	else
	{
		int remainder = abs(numToRound) % multiple;
		if (remainder == 0)
			return numToRound;
		if (numToRound < 0)
			return -(abs(numToRound) - remainder);
		return numToRound + multiple - remainder;
	}
}

void CentipedeHead::setDirAndRot(float r, float ud, float lr)
{
	rotation = r;
	in.rot = r;
	upDown=ud;
	leftRight=lr;
	if (leftRight>0)
		leftRightLast = 1;
	if(leftRight<0)
		leftRightLast=-1;
}

void CentipedeHead::Destroy()
{
	DeregisterInput();
	DeregisterCollision<CentipedeHead>(*this);
}

void CentipedeHead::Update()
{
	MainSprite.Update();

	offset = Game::FrameTime() * SPEED;;
	
	if (moveQ.empty())
	{
		if (nextSeg)
		{
			nextSeg->receiveQueue(lastQ);
			while (!lastQ.empty())
				lastQ.pop();
		}
		constructQueue();
	}
	if (moveQ.empty())
		return;

	out=moveQ.front();//retrieve from queue
	lastQ.push(out);//move it to the other queue to be passed to the next segment
	moveQ.pop();//remove from queue
	rotation = out.rot;
	Pos=out.newPos;
	MainSprite.setPosition(Pos);
	MainSprite.setRotation(rotation);
	Tools::Clamp<float>(Pos.x, fieldMinX+1, fieldMaxX-1  );
	
}

/*void CentipedeHead::setNextSeg(CentipedeNode* seg)
{
	nextSeg = seg;
}*/

void CentipedeHead::checkForTurn()
{
	if (yLock==504&&!turning)
	{
		upDown = -1;
		diving=false;
	}
	else if (Pos.y<=(fieldMaxY-(gridSpaceWidth*5))&&upDown==-1&&turning==false)
	{
		upDown=1;
	}
	if (diving)
	{
		turning=true;
		return;
	}
	int x,y;
	x = (int)Pos.x;
	y = (int)Pos.y;
	int tmpX=x;

	x+=(leftRight*((int)gridSpaceWidth));
	x= roundNum(x, (int)gridSpaceWidth);
	
	
	y-=(int)gridSpaceWidth;
	x/=(int)gridSpaceWidth;//divide by size of grid space
	y/=(int)gridSpaceWidth;//divide by size of grid space
	
	
	if (Pos.y<24)
	{
		turning=true;
	}
	
	else if (WaveManager::GetInstance()->m->field[x][y] != NULL&&(x<=30)&&(y<=30))
	{
		if (WaveManager::GetInstance()->m->field[x][y]->returnPoisoned())
			diving=true;
		turning = true;
	}
	else if ((((Pos.x)<=fieldMinX+gridSpaceWidth/2) && (leftRight<0))||(((Pos.x+leftRight)>=fieldMaxX-gridSpaceWidth/2)&&(leftRight>0)))
	{
		turning=true;
	}
	//check if segment needs to turn up/down

}

void CentipedeHead::constructQueue()//builds queue of moves for centipede to execute
{
	float tmpX = Pos.x;
	tmp=Pos;
	checkForTurn();
	int t = 0;
	
	if (turning)
	{
		while (turning) 
		{
			
			if (leftRightLast == -1)
			{
				if (leftRight>=1)
				{
					leftRightLast=1;
					turning = false;
					leftRight=1;
					yLock +=gridSpaceWidth*upDown;//lock to correct y value
					in.rot=180;
				}
				else
					leftRight+=offset/5.5f;
			}
			else if (leftRightLast==1)
			{
				if (leftRight<=-1)
				{
					leftRightLast=-1;
					turning = false;
					leftRight=-1;
					yLock +=gridSpaceWidth*upDown;//lock to correct y value
					in.rot=0;
				}
				else
					leftRight-=offset/5.5f;
			}
			tmp = sf::Vector2f(leftRight*offset,upDown*(offset));
			
			in.newPos+=tmp;
			if (!turning) 
				in.newPos.y=yLock;
			else 
				in.rot+=27*leftRight;
			in.leftRight = leftRight;
			in.upDown = upDown;
			moveQ.push(in);
			
		}
	}
	else 
	{
	
		if (leftRight>0)
			while(in.newPos.x<tmpX+gridSpaceWidth/2)
			{
				in.leftRight = leftRight;
				in.upDown = upDown;
				tmp = sf::Vector2f(leftRight*offset,0);
				in.newPos+=tmp;
				moveQ.push(in);
			}
		else if (leftRight<0)
			while(in.newPos.x>tmpX-gridSpaceWidth/2)
			{
				in.leftRight = leftRight;
				in.upDown = upDown;
				tmp = sf::Vector2f(leftRight*offset,0);
				in.newPos+=tmp;
				moveQ.push(in);	
			}
	}
	
}


void CentipedeHead::Collision(Shot *other)
{
	if (!other->fired)
		return;
	int x, y;
	x = Pos.x;
	y = Pos.y;
	y-=(float)gridSpaceWidth;
	x/=(float)gridSpaceWidth;//divide by size of grid space
	y/=(float)gridSpaceWidth;//divide by size of grid space
	
	if (nextSeg)
	{
		nextSeg->setPrev(NULL);
		nextSeg->becomeHead();
	}
	setNext(NULL);
	setPrev(NULL);
	other->fired=false;
	new Kill(Pos);
	WaveManager::GetInstance()->m->addMushroomAt(x,y);

	CentipedeNode* cn =(CentipedeNode* ) this;
	CentipedeManager::GetInstance()->centipedeNodes.remove(cn);
	clearQueue();
	MarkForDestroy();
	CentipedeManager::GetInstance()->subCentipede();
	ScoreManager::GetInstance()->addCentipedeHead();
}



sf::Vector2f CentipedeHead::getPos()
{
	
	return Pos;
}

void CentipedeHead::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}


