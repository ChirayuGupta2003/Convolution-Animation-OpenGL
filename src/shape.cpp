#include <shape.h>

Shape::Shape(bool hollow) : hollow(hollow) {}

Shape::~Shape() {}

void Shape::setupBuffers()
{
    VAO1.Bind();

    VBO1 = VBO(vertices.data(), vertices.size() * sizeof(GLfloat));

    if (hollow)
        EBO1 = EBO(hollow_indices.data(), hollow_indices.size() * sizeof(GLuint));
    else
        EBO1 = EBO(solid_indices.data(), solid_indices.size() * sizeof(GLuint));

    VAO1.LinkVBO(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void *)0);
    VAO1.LinkVBO(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void *)(3 * sizeof(float)));

    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();
}

void Shape::render()
{
    VAO1.Bind();
    if (!hollow)
        glDrawElements(GL_TRIANGLES, solid_indices.size(), GL_UNSIGNED_INT, 0);
    else
        glDrawElements(GL_LINES, hollow_indices.size(), GL_UNSIGNED_INT, 0);
}

void Shape::generateVerticesAndIndices() {}
