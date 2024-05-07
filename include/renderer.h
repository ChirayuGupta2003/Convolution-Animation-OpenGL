#ifndef RENDERER_CLASS_H
#define RENDERER_CLASS_H

#include <bits/stdc++.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Renderer
{
private:
    GLFWwindow *window;

    bool initGLFW();

public:
    int width, height, gridSize, kSize, size, padding;

    std::vector<int> data, kernel;

    Renderer(int width, int height, int gridSize, std::vector<int> kernel, int kSize, std::vector<int> &data, int padding);
    ~Renderer();

    void run();
};

#endif