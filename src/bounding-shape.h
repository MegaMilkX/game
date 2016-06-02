#ifndef _BOUNDING_SHAPE_H_
#define _BOUNDING_SHAPE_H_

#include "entity.h"

#include <vector>

DEF_ENTITY
(
    BoundingShape,
    Entity,
    CONSTRUCTOR(),
    PUBLIC
    (
        virtual void DebugRender() {}
    ),
    PROTECTED()
);

DEF_ENTITY
(
    AABBox,
    BoundingShape,
    CONSTRUCTOR
    (
        global_matrixmodel = GFXGlobal<mat4f>::Get("MatrixModel0");
    ),
    PUBLIC
    (
        void Size(float x, float y, float z)
        {
            size = vec3f(x, y, z);
        }

        void DebugRender()
        {
            global_matrixmodel = node->GetTransform();
            std::vector<vec3f> points;
            points.push_back(vec3f(-size.x * 0.5f, -size.y * 0.5f, -size.z * 0.5f));
            points.push_back(vec3f(size.x * 0.5f, -size.y * 0.5f, -size.z * 0.5f));
            points.push_back(vec3f(size.x * 0.5f, -size.y * 0.5f, -size.z * 0.5f));
            points.push_back(vec3f(size.x * 0.5f, size.y * 0.5f, -size.z * 0.5f));
            points.push_back(vec3f(size.x * 0.5f, size.y * 0.5f, -size.z * 0.5f));
            points.push_back(vec3f(-size.x * 0.5f, size.y * 0.5f, -size.z * 0.5f));
            points.push_back(vec3f(-size.x * 0.5f, size.y * 0.5f, -size.z * 0.5f));
            points.push_back(vec3f(-size.x * 0.5f, -size.y * 0.5f, -size.z * 0.5f));
            points.push_back(vec3f(-size.x * 0.5f, -size.y * 0.5f, size.z * 0.5f));
            points.push_back(vec3f(size.x * 0.5f, -size.y * 0.5f, size.z * 0.5f));
            points.push_back(vec3f(size.x * 0.5f, -size.y * 0.5f, size.z * 0.5f));
            points.push_back(vec3f(size.x * 0.5f, size.y * 0.5f, size.z * 0.5f));
            points.push_back(vec3f(size.x * 0.5f, size.y * 0.5f, size.z * 0.5f));
            points.push_back(vec3f(-size.x * 0.5f, size.y * 0.5f, size.z * 0.5f));
            points.push_back(vec3f(-size.x * 0.5f, size.y * 0.5f, size.z * 0.5f));
            points.push_back(vec3f(-size.x * 0.5f, -size.y * 0.5f, size.z * 0.5f));
            points.push_back(vec3f(-size.x * 0.5f, -size.y * 0.5f, -size.z * 0.5f));
            points.push_back(vec3f(-size.x * 0.5f, -size.y * 0.5f, size.z * 0.5f));
            points.push_back(vec3f(size.x * 0.5f, -size.y * 0.5f, -size.z * 0.5f));
            points.push_back(vec3f(size.x * 0.5f, -size.y * 0.5f, size.z * 0.5f));
            points.push_back(vec3f(size.x * 0.5f, size.y * 0.5f, -size.z * 0.5f));
            points.push_back(vec3f(size.x * 0.5f, size.y * 0.5f, size.z * 0.5f));
            points.push_back(vec3f(-size.x * 0.5f, size.y * 0.5f, -size.z * 0.5f));
            points.push_back(vec3f(-size.x * 0.5f, size.y * 0.5f, size.z * 0.5f));
            line.Render(points);
        }
    ),
    PROTECTED
    (
        vec3f size;
        GFXGlobal<mat4f> global_matrixmodel;
        GFXLine line;
    )
);

DEF_ENTITY
(
    BBox,
    BoundingShape,
    CONSTRUCTOR
    (
        global_matrixmodel = GFXGlobal<mat4f>::Get("MatrixModel0");
    ),
    PUBLIC
    (
        void Size(float x, float y, float z)
        {
            size = vec3f(x, y, z);
        }

        void DebugRender()
        {
            global_matrixmodel = node->GetTransform();
            std::vector<vec3f> points;
            points.push_back(vec3f(-size.x * 0.5f, -size.y * 0.5f, -size.z * 0.5f));
            points.push_back(vec3f(size.x * 0.5f, -size.y * 0.5f, -size.z * 0.5f));
            points.push_back(vec3f(size.x * 0.5f, -size.y * 0.5f, -size.z * 0.5f));
            points.push_back(vec3f(size.x * 0.5f, size.y * 0.5f, -size.z * 0.5f));
            points.push_back(vec3f(size.x * 0.5f, size.y * 0.5f, -size.z * 0.5f));
            points.push_back(vec3f(-size.x * 0.5f, size.y * 0.5f, -size.z * 0.5f));
            points.push_back(vec3f(-size.x * 0.5f, size.y * 0.5f, -size.z * 0.5f));
            points.push_back(vec3f(-size.x * 0.5f, -size.y * 0.5f, -size.z * 0.5f));
            points.push_back(vec3f(-size.x * 0.5f, -size.y * 0.5f, size.z * 0.5f));
            points.push_back(vec3f(size.x * 0.5f, -size.y * 0.5f, size.z * 0.5f));
            points.push_back(vec3f(size.x * 0.5f, -size.y * 0.5f, size.z * 0.5f));
            points.push_back(vec3f(size.x * 0.5f, size.y * 0.5f, size.z * 0.5f));
            points.push_back(vec3f(size.x * 0.5f, size.y * 0.5f, size.z * 0.5f));
            points.push_back(vec3f(-size.x * 0.5f, size.y * 0.5f, size.z * 0.5f));
            points.push_back(vec3f(-size.x * 0.5f, size.y * 0.5f, size.z * 0.5f));
            points.push_back(vec3f(-size.x * 0.5f, -size.y * 0.5f, size.z * 0.5f));
            points.push_back(vec3f(-size.x * 0.5f, -size.y * 0.5f, -size.z * 0.5f));
            points.push_back(vec3f(-size.x * 0.5f, -size.y * 0.5f, size.z * 0.5f));
            points.push_back(vec3f(size.x * 0.5f, -size.y * 0.5f, -size.z * 0.5f));
            points.push_back(vec3f(size.x * 0.5f, -size.y * 0.5f, size.z * 0.5f));
            points.push_back(vec3f(size.x * 0.5f, size.y * 0.5f, -size.z * 0.5f));
            points.push_back(vec3f(size.x * 0.5f, size.y * 0.5f, size.z * 0.5f));
            points.push_back(vec3f(-size.x * 0.5f, size.y * 0.5f, -size.z * 0.5f));
            points.push_back(vec3f(-size.x * 0.5f, size.y * 0.5f, size.z * 0.5f));
            line.Render(points);
        }
    ),
    PROTECTED
    (
        vec3f size;
        GFXGlobal<mat4f> global_matrixmodel;
        GFXLine line;
    )
);

DEF_ENTITY
(
    BSphere,
    BoundingShape,
    CONSTRUCTOR(),
    PUBLIC
    (
        void Radius(float r) {}
        
        void DebugRender()
        {

        }
    ),
    PROTECTED()
);

#endif