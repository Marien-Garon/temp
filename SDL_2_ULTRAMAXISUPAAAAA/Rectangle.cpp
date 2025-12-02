#include "Rectangle.h"




void Rectangle::Draw(SDL_Renderer* renderer)
{
	SDL_RenderDrawLine(renderer, rect.x, rect.y, rect.x + rect.w, rect.y);
	SDL_RenderDrawLine(renderer, rect.x, rect.y, rect.x, rect.y + rect.h);
	SDL_RenderDrawLine(renderer, rect.x + rect.w, rect.y, rect.x + rect.w, rect.y + rect.h);
	SDL_RenderDrawLine(renderer, rect.x, rect.y + rect.h, rect.x + rect.w, rect.y + rect.h);
}