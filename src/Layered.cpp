#include "Layered.h"

PostLib::Layered::Layered()
{
}

//TODO BOUNDING BOX
PostLib::Layered::Layered(const PostLib::PostScriptPoint & centerPoint, const std::initializer_list<Shape> & shapeList) : Shape(centerPoint, { { 5,4 } ,{ 4,4 } })
{
	for (const auto & item : shapeList)
	{
		if (item.bounds().size.width > bounds().size.width)
			setBounds({ item.bounds().size.width, bounds().size.height });
		if (item.bounds().size.height > bounds().size.height)
			setBounds({ bounds().size.width, item.bounds().size.height });
	
		//_shapeList.push_back(std::move(std::make_unique<Shape>(item)));
	}
}

//TODO Fix polygon so only the call is printed instead of entire function
//	   Currently only works with square and triangle.
std::string PostLib::Layered::PostScriptRepresentation(void)
{
	std::string ngonCalls;

	//for (int item = 0; item < _shapeList.size(); item++)
		//ngonCalls += *(_shapeList[item]).PostScriptRepresentation(); TODO

	return ngonCalls;
}

std::string PostLib::Layered::postScript(void) const
{
	return std::string();
}
