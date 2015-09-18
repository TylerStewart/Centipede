
#ifndef _ScorpionManager
#define _ScorpionManager

#include "Scorpion.h"
#include "Mushroom.h"
#include "MushroomField.h"
#include "TEAL\CommonElements.h"

//Forward declarations

class ScorpionManager
{
public:
	static ScorpionManager* GetInstance();
	Scorpion *scorpionActive;
	void Initialize(); 
	void createScorpion();
	void cleanup();
	void SetMushroomField(MushroomField* m);
	//virtual void KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey);
	
protected:
	float speed;
	MushroomField * m;
	ScorpionManager();
	static ScorpionManager* ScorpMan;
};

#endif _ScorpionManager