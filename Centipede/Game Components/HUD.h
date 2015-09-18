// HUD
// Andre Berthiaume, May 2013

#ifndef _HUD
#define _HUD

#include "TEAL/CommonElements.h"
#include <list>
#include "CentFont.h"


class HUD : public GameObject
{
public:
	HUD();
	void updateScore(int player);
	virtual void Draw();
	void updateLives(int player);
	void showStartText();
	void hideStartText();
private:
	CentFont font;	// Obviously, pick one or the other for a demo
	//KeysFont myfont;
	std::list<Glyph> symbols1;
	std::list<Glyph> symbols2;
	std::list<Glyph> lives1;
	std::list<Glyph> lives2;
	std::list<Glyph> symbolshigh;
	std::list<Glyph> symbolsStart;
	std::list<Glyph> symbolsGameOver;
	sf::Vector2f nextpos;
};


#endif _HUD