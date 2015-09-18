
#ifndef _Timers
#define _Timers

#include "TEAL\CommonElements.h"

//Forward declarations


class Timers : public GameObject
{
public:
	Timers();

	void Initialize(sf::Vector2f p); 

	void setTimer0(float t);
	void setTimer1(float t);
	void Alarm0();
	void Alarm1();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
	//virtual void Collision(Shot *other);

	private:
	
	
};

#endif _Timers