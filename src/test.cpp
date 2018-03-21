/*
test.cpp
Tristan Van Cise & Collin Lasley
Project 2 - CPS Library
03/21/2018
All test cases involving catch are defined here
*/

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