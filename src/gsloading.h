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
        
        mesh = Resource<GFXMesh>::Get("cube");
        //shader = Resource<GFXMesh>::Get("shader");
        
        perspective_ = ::perspective(1.5f, 16.0f/9.0f, 0.1f, 100.0f);
        camera_transform.Translate(0.0f, -0.0f, -1.7f);

        ResHdl<GFXTexture2D> texture = Resource<GFXTexture2D>::Get("250px-162Furret");
        texture->Use(0);
        
        GFXS::Position3D pos3d;
        pos3d.pos = GFXS::Position();
        shader.Transform(pos3d);
        GFXS::Texture2DColor tex2dcol;
        tex2dcol.texture_sampler = GFXS::Texture2D();
        tex2dcol.uv = GFXS::UV();
        //shader = tex2dcol;
        //GFXS::Multiply3f mult;
        //mult.a = GFXS::Position();
        //mult.b = GFXS::Normal();
        shader.Color(tex2dcol);
        shader.Compile();

        std::cout << shader.StatusString();

        GFXGlobal<mat4f>::Get("MatrixModel0") = transform.GetTransform();
        GFXGlobal<mat4f>::Get("MatrixView0") = camera_transform.GetTransform();
        GFXGlobal<mat4f>::Get("MatrixPerspective0") = perspective_;
        GFXGlobal<int>::Get("Texture2D0") = 0;

        std::string validate_result;
        shader.Validate(validate_result);
        std::cout << validate_result;
    }
    void OnSwitch()
    {
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        mesh->Bind();
    }
    void OnUpdate()
    {
        time = GetTickCount();
        transform.Rotate(0.01f, vec3f(0.0f, 1.0f, 0.0f));
        transform.Rotate(-0.05f, vec3f(1.0f, 0.0f, 0.0f));
        GFXGlobal<mat4f>::Get("MatrixModel0") = transform.GetTransform();
        shader.Bind();
        /*
        if (time - start_time >= 5000)
        {
            GameState::Pop();
        }*/
    }
    void OnRender()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
    ResHdl<GFXMesh> mesh;
    Transform camera_transform;
    Transform transform;
    mat4f perspective_;
    
    GFXShader shader;
};

#endif