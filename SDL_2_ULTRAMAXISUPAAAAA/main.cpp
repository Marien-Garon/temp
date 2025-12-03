#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include "Rectangle.h"
#include "Circle.h"
#include "Image.h"
#include "InputManager.h"

//THATS A JOKE 
double pi = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823;


struct pos { int x; int y; };

void handleInput()
{
	SDL_Event event;
	std::vector<SDL_KeyboardEvent> key;
	InputManager im = InputManager::getInstance();

	while (true)
	{
		im.update();

		if (im.IsKeyDown('a'))
			std::cout << "a : down" << std::endl;
		if (im.IsKeyReleased('a'))
			std::cout << "a : released" << std::endl;
		if (im.IsMouseDown(0))
			std::cout << "Clic gauche" << std::endl;

	}
}


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
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
	{
		std::cout << "SDL_Init_Error :  " << SDL_GetError() << std::endl;
		return 1;
	}

	if (IMG_Init(IMG_INIT_PNG) == 0) {
		std::cout << "Error SDL2_image Initialization";
		return 2;
	}

	SDL_Window* window;
	SDL_Renderer* renderer;


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
	//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	////SDL_RenderDrawPoint(renderer, 20, 20);
	//DrawHorizontalLine(renderer, 20, 21, 300);
	//DrawVerticallLine(renderer, 20, 22, 300);
	//SDL_RenderPresent(renderer);

	//SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	//DrawLine(renderer, 100, 100, 10, 10);
	////SDL_RenderDrawPoint(renderer, 10, 10);
	//DrawRectangle(renderer, 50, 50, 100, 100);
	//SDL_RenderDrawLine(renderer,0, 0, 50 ,20);

	//SDL_Rect rect = { 150, 150, 100, 100 };
	//SDL_RenderDrawRect(renderer, &rect);

	//DrawCircle(renderer, 300, 300, 100, 50);
	//Idk why but it's a feature now
	//SDL_Rect rect = { 300, 300, 50, 50 };

	//Rectangle rectangle1 = { rect };
	//rectangle1.SetPosition(0, 0, 0.5, 0.5);
	//rectangle1.Draw(renderer);

	//Rectangle rectangle2 = { rect };
	//rectangle2.SetPosition(0, 0, 0, 0);
	//rectangle2.Draw(renderer);

	//Rectangle rectangle3 = { rect };
	//rectangle3.SetPosition(0, 0, 1, 1);
	//rectangle3.Draw(renderer);

	//Rectangle rectangle4 = { rect };
	//rectangle4.SetPosition(0, 0, 1, 0.5);
	//rectangle4.Draw(renderer);

	//Rectangle rectangle5 = { rect };
	//rectangle5.SetPosition(0, 0, 0.5, 1);
	//rectangle5.Draw(renderer);

	/*Circle circle = { rect };
	circle.Draw(renderer);*/


	//DrawLine(renderer, 100, 100, 350, 200);

	SDL_Rect rect = { 0, 0, 410, 300 };

	Image img = { renderer, "../image/lettuce.png", rect };
	img.Draw(renderer);


	SDL_RenderPresent(renderer);
	//SDL_UpdateWindowSurface(window);



	std::cout << "Game Loop" << std::endl;
	handleInput();

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	IMG_Quit();
	SDL_Quit();

	return 0;
}
