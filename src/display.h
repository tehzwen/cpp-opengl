#define GL_SILENCE_DEPRECATION

#include <OpenGL/gl3.h>

#include <string>
#include <glm/glm.hpp>
#include "controls.h"
#include "scene.h"

#ifndef DISPLAY_H
#define DISPLAY_H

class Display
{

    int width, height;
    GLFWwindow *window;
    Controls *controls;
    glm::vec4 clearColor;

public:
    Display(int, int, std::string, glm::vec4);
    void Render(Scene *);
};

#endif
