#include "Horizontal.h"

PostLib::Horizontal::Horizontal()
{
}

PostLib::Horizontal::Horizontal(const PostLib::PostScriptPoint & centerPoint, const std::initializer_list<std::unique_ptr<Shape>>& shapeList) : Shape(centerPoint, { { 0,0 } ,{ 0,0 } }), _shapeList(shapeList)
{
	double shiftWidth = 0;
	for (auto & item : _shapeList)
	{
		item->setCenter({ item->center().x + shiftWidth, item->center().y });

		if (item->bounds().size.height > bounds().size.height)
			setBounds({ { bounds().origin.x, bounds().origin.y } ,{ bounds().size.width, item->bounds().size.height } });

		boundingBox.size.width += item->bounds().size.width;
		shiftWidth += item->bounds().size.width;
	}
}

std::string PostLib::Horizontal::PostScriptRepresentation(void)
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

std::string PostLib::Horizontal::postScript(void)
{
	return std::string();
}
