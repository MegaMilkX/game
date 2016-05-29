#ifndef _RENDERABLE_H_
#define _RENDERABLE_H_

#include "scene.h"
#include "entity.h"

#include <libgame.h>

#include <iostream>

DEF_ENTITY
(
    Renderable,
    Entity,
    PUBLIC
    (
        void Mesh(ResHdl<GFXMesh> mesh) { this->mesh = mesh; }
        void Material(ResHdl<GFXMaterial> material) { this->material = material; }

        virtual void Render()
        {
            GFXGlobal<mat4f>::Get("MatrixModel0") = node->GetTransform()->GetTransform();
            material->Bind();
            mesh->Render();
        }
    ),
    PROTECTED
    (
        ResHdl<GFXMesh> mesh;
        ResHdl<GFXMaterial> material;
    )
);

#endif