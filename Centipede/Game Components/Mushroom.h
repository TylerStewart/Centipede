
#ifndef _Mushroom
#define _Mushroom

#include "TEAL\CommonElements.h"

//Forward declarations
class MushroomField;
class Shot;

class Mushroom : public GameObject
{
public:
	Mushroom(sf::Vector2f p, MushroomField* m, int x, int y);

	void Initialize(sf::Vector2f p); 

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
	void Refresh();
	void TakeDamage();
	void poison();
	void unPoison();
	bool returnPoisoned();
	virtual void Collision( GameObject *go){};
	//virtual void Collision(Shot *other);
	MushroomField* Field;
	int gridX, gridY;
	int damage;

private:
	bool poisoned;
	sf::Vector2f Pos;
	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;
	sf::Sound KillSnd;
};

#endif _Mushroom