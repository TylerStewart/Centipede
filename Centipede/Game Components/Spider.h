
#ifndef _Spider
#define _Spider

#include "TEAL\CommonElements.h"
#include "MushroomField.h"
#include "Kill.h"
#include <queue>
#include <vector>
#include <list>

using namespace std;

class Spider: public GameObject
{
public:
	Spider(sf::Vector2f p, float l, float s);
	
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
	void spawnMushroom();
	virtual void Collision( GameObject *go){};
	void Collision(Shot* other);
	void fillQueue();

private:
	sf::Vector2f Pos;	
	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;
	queue<sf::Vector2f> posQ;
	float leftRight;
	float speed;
};



#endif _Spider