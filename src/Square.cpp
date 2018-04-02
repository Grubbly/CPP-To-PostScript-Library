#include "Square.h"

PostLib::Square::Square()
{
}

PostLib::Square::Square(PostLib::PostScriptPoint centerPoint, double sideLength) : Polygon(centerPoint, 4, sideLength)
{
	setPostScript(PostScriptRepresentation());
}

std::string PostLib::Square::PostScriptRepresentation(void)
{
	/*return std::to_string(bounds().origin.x - (0.5*bounds().size.width)) +
			" inch " + std::to_string(bounds().origin.y - (0.5*bounds().size.height))
			+ " inch 4 " + std::to_string(getSideLength()) + " inch ngon\n";*/

	return std::to_string(center().x) + " inch " + std::to_string(center().y)
		+ " inch 4 " + std::to_string(getSideLength()) + " inch ngon\n";
}

std::string PostLib::Square::postScript(void)
{
	setPostScript(PostScriptRepresentation());
	return PostScriptRepresentation();
}
