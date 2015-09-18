#include "TEAL\CommonElements.h"
#include "PlayerOneScene.h"
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

void PlayerOneScene::Initialize()
{
	WindowManager::SetBackgroundColor( sf::Color(0,0,0,255) );
	InputManager* i =InputManager ::GetInstance();
	MushroomField* m = new MushroomField;
	m->attractorFix();
	i->setBlaster();
	new AI();
	//new Keyboard();
	WaveManager* WM;
	ScoreManager* SM;
	SM = ScoreManager::GetInstance();
	SM->setPlayer(0);
	SM->createHud();
	WM = WaveManager::GetInstance();
	WM->newTimer();
	WM->SetMushroomField(m);
	WM->startWave();
	CollisionTestPair<Shot,Mushroom>();
	CollisionTestPair<Shot,CentipedeHead>();
	CollisionTestPair<Shot,CentipedeSegment>();
	CollisionTestPair<Blaster,Mushroom>();
	CollisionTestPair<Blaster,CentipedeHead>();
	CollisionTestPair<Blaster,CentipedeSegment>();
	CollisionTestPair<Blaster,Spider>();
	CollisionTestPair<Blaster, Flea>();
	CollisionTestPair<Scorpion, Mushroom>();
	CollisionTestPair<Scorpion, Shot>();
	CollisionTestPair<Flea, Shot>();
	CollisionTestPair<Spider, Shot>();
};