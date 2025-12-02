#pragma once
#include "Geometry.h"

class Rectangle : public Geometry
{

public:

	Rectangle(SDL_Rect rect) :
		Geometry(rect) {}

	void Draw(SDL_Renderer* renderer) override;
};

