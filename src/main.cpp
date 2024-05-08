#include <renderer.h>
#include <GLFW/glfw3.h>
#include <bits/stdc++.h>
#include <images.h>
#include <math.h>


int main()
{

    int gridSize = 25;
    int padding = 0, kSize = 3, stride = 1;

    // Kernels in Row major order
    std::vector<int> prewittVerticalEdgeKernel = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    std::vector<int> prewittHorizontalEdgeKernel = {-1, -1, -1, 0, 0, 0, 1, 1, 1};

    std::vector<int> sobelVerticalEdgeKernel = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    std::vector<int> sobelHorizontalEdgeKernel = {-1, -2, -1, 0, 0, 0, 1, 2, 1};

    std::vector<int> laplacianKernel = {0, 1, 0, 1, -4, 1, 0, 1, 0};

    std::vector<int> data = queen;
    std::vector<int> kernel = sobelHorizontalEdgeKernel;

    std::vector<int> paddedData = {};

    for (int i = 0; i < gridSize + 2 * padding; i++)
    {
        for (int j = 0; j < gridSize + 2 * padding; j++)
        {
            int xCord = i - padding, yCord = j - padding;

            if (xCord >= 0 && yCord >= 0 && xCord < gridSize && yCord < gridSize)

                paddedData.push_back(data[xCord * gridSize + yCord]);
            else
                paddedData.push_back(0);
        }
    }

    Renderer renderer(1920, 1080, gridSize, kernel, (int)sqrt(kernel.size()), paddedData, padding, stride);

    renderer.run();
}