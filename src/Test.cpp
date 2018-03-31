/*-------------------------------------------------------
 | CS 372: Software Construction                        |
 | Project 2: C++ To PostScript Library                 |
 | Date: 3/20/18                                        |
 | File: test.cpp                                       |
 | Written By: Collin Lasley & Tristan Van Cise         |
 | Description: Unit Tests For Library, Using Catch     |
 ------------------------------------------------------*/

#define CATCH_CONFIG_MAIN


#include "catch.hpp"
#include <iostream>
#include <fstream>
#include <string>

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"

static std::string psCommands;

using namespace PostLib;

#define OUTPUT_FILE 1

TEST_CASE("Shape Accessors", "[SHAPE]")
{
    PostLib::Shape              aShape;
    PostLib::PrimitiveRectangle aRect;
    PostLib::PostScriptPoint    aPoint;
    
    aPoint = (PostLib::PostScriptPoint){500, 500};
    aRect = (PostLib::PrimitiveRectangle){aPoint, 200, 200};
    
    aShape.setCenter(aPoint);
    aShape.setBounds(aRect);
    
    REQUIRE(aShape.bounds().origin.x == aPoint.x);
    REQUIRE(aShape.bounds().origin.y == aPoint.y);
    
    REQUIRE(aShape.bounds().size.width == aRect.size.width);
    REQUIRE(aShape.bounds().size.height == aRect.size.height);
}

TEST_CASE("Circle Construction", "[CIRCLE]")
{
    PostLib::Circle             aCircle;
    PostLib::PrimitiveRectangle aRect;
    PostLib::PostScriptPoint    aPoint;
    
    aPoint = (PostLib::PostScriptPoint){500, 500};
    
    aCircle = Circle(aPoint, 12);
    
    REQUIRE(aCircle.bounds().origin.x == aPoint.x - 12);
    REQUIRE(aCircle.bounds().origin.y == aPoint.y - 12);
}

TEST_CASE("Circle PostScript Conversion", "[CIRCLE]")
{
    PostLib::Circle             aCircle;
    PostLib::PrimitiveRectangle aRect;
    PostLib::PostScriptPoint    aPoint;
    
    aPoint = (PostLib::PostScriptPoint){72, 72};
    
    aCircle = Circle(aPoint, 12);
    
    aCircle.PostScriptRepresentation();
    psCommands.append(aCircle.postScript());
}

TEST_CASE("Rectangle PostScript Conversion", "[RECT]")
{
    PostLib::Rectangle             objRect;
    PostLib::PrimitiveRectangle    aRect;
    PostLib::PostScriptPoint       aPoint;
    
    aPoint = (PostLib::PostScriptPoint){120, 120};
    
    objRect = Rectangle(aPoint, 100, 100);
    
    objRect.PostScriptRepresentation();
    psCommands.append(objRect.postScript());
}

TEST_CASE("File Output", "I/O")
{
    std::ofstream outFile;
    
#if OUTPUT_FILE
    outFile.open("/file.ps");
    outFile << "%!\n";
    outFile << psCommands << "\n" << "renderCircle\n\naRect\n\n";

    
    outFile << "showpage\n\n";
    outFile.close();
#else
    
#endif
}
