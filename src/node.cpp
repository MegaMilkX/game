#include "node.h"

#include "scene.h"

Node::Node(Scene* scene) : scene(scene), parent(0)
{}
Node::Node(Node* parent) : scene(parent->GetScene()), parent(parent)
{}

void Node::Translate(float x, float y, float z, Space space) { Translate(vec3f(x, y, z), space); }
void Node::Translate(vec3f trans, Space space) { transform.Translate(trans, space); }
void Node::Rotate(float angle, float x, float y, float z, Space space) { Rotate(angle, vec3f(x, y, z), space); }
void Node::Rotate(float angle, vec3f axis, Space space) { transform.Rotate(angle, axis, space); }
void Node::Scale(float x, float y, float z) { transform.Scale(x, y, z); }
void Node::Scale(vec3f scale) { transform.Scale(scale); }
void Node::Scale(float scale) { transform.Scale(scale); }