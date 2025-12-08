#pragma once
#include <SDL.h>
#include "Vector2D.h"


class Geometry 
{
protected:

	Vector2D position;
	
	int width;
	int height;

	SDL_Rect rect;


public:

	Geometry(int x, int y, int w, int h) :
		position({ (float)x, (float)y }),
		width(w),
		height(h)
	{ 
		rect = { x, y, w, h};
	}

	void SetPositionAnchor(int x, int y, float anchorX, float anchorY);
	Vector2D GetPositionAnchor(float anchorX, float anchorY);

	SDL_Rect GetRect() { return rect; };

	Vector2D GetPosition() { return position; };

	void Move(Vector2D movement);

	void SetPosition(Vector2D newPos);

	void UpdateRect();

	virtual bool isCollided(Geometry* forme);

	virtual void Draw(SDL_Renderer* renderer) = 0;
};

