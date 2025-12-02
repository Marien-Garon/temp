#pragma once
#include "Geometry.h"
#include <string>
#include "AssetManager.h"

class Image : Geometry
{
private:
	SDL_Texture* texture;

public:

	Image(SDL_Renderer* renderer, std::string path, SDL_Rect rect) :
		Geometry(rect)
	{
		texture = AssetManager::LoadImage(renderer, path);
	}

	void Draw(SDL_Renderer* renderer) override;

};

