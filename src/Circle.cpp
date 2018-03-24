/*-------------------------------------------------------
 | CS 372: Software Construction                        |
 | Project 2: C++ To PostScript Library                 |
 | Date: 3/20/18                                        |
 | File: circle.cpp                                     |
 | Written By: Collin Lasley & Tristan Van Cise         |
 | Description: Implementation Of Circle Class          |
 ------------------------------------------------------*/


#include "circle.h"

PostLib::Circle::Circle()
{
    PrimitiveRectangle newBoundBox;
    PostScriptPoint    centerPoint;
    
    this->radius            = 2;
    newBoundBox.origin.x    = (int)(centerPoint.x - radius);
    newBoundBox.origin.y    = (int)(centerPoint.y - radius);
    newBoundBox.size.width  = 2*radius;
    newBoundBox.size.height = 2*radius;
    
    Shape(centerPoint, newBoundBox);
}

PostLib::Circle::Circle(PostLib::PostScriptPoint centerPoint, unsigned int radius)
{
    PrimitiveRectangle newBoundBox;
    
    this->radius            = radius;
    newBoundBox.origin.x    = (int)(centerPoint.x - radius);
    newBoundBox.origin.y    = (int)(centerPoint.y - radius);
    newBoundBox.size.width  = 2*radius;
    newBoundBox.size.height = 2*radius;
    
    this->boundingBox = newBoundBox;
    this->centerPoint = centerPoint;
}
