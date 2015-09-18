#include "ScoreManager.h"
#include "Constants.h"

ScoreManager* ScoreManager::ScoreMan = NULL;

ScoreManager::ScoreManager()
{
	player = 0;
	score[0] = 0;
	score[1] = 0;
	score[2] = 0;
	score[3] = 0;
	lives[0] = 2;
	lives[1] = 2;
	lives[2] = 2;
	//hud = new HUD();
}

ScoreManager* ScoreManager::GetInstance()
{
	if (ScoreMan== NULL) {
		ScoreMan = new ScoreManager();
	}
	return ScoreMan;
}

void ScoreManager::createHud()
{
	hud = NULL;
	hud = new HUD();
}

int ScoreManager::returnScore()
{
	return score[player];
}

void ScoreManager::addMushroom()
{
	score[player]+=1;
	hud->updateScore(player);
	checkHigh();
}

void ScoreManager::addCentipedeHead()
{
	score[player]+=100;
	hud->updateScore(player);
	checkHigh();
}

void ScoreManager::addCentipedeSeg()
{
	score[player]+=10;
	hud->updateScore(player);
	checkHigh();
}

void ScoreManager::addScorpion()
{
	score[player]+=2000;
	 hud->updateScore(player);
	checkHigh();
}

void ScoreManager::addFlea()
{
	score[player]+=200;
	 hud->updateScore(player);
	 checkHigh();
}

void ScoreManager::addSpider(int dist)
{
	switch (dist)
	{
		case 0:
			score[player]+=300;
		break;
		case 1:
			score[player]+=600;
		break;
		case 2:
			score[player]+=900;
		break;
	}
	 hud->updateScore(player);
	 checkHigh();
}

void ScoreManager::checkHigh()
{
	if (score[player]>score[3])
	{
		score[3]=score[player];
		hud->updateScore(3);
	}
}

void ScoreManager::loseLife()
{
	if (player = 0)
		return;
	lives[player]--;
	hud->updateLives(player);
}

int ScoreManager::returnLives()
{
	return lives[player];
}

void ScoreManager::Play()
{
	setPlayer(1);
	hud->hideStartText();
}

int ScoreManager::returnHighScore()
{
	return (score[3]);
}
void ScoreManager::Attract()
{
	hud->showStartText();
	lives[player]=2;
	score[player] = 0;
	hud->updateScore(player);
	setPlayer(0);
	lives[player] = 2;
}

void ScoreManager::setPlayer(int p )
{
	//1,  2, or 0
	player = p;
}
