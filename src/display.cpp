#include "display.h"

using namespace std;

Display::Display(int w, int h, string name, glm::vec4 color)
{
    clearColor = color;
    width = w;
    height = h;

    window = glfwCreateWindow(w, h, name.c_str(), NULL, NULL);
    if (window == NULL)
    {
        printf("Failed to create GLFW window");
        glfwTerminate();
    }

    controls = new Controls(window, GLFW_KEY_ESCAPE);
    glfwMakeContextCurrent(window);
}

void Display::Render(Scene *scene)
{
    while (!glfwWindowShouldClose(window))
    {
        (*controls).ProcessInput();

        GLenum err;
        if ((err = glGetError()) != GL_NO_ERROR)
        {
            std::cout << err << std::endl;
            std::cout << gluErrorString(err) << std::endl;
        }

        glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
        glClear(GL_COLOR_BUFFER_BIT);

        std::vector<GameObject *> objects = scene->GetObjects();
        for (int i = 0; i < objects.size(); i++)
        {
            cout << objects[i]->GetRenderObject() << endl;
            cout << objects[i]->GetRenderObject()->GetShader() << endl;
            cout << objects[i]->GetRenderObject()->GetShader()->GetProgram() << endl;

            glUseProgram(objects[i]->GetRenderObject()->GetShader()->GetProgram());

            glBindVertexArray(objects[i]->GetRenderObject()->GetVAO());
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}
