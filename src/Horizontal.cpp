#include "Horizontal.h"

PostLib::Horizontal::Horizontal()
{
}

PostLib::Horizontal::Horizontal(const PostLib::PostScriptPoint & centerPoint, const std::initializer_list<std::unique_ptr<Shape>>& shapeList) : PostLib::CompositeShape(centerPoint, shapeList)
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
