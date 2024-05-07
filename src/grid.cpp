#include <grid.h>
#include <line.h>
#include <glad/glad.h>
#include <rectangle.h>

Grid::Grid(int dim, bool lines, bool isLeft, std::vector<int> &data, int padding) : dim(dim), padding(padding), lines(lines), data(data), isLeft(isLeft), Shape(false)
{
    generateVerticesAndIndices();
    setupBuffers();
    int size = dim - 2 * padding;
}

void Grid::render()
{
    float cellWidth = 800.0f / dim;

    float xStart = isLeft ? 80.0f : 1040.0f;
    float yStart = 940.0f;
    float lineLength = 800.0f;

    GLfloat offWhite[] = {0.8f, 0.8f, 0.8f};

    if (lines)
        for (int i = 0; i < dim + 1; i++)
        {
            Line verticleLine(
                xStart + i * cellWidth,
                yStart,
                xStart + i * cellWidth,
                yStart - lineLength,
                offWhite);

            Line horizontalLine(
                xStart,
                yStart - i * cellWidth,
                xStart + lineLength,
                yStart - i * cellWidth,
                offWhite);

            verticleLine.render();
            horizontalLine.render();
        }

    if (isLeft)
    {
        for (int i = 0; i < dim; i++)
        {
            for (int j = 0; j < dim; j++)
            {

                GLfloat brightness = (float)data[i * dim + j] / 255.0f;

                GLfloat col[] = {brightness, brightness, brightness};

                Rectangle rect(
                    xStart + j * cellWidth + cellWidth / 2,
                    yStart - i * cellWidth - cellWidth / 2,
                    cellWidth,
                    cellWidth,
                    col,
                    false);

                rect.render();
            }
        }

        return;
    }

    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            if ((i * dim + j) >= data.size())
                return;

            GLfloat brightness = data[i * dim + j] / 255.0f;
            GLfloat col[] = {brightness, brightness, brightness};

            Rectangle rect(
                xStart + j * cellWidth + cellWidth / 2,
                yStart - i * cellWidth - cellWidth / 2,
                cellWidth,
                cellWidth,
                col,
                false);

            rect.render();
        }
    }
}

int Grid::convolve(int stRow, int stCol, int kSize, std::vector<int> &kernel)
{
    int sum = 0;

    for (int i = 0; i < kSize; i++)
    {
        for (int j = 0; j < kSize; j++)
        {
            sum += data[(stRow + i) * dim + stCol + j] * kernel[i * kSize + j];
        }
    }

    return sum;
}

Grid::~Grid() {}