#define GL_SILENCE_DEPRECATION

#include <OpenGL/gl3.h>

#include <string>
#include <fstream>
#include <iostream>

#ifndef SHADER_H
#define SHADER_H

class Shader
{
    GLuint program;
    GLuint fragmentShader;
    GLuint vertexShader;
    std::string vertexSource;
    std::string fragSource;

private:
    void checkShaderStatus();
    std::string loadShaderFile(std::string);

public:
    Shader(std::string);
    GLuint GetProgram()
    {
        std::cout << "HERE2!" << std::endl;
        return program;
    }
};

#endif
