/*-------------------------------------------------------
 | CS 372: Software Construction                        |
 | Project 2: C++ To PostScript Library                 |
 | Date: 3/20/18                                        |
 | File: circle.cpp                                     |
 | Written By: Collin Lasley & Tristan Van Cise         |
 | Description: Implementation Of Circle Class          |
 ------------------------------------------------------*/


#include "circle.h"
#include <iostream>
#include <cstring>

PostLib::Circle::Circle() : Shape({ 50,50 }, { {5,4} , {4,4} }), radius(2)
{
    /*PrimitiveRectangle newBoundBox;
    PostScriptPoint    centerPoint;
    
    centerPoint.x     = 50;
    centerPoint.y     = 50;
    this->radius            = 2;
    newBoundBox.origin.x    = (int)(centerPoint.x - radius);
    newBoundBox.origin.y    = (int)(centerPoint.y - radius);
    newBoundBox.size.width  = 2*radius;
    newBoundBox.size.height = 2*radius;
    
    Shape(centerPoint, newBoundBox);*/
}

PostLib::Circle::Circle(PostLib::PostScriptPoint centerPoint, unsigned int radius) : Shape(centerPoint, { {(centerPoint.x - (int)radius), (centerPoint.y - (int)radius)}, {2* (double)radius, 2* (double)radius} }), radius((int)radius)
{
    /*PrimitiveRectangle newBoundBox;
    
    this->radius            = radius;
    newBoundBox.origin.x    = (int)(centerPoint.x - radius);
    newBoundBox.origin.y    = (int)(centerPoint.y - radius);
    newBoundBox.size.width  = 2*radius;
    newBoundBox.size.height = 2*radius;
    
    this->boundingBox = newBoundBox;
    this->centerPoint = centerPoint;*/
}

std::string PostLib::Circle::PostScriptRepresentation(void)
{
    char* replacedCirclePSCode;
    const char* blankCirclePSCode = "/renderCircle {\n\
    2 dict begin\n\
        /drawPosX %f def\n\
        /drawPosY %f def\n\
        \n\
        drawPosX drawPosY %d 0 360 arc fill\n\
        \n\
        end\n\
    } def\n\n\n\n";
    
    replacedCirclePSCode = (char *)malloc(strlen(blankCirclePSCode));
    sprintf(replacedCirclePSCode, blankCirclePSCode, (float)this->centerPoint.x, (float)this->centerPoint.y, this->radius);
    this->PostScriptCode = std::string(replacedCirclePSCode);
    
    //free(replacedCirclePSCode);
    
    return this->PostScriptCode;
}

std::string PostLib::Circle::postScript() const
{
    return this->PostScriptCode;
}
