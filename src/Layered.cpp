#include "Layered.h"

PostLib::Layered::Layered()
{
}

//TODO BOUNDING BOX
PostLib::Layered::Layered(const PostLib::PostScriptPoint & centerPoint, const std::initializer_list<std::unique_ptr<Shape>> & shapeList) : Shape(centerPoint, { { 5,4 } ,{ 4,4 } }), _shapeList(shapeList)
{
	for (auto & item : shapeList)
	{
		if ((*item).bounds().size.width > bounds().size.width)
			setBounds({ (*item).bounds().size.width, bounds().size.height });
		if ((*item).bounds().size.height > bounds().size.height)
			setBounds({ bounds().size.width, (*item).bounds().size.height });

		(*item).setCenter(centerPoint);
	}
}

//TODO Fix polygon so only the call is printed instead of entire function
//	   Currently only works with square and triangle.
std::string PostLib::Layered::PostScriptRepresentation(void)
{
	std::string ngonCalls = "";

	for (const auto & item : _shapeList) {
		ngonCalls += (*item).postScript();
		//ngonCalls += "Called\n" + item.get()->postScript();
	}

	return ngonCalls;
}

std::string PostLib::Layered::postScript(void) const
{
	std::string ngonCalls = "";

	for (auto & item : _shapeList) {
		ngonCalls += "Called\n" + item.get()->postScript();
	}

	return ngonCalls;
}
