#/*-------------------------------------------------------
| CS 372: Software Construction                        |
| Project 2: C++ To PostScript Library                 |
| Date: 3/20/18                                        |
| File: Horizontal.h                                     |
| Written By: Collin Lasley & Tristan Van Cise         |
| Description: Header Of Horizontal Class                |
------------------------------------------------------*/

#include <string>
#include <vector>
#include "Shape.h"
#include <memory>

#ifndef Horizontal_H
#define Horizontal_H

namespace PostLib {

	class Horizontal : public PostLib::Shape
	{
	public:
		Horizontal();
		Horizontal(const PostLib::PostScriptPoint & centerPoint, const std::initializer_list<std::unique_ptr<Shape>> & shapeList);

		virtual std::string PostScriptRepresentation(void) override;
		std::string         postScript(void);

	private:
		std::initializer_list<std::unique_ptr<Shape>> _shapeList;
	};
}

#endif // !Horizontal_H