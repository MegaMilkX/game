#ifndef _SCENE_H_
#define _SCENE_H_

#include <map>
#include <vector>

#include <libgame.h>

#include "node.h"
#include "entity.h"

//============================
// Scene
//============================
class Scene
{
public:
    // Has to initialize its root node
    Scene() : root_node(this) {  }
    //
    ~Scene();
    // Adds a Node to root with an attached entity of specified type
    template<typename ENTITY>
    ENTITY* Add();
    // Get scene root Node
    Node* Root() { return &root_node; }
    // 
    void AddEntityInstance(Entity* entity);
    void AddEntityType(int index, Entity* entity);
    //
    std::vector<Entity*>& GetEntitiesByType(int typeindex);
    //
    void PrintStats()
    {
        std::cout << "Scene " << (int)this << " now has " << entities.size() << " entities of " << entity_by_type.size() << " types" << std::endl;
    }
private:
    // Can't copy, won't copy
    Scene(const Scene& other) : root_node(this) {}
    Scene& operator=(const Scene& other) { return *this; }
    // Has a root node, is not itself one
    Node root_node;
    // Scene owns all entities
    std::vector<Entity*> entities;
    // Also stores them by type. Same entity can be stored as more than one type
    std::map<int, std::vector<Entity*>> entity_by_type;
};

template<typename ENTITY>
ENTITY* Scene::Add()
{
    ENTITY* entity = ENTITY::Create(this);
    return entity;
}

#endif