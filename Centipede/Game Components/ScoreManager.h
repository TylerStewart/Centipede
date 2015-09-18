#ifndef _ScoreManager
#define _ScoreManager

#include "Mushroom.h"
#include "MushroomField.h"
#include "TEAL\CommonElements.h"
#include "CentipedeManager.h"
#include "ScorpionManager.h"
#include "FleaManager.h"
#include "SpiderManager.h"
#include "HUD.h"
//Forward declarations

class ScoreManager: public GameObject
{
public:
	static ScoreManager* GetInstance();
	
	void Initialize(); 
	void startScore();
	int returnScore();
	void setPlayer(int p);
	void addSpider(int dist);
	void addCentipedeHead();
	void addCentipedeSeg();
	void addScorpion();
	void addFlea();
	void addSpider();
	void addMushroom();
	void createHud();
	void loseLife();
	int returnLives();
	void Attract();
	void Play();
	int returnHighScore();
	void checkHigh();
protected:
	ScoreManager();
	static ScoreManager* ScoreMan;
	int score[4];
	int player;
	int lives[3];
	HUD* hud;
};

#endif _ScoreManager