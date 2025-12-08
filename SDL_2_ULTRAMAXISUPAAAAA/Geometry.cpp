#include "Geometry.h"

void Geometry::SetPositionAnchor(int x, int y, float anchorX, float anchorY)
{
	rect.x = x + anchorX * rect.w;
	rect.y = y + anchorY * rect.h;

	if (rect.x < 0) rect.x += 800;
	if (rect.x > 800) rect.x -= 800;

	if (rect.y < 0) rect.y += 800;
	if (rect.y> 800) rect.y -= 800;
}

Vector2D Geometry::GetPositionAnchor(float anchorX, float anchorY)
{
	Vector2D pos;
	pos.x = rect.x + anchorX * rect.w;
	pos.y = rect.y + anchorY * rect.h;

	return pos;
}

void Geometry::Move(Vector2D movement)
{
	position += movement;
	
	UpdateRect();
}

void Geometry::SetPosition(Vector2D newPos)
{
	position = newPos;

	UpdateRect();
}

void Geometry::UpdateRect()
{
	rect.x = (int)position.x;
	rect.y = (int)position.y;
	rect.w = width;
	rect.h = height;

}

bool Geometry::isCollided(Geometry* forme)
{
	//jcrois c'est bugge avec le cercle
	if ((rect.x < forme->rect.x + forme->rect.w && rect.x + rect.w > forme->rect.x && rect.y < forme->rect.y + forme->rect.h && rect.y + rect.h > forme->rect.y))
		return true;

	return false;
}
