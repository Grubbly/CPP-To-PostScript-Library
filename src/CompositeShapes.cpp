/*-------------------------------------------------------
 | CS 372: Software Construction                        |
 | Homework 5: Template Design Pattern                  |
 | Date: 4/24/18                                        |
 | File: CompositeShapes.cpp                            |
 | Written By: Collin Lasley                            |
 | Description: Base class for composite-type shapes    |
 ------------------------------------------------------*/

#include <string>

#include "CompositeShapes.h"

PostLib::CompositeShape::CompositeShape()
{
    
}

PostLib::CompositeShape::CompositeShape(const PostLib::PostScriptPoint &centerPoint, const std::initializer_list<std::unique_ptr<Shape>> &shapeList) : Shape(centerPoint, { { 0,0 } ,{ 0,0 } }), _shapeList(shapeList)
{
    
}

std::string PostLib::CompositeShape::PostScriptRepresentation(void)
{
    return "/ngon { %Parameter order: xPosOrigin, yPosOrigin, sides, sideLen\n\
    newpath\n\n\
    /sideLen 				exch def\n\
    /sides 					exch def\n\
    /yPosOrigin 			exch def\n\
    /xPosOrigin 			exch def\n\
    /regularAngle 360 sides div def\n\n\
    xPosOrigin yPosOrigin 	moveto\n\
    sideLen sideLen 	  	scale\n\
    1 sideLen inch		  	div setlinewidth % Counterbalances the scaling to prevent fat lines\n\n\
    1 1 sides{\n\
    /vertex exch def\n\
    /theta vertex regularAngle mul def\n\
    theta cos theta sin rlineto\n\
    } for\n\
    closepath\n\n\
    } def";
}

std::string PostLib::CompositeShape::postScript(void)
{
    std::string ngonCalls = "";
    
    for (const auto & item : _shapeList) {
        ngonCalls += "gsave\n";
        ngonCalls += item->postScript();
        ngonCalls += "stroke\ngrestore\n";
    }
    ngonCalls += "\nshowpage\n";
    
    return ngonCalls;
}
