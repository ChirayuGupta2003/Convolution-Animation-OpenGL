#ifndef LINE_CLASS_H
#define LINE_CLASS_H

#include <shape.h>

class Line : public Shape
{
public:
    float x1, y1, x2, y2;
    GLfloat *color;

    Line(float x1, float y1, float x2, float y2, GLfloat *color);
    void generateVerticesAndIndices();
    ~Line();
};

#endif