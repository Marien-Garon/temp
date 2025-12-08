#pragma once
#include <vector>
#include "Geometry.h"

class Circle : public Geometry
{
public:

	Circle(SDL_Rect rect):
		Geometry(rect.x, rect.y, rect.w, rect.h) {}

	void Draw(SDL_Renderer* renderer) override;
};

