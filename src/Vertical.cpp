#include "Vertical.h"

PostLib::Vertical::Vertical()
{
    
}

PostLib::Vertical::Vertical(const PostLib::PostScriptPoint & centerPoint, const std::initializer_list<std::unique_ptr<Shape>>& shapeList) : PostLib::CompositeShape(centerPoint, shapeList)
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
