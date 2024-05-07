#ifndef RECTANGLE_CLASS_H
#define RECTANGLE_CLASS_H

#include <shape.h>

class Rectangle : public Shape
{

public:
    float x, y, height, width;
    GLfloat *color;

    Rectangle(float x, float y, float height, float width, GLfloat *color, bool hollow = false);

    void generateVerticesAndIndices();
    ~Rectangle();
};

#endif