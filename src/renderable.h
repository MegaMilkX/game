#ifndef _RENDERABLE_H_
#define _RENDERABLE_H_

#include "scene.h"

class Renderable
{
public:
    static Renderable* Create(Scene& scene);
};

#endif