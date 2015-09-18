
#ifndef _InputManager
#define _InputManager
#include "Blaster.h"
#include "TEAL\CommonElements.h"
//Forward declarations


class InputManager
{
public:
	static InputManager* GetInstance();
	
	void Initialize(); 

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void fire();
	sf::Vector2f getMoveBy();
	void setBlaster();
	void destroyBlaster();

private:
	sf::Vector2f moveBy;
	Blaster * blaster;
	InputManager();
	static InputManager* InputMan;
};

#endif _InputManager