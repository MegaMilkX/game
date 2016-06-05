#ifndef _GSLOADING_H_
#define _GSLOADING_H_

#include <Windows.h>

#include "GameState.h"

#include "gui.h"
#include "scene.h"
#include "renderable.h"
#include "camera.h"
#include "lightomni.h"
#include "bounding-shape.h"

#include <string>
#include <iostream>

class ActCamMove : public Action
{
public:
    ActCamMove(Camera* cam) : camera(cam)
    {}
    void Execute()
    {
        camera->Rotate(InputMouse::GetXRel() * -0.005f, vec3f(0.0f, 1.0f, 0.0f));
        camera->Rotate(InputMouse::GetYRel() * -0.005f, vec3f(1.0f, 0.0f, 0.0f), Space::WORLD);
    }

    ActCamMove* clone() { return new ActCamMove(*this); }
private:
    Camera* camera;
};

class GSLoading : public GameState
{
public:
    GSLoading() : start_time(0), time(0) {}
    void OnInit();
    void OnSwitch();
    void OnUpdate();
    void OnRender();
    void OnCleanup();

private:
    DWORD start_time;
    DWORD time;
    
    Scene scene;
    Camera* camera;
    Camera* camera2;
    Renderable* cube;
    Renderable* cube2;

    GFXLine line;

    GUI gui;
};

#endif