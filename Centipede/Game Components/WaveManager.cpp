#include "WaveManager.h"
#include "Constants.h"
#include "WaveConsts.h"
#include "InputManager.h"
#include "ScoreManager.h"
#include "AI.h"
WaveManager* WaveManager::WaveMan = NULL;
	CentipedeManager* CM;
	ScorpionManager* SM;
	FleaManager* FM;
	SpiderManager* SpM;
	
WaveManager::WaveManager()
{
	CM = CentipedeManager::GetInstance();
	SM = ScorpionManager::GetInstance();
	FM = FleaManager::GetInstance();
	SpM = SpiderManager::GetInstance();
	SB = new SoundBox();
	setWaves();
	counter = 8;
	waveLock=false;
}

void WaveManager::makeKeyboard()
{
	k = new Keyboard();
}

void WaveManager::newTimer()
{
	SpawnTimers = new Timers;
}

WaveManager* WaveManager::GetInstance()
{
	if (WaveMan== NULL) {
		WaveMan = new WaveManager();
	}
	return WaveMan;
}

void WaveManager::Cleanup()
{
	CM->Cleanup();
}

void WaveManager::Update()
{
	if (m->spawnFlea)
		FM->createFlea();
}

void WaveManager::spawnScorpion()
{
	SM->createScorpion();
}

void WaveManager::spawnSpider()
{
	SpM->createSpider();
	SB->SpidSnd.setVolume(25);
}

void WaveManager::spawnFlea()
{
	FM->createFlea();
}

void WaveManager::setSpiderTimer()
{
	SpawnTimers->setTimer0(currentWave.SpiderTime);
	SB->SpidSnd.setVolume(0);
}

void WaveManager::setScorpionTimer()
{
	if (currentWave.ScorpionTime>0)
		SpawnTimers->setTimer1(currentWave.ScorpionTime);
}

void WaveManager::startWave()
{
	if (waveLock)
		return;
	if (!waves.empty())
	{
		SM->cleanup();
		SpM->cleanup();
		FM->cleanup();
		currentWave = waves.front();
		waves.pop();
		CM->createCentipede(currentWave.CentipedeLength);
		setSpiderTimer();
		setScorpionTimer();
	}
	else
	{
		setWaves();
		startWave();
	}
}

void WaveManager::restartWave()
{
	if (ScoreManager::GetInstance()->returnLives()<0)
	{
		ScoreManager::GetInstance()->Attract();
		InputManager::GetInstance()->setBlaster();
		m->attractorFix();
		new AI();
		return;
	}
	//repair mushrooms - animated??
	waveLock = true;
	CM->clearCentipede();
	SM->cleanup();
	SpM->cleanup();
	FM->cleanup();
	//InputManager::GetInstance()->destroyBlaster();
	m->refreshField();
	CM->createCentipede(currentWave.CentipedeLength);
	setSpiderTimer();
	setScorpionTimer();
	waveLock = false;
	InputManager::GetInstance()->setBlaster();
	
}

void WaveManager::SetMushroomField(MushroomField* f)
{
	m=f;
	CM->SetMushroomField(f);
	SM->SetMushroomField(f);
	FM->SetMushroomField(f);
//	SpM->SetMushroomField(f);
}

void WaveManager::Destroy()
{
	//DeregisterInput();
	
}