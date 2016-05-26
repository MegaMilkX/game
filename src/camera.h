#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "scene.h"

class Camera
{
public:
    static Camera* Create(Scene& scene);
};

#endif