#ifndef _Blaster
#define _Blaster

#include "TEAL\CommonElements.h"

class Shot;
class Mushroom;
class InputManager;
class CentipedeHead;
class CentipedeSegment;
class Spider;
class Flea;

class Blaster : public GameObject
{
public:
	Blaster();
	void Update();
	void Draw();
	void Destroy();
	//virtual void KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey);
	virtual void Collision( GameObject *go){};
	virtual void Collision( Mushroom *other );
	virtual void Collision( CentipedeHead* other);
	virtual void Collision( CentipedeSegment* other);
	virtual void Collision( Flea *other);
	virtual void Collision( Spider *other);
	sf::Vector2f getPos();
	//to be called by input manager
	/*virtual void moveUp();
	virtual void moveDown();
	virtual void moveLeft();
	virtual void moveRight();*/
	void fire();
	void die();

private:
	float SPEED;
	float HBORDER;
	float TBORDER;
	sf::Vector2f GunOffset;
	
	float offset;
	sf::Vector2f lastPos;
	sf::Vector2f Pos;
	sf::Vector2f Impulse;
	float friction;

	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;
	InputManager* inputManager;

	sf::Sound FireSnd;
	Shot* shot;
};

#endif _Blaster