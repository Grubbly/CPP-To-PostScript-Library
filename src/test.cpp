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
using std::cin;

int factorial(int a)
{
	return a <= 1 ? a : a * factorial(a - 1);
}

TEST_CASE("Catch working using factorial function?", "[Test Catch]")
{
	REQUIRE(factorial(2) == 2);
	REQUIRE(factorial(3) == 6);
	REQUIRE(factorial(-1) == -1);
}

TEST_CASE("Shape", "[]")
{
	//add test cases here once classes are defined
}
