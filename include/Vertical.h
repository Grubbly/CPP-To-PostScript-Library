#/*-------------------------------------------------------
| CS 372: Software Construction                        |
| Project 2: C++ To PostScript Library                 |
| Date: 3/20/18                                        |
| File: Vertical.h                                     |
| Written By: Collin Lasley & Tristan Van Cise         |
| Description: Header Of Vertical Class                |
------------------------------------------------------*/

#include <string>
#include <vector>
#include "Shape.h"
#include <memory>

#ifndef Vertical_H
#define Vertical_H

namespace PostLib {

	class Vertical : public PostLib::Shape
	{
	public:
		Vertical();
		Vertical(const PostLib::PostScriptPoint & centerPoint, const std::initializer_list<std::unique_ptr<Shape>> & shapeList);

		virtual std::string PostScriptRepresentation(void) override;
		std::string         postScript(void) override;

	private:
		std::initializer_list<std::unique_ptr<Shape>> _shapeList;
	};
}

#endif // !Vertical_H
