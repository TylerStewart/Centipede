#include "MushroomField.h"
#include "ScoreManager.h"


const float gridSpaceWidth = 16;

MushroomField::MushroomField()//tried to offload this all to newField but it broke things.  
{
	cnt = 0;
	spawnFlea=false;
	for (int i = 0; i<31; i++)
	{
		for (int j = 0; j<31; j++)
		{
			int r = rand() % 20;
			if (r == 1)
			{
				if (j<30)
				{
					field[i][j] = new Mushroom(sf::Vector2f(-8+i*gridSpaceWidth,gridSpaceWidth+8+j*gridSpaceWidth),this, i, j);
					if (j>21)
					cnt++;
				}
				else 
					field[i][j] = NULL;
			}
			else 
				field[i][j] = NULL;
		}
	}
}

void MushroomField::attractorFix()
{
	for (int i = 7; i<24; i++)
	{
		if (field[i][15] )
			field[i][15]->MarkForDestroy();
		if (field[i][16] )
			field[i][16]->MarkForDestroy();
		field[i][15] = NULL;
		field[i][16] = NULL;
					
	}
}

void MushroomField::destroyMushroomAt(int x, int y)
{
	ScoreManager::GetInstance()->addMushroom();
	field[x][y] = NULL;
	if (y>21)
		cnt--;	
	if (cnt<5)
		spawnFlea = true;
}

void MushroomField::Update()
{

}

void MushroomField::addMushroomAt(int x, int y)
{
	if (y>=31)
		return;
	if (!field[x][y])
	{
		field[x][y] = new Mushroom(sf::Vector2f(x*gridSpaceWidth+gridSpaceWidth/2,gridSpaceWidth+gridSpaceWidth/2+y*gridSpaceWidth), this, x,y);
		if (y>21)
			cnt++;
	}
	if (cnt>=5)
		spawnFlea=false;

}

void MushroomField::refreshField()
{
	int tmp = 0;
	for (int i = 30; i>=0; i--)
	{
		for (int j = 30; j>=0; j--)
		{
			if (field[i][j])
			{
				if (field[i][j]->damage>0)
				{
					tmp++;
					if (tmp>=2)
					{
						tmp=0;
						ScoreManager::GetInstance()->addMushroom();
					}
					field[i][j]->Refresh();
					SceneManager::ProcessOneFrame();
					SceneManager::ProcessOneFrame();
					SceneManager::ProcessOneFrame();
					SceneManager::ProcessOneFrame();
					SceneManager::ProcessOneFrame();
					SceneManager::ProcessOneFrame();
				}
			}
		}
	}
}

void MushroomField::newField()//duplicate code,but calling this instead of doing it in the creation section stops it from breaking
{
	cnt=0;
	for (int i = 0; i<31; i++)
	{
		for (int j = 0; j<31; j++)
		{
			if (field[i][j])
				field[i][j]->MarkForDestroy();
			field[i][j]=NULL;

		}
	}

	for (int i = 0; i<31; i++)
	{
		for (int j = 0; j<31; j++)
		{
			int r = rand() % 20;
			if (r == 1)
			{
				if (j<30)
				{
					field[i][j] = new Mushroom(sf::Vector2f(-8+i*gridSpaceWidth,gridSpaceWidth+8+j*gridSpaceWidth),this, i, j);
					if (j>21)
					cnt++;
				}
				else 
					field[i][j] = NULL;
			}
			else 
				field[i][j] = NULL;
		}
	}
}

void MushroomField::Draw()
{
	//WindowManager::MainWindow.draw(MainSprite);
}

void MushroomField::Destroy()
{
	DeregisterCollision<MushroomField>( *this );
}
