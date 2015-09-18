
#include "Timers.h"
#include "WaveManager.h"
Timers::Timers()
{
	

}


void Timers::Update()
{
	WaveManager::GetInstance()->Update();
}

void Timers::Draw()
{
	
}

void Timers::setTimer0(float t)
{
	SetAlarm(0, t);
}

void Timers::setTimer1(float t)
{
	SetAlarm(1, t);
}

void Timers::Alarm0()
{
	WaveManager::GetInstance()->spawnSpider();
}

void Timers::Alarm1()
{
	WaveManager::GetInstance()->spawnScorpion();
}


void Timers::Destroy()
{
	
}
