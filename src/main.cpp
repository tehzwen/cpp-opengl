#include <iostream>
#include <GLFW/glfw3.h>

#include "game-object.h"
#include "display.h"
#include "shader.h"
#include "render-object.h"
#include "geometry/cube.h"

using namespace std;

int main(int argc, char **argv)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    Scene *s = new Scene();
    Display *d = new Display(500, 500, "Hello world!", glm::vec4(0.3f, 0.3f, 0.3f, 1.0f));
    Cube *c = new Cube("testCube");
    s->AddObject(c);
    // s->PrintObjects();

    // s->GetObjectById("");
    (*d).Render(s);

    cout << "Exiting" << endl;
    return EXIT_SUCCESS;
}
