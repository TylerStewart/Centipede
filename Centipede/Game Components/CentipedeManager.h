
#ifndef _CentipedeManager
#define _CentipedeManager

#include "CentipedeHead.h"
#include "CentipedeSegment.h"
#include "CentipedeNode.h"
#include "TEAL\CommonElements.h"
#include "MushroomField.h"
#include <list>
#include <stack>

using namespace std;
//make this a singleton

//Forward declarations


class CentipedeManager //CentipedeManager acts as both the manager and the recycling factory for centipede segments and heads
{
public:

	static CentipedeManager* GetInstance();
	~CentipedeManager();
	void Initialize(); 
	void createCentipede(int segs);
	virtual void Update();
	
	void SetMushroomField(MushroomField* m);
	void createHead(sf::Vector2f pos, CentipedeNode* n, float r, float ud, float lr);
	virtual void KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey);
	void Cleanup();
	void clearCentipede();
	void testHead();
	void addCentipede();
	void subCentipede();
	list <CentipedeNode*> centipedeNodes;

	static CentipedeSegment* CreateSegment(sf::Vector2f pos);
	static void RecycleSegment(GameObject* b);  // Arguments must be GameObject since it will be called by the base class
	static CentipedeHead* CreateHead(sf::Vector2f pos);
	static void RecycleHead(GameObject* b);  // Arguments must be GameObject since it will be called by the base class
	MushroomField * m;
private:
	static std::stack <CentipedeSegment*> segs;
	static std::stack <CentipedeHead*> heads;
	int numCentipedes;
	float speed;
	
	CentipedeManager();
	static CentipedeManager* CentMan;
	
};

#endif _CentipedeManager