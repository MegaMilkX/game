#include "entity.h"

#include "node.h"
#include "scene.h"

void Entity::Translate(float x, float y, float z, Space space) { Translate(vec3f(x, y, z), space); }
void Entity::Translate(vec3f trans, Space space) { node->Translate(trans, space); }
void Entity::Rotate(float angle, float x, float y, float z, Space space) { Rotate(angle, vec3f(x, y, z), space); }
void Entity::Rotate(float angle, vec3f axis, Space space) { node->Rotate(angle, axis, space); }
void Entity::Scale(float x, float y, float z) { node->Scale(x, y, z); }
void Entity::Scale(vec3f scale) { node->Scale(scale); }
void Entity::Scale(float scale) { node->Scale(scale); }

Entity::Entity(Node* node) : node(node)
{
    Scene* scene = node->GetScene();
    scene->AddEntityInstance(this);
    scene->AddEntityType(TypeInfo<Entity>::GetId(), this);
}