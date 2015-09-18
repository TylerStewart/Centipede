
#ifndef _SoundBox
#define _SoundBox

#include "TEAL\CommonElements.h"

//Forward declarations

class SoundBox : public GameObject
{
public:
	SoundBox();

	void Initialize(sf::Vector2f p); 

	/*void setTimer0(float t);
	void setTimer1(float t);*/
	void Alarm0();
	void Alarm1();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
	//virtual void Collision(Shot *other);
	sf::Sound CentSnd;
	sf::Sound SpidSnd;
	
	private:
	
	
};

#endif _SoundBox