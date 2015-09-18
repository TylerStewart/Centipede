// HUD
// Andre Berthiaume, May 2013

#include "HUD.h"
#include "ScoreManager.h"
const float score1X = 100;
const float lives1X = 116;
const float score2X = 448;
const float lives2X = 464;
const float scorehighX = 300;
const float centerX = 480/2;
const float centerY = 512/2;


HUD::HUD()
{

	std::string text = "0";

	nextpos = sf::Vector2f(score1X-font.CellWidth()*text.length(),0);
	for (int i=0; i < text.length(); i++)
	{
		symbols1.push_back(  font.GetGlyph(text.at(i), nextpos) );
		nextpos.x -= font.CellWidth();
	}

	nextpos = sf::Vector2f(score2X-font.CellWidth()*text.length(),0);
	for (int i=0; i < text.length(); i++)
	{
		symbols2.push_back(  font.GetGlyph(text.at(i), nextpos) );
		nextpos.x -= font.CellWidth();
	}

	nextpos= sf::Vector2f(scorehighX-font.CellWidth()*text.length(),0);
	for (int i=0; i < text.length(); i++)
	{
		symbolshigh.push_back(  font.GetGlyph(text.at(i), nextpos) );
		nextpos.x -= font.CellWidth();
	}

	text = "^^";
	nextpos= sf::Vector2f(lives1X,0);
	for (int i=0; i < text.length(); i++)
	{
		lives1.push_back(  font.GetGlyph(text.at(i), nextpos) );
		nextpos.x -= font.CellWidth();
	}
	nextpos= sf::Vector2f(lives2X,0);
	for (int i=0; i < text.length(); i++)
	{
		lives2.push_back(  font.GetGlyph(text.at(i), nextpos) );
		nextpos.x -= font.CellWidth();
	}
	text = "press 1 to play";
	nextpos= sf::Vector2f(centerX-font.CellWidth()*text.length()/2, centerY);
	for (int i=0; i < text.length(); i++)
	{
		symbolsStart.push_back(  font.GetGlyph(text.at(i), nextpos) );
		nextpos.x += font.CellWidth();
	}
	
}

void HUD::showStartText()
{
	std::string text = "press 1 to play";
	while (!symbolsStart.empty())
			symbolsStart.pop_front();
	nextpos= sf::Vector2f(centerX-font.CellWidth()*text.length()/2, centerY);
	for (int i=0; i < text.length(); i++)
	{
		symbolsStart.push_back(  font.GetGlyph(text.at(i), nextpos) );
		nextpos.x += font.CellWidth();
	}
	text = "game over";
	while (!symbolsGameOver.empty())
		symbolsGameOver.pop_front();
	nextpos= sf::Vector2f(centerX-font.CellWidth()*text.length()/2, centerY+16);
	for (int i=0; i < text.length(); i++)
	{
		symbolsGameOver.push_back(  font.GetGlyph(text.at(i), nextpos) );
		nextpos.x += font.CellWidth();
	}
}

void HUD::hideStartText()
{
	
	while (!symbolsStart.empty())
			symbolsStart.pop_front();
	while (!symbolsGameOver.empty())
			symbolsGameOver.pop_front();

}



void HUD::updateScore(int player) 
{
	if (player == 1)
	{
		std::string text = to_string(ScoreManager::GetInstance()->returnScore());

		while (!symbols1.empty())
			symbols1.pop_front();
		nextpos = sf::Vector2f(score1X-font.CellWidth()*text.length(),0);
		for (int i=0; i < text.length(); i++)
		{
			symbols1.push_back(  font.GetGlyph(text.at(i), nextpos) );
			nextpos.x += font.CellWidth();
		}
	}
	else if (player == 2)
	{
		std::string text = to_string(ScoreManager::GetInstance()->returnScore());

		while (!symbols2.empty())
			symbols2.pop_front();
		nextpos = sf::Vector2f(score2X-font.CellWidth()*text.length(),0);
		for (int i=0; i < text.length(); i++)
		{
			symbols2.push_back(  font.GetGlyph(text.at(i), nextpos) );
			nextpos.x += font.CellWidth();
		}
	}
	else if (player == 3)
	{
		std::string text = to_string(ScoreManager::GetInstance()->returnHighScore());

		while (!symbolshigh.empty())
			symbolshigh.pop_front();
		nextpos = sf::Vector2f(scorehighX-font.CellWidth()*text.length(),0);
		for (int i=0; i < text.length(); i++)
		{
			symbolshigh.push_back(  font.GetGlyph(text.at(i), nextpos) );
			nextpos.x += font.CellWidth();
		}
	}
	//nextpos.x += font.CellWidth();
}

void HUD::updateLives(int player)
{
	std::string text = "";
	if (player == 1)
	{
		while (!lives1.empty())
			lives1.pop_front();
		nextpos = sf::Vector2f(lives1X,0);
		for (int i=0; i < ScoreManager::GetInstance()->returnLives(); i++)
		{
			lives1.push_back(  font.GetGlyph('^', nextpos) );
			nextpos.x += font.CellWidth();
			
		}
	}
	else if (player == 2)
	{
		while (!lives2.empty())
			lives2.pop_front();
		nextpos = sf::Vector2f(lives2X,0);
		for (int i=0; i < ScoreManager::GetInstance()->returnLives(); i++)
		{
			lives2.push_back(  font.GetGlyph('^', nextpos) );
			nextpos.x += font.CellWidth();
		}
	}
}

void HUD::Draw()
{
	
	std::list<Glyph>::iterator it;
	for (it = symbols1.begin(); it != symbols1.end(); it++)
		it->Draw();
	for (it = symbols2.begin(); it != symbols2.end(); it++)
		it->Draw();
	for (it = symbolshigh.begin(); it != symbolshigh.end(); it++)
		it->Draw();
	for (it = lives1.begin(); it != lives1.end(); it++)
		it->Draw();
	for (it = lives2.begin(); it != lives2.end(); it++)
		it->Draw();
	for (it = symbolsStart.begin(); it != symbolsStart.end(); it++)
		it->Draw();
	for (it = symbolsGameOver.begin(); it != symbolsGameOver.end(); it++)
		it->Draw();
}