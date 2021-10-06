#include "game-object.h"

using namespace std;

GameObject::GameObject(string n, Model *m, RenderObject *o)
{
    model = m;
    renderObject = o;
    name = n;
    GenerateID();
}
