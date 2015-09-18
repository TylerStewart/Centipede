#ifndef _WAVE_CONSTS
#define _WAVE_CONSTS

#include <queue>
#include <vector>
#include <list>
#include "Wave.h"

queue <Wave> waves;

/*
Time variables represent seconds between spawn.  0 indicates that it will not spawn.  
*/
void setWaves()
{

	//Wave 1
	Wave wave1;
	wave1.CentipedeLength = 12;
	wave1.CentipedeHeads = 1;
	wave1.CentipedeSpeed = 100;
	wave1.ScorpionTime = 0;
	//wave1.ScorpionSpeed = 0;
	wave1.SpiderTime = 8;
	wave1.SpiderSpeed = 2;
	waves.push(wave1);
	//Wave2
	Wave wave2;
	wave2.CentipedeLength = 12;
	wave2.CentipedeHeads = 2;
	wave2.CentipedeSpeed = 120;
	wave2.ScorpionTime = 15;
	//wave2.ScorpionSpeed = 0;
	wave2.SpiderTime = 5;
	wave2.SpiderSpeed = 4;
	waves.push(wave2);
	//Wave3
	Wave wave3;
	wave3.CentipedeLength = 12;
	wave3.CentipedeHeads = 3;
	wave3.CentipedeSpeed = 160;
	wave3.ScorpionTime = 0;
	//wave3.ScorpionSpeed = 0;
	wave3.SpiderTime = 3;
	wave3.SpiderSpeed = 6;
	waves.push(wave3);
}

#endif _WAVE_CONSTS