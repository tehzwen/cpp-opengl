#include "render-object.h"

using namespace std;

RenderObject::RenderObject(float v[], unsigned int numVertices, unsigned int i[], unsigned int numIndices, string shaderName)
{
    shader = new Shader(shaderName);
    vertices = v;
    indices = i;

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &EBO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, numVertices, vertices, GL_STATIC_DRAW);

    GLenum err;
    if ((err = glGetError()) != GL_NO_ERROR)
    {
        std::cout << err << std::endl;
        std::cout << gluErrorString(err) << std::endl;
    }

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, numIndices, indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
}
