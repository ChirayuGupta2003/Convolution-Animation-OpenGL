#ifndef GRID_CLASS_H
#define GRID_CLASS_H

#include <shape.h>
#include <bits/stdc++.h>

class Grid : public Shape
{
public:
    int dim, padding, size;

    std::vector<int> data;

    bool isLeft, lines;

    Grid(int dim, bool lines, bool isLeft, std::vector<int> &data, int padding = 0);

    void render();
    int convolve(int stRow, int stCol, int kSize, std::vector<int> &kernel);
    ~Grid();
};

#endif