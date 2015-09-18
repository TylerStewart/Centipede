#include "CentipedeManager.h"
#include "Constants.h"
#include "WaveManager.h"



CentipedeManager* CentipedeManager::CentMan = NULL;

std::stack<CentipedeSegment*> CentipedeManager::segs;
std::stack<CentipedeHead*> CentipedeManager::heads;

CentipedeManager::CentipedeManager()
{
	numCentipedes=0;
	
	//SetAlarm(0, .25f);
	speed = 100;
	//RegisterInput( InputFlags::KeyPressed ); 
}

void CentipedeManager::addCentipede()
{
	numCentipedes++;
}

void CentipedeManager::subCentipede()
{
	numCentipedes--;
}

CentipedeManager* CentipedeManager::GetInstance()
{
	if (CentMan== NULL) {
		CentMan = new CentipedeManager();
	}
	return CentMan;
}

void CentipedeManager::Update()
{
	
}

void CentipedeManager::KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey)
{
	if ( k == sf::Keyboard::Period )
	{
		createCentipede(12);
	}
}

/*void CentipedeManager::createHead(sf::Vector2f pos, CentipedeNode* n, float r, float ud, float lr)
{
	CentipedeHead* ch = new CentipedeHead(pos,m);
	CentipedeNode* h = ch;
	h->setNext(n);
	if (n)
	{
		n->pingBack();
		n->setPrev(h);
	}
	ch->setDirAndRot(r, ud, lr);
	//testHead();
	addCentipede();
}*/

void CentipedeManager::testHead()
{
	//CentipedeNode *h = new CentipedeHead(CentipedeSpawnCenter);
}

/*void CentipedeManager::Alarm0()
{
	if (numCentipedes>0)
		CentSnd.play();

	SetAlarm(0, .25f);

}*/

void CentipedeManager::createCentipede(int segs)//make this allow the legnth and speed to be defined as inputs
{

	clearCentipede();

	float tmp = (float) segs;
	tmp*=(-16);
	sf::Vector2f spawnLocation = CentipedeSpawnCenter + sf::Vector2f(0, tmp);
	CentipedeNode* h = NULL;
	h = CreateHead(spawnLocation);
	//centipedeNodes.push_front(h);
 	segs--;
	if (segs>0)
	{
		CentipedeNode* s0 = NULL;
		CentipedeNode* s1 = NULL;
		s0 = CreateSegment(spawnLocation);
		h->setNext(s0);
		s0->setPrev(h);
		//centipedeNodes.push_front(s0);
		segs--;
		while (segs>0)
		{
 			s1 = CreateSegment(spawnLocation);
			s0->setNext(s1);
			s1->setPrev(s0);
			s0 = s1;
			//centipedeNodes.push_front(s0);
			segs--;
		}
	}
	addCentipede();
}

CentipedeSegment* CentipedeManager::CreateSegment(sf::Vector2f pos)
{
	CentipedeSegment* b;

	if ( segs.empty() )
	{
		b = new CentipedeSegment(pos);

		// Declares that this object should be returned here (rather than deleted) when destroyed
		b->SetExternalManagement( RecycleSegment);
	}
	else
	{
		b = segs.top();
		segs.pop();	// Remember: top doesn't pop and pop returns void...
		b->setPos(pos);
		b->initialize();
		// Tell the object to register itself to the scene
		b->RegisterToCurrentScene();  
	}

	b->clearQueue();//clean out queue if it has any garbage
	CentipedeManager::GetInstance()->centipedeNodes.push_front(b);
	return b;
}

void CentipedeManager::RecycleSegment(GameObject* b)
{
	CentipedeManager::GetInstance()->centipedeNodes.remove((CentipedeNode*) b);
	
	segs.push( (CentipedeSegment*) b);
}

CentipedeHead* CentipedeManager::CreateHead(sf::Vector2f pos)
{
	CentipedeHead* b;

	if ( heads.empty() )
	{
		b = new CentipedeHead(pos, WaveManager::GetInstance()->currentWave.CentipedeSpeed);

		// Declares that this object should be returned here (rather than deleted) when destroyed
		b->SetExternalManagement( RecycleHead);
	}
	else
	{
		b = heads.top();
		heads.pop();	// Remember: top doesn't pop and pop returns void...
		b->setPos(pos);
		//b->setSpeed(WaveManager::GetInstance()->currentWave.CentipedeSpeed);
		b->initialize();
		
		// Tell the object to register itself to the scene
		b->RegisterToCurrentScene();  
	}
	
	b->clearQueue();//clean out queue if it has any garbage
	CentipedeManager::GetInstance()->centipedeNodes.push_front(b);
	WaveManager::GetInstance()->SB->CentSnd.setVolume(25);
	return b;

}

void CentipedeManager::RecycleHead(GameObject* b)
{
	if (CentipedeManager::GetInstance()->centipedeNodes.empty())
	{
		WaveManager::GetInstance()->SB->CentSnd.setVolume(0);
		WaveManager::GetInstance()->startWave();
	}
	CentipedeManager::GetInstance()->centipedeNodes.remove((CentipedeNode*) b);
	heads.push( (CentipedeHead*) b);
}

void CentipedeManager::SetMushroomField(MushroomField* f)
{
	m=f;
}

void CentipedeManager::Cleanup()
{
	
}

void CentipedeManager::clearCentipede()
{
	while (!centipedeNodes.empty())
	{
		centipedeNodes.back()->MarkForDestroy();
		centipedeNodes.pop_back();
	}
}

CentipedeManager::~CentipedeManager()
{
	while ( ! segs.empty() ) 
	{
		delete segs.top();
		segs.pop();
	}
	while ( ! heads.empty() ) 
	{
		delete heads.top();
		heads.pop();
	}
}