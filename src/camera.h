#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "scene.h"
#include "entity.h"
#include "renderable.h"
#include "bounding-shape.h"
#include <iostream>

DEF_ENTITY
(
    Camera,
    Entity,
    CONSTRUCTOR
    (
        matrixview = GFXGlobal<mat4f>::Get("MatrixView0");
        matrixprojection = GFXGlobal<mat4f>::Get("MatrixPerspective0");
    ),
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
            matrixview = node->GetTransform();
            matrixprojection = projection;

            for (unsigned int i = 0; i < entities.size(); ++i)
            {
                Entity* entity = entities[i];
                Renderable* renderable = (Renderable*)entity;
                renderable->Render();
            }

            glClear(GL_DEPTH_BUFFER_BIT);
            
            std::vector<Entity*> shapes = node->GetScene()->GetEntitiesByType(TypeInfo<BoundingShape>::GetId());
            for (unsigned int i = 0; i < shapes.size(); ++i)
            {
                BoundingShape* shape = (BoundingShape*)(shapes[i]);
                shape->DebugRender();
            }
        }
    ),
    PROTECTED
    (
        mat4f projection;
        GFXGlobal<mat4f> matrixview;
        GFXGlobal<mat4f> matrixprojection;
    )
);

#endif