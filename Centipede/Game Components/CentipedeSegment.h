#ifndef _CentipedeSegment
#define _CentipedeSegment

#include "TEAL\CommonElements.h"
#include "CentipedeNode.h"
#include "MushroomField.h"
#include "Kill.h"
#include <queue>
#include <vector>
#include <list>
using namespace std;

class CentipedeHead;

class CentipedeSegment: public CentipedeNode
{
public:
	CentipedeSegment(sf::Vector2f p);
	void Update();
	void Draw();
	void Destroy();

	void Collision( GameObject *go){};
	void Collision(Shot* other);
	void initialize();
	

private:
	
	int leftRightLast;
	int tilSend;

	CentipedeHead* head;
	
	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;
};



#endif _CentipedeSegment