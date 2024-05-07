#include <line.h>

Line::Line(float x1, float y1, float x2, float y2, GLfloat *color) : x1(x1), y1(y1), x2(x2), y2(y2), color(color), Shape(true)
{
    generateVerticesAndIndices();
    setupBuffers();
}

void Line::generateVerticesAndIndices()
{
    float r = color[0];
    float g = color[1];
    float b = color[2];

    vertices = {
        x1, y1, 0.0f, r, g, b,
        x2, y2, 0.0f, r, g, b};

    hollow_indices = {0, 1};
}

Line::~Line() {}