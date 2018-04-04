#include "Vertical.h"

PostLib::Vertical::Vertical()
{
}

PostLib::Vertical::Vertical(const PostLib::PostScriptPoint & centerPoint, const std::initializer_list<std::unique_ptr<Shape>>& shapeList) : Shape(centerPoint, { { 0,0 } ,{ 0,0 } }), _shapeList(shapeList)
{
	double shiftHeight = 0;
	for (auto & item : _shapeList)
	{
		item->setCenter({ item->center().x, item->center().y + shiftHeight });

		if (item->bounds().size.width > bounds().size.width)
			setBounds({ { bounds().origin.x, bounds().origin.y },{ item->bounds().size.width, bounds().size.height } });
	
		boundingBox.size.height += item->bounds().size.height;
		shiftHeight += item->bounds().size.height;
	}
}

std::string PostLib::Vertical::PostScriptRepresentation(void)
{
	return "/ngon { %Parameter order: xPosOrigin, yPosOrigin, sides, sideLen\n\
		newpath\n\n\
		/sideLen 				exch def\n\
		/sides 					exch def\n\
		/yPosOrigin 			exch def\n\
		/xPosOrigin 			exch def\n\
		/regularAngle 360 sides div def\n\n\
		xPosOrigin yPosOrigin 	moveto\n\
		sideLen sideLen 	  	scale\n\
		1 sideLen inch		  	div setlinewidth % Counterbalances the scaling to prevent fat lines\n\n\
		1 1 sides{\n\
		/vertex exch def\n\
		/theta vertex regularAngle mul def\n\
		theta cos theta sin rlineto\n\
		} for\n\
		closepath\n\n\
	} def";
}

std::string PostLib::Vertical::postScript(void)
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
