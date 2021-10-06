#define GL_SILENCE_DEPRECATION

#include <GLUT/glut.h>

#include "shader.h"

#ifndef RENDER_OBJECT_H
#define RENDER_OBJECT_H

class RenderObject
{
    float *vertices;
    unsigned int *indices;
    Shader *shader;
    GLuint VBO, VAO, EBO;

public:
    unsigned int numVertices;
    unsigned int numIndices;

    RenderObject(float v[], unsigned int vS, unsigned int i[], unsigned int Is, std::string);
    float *GetVertices()
    {
        return vertices;
    }

    void SetVertices(float v[], unsigned int vS)
    {
        vertices = v;
        numVertices = vS;
    }

    unsigned int *GetIndices()
    {
        return indices;
    }

    void SetIndices(unsigned int i[], unsigned int iS)
    {
        indices = i;
        numIndices = iS;
    }

    Shader *GetShader()
    {
        return shader;
    }

    GLuint GetVAO()
    {
        return VAO;
    }
};

#endif
