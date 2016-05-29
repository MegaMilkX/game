#ifndef _GUI_H_
#define _GUI_H_

#include "scene.h"
#include "camera.h"

DEF_ENTITY
(
    GUIElement,
    Entity,
    CONSTRUCTOR(),
    PUBLIC(),
    PROTECTED()
);

DEF_ENTITY
(
    GUIImage,
    GUIElement,
    CONSTRUCTOR(),
    PUBLIC(),
    PROTECTED()
);

class GUI
{
public:
    void Init()
    {
        cam = scene.Add<Camera>();
        cam->Ortho(0, 100, 0, 100, 0.1f, 100.0f);
    }
    void Render()
    {
        cam->Render();
    }
    template<typename GUIELEM>
    GUIELEM* AddElement()
    {
        return scene.Add<GUIELEM>();
    }
private:
    Scene scene;
    Camera* cam;
};

#endif