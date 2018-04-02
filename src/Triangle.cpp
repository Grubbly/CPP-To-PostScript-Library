#include "Triangle.h"

PostLib::Triangle::Triangle()
{
}

PostLib::Triangle::Triangle(PostLib::PostScriptPoint centerPoint, double sideLength) : Polygon(centerPoint, 3, sideLength)
{
	setPostScript(PostScriptRepresentation());
}

std::string PostLib::Triangle::PostScriptRepresentation(void)
{
	/*return std::to_string(bounds().origin.x - (0.5*bounds().size.width)) +
			" inch " + std::to_string(bounds().origin.y - (0.5*bounds().size.height))
			+ " inch 3 " + std::to_string(getSideLength()) + " inch ngon\n";*/

	return std::to_string(center().x) + " inch " + std::to_string(center().y)
		+ " inch 3 " + std::to_string(getSideLength()) + " inch ngon\n";
}

std::string PostLib::Triangle::postScript(void)
{
	setPostScript(PostScriptRepresentation());
	return PostScriptRepresentation();
}
