#include <iostream>
#include "game-object.h"

#ifndef SCENE_H
#define SCENE

class Scene
{
    std::vector<GameObject *> objects;

public:
    Scene();
    void AddObject(GameObject *);
    void PrintObjects();
    GameObject *GetObjectById(std::string);
    std::vector<GameObject *> GetObjects();
};

#endif
