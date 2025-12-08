#pragma once
#include "Vector2D.h"
#include "SDL.h"
#include "Geometry.h"


class Particle
{
private:

	Vector2D pos;
	Vector2D velocity;

	SDL_Color color;

	Geometry* forme; //A delete plus tard

	float lifeDuration;

	float size;

public:
	
	void Update();


};

