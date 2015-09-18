// LoadAllResources.cpp
// Andre Berthiaume, June 2012
//
// The user fills the method with all resources that need loading

#include "ResourceManager.h"
#include "../FirstScene.h"
#include "../PlayerOneScene.h"
#include "../AttractScene.h"

void ResourceManager::LoadAllResources()
{
	SetStartScene( new FirstScene() );

	AddFont("MyDefaultFont", "../Game Components/TEAL/Arial.ttf");

	AddTexture("Blaster", "Sprites/blaster.png");
	AddTexture("Shot", "Sprites/bullet.png");

	AddTexture("Mushroom", "Sprites/mushroom.png");
	AddTexture("PoisonedMushroom", "Sprites/poisoned-mushroom.png");

	AddTexture("CentipedeHead", "Sprites/centipede_head.png");
	AddTexture("CentipedeSegment", "Sprites/centipede_segment.png");
	AddTexture("Scorpion", "Sprites/scorpion.png");
	AddTexture("Flea", "Sprites/flea.png");
	AddTexture("Spider","Sprites/spider.png");
	AddTexture("Death", "Sprites/death.png");
	AddTexture("SpiderScore", "Sprites/spiderScores.png");
	AddTexture("Alphabet", "Sprites/FONT1.bmp");
	AddSound("FireSnd", "Sounds/fire1.wav");
	AddSound("FleaSnd", "Sounds/flea_new.wav");
	AddSound("KillSnd", "Sounds/kill.wav");
	AddSound("CentSnd", "Sounds/newBeat.wav");
	AddSound("SpidSnd", "Sounds/spider_new.wav");

	
}

