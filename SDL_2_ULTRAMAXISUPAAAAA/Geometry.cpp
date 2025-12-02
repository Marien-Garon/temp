#include "Geometry.h"

void Geometry::SetPosition(int x, int y, float anchorX, float anchorY)
{
	rect.x = x + anchorX * rect.w;
	rect.y = y + anchorY * rect.h;
}

Vector2D Geometry::GetPosition(float anchorX, float anchorY)
{

}
