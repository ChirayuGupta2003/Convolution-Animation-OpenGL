#include <kernel.h>
#include <line.h>

Kernel::Kernel(int gridRows, int kernelRows, bool isLeft, int padding) : gridRows(gridRows), kernelRows(kernelRows), isLeft(isLeft), padding(padding), Shape(false)
{
    generateVerticesAndIndices();
    setupBuffers();

    int stRow = 0, stCol = 0;
}

void Kernel::render()
{
    GLfloat red[] = {1.0f, 0.0f, 0.0f};

    float cellWidth = 800.0f / gridRows;

    float xStart = isLeft ? 80.0f : 1040.0f;
    xStart += stCol * cellWidth;

    float yStart = 940.0f;
    yStart -= stRow * cellWidth;

    float lineLength = cellWidth * kernelRows;

    for (int i = 0; i < kernelRows + 1; i++)
    {
        Line verticleLine(
            xStart + i * cellWidth,
            yStart,
            xStart + i * cellWidth,
            yStart - lineLength,
            red);

        Line horizontalLine(
            xStart,
            yStart - i * cellWidth,
            xStart + lineLength,
            yStart - i * cellWidth,
            red);

        verticleLine.render();
        horizontalLine.render();
    }
}

void Kernel::step()
{
    if (stCol >= gridRows - kernelRows)
    {
        stCol = 0;
        stRow++;
    }
    else
    {
        stCol++;
    }

    if (stRow > gridRows - kernelRows)
    {
        stRow = 0;
        stCol = 0;
    }
}

Kernel::~Kernel() {}