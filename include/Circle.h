/*-------------------------------------------------------
 | CS 372: Software Construction                        |
 | Project 2: C++ To PostScript Library                 |
 | Date: 3/20/18                                        |
 | File: circle.h                                       |
 | Written By: Collin Lasley & Tristan Van Cise         |
 | Description: Header Of Circle Class                  |
 ------------------------------------------------------*/

#include <string>

#include "shape.h"

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle : public PostLib::Shape
{
public:

private:
    unsigned int radius;
};

#endif // !CIRCLE_H
