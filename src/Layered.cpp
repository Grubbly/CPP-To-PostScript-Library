#include "Layered.h"

PostLib::Layered::Layered()
{
}

//TODO BOUNDING BOX
PostLib::Layered::Layered(const PostLib::PostScriptPoint & centerPoint, const std::initializer_list<std::unique_ptr<Shape>> & shapeList) : Shape(centerPoint, { { 0,0 } ,{ 0,0 } }), _shapeList(shapeList)
{
	for (auto & item : _shapeList)
	{
		if (item->bounds().size.width > bounds().size.width)
			setBounds({ { bounds().origin.x, bounds().origin.y }, { item->bounds().size.width, bounds().size.height } });
		if (item->bounds().size.height > bounds().size.height)
			setBounds({ { bounds().origin.x, bounds().origin.y } , { bounds().size.width, item->bounds().size.height } });

		item->setCenter(centerPoint);
		item->setBounds({ centerPoint, {item->bounds().size.width, item->bounds().size.height} });
	}

//	double centerDifferenceX;
	double centerDifferenceY;

	//TODO HORIZONTAL SHIFT
	for (auto & item : _shapeList)
	{
		centerDifferenceY = (bounds().size.height/2) - (item->bounds().size.height/2);
		if (centerDifferenceY > 0)
			item->setCenter({ item->center().x , (item->center().y + centerDifferenceY) });
		/*
		centerDifferenceX = (bounds().origin.x) - (item->bounds().origin.y);
		if (centerDifferenceX > 0)
			item->setCenter({ (item->center().x + centerDifferenceX), item->center().y });*/
	}
}

//TODO Fix polygon so only the call is printed instead of entire function
//	   Currently only works with square and triangle.
std::string PostLib::Layered::PostScriptRepresentation(void)
{
	std::string ngonCalls = "";

	for (const auto & item : _shapeList) {
		ngonCalls += "gsave\n";
		ngonCalls += item->postScript();
		ngonCalls += "stroke\ngrestore\n";
	}
	ngonCalls += "\nshowpage\n";

	return ngonCalls;
}

std::string PostLib::Layered::postScript(void)
{
	return std::string();
}
