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

namespace PostLib {

	class Polygon : public PostLib::Shape
	{
	public:
		Polygon();
		Polygon(unsigned int numSides, double sideLength);

		virtual int		   PostScriptRepresentation() override;

		int				   getNumSides() const;
		double			   getSideLength() const;

	private:
		int _numSides;
		double _sideLength;

		unsigned int	  calculateRegularAngle(unsigned int numSides);
	};

}

#endif // !POLYGON_H
