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

	void Font(ResHdl<GFXFont> fnt) { font = fnt; }

	void Text(const std::string& txt, unsigned char size)
	{
		this->size = size;
		text = txt;
		mesh = font->MakeString(txt, size);
	}

	void Render()
	{
		global_matrixmodel = node->GetTransform();
		font->Bind(size);
		mesh.Render();
	}

protected:
	unsigned char size;
	std::string text;
	GFXMesh mesh;
	GFXGlobal<mat4f> global_matrixmodel;
	ResHdl<GFXFont> font;
};
/*
DEF_ENTITY
(
	TextRenderable,
	IRenderable,
	CONSTRUCTOR
	(
		mesh = GFXMesh::Create(GFXMesh::DYNAMIC);
	),
	PUBLIC
	(
		void Text(const std::string& txt)
		{ 
			text = txt;
			std::vector<Vertex> vertices;
			std::vector<unsigned short> indices;

			float advance_x;
			float advance_y;

			for (unsigned int i = 0; i < text.size(); ++i)
			{


				vertices +=
				({
					{ vec3f(advance_x + -0.5f, advance_y + -0.5f, 0.0f), vec3f(0.5f, 0.1f, 0.1f), vec2f(1.0f, 0.0f) },
					{ vec3f(advance_x + 0.5f, advance_y + -0.5f, 0.0f), vec3f(0.5f, 0.3f, 0.1f), vec2f(0.0f, 0.0f) },
					{ vec3f(advance_x + 0.5f, advance_y + 0.5f, 0.0f), vec3f(0.5f, 0.1f, 0.1f), vec2f(0.0f, 1.0f) },
					{ vec3f(advance_x + -0.5f, advance_y + 0.5f, 0.0f), vec3f(0.5f, 0.3f, 0.1f), vec2f(1.0f, 1.0f) }
				});

				indices += ({ 0, 1, 2, 2, 0, 3 });

				advance_x += 1.0f;
				advance_y += 0.0f;
			}

			mesh.SetVertices(vertices);
			mesh.SetIndices(indices);
		}
	),
	PROTECTED
	(
		std::string text;
		GFXMesh mesh;
	)
);
*/
#endif