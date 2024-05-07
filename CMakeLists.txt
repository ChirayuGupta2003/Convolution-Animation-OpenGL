cmake_minimum_required(VERSION 3.5.0)
project(convolution_animation VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(glfw3 REQUIRED)
find_package(glm CONFIG REQUIRED)

# Add include directory for all targets
include_directories(include)

file(GLOB SOURCES "src/*.cpp" "src/*.c")

# Define the shaders directory
set(SHADERS_DIR ${CMAKE_SOURCE_DIR}/shaders)
set(SHADERS_OUTPUT_DIR ${CMAKE_BINARY_DIR}/shaders)  # Where shaders will be copied to in the build directory

# Copy shader files to the build directory during build
file(COPY ${SHADERS_DIR} DESTINATION ${SHADERS_OUTPUT_DIR})

# Add the shader files to the sources
file(GLOB SHADER_SOURCES "${SHADERS_OUTPUT_DIR}/*.vert" "${SHADERS_OUTPUT_DIR}/*.frag")
list(APPEND SOURCES ${SHADER_SOURCES})

add_executable(convolution_animation ${SOURCES})

# Include the include directory specifically for the target
target_include_directories(convolution_animation PRIVATE include)

target_link_libraries(convolution_animation PRIVATE glfw)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
