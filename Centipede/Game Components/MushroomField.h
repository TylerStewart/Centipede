
#ifndef _MushroomField
#define _MushroomField

#include "TEAL\CommonElements.h"
#include "Blaster.h"
#include "Mushroom.h"

//Forward declarations


class MushroomField : public GameObject
{
public:
	MushroomField();

	void Initialize(); 

	void Update();
	void Draw();
	void Destroy();
	void newField();
	void attractorFix();
	void Collision( GameObject *go){};
	int damage;
	void refreshField();
	void checkForFlea();
	Mushroom* field[31][31];
	bool spawnFlea;
	void destroyMushroomAt(int x, int y);
	void addMushroomAt(int x, int y);
	int cnt;
private:
	
	sf::Vector2f Pos;
	AnimatedSprite MainSprite;
	//CollisionTools::TextureBitmap bitmap;

};

#endif _MushroomField