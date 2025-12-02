#include "Circle.h"

void Circle::Draw(SDL_Renderer* renderer)
{
	struct pos { float x; float y; };
	std::vector<pos> pointsList;

	float deltaangle = 2 * M_PI / 360;
	for (int i = 0; i < 360; i++)
	{
		float angle = (i * deltaangle);

		pos points = { rect.x + cos(angle) * rect.w, rect.x + sin(angle) * rect.h };
		pointsList.push_back(points);
	}

	for (int j = 0; j < pointsList.size() - 1; j++)
	{
		SDL_RenderDrawLine(renderer, pointsList[j].x, pointsList[j].y, pointsList[j + 1].x, pointsList[j + 1].y);
	}
	int p1 = pointsList.size() - 1;

	SDL_RenderDrawLine(renderer, pointsList[p1].x, pointsList[p1].y, pointsList[0].x, pointsList[0].y);
}
