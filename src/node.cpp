#include "node.h"

#include "scene.h"

Node::Node(Scene* scene) : scene(scene), parent(scene->Root())
{}
Node::Node(Node* parent) : scene(parent->GetScene()), parent(parent)
{}