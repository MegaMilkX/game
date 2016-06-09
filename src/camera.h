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
        screen_size = vec2i(640, 480);
    ),
    PUBLIC
    (
        void ViewportSize(int w, int h)
        {
            screen_size.x = w;
            screen_size.y = h;
        }

        void Perspective(float fov, int vp_w, int vp_h, float znear, float zfar)
        {
            this->znear = znear;
            this->zfar = zfar;
            ViewportSize(vp_w, vp_h);
            float aspect = screen_size.x / (float)screen_size.y;
            projection = perspective(fov, aspect, znear, zfar);
        }

        void Ortho(float left, float right, float bottom, float top, float znear, float zfar)
        {
            this->znear = znear;
            this->zfar = zfar;
            projection = ortho(left, right, bottom, top, znear, zfar);
        }

        ray ScreenToWorld(vec2f pos)
        {
            float x = (pos.x * 2.0f) - 1.0f;
            float y = 1.0f - (pos.y * 2.0f);
            float z = 1.0f;
            vec3f ray_nds = vec3f(x, y, z);

            vec4f ray_clip = vec4f(ray_nds.x, ray_nds.y, -1.0f, 1.0f);

            vec4f ray_eye = inverse(projection) * ray_clip;

            ray_eye = vec4f(ray_eye.x, ray_eye.y, -1.0f, 0.0f);

            vec3f ray_world = node->GetTransform() * ray_eye;
            
            ray_world = normalize(ray_world);

            ray r;
            r.direction = ray_world;
            r.origin = node->GetTransform()[3];

            return r;
        }

        vec2i WorldToScreen(vec3f pos)
        {
            return vec2i();
        }

        void Render()
        {
            std::vector<Entity*> entities = node->GetScene()->GetEntitiesByType(TypeInfo<IRenderable>::GetId());
            matrixview = inverse(node->GetTransform());
            matrixprojection = projection;

            for (unsigned int i = 0; i < entities.size(); ++i)
            {
                Entity* entity = entities[i];
				IRenderable* renderable = (IRenderable*)entity;
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
        float znear;
        float zfar;
        vec2i screen_size;
        mat4f projection;
        GFXGlobal<mat4f> matrixview;
        GFXGlobal<mat4f> matrixprojection;
    )
);

#endif