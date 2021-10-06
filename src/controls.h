#include <GLFW/glfw3.h>

#ifndef CONTROLS_H
#define CONTROLS_H

class Controls
{
    GLFWwindow *window;
    unsigned int exitKey;

public:
    Controls(GLFWwindow *, unsigned int);
    void ProcessInput();
};

#endif
