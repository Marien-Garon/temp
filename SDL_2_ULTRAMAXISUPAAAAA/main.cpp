#include <SDL.h>
#include <iostream>
#include <vector>
#include "Rectangle.h"
#include "Circle.h"

//THATS A JOKE 
double pi = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823;


struct pos { int x; int y; };

void DrawHorizontalLine(SDL_Renderer* renderer, int x, int y, int length) 
{
	for (int i = 0;  i < length; i++)
		SDL_RenderDrawPoint(renderer, x+i, y);
}

void DrawVerticallLine(SDL_Renderer* renderer, int x, int y, int length)
{
	for (int i = 0; i < length; i++)
		SDL_RenderDrawPoint(renderer, x, y+i);
}

void PlacePoint(SDL_Renderer* renderer,pos p1, pos p2)
{

	int d = abs(p1.x - p2.x) + abs(p1.y - p2.y);
	
	if (d < 3)
		return;

	pos milieu;
	milieu.x = (int)(p1.x + p2.x) / 2;
	milieu.y = (int)(p1.y + p2.y) / 2;

	SDL_RenderDrawPoint(renderer, milieu.x, milieu.y);
	PlacePoint(renderer, milieu, p1);
	PlacePoint(renderer, milieu, p2);
}

void DrawLine(SDL_Renderer* renderer, int x, int y, int x2, int y2)
{
	pos pos1 = { x, y };
	pos pos2 = { x2, y2 };

	PlacePoint(renderer, pos1, pos2);

}

void DrawRectangle(SDL_Renderer* renderer, int x, int y, int width, int height)
{
	DrawHorizontalLine(renderer, x, y, width);
	DrawVerticallLine(renderer, x, y, height);
	DrawHorizontalLine(renderer, x, y + height, width);
	DrawVerticallLine(renderer, x + width, y, height);
}

void DrawCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius, int precision)
{
	struct pos { float x; float y; };
	std::vector<pos> pointsList;

	float deltaangle = 2*M_PI / precision;
	for (int i = 0; i < precision; i++)
	{
		float angle = (i * deltaangle);

		pos points = {centerX + cos(angle) * radius, centerY + sin(angle) * radius};
		pointsList.push_back(points);
	}

	for (int j = 0; j < pointsList.size() - 1; j++)
	{
		SDL_RenderDrawLine(renderer, pointsList[j].x, pointsList[j].y, pointsList[j+1].x, pointsList[j+1].y);
	}
	int p1 = pointsList.size() - 1;

	SDL_RenderDrawLine(renderer, pointsList[p1].x, pointsList[p1].y, pointsList[0].x, pointsList[0].y);
}



int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO)!= 0)
	{
		std::cout << "SDL_Init_Error :  " << SDL_GetError() << std::endl;
		return 1;
	}
	

	SDL_Window *window;
	SDL_Renderer *renderer;


	SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_RESIZABLE, &window, &renderer);


	if (!window)
	{
		std::cout << "SDL_CreateWindow_Error : " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	if (!renderer) {
		std::cout << "Renderer_error : " << SDL_GetError() << std::endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}


	//SDL_Surface* winSurface = SDL_GetWindowSurface(window);

	//if (!winSurface) {
	//	std::cout << "Surface_error : " << SDL_GetError() << std::endl;
	//	SDL_DestroyWindow(window);
	//	SDL_Quit();
	//	return 1;
	//}



	//SDL_FillRect(winSurface, NULL, SDL_MapRGB(winSurface->format, 255, 255, 255));


	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	//SDL_RenderDrawPoint(renderer, 20, 20);
	DrawHorizontalLine(renderer, 20, 21, 300);
	DrawVerticallLine(renderer, 20, 22, 300);
	SDL_RenderPresent(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	//DrawLine(renderer, 100, 100, 10, 10);
	////SDL_RenderDrawPoint(renderer, 10, 10);

	//DrawRectangle(renderer, 50, 50, 100, 100);


	//SDL_RenderDrawLine(renderer,0, 0, 50 ,20);

	//SDL_Rect rect = { 150, 150, 100, 100 };
	//SDL_RenderDrawRect(renderer, &rect);

	//DrawCircle(renderer, 300, 300, 100, 50);

	//Idk why but it's a feature now
	SDL_Rect rect = {300, 300, 40, 100};

	//Rectangle rectangle = { rect };
	//rectangle.Draw(renderer);

	Circle circle = { rect };
	circle.Draw(renderer);


	DrawLine(renderer, 100, 100, 350, 200);

	SDL_RenderPresent(renderer);
	//SDL_UpdateWindowSurface(window);

	


	system("pause");
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}