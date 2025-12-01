#include <SDL.h>
#include <iostream>
#include <vector>


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

void DrawLine(SDL_Renderer* renderer, int x, int y, int x2, int y2)
{
	for (int i = 0; i < 10; i++)
	{
		SDL_RenderDrawPoint(renderer, x , y );
	}
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
		//SDL_RenderDrawPoint(renderer, points.x, points.y);
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
	DrawLine(renderer, 100, 100, 10, 10);
	//SDL_RenderDrawPoint(renderer, 10, 10);

	DrawRectangle(renderer, 50, 50, 100, 100);


	SDL_RenderDrawLine(renderer,0, 0, 50 ,20);

	SDL_Rect rect = { 150, 150, 100, 100 };
	SDL_RenderDrawRect(renderer, &rect);

	DrawCircle(renderer, 300, 300, 100, 50);

	SDL_RenderPresent(renderer);
	//SDL_UpdateWindowSurface(window);

	


	system("pause");
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}