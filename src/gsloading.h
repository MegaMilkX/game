#ifndef _GSLOADING_H_
#define _GSLOADING_H_

#include <Windows.h>

#include "GameState.h"

class GSLoading : public GameState
{
public:
    GSLoading() : start_time(0), time(0), scene(Scene::Create()) {}
    void OnInit()
    { 
        start_time = GetTickCount();
        
        camera = Camera::Create(&scene);
        cube = Renderable::Create(&scene);

        mesh = Resource<GFXMesh>::Get("cube");
        shader = Resource<GFXShader>::Get("shader");
        texture = Resource<GFXTexture2D>::Get("wallhaven-3635232");
        texture->Use(0);
        
        perspective_ = ::perspective(1.5f, 16.0f/9.0f, 0.1f, 100.0f);
        camera_transform.Translate(0.0f, -0.0f, -1.7f);

        //ResHdl<GFXFont> font = Resource<GFXFont>::Get("MagicCardsNormal");
        //font->Glyph(123, 16);
        //font->Glyph(12, 16);
        //font->Glyph(0xA9, 16);
        //std::cout << "poop";

        //GFXText text = GFXText::Create("magic", 16);
        

        GFXGlobal<mat4f>::Get("MatrixModel0") = transform.GetTransform();
        GFXGlobal<mat4f>::Get("MatrixView0") = camera_transform.GetTransform();
        GFXGlobal<mat4f>::Get("MatrixPerspective0") = perspective_;
        GFXGlobal<int>::Get("Texture2D0") = 0;
    }
    void OnSwitch()
    {
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        
    }
    void OnUpdate()
    {
        time = GetTickCount();
        transform.Rotate(0.01f, vec3f(0.0f, 1.0f, 0.0f));
        transform.Rotate(-0.05f, vec3f(1.0f, 0.0f, 0.0f));
        GFXGlobal<mat4f>::Get("MatrixModel0") = transform.GetTransform();
        
        /*
        if (time - start_time >= 5000)
        {
            GameState::Pop();
        }*/
    }
    void OnRender()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        mesh->Bind();
        shader->Bind();
        mesh->Render();
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
    ResHdl<GFXMesh> mesh;
    ResHdl<GFXShader> shader;
    ResHdl<GFXTexture2D> texture;
    Transform camera_transform;
    Transform transform;
    mat4f perspective_;
};

#endif