#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "scene.h"
#include "entity.h"

#include <libgame.h>

class Sprite : public IRenderable
{
	ENTITY_BODY
	(
		Sprite, IRenderable,
		CONSTRUCTOR
		(
		)
	)

public:
	void SetSprite(std::string map, std::string sprite)
	{
		this->sprite = GFXSprite(map, sprite);
	}
	void SetSprite(std::string map, unsigned index)
	{
		sprite = GFXSprite(map, index);
	}
	void Render()
	{
		global_matrixmodel = node->GetTransform();
		sprite.Render();
	}
protected:
	GFXSprite sprite;
	GFXGlobal<mat4f> global_matrixmodel;
};

#endif