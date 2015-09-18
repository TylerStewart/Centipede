
#ifndef _Flea
#define _Flea

#include "TEAL\CommonElements.h"
#include "MushroomField.h"
#include "Kill.h"


using namespace std;

class Flea: public GameObject
{
public:
	Flea(sf::Vector2f p);
	
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
	void spawnMushroom();
	virtual void Collision( GameObject *go){};
	void Collision(Shot* other);
	bool hit;
private:
	sf::Vector2f Pos;
	int speed;
	int gridY;
	sf::Sound FleaSnd;
	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;
	float counter;
};



#endif _Flea