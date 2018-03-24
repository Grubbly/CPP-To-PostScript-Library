/*-------------------------------------------------------
 | CS 372: Software Construction                        |
 | Project 2: C++ To PostScript Library                 |
 | Date: 3/20/18                                        |
 | File: shape.cpp                                      |
 | Written By: Collin Lasley & Tristan Van Cise         |
 | Description: Implementation Of Shape Class           |
 ------------------------------------------------------*/


#include "Shape.h"

using PostLib::PostScriptPoint;
using PostLib::PrimitiveRectangle;

PostScriptPoint PostLib::Shape::center(void) const
{
    return this->centerPoint;
}

PrimitiveRectangle PostLib::Shape::bounds(void) const
{
    return this->boundingBox;
}

void PostLib::Shape::setCenter(const PostScriptPoint& newCenter)
{
    this->centerPoint = newCenter;
}

void PostLib::Shape::setBounds(const PrimitiveRectangle &newBounds)
{
    this->boundingBox = newBounds;
}
