#include "CentipedeNode.h"
#include "TEAL\CommonElements.h"
#include "Mushroom.h"
#include "CentipedeHead.h"
#include "CentipedeManager.h"
//const float gridSpaceWidth = 16;

CentipedeNode::CentipedeNode(sf::Vector2f p, MushroomField* m)
{
	setNext(NULL);
	setPrev(NULL);
}

CentipedeNode::CentipedeNode()
{
	setNext(NULL);
	setPrev(NULL);
}

void CentipedeNode::Destroy()
{
	DeregisterInput();
	DeregisterCollision<CentipedeNode>(*this);
}

void CentipedeNode::Update()
{
	
}

void CentipedeNode::setNext(CentipedeNode* n)
{
	nextSeg = n;
}

void CentipedeNode::setPrev(CentipedeNode* n)
{
	prevSeg=n;
}

CentipedeNode* CentipedeNode::returnNext()
{
	return (nextSeg);
}

CentipedeNode* CentipedeNode::returnPrev()
{
	return (prevSeg);
}


void CentipedeNode::Collision(Shot *other)
{

}

void CentipedeNode::Collision(Blaster* other)
{

}

void CentipedeNode::becomeHead()
{
	CentipedeNode* tmp;
	tmp=NULL;
	if (nextSeg)
	{
		tmp = nextSeg;
	}
	
	CentipedeHead* ch= CentipedeManager::CreateHead(Pos);
	ch->setNext(tmp);
	if (tmp)
	{
		//tmp->pingBack();
		tmp->setPrev(ch);
	}
	ch->setDirAndRot(rotation, upDown, leftRight);
	CentipedeManager::GetInstance()->addCentipede();
	MarkForDestroy();

}

void CentipedeNode::setPos(sf::Vector2f p)
{
	Pos = p;
}

void CentipedeNode::pingBack()
{
	
}

void CentipedeNode::receiveQueue(queue <MOVEDATA> q)
{
	while(!q.empty())
	{	
		moveQ.push(q.front());
		q.pop();
		tilEmpty+=1;
	}

	if (nextSeg==NULL)
		return;
	if ((!nextSeg==NULL) && !lastQ.empty())
	{

		nextSeg->receiveQueue(lastQ);
		while (!lastQ.empty())
			lastQ.pop();
	}
}

void CentipedeNode::clearQueue()
{
	while(!moveQ.empty())
	{	
		moveQ.pop();
	}
	while (!lastQ.empty())
		lastQ.pop();
}

void CentipedeNode::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}


