#include "controls.h"

Controls::Controls(GLFWwindow *w, unsigned int exit)
{
    window = w;
    exitKey = exit;
}

void Controls::ProcessInput()
{
    if (glfwGetKey(window, exitKey) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
