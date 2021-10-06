#include "scene.h"

using namespace std;

Scene::Scene()
{
    cout << "Created a new scene!" << endl;
}

void Scene::AddObject(GameObject *o)
{
    objects.push_back(o);
}

std::vector<GameObject *> Scene::GetObjects()
{
    return objects;
}

GameObject *Scene::GetObjectById(string id)
{
    for (int i = 0; i < objects.size(); i++)
    {
        if (objects[i]->GetId() == id)
        {
            return objects[i];
        }
    }
    return NULL;
}

void Scene::PrintObjects()
{
    for (int i = 0; i < objects.size(); i++)
    {
        cout << objects[i]->GetName() << endl;
    }
}
