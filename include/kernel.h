#ifndef KERNEL_CLASS_H
#define KERNEL_CLASS_H

#include <shape.h>


class Kernel : public Shape
{
public:
    int gridRows, kernelRows, stRow = 0, stCol = 0, padding;
    bool isLeft;

    Kernel(int gridRows, int kernelRows, bool isLeft, int padding = 0);

    void render();
    void step();

    ~Kernel();
};

#endif