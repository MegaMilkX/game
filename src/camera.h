#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "scene.h"
#include "entity.h"
#include "renderable.h"

DEF_ENTITY
(
    Camera, 
    Entity,
    PUBLIC
    (
        void Perspective(float fov, float aspect, float znear, float zfar)
        {
            projection = perspective(fov, aspect, znear, zfar);
        }

        void Ortho(float left, float right, float bottom, float top, float znear, float zfar)
        {
            projection = ortho(left, right, bottom, top, znear, zfar);
        }

        void Render()
        {
            std::vector<Entity*> entities = node->GetScene()->GetEntitiesByType(TypeInfo<Renderable>::GetId());
            GFXGlobal<mat4f>::Get("MatrixView0") = node->GetTransform()->GetTransform();
            GFXGlobal<mat4f>::Get("MatrixPerspective0") = projection;

            for (unsigned int i = 0; i < entities.size(); ++i)
            {
                Entity* entity = entities[i];
                Renderable* renderable = (Renderable*)entity;
                renderable->Render();
            }
        }
    ),
    PROTECTED
    (
        mat4f projection;
    )
);

#endif