
#ifndef _Scorpion
#define _Scorpion

#include "TEAL\CommonElements.h"
#include "MushroomField.h"
#include "Kill.h"
#include <queue>
#include <vector>
#include <list>


using namespace std;

class Scorpion: public GameObject
{
public:
	Scorpion(sf::Vector2f p, float lr);
	
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	virtual void Collision( GameObject *go){};
	void Collision(Shot* other);
	void Collision(Mushroom* other);

private:
	sf::Vector2f Pos;
	int speed;
	float leftRight;//left = -1, right = 1

	queue <Mushroom*> poisoned;//to unpoison mushrooms when scorpion dies
	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;
};



#endif _Scorpion