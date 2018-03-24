/*-------------------------------------------------------
 | CS 372: Software Construction                        |
 | Project 2: C++ To PostScript Library                 |
 | Date: 3/20/18                                        |
 | File: shape.h                                        |
 | Written By: Collin Lasley & Tristan Van Cise         |
 | Description: Header Of Shape Class                   |
 ------------------------------------------------------*/

#ifndef SHAPE_H
#define SHAPE_H

namespace PostLib {
    
    typedef struct{
        signed int x;
        signed int y;
    }PostScriptPoint;
    
    typedef struct{
        signed int width;
        signed int height;
    }Size;
    
    typedef struct{
        PostLib::PostScriptPoint origin;
        PostLib::Size            size;
    }PrimitiveRectangle;
    
    
    
    class Shape {
    public:
        
        PostScriptPoint    center(void) const;
        PrimitiveRectangle bounds(void) const;
        void               setCenter(const PostScriptPoint& newCenter);
        void               setBounds(const PrimitiveRectangle &newBounds);
        
    private:
        PostScriptPoint    centerPoint;
        PrimitiveRectangle boundingBox;
        
    };
    
}

#endif // !SHAPE_H
