#ifndef _NODE_H_
#define _NODE_H_

#include <vector>
#include <map>
#include <iostream>

#include <libgame.h>

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

    template<typename ENTITY>
    ENTITY* Add();

    template<typename ENTITY>
    void Add(Entity* entity);

    Scene* GetScene() { return scene; }

    Transform* GetTransform() { return &transform; }
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

}

template<typename ENTITY>
void Node::Add(Entity* entity)
{
    if(entities.find(TypeInfo<ENTITY>::GetId()) == entities.end())
        entities.insert(std::make_pair(TypeInfo<ENTITY>::GetId(), entity));
}

#endif