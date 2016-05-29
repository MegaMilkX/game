#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <libgame.h>

class Node;
class Scene;
class Entity
{
public:
    virtual ~Entity() {}
    Node* GetNode() { return node; }
    void Translate(float x, float y, float z, Space space = LOCAL);
    void Translate(vec3f trans, Space space = LOCAL);
    void Rotate(float angle, float x, float y, float z, Space space = LOCAL);
    void Rotate(float angle, vec3f axis, Space space = LOCAL);
    void Scale(float x, float y, float z);
    void Scale(vec3f scale);
    void Scale(float scale);
protected:
    Entity(Node* node);
    Node* node;
};

#define PUBLIC(SOURCE) public: SOURCE
#define PROTECTED(SOURCE) protected: SOURCE

#define DEF_ENTITY(NAME, BASE, PUB, PROT) \
    class NAME : public BASE \
    { \
    public: \
        static NAME* Create(Scene* scene) \
        { \
            NAME* entity = new NAME(scene->Root()->AddNode()); \
            return entity; \
        } \
    protected: \
        NAME(Node* node) : BASE(node) \
        { \
            Scene* scene = node->GetScene(); \
            scene->AddEntityType(TypeInfo<NAME>::GetId(), this); \
            node->Add<NAME>(this); \
        } \
        PUB \
        PROT \
    }

#endif
