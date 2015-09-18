
#include "TEAL\CommonElements.h"
#include "PlayerOneScene.h"
#include "AttractScene.h"
#include "Blaster.h"
#include "MushroomField.h"
#include "Mushroom.h"
#include "Shot.h"
#include "Constants.h"
#include "InputManager.h"
#include "Keyboard.h"
#include "WaveManager.h"
#include "ScoreManager.h"
#include "AI.h"
void AttractScene::Initialize()
{
	WindowManager::SetBackgroundColor( sf::Color(0,0,0,255) );
	InputManager* i = InputManager::GetInstance();
	MushroomField* m = new MushroomField;
	Blaster * b = new Blaster();
	i->setBlaster();
	new AI();
	WaveManager* WM;
	ScoreManager* SM;
	SM = ScoreManager::GetInstance();
	SM->setPlayer(0);
	WM = WaveManager::GetInstance();
	WM->SetMushroomField(m);
	WM->startWave();
	CollisionTestPair<Shot,Mushroom>();
	CollisionTestPair<Shot,CentipedeHead>();
	CollisionTestPair<Shot,CentipedeSegment>();
	CollisionTestPair<Blaster,Mushroom>();
	CollisionTestPair<Scorpion, Mushroom>();
	CollisionTestPair<Scorpion, Shot>();
	CollisionTestPair<Flea, Shot>();
	CollisionTestPair<Spider, Shot>();
};