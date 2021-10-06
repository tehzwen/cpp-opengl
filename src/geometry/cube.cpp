#include "cube.h"

using namespace std;

Cube::Cube(string name, GameObject *parent, glm::vec3 position, glm::vec3 scale, glm::mat4 *rotation)
{
    SetName(name);
    GenerateID();

    Model *tempModel = new Model(
        position,
        scale,
        (*rotation));

    float vertices[] = {
        0.5f, 0.5f, 0.0f,   // top right
        0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f, // bottom left
        -0.5f, 0.5f, 0.0f   // top left
    };
    unsigned int indices[] = {
        0, 1, 3, // first Triangle
        1, 2, 3  // second Triangle
    };

    SetModel(tempModel);
    RenderObject *renderObject = new RenderObject(vertices, sizeof(vertices), indices, sizeof(indices), "test");
    SetRenderObject(renderObject);
}
