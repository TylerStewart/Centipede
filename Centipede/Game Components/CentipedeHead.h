
#ifndef _CentipedeHead
#define _CentipedeHead

#include "CentipedeNode.h"
#include "TEAL\CommonElements.h"
#include "MushroomField.h"
#include "Kill.h"
#include <queue>
#include <vector>
#include <list>
//#include "CentipedeSegment.h"

using namespace std;

const float fieldMinY=24;//this is the top border
const float fieldMinX=8;//center of extreme left grid space.  
const float fieldMaxY=512-16;//-8 because its half the width of a grid space
const float fieldMaxX=480-8;//same here



class CentipedeHead: public CentipedeNode
{
public:
	CentipedeHead(sf::Vector2f p, float s);
	void Update();
	void Draw();
	void Destroy();
	//virtual void KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey);
	void checkForTurn();
	void initialize();
	void Collision( GameObject *go){};
	void Collision(Shot* other);
	void constructQueue();
	sf::Vector2f getPos();
	void setDirAndRot(float r, float ud, float lr);

private:
	float SPEED;
	
	int leftRightLast;
	bool turning;
	sf::Vector2f direction;
	float yLock;
	float offset;
	bool diving;
	sf::Vector2f tmp;
	
	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;

	//MushroomField* Field;
};



#endif _CentipedeHead