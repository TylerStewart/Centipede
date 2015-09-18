#ifndef _SpiderManager
#define _SpiderManager

#include "Spider.h"
#include "Mushroom.h"
#include "MushroomField.h"
#include "TEAL\CommonElements.h"

//Forward declarations

class SpiderManager
{
public:
	static SpiderManager* GetInstance();
	
	void Initialize(); 
	void createSpider();
	virtual void Update();
	virtual void Destroy();
	void cleanup();
	//void SetMushroomField(MushroomField* m);
	//virtual void KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey);
	Spider* spiderActive;
protected:
	float speed;
	MushroomField * m;
	SpiderManager();
	static SpiderManager* SpiderMan;
	
};

#endif _SpiderManager