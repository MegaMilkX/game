#include "scene.h"

Scene::~Scene()
{
    for (unsigned int i = 0; i < entities.size(); ++i)
        delete entities[i];
}

void Scene::AddEntityInstance(Entity* entity)
{
    entities.push_back(entity);
}

void Scene::AddEntityType(int index, Entity* entity)
{
    entity_by_type[index].push_back(entity);
}

std::vector<Entity*>& Scene::GetEntitiesByType(int typeindex)
{
    return entity_by_type[typeindex];
}