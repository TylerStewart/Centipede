
#ifndef _AI
#define _AI
#include "InputManager.h"
#include "TEAL\CommonElements.h"

class AI: public GameObject
{
public:
	void Initialize(); 
	AI();
	virtual void Update();
	virtual void Destroy();
	void Alarm1();
	/*
	virtual void moveUp();
	virtual void moveDown();
	virtual void moveLeft();
	virtual void moveRight();
	//*/

private:
	InputManager* inputManager;
	int action;

};
#endif _AI