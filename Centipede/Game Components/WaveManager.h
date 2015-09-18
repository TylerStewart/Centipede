#ifndef _WaveManager
#define _WaveManager

#include "Mushroom.h"
#include "MushroomField.h"
#include "TEAL\CommonElements.h"
#include "CentipedeManager.h"
#include "ScorpionManager.h"
#include "FleaManager.h"
#include "SpiderManager.h"
#include "Timers.h"
#include "Soundbox.h"
#include "Wave.h"
#include "Keyboard.h"
//Forward declarations

class WaveManager//: public GameObject
{
public:
	static WaveManager* GetInstance();


	void Initialize(); 
	
	virtual void Update();
	virtual void Destroy();
	void startWave();//for beginning a new wave
	void restartWave();//for restarting same wave after player death
	void setSpiderTimer();
	void setScorpionTimer();
	void spawnScorpion();
	void spawnSpider();
	void spawnFlea();
	void newTimer();
	void Alarm0();
	void Alarm1();
	void Cleanup();
	void makeKeyboard();
	void SetMushroomField(MushroomField* m);
	Timers* SpawnTimers;
	MushroomField * m;
	SoundBox* SB;
	Wave currentWave;
	bool waveLock;

protected:
	Keyboard* k;
	WaveManager();
	static WaveManager* WaveMan;
	
	int counter;
};

#endif _WaveManager