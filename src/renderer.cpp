#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <renderer.h>
#include <shaderClass.h>
#include <grid.h>
#include <kernel.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <math.h>

Renderer::Renderer(int width, int height, int gridSize, std::vector<int> kernel, int kSize, std::vector<int> &data, int padding = 0) : window(), width(width), height(height), gridSize(gridSize), kernel(kernel), kSize(kSize), data(data), padding(padding) {}

Renderer::~Renderer()
{
    if (window)
    {
        glfwDestroyWindow(window);
    }

    glfwTerminate();
}

void Renderer::run()
{
    if (!initGLFW())
    {
        std::cerr << "Failed to initialize GLFW\n";
        return;
    }

    gladLoadGL();

    glViewport(0, 0, width, height);

    Shader shaderProgram("../shaders/default.vert", "../shaders/default.frag");

    Grid grid1 = Grid(gridSize + 2 * padding, false, true, data, padding);

    int outDim = (gridSize - kSize + 2 * padding) + 1;

    std::vector<int> grid2Data = {};

    Grid grid2 = Grid(outDim, false, false, grid2Data);

    Kernel kernel1(gridSize + 2 * padding, kSize, true, padding);
    Kernel kernel2(outDim, 1, false);

    // Desired frame rate
    const double desiredFPS = 144.0;

    double frameNum = 0.0;

    glm::mat4 projection = glm::ortho(0.0f, (float)width, 0.0f, (float)height, -1.0f, 1.0f);

    // Main loop
    while (!glfwWindowShouldClose(window))
    {

        // Calculate the time taken to render the previous frame
        static auto previousTime = std::chrono::high_resolution_clock::now();
        auto currentTime = std::chrono::high_resolution_clock::now();
        double deltaTime = std::chrono::duration<double, std::milli>(currentTime - previousTime).count() / 1000.0;
        previousTime = currentTime;

        // Limit the frame rate
        double targetTimePerFrame = 1.0 / desiredFPS;
        if (deltaTime < targetTimePerFrame)
        {
            double sleepTime = targetTimePerFrame - deltaTime;
            std::this_thread::sleep_for(std::chrono::duration<double>(sleepTime));
        }

        // Specify the color of the background
        // Clean the back buffer and assign the new color to it

        shaderProgram.Activate();

        int modelLoc = glGetUniformLocation(shaderProgram.ID, "projection");

        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(projection));

        frameNum++;

        if (frameNum >= desiredFPS / (outDim * outDim))
        {
            glClear(GL_COLOR_BUFFER_BIT);

            glClearColor(0.9725490196078431f, 0.9764705882352941f, 0.9725490196078431f, 1.0f);

            int val = grid1.convolve(kernel1.stRow, kernel1.stCol, kernel1.kernelRows, kernel);

            grid2.data.push_back(val);

            kernel1.step();
            kernel2.step();

            grid1.render();
            kernel1.render();
            kernel2.render();
            grid2.render();
            
            frameNum = 0;
        }

        // Swap the front and back buffers
        glfwSwapBuffers(window);

        glfwPollEvents();
    }
}

bool Renderer::initGLFW()
{
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW\n";
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a GLFW window
    window = glfwCreateWindow(width, height, "OpenGL Window", NULL, NULL);

    glfwSetWindowAspectRatio(window, 16, 9);

    if (!window)
    {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return false;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    return true;
}
