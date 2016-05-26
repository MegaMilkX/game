#ifndef _SCENE_H_
#define _SCENE_H_

#include <map>
#include <vector>

#include <libgame.h>

struct AABB {};

class Entity
{
public:
};

class Node
{
public:
    Node(Node& parent) : parent(0)
    {
        this->parent = &parent;
    }
    Node* AddNode()
    {
        nodes.push_back(Node(*this));
        return &(nodes[nodes.size() - 1]);
    }

    Node* Root()
    {
        if (parent)
            return parent->Root();
        else
            return this;
    }
private:
    Node* parent;
    std::vector<Node> nodes;
    std::map<int, Entity*> entities;
    AABB bounds;
    Transform transform;
};

class Scene : public Node
{
public:
    template<typename ENTITY>
    ENTITY* AddEntity();
private:
    std::vector<Node> nodes;
    std::map<int, std::vector<Entity*>> entities;
};

#endif