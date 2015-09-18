
#ifndef _Keyboard
#define _Keyboard
#include "InputManager.h"
#include "TEAL\CommonElements.h"

class Keyboard: public GameObject
{
public:
	void Initialize(); 
	Keyboard();
	virtual void Update();
	virtual void Destroy();

	/*
	virtual void moveUp();
	virtual void moveDown();
	virtual void moveLeft();
	virtual void moveRight();
	//*/

private:
	InputManager* inputManager;
	

};
#endif _Keyboard