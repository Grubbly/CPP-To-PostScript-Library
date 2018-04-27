/*-------------------------------------------------------
 | CS 372: Software Construction                        |
 | Homework 5: Template Design Pattern                  |
 | Date: 4/24/18                                        |
 | File: CompositeShapes.h                              |
 | Written By: Collin Lasley                            |
 | Description: Base class for composite-type shapes    |
 ------------------------------------------------------*/

#ifndef COMPOSITESHAPES_h
#define COMPOSITESHAPES_h

#include <string>
#include <vector>
#include <memory>

#include "Shape.h"

namespace PostLib {
    class CompositeShape : public PostLib::Shape
    {
    public:
        CompositeShape();
        CompositeShape(const PostLib::PostScriptPoint &centerPoint, const std::initializer_list<std::unique_ptr<Shape>> &shapeList);
        
        virtual std::string PostScriptRepresentation(void) override final;
                std::string postScript(void) final override;
        
    protected:
        std::initializer_list<std::unique_ptr<Shape>> _shapeList;
    };
}

#endif /* COMPOSITESHAPES_h */
