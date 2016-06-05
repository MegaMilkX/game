#ifndef _NODE_H_
#define _NODE_H_

#include <vector>
#include <map>
#include <iostream>

#include <libgame.h>

enum Space
{
    LOCAL,
    PARENT,
    WORLD
};

//============================
// Node
//============================
class Entity;
class Scene;
class Node
{
public:
    Node(Scene* scene);
    Node(Node* parent);
    ~Node()
    {
        for (unsigned int i = 0; i < children.size(); ++i)
            delete children[i];
    }

    Node* AddNode()
    {
        children.push_back(new Node(this));
        return children.back();
    }

    Node* Parent()
    {
        return parent;
    }

    template<typename ENTITY>
    ENTITY* Add();

    template<typename ENTITY>
    void Add(Entity* entity);

    Scene* GetScene() { return scene; }

    void Translate(float x, float y, float z, Space space = LOCAL);
    void Translate(vec3f trans, Space space = LOCAL);
    void Rotate(float angle, float x, float y, float z, Space space = LOCAL);
    void Rotate(float angle, vec3f axis, Space space = LOCAL);
    void Scale(float x, float y, float z);
    void Scale(vec3f scale);
    void Scale(float scale);

    vec3f Forward();
    vec3f Back();
    vec3f Left();
    vec3f Right();

    mat4f GetTransform() 
    { 
        if (parent)
            return parent->GetTransform() * transform.GetTransform();
        else
            return transform.GetTransform(); 
    }

    void PrintEntityTypes()
    {
        std::map<int, Entity*>::iterator it;
        for (it = entities.begin(); it != entities.end(); ++it)
        {
            std::cout << it->first << std::endl;
        }
    }
private:
    Scene* scene;
    Node* parent;
    Transform transform;
    std::vector<Node*> children;
    std::map<int, Entity*> entities;
};

template<typename ENTITY>
ENTITY* Node::Add()
{
    ENTITY* entity = ENTITY::Create(this);
    return entity;
}

template<typename ENTITY>
void Node::Add(Entity* entity)
{
    if(entities.find(TypeInfo<ENTITY>::GetId()) == entities.end())
        entities.insert(std::make_pair(TypeInfo<ENTITY>::GetId(), entity));
}

#endif