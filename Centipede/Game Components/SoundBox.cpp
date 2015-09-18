
#include "SoundBox.h"
#include "WaveManager.h"
SoundBox::SoundBox()
{
	CentSnd.setBuffer( ResourceManager::GetSound("CentSnd")  );
	CentSnd.setPitch(1);
	CentSnd.setVolume(25);
	SpidSnd.setBuffer( ResourceManager::GetSound("SpidSnd")  );
	SpidSnd.setPitch(1);
	SpidSnd.setVolume(25);
	SetAlarm(0, .25f);
	SetAlarm(1, .25f);
	
}


void SoundBox::Update()
{
	WaveManager::GetInstance()->Update();
}

void SoundBox::Draw()
{
	
}

/*void SoundBox::setTimer0(float t)
{
	SetAlarm(0, t);
}

void SoundBox::setTimer1(float t)
{
	SetAlarm(1, t);
}*/

void SoundBox::Alarm0()
{
	CentSnd.play();
	SetAlarm(0, .25f);
}

void SoundBox::Alarm1()
{
	SpidSnd.play();
	SetAlarm(1, .75f);
}


void SoundBox::Destroy()
{
	
}
