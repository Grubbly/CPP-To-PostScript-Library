/*-------------------------------------------------------
 | CS 372: Software Construction                        |
 | Project 2: C++ To PostScript Library                 |
 | Date: 3/20/18                                        |
 | File: polygon.cpp                                    |
 | Written By: Collin Lasley & Tristan Van Cise         |
 | Description: Implementation Of Polygon Class         |
 ------------------------------------------------------*/


#include "Polygon.h"

PostLib::Polygon::Polygon() : Shape({ 50,50 }, { { 48,48 } ,{ 4,4 } }), _numSides(3), _sideLength(1)
{
}

PostLib::Polygon::Polygon(unsigned int numSides, double sideLength) : Shape({ 50,50 }, { { 48,48 } ,{ 4,4 } }), _numSides((int)numSides), _sideLength(sideLength)
{
}

int PostLib::Polygon::PostScriptRepresentation()
{
	this->PostScriptCode = "/ngon { %Parameter order: xPosOrigin, yPosOrigin, sides, sideLen\n\
		newpath\n\n\
		/sideLen 				exch def\n\
		/sides 					exch def\n\
		/yPosOrigin 			exch def\n\
		/xPosOrigin 			exch def\n\
		/regularAngle 360 sides div def\n\n\
		xPosOrigin yPosOrigin 	moveto\n\
		sideLen sideLen 	  	scale\n\
		1 72 				  	div setlinewidth % Counterbalances the scaling to prevent fat lines\n\n\
		1 1 sides{\n\
		/vertex exch def\n\
		/theta vertex regularAngle mul def\n\
		theta cos theta sin rlineto\n\
		} for\n\
		closepath\n\n\
	} def";

	return 0;
}

int PostLib::Polygon::getNumSides() const
{
	return _numSides;
}

double PostLib::Polygon::getSideLength() const
{
	return _sideLength;
}

unsigned int PostLib::Polygon::calculateRegularAngle(unsigned int numSides)
{
	return ((numSides - 2) * 180) / numSides;
}
