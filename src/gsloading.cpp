#include "gsloading.h"

void GSLoading::OnInit()
{
    start_time = GetTickCount();

    gui.Init();

    GFXGlobal<int>::Get("Texture2D0") = 0;

    camera = scene.Add<Camera>();
    camera->Translate(0.0f, 0.0f, 2.7f);
    camera->Rotate(0.7f, vec3f(0.0f, 1.0f, 0.0f));
    //camera->Translate(-1.0f, 1.5f, -2.7f);
    //camera->Rotate(0.5f, vec3f(0.0f, 1.0f, 0.0f));
    //camera->Rotate(0.5f, vec3f(1.0f, 0.0f, 0.0f));
    camera->Perspective(1.5f, 1280, 720, 0.1f, 100.0f);
    //camera->Ortho(-2.0f, 2.0f, -2.0f, 2.0f, 0.01f, 100.0f);

    camera2 = scene.Add<Camera>();
    camera2->Translate(0.0f, 0.0f, 2.7f);
    camera2->Rotate(0.5f, vec3f(0.0f, 1.0f, 0.0f));
    camera2->Rotate(0.5f, vec3f(1.0f, 0.0f, 0.0f));
    camera2->Perspective(1.5f, 1280, 720, 0.1f, 100.0f);

    cube = scene.Add<Renderable>();
    cube->Mesh(Resource<GFXMesh>::Get("cube"));
    cube->Material(Resource<GFXMaterial>::Get("material"));
    cube->Translate(-0.3f, 0.0f, 0.0f);

    cube2 = cube->GetNode()->AddNode()->Add<Renderable>();
    cube2->Translate(-1.4f, 0.0f, 0.0f);
    cube2->Material(Resource<GFXMaterial>::Get("material"));

    BSphere* s = cube->GetNode()->Add<BSphere>();
    s->Radius(0.7f);

    BBox* box = cube2->GetNode()->Add<BBox>();
    box->Size(1.0f, 1.0f, 1.0f);

    LightOmni* omni = scene.Add<LightOmni>();

	TextRenderable* paragraph = scene.Add<TextRenderable>();
	paragraph->Text("Hello");
	paragraph->Translate(0.0f, 1.0f, 0.0f);

    //GUIImage* gui_image = gui.AddElement<GUIImage>();
    //gui_image->

    InputMouse::SetMoveCallback(ActCamMove(camera->GetNode()));
}

void GSLoading::OnSwitch()
{
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    InputShowCursor(false);
}

void GSLoading::OnUpdate()
{
    time = GetTickCount();
    cube->Rotate(0.01f, vec3f(0.0f, 1.0f, 0.0f));
    cube2->Rotate(0.01f, vec3f(1.0f, 0.0f, 0.0f));

    if (InputKB::Key(0x57))
    {
        camera->Translate(camera->Forward() * 0.05f, Space::WORLD);
    }
    if (InputKB::Key(0x41))
    {
        camera->Translate(camera->Left() * 0.05f, Space::WORLD);
    }
    if (InputKB::Key(0x53))
    {
        camera->Translate(camera->Back() * 0.05f, Space::WORLD);
    }
    if (InputKB::Key(0x44))
    {
        camera->Translate(camera->Right() * 0.05f, Space::WORLD);
    }

    if (GetActiveWindow() == window.GetHandle())
    {
        RECT rect;
        GetWindowRect(window.GetHandle(), &rect);
        int x = rect.left, y = rect.top;
        GetClientRect(window.GetHandle(), &rect);
        SetCursorPos(rect.right / 2 + rect.left + x, rect.bottom / 2 + rect.top + y);
    }
    /*
    if (ResourceQueueCount() == 0)
    {
		GameState::Pop();
    }*/
}

void GSLoading::OnRender()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    camera->Render();

    GFXGlobal<mat4f>::Get("MatrixModel0") = mat4f(1.0f);
    Node* node = 0;
    vec3f point;
    node = scene.RayTest(camera->ScreenToWorld(vec2f(InputMouse::GetXNorm(), InputMouse::GetYNorm())), point);
    if (node)
    {
        if (InputKB::Key(VK_SPACE))
        {
            Renderable* r = node->AddNode()->Add<Renderable>();
            r->Material(Resource<GFXMaterial>::Get("material2"));
            r->Position(point, WORLD);
            r->Rotation(node->Rotation(), LOCAL);
            r->Scale(0.1f);
        }

        GFXGlobal<mat4f>::Get("MatrixView0") = inverse(camera->GetNode()->GetTransform());
        std::vector<vec3f> points;
        points.push_back(point - vec3f(0.5f, 0.0f, 0.0f));
        points.push_back(point + vec3f(0.5f, 0.0f, 0.0f));
        points.push_back(point - vec3f(0.0f, 0.5f, 0.0f));
        points.push_back(point + vec3f(0.0f, 0.5f, 0.0f));
        points.push_back(point - vec3f(0.0f, 0.0f, 0.5f));
        points.push_back(point + vec3f(0.0f, 0.0f, 0.5f));
        line.Render(points);
    }
}

void GSLoading::OnCleanup()
{

}
