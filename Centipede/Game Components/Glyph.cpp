// Glyph
// Andre Berthiaume, May 2013

#include "Glyph.h"
#include "SpriteSheet.h"
#include "TEAL\ResourceManager.h"

Glyph::Glyph()
{
	sprsheet = 0;
	cellIndex = 0; 
	position = sf::Vector2f(0,0);
}

Glyph::Glyph( SpriteSheet* sheet, int cellInd, sf::Vector2f pos )
{
	sprsheet = sheet;
	position = pos;
	cellIndex = cellInd;
}

void Glyph::Draw()
{
	sprsheet->Draw(cellIndex, position);
}
