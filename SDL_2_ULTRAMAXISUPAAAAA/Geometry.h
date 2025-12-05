#pragma once
#include <SDL.h>

struct Vector2D 
{
	float x;
	float y;
};


class Geometry 
{
protected:
	SDL_Rect rect;


public:

	Geometry(SDL_Rect rectVal) :
		rect(rectVal) {}

	void SetPosition(int x, int y, float anchorX, float anchorY);
	Vector2D GetPosition(float anchorX, float anchorY);

	bool isCollided(Geometry* forme);

	virtual void Draw(SDL_Renderer* renderer) = 0;
};

