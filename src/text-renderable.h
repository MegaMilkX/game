#ifndef _TEXT_RENDERABLE_H_
#define _TEXT_RENDERABLE_H_

#include "scene.h"
#include "entity.h"

#include <libgame.h>

class TextRenderable : public IRenderable
{
	ENTITY_BODY
	(
		TextRenderable, IRenderable,
		CONSTRUCTOR
		(
		)
	)

public:
	enum ALIGN
	{
		LEFT = 1,
		RIGHT = 2,
		TOP = 4,
		BOTTOM = 8,
		HCENTER = LEFT | RIGHT,
		VCENTER = TOP | BOTTOM
	};

	void Font(const std::string& font_name) { string.Font(font_name); }
	void Size(unsigned char size) { string.Size(size); }
	void Align(int align) { string.Align(align); }
	void Text(const std::string& txt) { string = txt; }

	void Render()
	{
		global_matrixmodel = node->GetTransform();
		string.Render();
	}

protected:
	GFXString string;
	GFXGlobal<mat4f> global_matrixmodel;
};

#endif