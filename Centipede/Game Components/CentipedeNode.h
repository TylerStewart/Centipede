#ifndef MOVE_DATA
#define MOVE_DATA
#include "TEAL\CommonElements.h"

const int maxSpeed = 160;

struct MOVEDATA{ 
	sf::Vector2f newPos;
    float rot;
	float upDown;
	float leftRight;
}; //Holds movement data to be used by the centipede node, can be passed from head to segments
#endif MOVE_DATA 


#ifndef _CentipedeNode
#define _CentipedeNode

#include "TEAL\CommonElements.h"
//#include "CentipedeManager.h"
#include "MushroomField.h"
#include "Kill.h"
#include <queue>
#include <vector>
#include <list>
using namespace std;

class Blaster;

class CentipedeNode: public GameObject
{
public:
	CentipedeNode(sf::Vector2f p, MushroomField* m);
	CentipedeNode();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	virtual void Collision( GameObject *go){};
	virtual void Collision(Shot* other);
	virtual void Collision(Blaster* other);
	virtual void receiveQueue(queue <MOVEDATA> q);
	void clearQueue();
	void becomeHead();
	virtual void setNext(CentipedeNode* n);
	virtual void setPrev(CentipedeNode* n);
	virtual CentipedeNode* returnNext();
	virtual CentipedeNode* returnPrev();
	void pingBack();
	void setPos(sf::Vector2f p);

protected:
	sf::Vector2f Pos;

	CentipedeNode* nextSeg;
	CentipedeNode* prevSeg;

	queue <MOVEDATA> moveQ;
	queue <MOVEDATA> lastQ;

	int tilEmpty;

	float leftRight;//left = -1, right = 1
	float upDown;//up = -1, down = 1
	float rotation;

	MOVEDATA in;
	MOVEDATA out;//to be used by next segment

	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;
};



#endif _CentipedeNode