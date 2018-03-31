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
	const char* blankPolygonPSCode = "/renderPolygon {\n\
	2 dict begin\n\
		/drawPosX %d def\n\
		/drawPosY %d def\n\
		\n";

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
