/*-------------------------------------------------------
 | CS 372: Software Construction                        |
 | Project 2: C++ To PostScript Library                 |
 | Date: 3/20/18                                        |
 | File: shape.h                                        |
 | Written By: Collin Lasley & Tristan Van Cise         |
 | Description: Implementation Of Rotated Shapes Class  |
 ------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#include "Rotated.h"

PostLib::RotatedShape::RotatedShape(PostLib::Shape *passedShape, RotationAngleType passedAngle)
{
    this->theShape = passedShape;
    rotationAngle  = passedAngle;
    PostScriptCode = "";
}

std::string PostLib::RotatedShape::PostScriptRepresentation(void)
{
    std::string   workingCodeStr;
    std::string   plainShapePS;
    std::string   plainFunctionName;
    const char *aStr = "\n\ngsave\n\
                        %lf %lf translate\n\
                        %lf rotate\n\
                        %lf %lf translate\n\
                        %s\n\
                        stroke";
    char *replacedStr = (char*)malloc(strlen(aStr));
    
    plainShapePS = theShape->PostScriptRepresentation();
    plainFunctionName = plainFunctionName.substr(1, plainShapePS.find(" "));
    
    workingCodeStr.append(plainShapePS);
    workingCodeStr.append("\n\n");
    sprintf(replacedStr, aStr, theShape->centerPoint.x, theShape->centerPoint.y, this->rotationAngle, (-1*theShape->centerPoint.x), (-1*theShape->centerPoint.y), plainFunctionName.c_str());
    
    workingCodeStr.append(replacedStr);
    this->PostScriptCode = workingCodeStr;
    //free(replacedStr);
    
    return workingCodeStr;
}

std::string PostLib::RotatedShape::postScript(void)
{
    if (this->PostScriptCode == "")
        this->PostScriptRepresentation();
    
    return this->PostScriptCode;
}

