#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.
#include <boost/lexical_cast.hpp>
#include <glm/glm.hpp>

#include <string>
#include "render-object.h"

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

class Model
{
public:
    glm::vec3 position;
    glm::vec3 scale;
    glm::mat4 rotation;

    Model(glm::vec3 p, glm::vec3 s, glm::mat4 r)
    {
        position = p;
        scale = s;
        rotation = r;
    }
};

class GameObject
{
    Model *model;
    std::string name;
    std::string id;
    GameObject *parent;
    RenderObject *renderObject;

public:
    GameObject(){};
    GameObject(std::string, Model *, RenderObject *);

    void GenerateID()
    {
        boost::uuids::uuid uuid = boost::uuids::random_generator()();
        id = boost::lexical_cast<std::string>(uuid);
    }

    const GameObject &Parent() const;
    GameObject &Parent(const GameObject &newParent);

    void SetName(std::string newName)
    {
        name = newName;
    }

    std::string GetName()
    {
        return name;
    }

    std::string GetId()
    {
        return id;
    }

    RenderObject *GetRenderObject()
    {
        return renderObject;
    }

    void SetRenderObject(RenderObject *object)
    {
        renderObject = object;
    }

    Model *GetModel()
    {
        return model;
    }

    void SetModel(Model *m)
    {
        model = m;
    }
};

#endif
