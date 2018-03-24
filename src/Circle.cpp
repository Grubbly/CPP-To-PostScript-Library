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
#include <regex>

std::string strSearchReplace(std::string const &inStr, std::string const &searchStr, std::string const &replaceStr)
{
    return std::regex_replace(inStr, std::regex(searchStr), replaceStr);
}

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

int PostLib::Circle::PostScriptRepresentation(void)
{
    //PostLib::Shape::PostScriptCode
    std::string psCode = "/renderCenterDots {\
    2 dict begin\
        /drawPosX %%DRAWPOSX%% def\
        /drawPosY %%DRAWPOSY%% def\
        \
        drawPosX drawPosY %%RADIUS%% 0 360 arc fill\
        \
        end\
    } def";
    
    strSearchReplace(psCode, "%%DRAWPOSX%%", std::to_string(this->center().x));
    strSearchReplace(psCode, "%%DRAWPOSY%%", std::to_string(this->center().y));
    strSearchReplace(psCode, "%%RADIUS%%"  , std::to_string(this->radius));
    std::cout<<psCode<<std::endl;
    
    return 0;
}
