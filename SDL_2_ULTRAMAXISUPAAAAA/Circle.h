#pragma once
#include <vector>
#include "Geometry.h"

class Circle : public Geometry
{
public:

	Circle(SDL_Rect rect):
		Geometry(rect) {}

	void Draw(SDL_Renderer* renderer) override;
};

