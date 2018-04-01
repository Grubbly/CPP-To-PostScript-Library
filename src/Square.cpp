#include "Square.h"

PostLib::Square::Square()
{
}

PostLib::Square::Square(PostLib::PostScriptPoint centerPoint, double sideLength) : Polygon(centerPoint, 4, sideLength)
{}

std::string PostLib::Square::PostScriptRepresentation(void)
{
	return std::to_string(bounds().origin.x - (0.5*bounds().size.width)) +
			" " + std::to_string(bounds().origin.y - (0.5*bounds().size.height))
			+ " 4 " + std::to_string(getSideLength());
}

std::string PostLib::Square::postScript(void) const
{
	return std::string();
}
