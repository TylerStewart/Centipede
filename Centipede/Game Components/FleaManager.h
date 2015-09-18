
#ifndef _FleaManager
#define _FleaManager

#include "Flea.h"
#include "Mushroom.h"
#include "MushroomField.h"
#include "TEAL\CommonElements.h"

//Forward declarations

class FleaManager
{
public:
	static FleaManager* GetInstance();
	
	void Initialize(); 
	void createFlea();
	void cleanup();

	void SetMushroomField(MushroomField* m);
	//virtual void KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey);
	Flea *fleaActive;
protected:
	float speed;
	MushroomField * m;
	FleaManager();
	static FleaManager* FleaMan;
};

#endif _FleaManager