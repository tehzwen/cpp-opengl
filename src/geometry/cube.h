#define GL_SILENCE_DEPRECATION
#include "../game-object.h"
#include <glm/glm.hpp>

#ifndef CUBE_H
#define CUBE_H

class Cube : public GameObject
{

public:
    Cube(std::string name, GameObject *parent = NULL, glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f), glm::mat4 *rotation = new glm::mat4());
};

#endif
