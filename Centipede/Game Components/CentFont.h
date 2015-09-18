// CentFont
// Andre Berthiaume, May 2013

#ifndef _CentFont
#define _CentFont

#include "SpriteSheet.h"

class CentFont : public SpriteSheet
{
public:
	CentFont();

private:
	virtual int CharToIndex( char& c ); 
};


#endif _CentFont