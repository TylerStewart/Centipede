
#ifndef _Shot
#define _Shot

#include "TEAL\CommonElements.h"
#include "Blaster.h"
#include "Mushroom.h"

//Forward declarations
class CentipedeHead;
class CentipedeSegment;
class Scorpion;
class Flea;
class Spider;

class Shot : public GameObject
{
public:
	Shot(sf::Vector2f p, Blaster* b);

	void Initialize(sf::Vector2f p); 

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
	void die();
	void Collision( GameObject *go){};
	void Collision( Mushroom *other );
	void Collision(Flea *other);
	void Collision( CentipedeHead *other );
	void Collision( CentipedeSegment *other );
	void Collision(Scorpion* other);
	void Collision(Spider* other);
	bool returnFired();
	bool fired;


private:
	float SPEED;
	Blaster* blaster;
	sf::Vector2f Pos;
	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;
	
	void Fired();
};

#endif _Shot