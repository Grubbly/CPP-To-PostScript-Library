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
    /*PostLib::Shape              aShape;
    PostLib::PrimitiveRectangle aRect;
    PostLib::PostScriptPoint    aPoint;
    
    aPoint = {500, 500};
    aRect = {aPoint, 200, 200};
    
    aShape.setCenter(aPoint);
    aShape.setBounds(aRect);
    
    REQUIRE(aShape.bounds().origin.x == aPoint.x);
    REQUIRE(aShape.bounds().origin.y == aPoint.y);
    
    REQUIRE(aShape.bounds().size.width == aRect.size.width);
    REQUIRE(aShape.bounds().size.height == aRect.size.height);*/
}

TEST_CASE("Circle Construction", "[CIRCLE]")
{
    PostLib::Circle             aCircle;
    PostLib::PostScriptPoint    aPoint;
    
    aPoint = {500, 500};
    
    aCircle = Circle(aPoint, 12);
    
    REQUIRE(aCircle.bounds().origin.x == aPoint.x - 12);
    REQUIRE(aCircle.bounds().origin.y == aPoint.y - 12);


	const unsigned int bRADIUS = 42;
	PostScriptPoint bPoint = { 10, 10 };

	Circle bCircle = { bPoint, bRADIUS };

	REQUIRE(bCircle.bounds().origin.x == bPoint.x - bRADIUS);
	REQUIRE(bCircle.bounds().origin.y == bPoint.y - bRADIUS);
}

TEST_CASE("Circle Bounding Box Origin", "[CIRCLE]")
{
	const unsigned int RADIUS = 42;
	PostScriptPoint aPoint = { 20, 20 };

	Circle aCircle = { aPoint, RADIUS };

	REQUIRE(aCircle.bounds().origin.x == -22);
	REQUIRE(aCircle.bounds().origin.y == aPoint.y - RADIUS);
}

TEST_CASE("Circle Bounding Box Size", "[CIRCLE]")
{
	const unsigned int RADIUS = 42;
	PostScriptPoint aPoint = { 10, 10 };

	Circle aCircle = { aPoint, RADIUS };

	REQUIRE(aCircle.bounds().size.width == RADIUS*2);
	REQUIRE(aCircle.bounds().size.height == RADIUS*2);
}

TEST_CASE("Circle PostScript Conversion", "[CIRCLE]")
{
    PostLib::Circle             aCircle;
    PostLib::PostScriptPoint    aPoint;
    
    aPoint = {72, 72};
    
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

TEST_CASE("Polygon Side Lengths and Number of Sides (Default Ctor)", "[POLYGON]")
{
	PostLib::Polygon aPoly;

	REQUIRE(aPoly.getNumSides() == 3);
	REQUIRE(aPoly.getSideLength() == 1.0);
}

TEST_CASE("Polygon Side Lengths and Number of Sides (2 param Ctor)", "[POLYGON]")
{
	const unsigned int SIDES = 5;
	const double SIDE_LENGTH = 3;

	PostLib::Polygon aPoly(SIDES, SIDE_LENGTH);

	REQUIRE(aPoly.getNumSides() == SIDES);
	REQUIRE(aPoly.getSideLength() == SIDE_LENGTH);
}
