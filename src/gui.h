#ifndef _GUI_H_
#define _GUI_H_

class GUINode
{
public:
    struct AABB
    {};
private:
};

class GUI
{
public:
    GUINode* Root();
    void Render();
private:
};

#endif