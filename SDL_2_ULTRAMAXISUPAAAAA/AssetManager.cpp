#include "AssetManager.h"

SDL_Texture* AssetManager::LoadImage(SDL_Renderer* renderer, std::string path)
{
    SDL_Surface* lettuce_sur = IMG_Load(path.c_str());
    if (lettuce_sur == NULL)
        return nullptr;

    SDL_Texture* lettuce_tex = SDL_CreateTextureFromSurface(renderer, lettuce_sur);
    if (lettuce_tex == NULL)
        return nullptr;

    SDL_FreeSurface(lettuce_sur);

    return lettuce_tex;
}
