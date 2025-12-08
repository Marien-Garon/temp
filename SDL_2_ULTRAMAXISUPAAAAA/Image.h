#pragma once
#include "Geometry.h"
#include <string>
#include "AssetManager.h"

class Image : Geometry
{
private:
	SDL_Texture* texture;

public:

	Image(SDL_Renderer* renderer, std::string id, SDL_Rect rect) :
		Geometry(rect.x, rect.y, rect.w, rect.h)
	{
		texture = AssetsManager::getInstance().GetTexture(id);
	}

	~Image() { SDL_DestroyTexture(texture); };


	SDL_Texture* GetTexture() { return texture; };
	SDL_Rect* GetRect() { return &rect; };

	void Draw(SDL_Renderer* renderer) override;

};

