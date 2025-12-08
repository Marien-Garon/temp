#include "Circle.h"

void Circle::Draw(SDL_Renderer* renderer)
{
	struct pos { float x; float y; };
	std::vector<pos> pointsList;
	int precision = 360;

	float deltaangle = 2 * M_PI / precision;
	for (int i = 0; i < precision; i++)
	{
		float angle = (i * deltaangle);
		int posX = rect.x + cos(angle) * rect.w;
		posX > 800 ? posX -= 800 : posX < 0 ? posX += 800 : posX+= 0;

		int posY = rect.y + sin(angle) * rect.h;
		posY > 800 ? posY -= 800 : posY < 0 ? posY += 800 : posY += 0;

		pos points = { posX, posY };
		pointsList.push_back(points);
	}

	for (int j = 0; j < pointsList.size() - 1; j++)
	{
		if ((abs(pointsList[j].x - pointsList[j + 1].x) + abs(pointsList[j].y - pointsList[j + 1].y)) > 400)
			continue;
		SDL_RenderDrawLine(renderer, pointsList[j].x, pointsList[j].y, pointsList[j + 1].x, pointsList[j + 1].y);
	}
	int p1 = pointsList.size() - 1;

	if ((abs(pointsList[0].x - pointsList[p1].x) + abs(pointsList[0].y - pointsList[p1].y)) > 400)
		return;
	SDL_RenderDrawLine(renderer, pointsList[p1].x, pointsList[p1].y, pointsList[0].x, pointsList[0].y);
}

bool Circle::isCollided(Circle* circ)
{
	//if ((rect.x < forme->rect.x + forme->rect.w && rect.x + rect.w > forme->rect.x && rect.y < forme->rect.y + forme->rect.h && rect.y + rect.h > forme->rect.y))

	//SDL_Rect circRect = circ->GetRect();
	int radiusW = circ->GetRadiusW();
	int radiusH = circ->GetRadiusH();

	int distance = (int)position.Distance(&circ->position);

	//std::cout << "distance: " << distance << " true :" << (radiusW + GetRadiusW() + radiusH + GetRadiusH()) / 2 << "\n";
	if (distance <= (radiusW + GetRadiusW() + radiusH + GetRadiusH()) / 2)
		return true;
	


	return false;
}

