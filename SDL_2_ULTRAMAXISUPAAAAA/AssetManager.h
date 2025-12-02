#pragma once
#include <SDL_image.h>
#include <string>

class AssetManager
{
private:

public:

	static SDL_Texture* LoadImage(SDL_Renderer* renderer, std::string path);

};

