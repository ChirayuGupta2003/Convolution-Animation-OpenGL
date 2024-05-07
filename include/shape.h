#ifndef SHAPE_CLASS_H
#define SHAPE_CLASS_H

#include <bits/stdc++.h>
#include <glad/glad.h>
#include <VAO.h>
#include <VBO.h>
#include <EBO.h>

class Shape
{

public:
    GLuint numIndices;
    std::vector<GLfloat> vertices;
    
    std::vector<GLuint> solid_indices;
    std::vector<GLuint> hollow_indices;

    VAO VAO1;
    VBO VBO1;
    EBO EBO1;
    
    bool hollow;

    Shape(bool hollow);

    void generateVerticesAndIndices();
    void setupBuffers();
    void render();

    ~Shape();
};

#endif