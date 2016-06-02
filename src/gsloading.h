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

class GSLoading : public GameState
{
public:
    GSLoading() : start_time(0), time(0) {}
    void OnInit()
    {
        start_time = GetTickCount();

        gui.Init();
        
        GFXGlobal<int>::Get("Texture2D0") = 0;

        camera = scene.Add<Camera>();
        camera->Translate(0.0f, 0.0f, -2.7f);
        camera->Perspective(1.5f, 16.0f / 9.0f, 0.1f, 100.0f);

        cube = scene.Add<Renderable>();
        cube->Mesh(Resource<GFXMesh>::Get("cube"));
        cube->Material(Resource<GFXMaterial>::Get("material"));
        cube->Translate(-0.3f, 0.0f, 0.0f);

        
        
        cube2 = cube->GetNode()->AddNode()->Add<Renderable>();
        cube2->Translate(1.4f, 0.0f, 0.0f);
        cube2->Material(Resource<GFXMaterial>::Get("material"));

        BBox* bbox = cube2->GetNode()->Add<BBox>();
        bbox->Size(1.0f, 1.0f, 1.0f);

        LightOmni* omni = scene.Add<LightOmni>();

        //GUIImage* gui_image = gui.AddElement<GUIImage>();
        //gui_image->
    }
    void OnSwitch()
    {
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        
    }
    void OnUpdate()
    {
        time = GetTickCount();
        cube->Rotate(0.01f, vec3f(0.0f, 1.0f, 0.0f));
        cube2->Rotate(0.01f, vec3f(1.0f, 0.0f, 0.0f));

        
        //cube->Rotate(-0.05f, vec3f(1.0f, 0.0f, 0.0f));

        /*
        if (time - start_time >= 5000)
        {
            GameState::Pop();
        }*/
    }
    void OnRender()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        camera->Render();
        //gui.Render();
    }
    void OnCleanup()
    {

    }

private:
    DWORD start_time;
    DWORD time;
    
    Scene scene;
    Camera* camera;
    Renderable* cube;
    Renderable* cube2;

    GUI gui;
};

#endif