#ifndef _Kill
#define _Kill

#include "TEAL\CommonElements.h"
//Forward declarations


class Kill : public GameObject
{
public:
	Kill(sf::Vector2f p);

	void Initialize(sf::Vector2f p); 
	void setSprite(int i);
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
	int countdown;
	

private:
	sf::Vector2f Pos;
	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;
	sf::Sound KillSnd;
};

#endif _Kill