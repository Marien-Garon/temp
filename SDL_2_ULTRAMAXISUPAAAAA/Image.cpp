#include "Image.h"




void Image::Draw(SDL_Renderer* renderer)
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, &rect, NULL);
	return;
}
