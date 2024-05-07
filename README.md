# Convolution Animation using Modern OpenGL

This project is aimed at demonstrating the convolution process in images using Modern OpenGL. Convolution is a fundamental operation in image processing, widely used in tasks like blurring, edge detection, and noise reduction. This animation visualizes how convolution works by applying different kernels to an input image.

### Requirements

To build and run this project, you need the following dependencies installed on your system:

- CMake (version 3.0 or later)
- OpenGL (version 3.3 or later)
- GLFW (version 3.3 or later)
- GLAD (OpenGL loader generator)
- Any C++ compiler with C++11 support

### Building Instructions

Follow these steps to build the project using CMake:

1. Clone the repository to your local machine:

```
git clone <repository-url>
```

2. Navigate to the project directory:

```
cd convolution-animation-opengl
```

3. Create a build directory:

```
mkdir build
cd build
```

4. Generate build files using CMake:

```
cmake ..
```

5. Build the project using your preferred build tool (e.g., make for Unix-based systems, Visual Studio for Windows):

```
cmake --build .
```

### Running the Program

Once you've successfully built the project, you can run the executable to view the convolution animation.

```
./convolution_animation
```

### Instructions

- Upon running the program, you will see the animation window.
- You can change the input image in `main.cpp`
- You can modify the kernel size and kernel values by editing the appropriate variables in the source code (`main.cpp`).

### Credits

This project uses Modern OpenGL and is inspired by various resources and tutorials available online. Special thanks to GLFW and GLAD for making OpenGL development more accessible.

### License

This project is licensed under the MIT License. See the LICENSE file for more details.

### Author

Chirayu Gupta

### Contact

For any inquiries or issues regarding the project, please contact chirayugupta2003@gmail.com.
