#include "Triangle.h"

PostLib::Triangle::Triangle()
{
}

PostLib::Triangle::Triangle(PostLib::PostScriptPoint centerPoint, double sideLength) : Polygon(centerPoint, 3, sideLength)
{}

std::string PostLib::Triangle::PostScriptRepresentation(void)
{
	return std::to_string(bounds().origin.x - (0.5*bounds().size.width)) +
			" " + std::to_string(bounds().origin.y - (0.5*bounds().size.height))
			+ " 3 " + std::to_string(getSideLength());
}

std::string PostLib::Triangle::postScript(void) const
{
	return std::string();
}
