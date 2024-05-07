#include <rectangle.h>

Rectangle::Rectangle(float x, float y, float height, float width, float *color, bool hollow)
    : x(x), y(y), height(height), width(width), color(color), Shape(hollow)
{

    generateVerticesAndIndices();
    setupBuffers();
}

void Rectangle::generateVerticesAndIndices()
{

    float r = color[0];
    float g = color[1];
    float b = color[2];

    vertices = {
        x - width / 2, y - height / 2, 0.0f, r, g, b, // bottom left
        x + width / 2, y - height / 2, 0.0f, r, g, b, // bottom right
        x + width / 2, y + height / 2, 0.0f, r, g, b, // top right
        x - width / 2, y + height / 2, 0.0f, r, g, b  // top left
    };

    solid_indices = {0, 1, 3, 1, 2, 3};
    hollow_indices = {0, 1, 1, 2, 2, 3, 3, 0};
}

Rectangle::~Rectangle() {}