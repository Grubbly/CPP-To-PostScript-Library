/*-------------------------------------------------------
 | CS 372: Software Construction                        |
 | Project 2: C++ To PostScript Library                 |
 | Date: 3/20/18                                        |
 | File: polygon.h                                      |
 | Written By: Collin Lasley & Tristan Van Cise         |
 | Description: Header Of Polygon Class                 |
 ------------------------------------------------------*/

#include <string>

#include "shape.h"

#ifndef POLYGON_H
#define POLYGON_H

class Polygon : PostLib::Shape
{
public:
	Polygon();
	Polygon(double numSides, double sideLength);
protected:

};

#endif // !POLYGON_H
