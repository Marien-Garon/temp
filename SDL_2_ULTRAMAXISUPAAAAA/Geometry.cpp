#include "Geometry.h"

void Geometry::SetPosition(int x, int y, float anchorX, float anchorY)
{
	rect.x = x + anchorX * rect.w;
	rect.y = y + anchorY * rect.h;

	if (rect.x < 0) rect.x += 800;
	if (rect.x > 800) rect.x -= 800;

	if (rect.y < 0) rect.y += 800;
	if (rect.y> 800) rect.y -= 800;
}

Vector2D Geometry::GetPosition(float anchorX, float anchorY)
{
	Vector2D pos;
	pos.x = rect.x + anchorX * rect.w;
	pos.y = rect.y + anchorY * rect.h;

	return pos;
}

bool Geometry::isCollided(Geometry* forme)
{
	if (rect.x + rect.w)
		
	return false;
}
