#include "AssetManager.h"


/*
Mode : 
0 = joue une fois,
1 = boucle une fois,
-1 = boucle infinie

Volume:
0 - 128
*/
void AssetsManager::PlaySoundEffect(std::string id, int mode, int volume)
{
    if (soundMap.count(id))
    {
        Mix_Chunk* sound = soundMap[id];
        Mix_VolumeChunk(sound, 64);
        Mix_PlayChannel(-1, sound, mode);
    }
    else
        std::cout << "[Sound] " << id <<" : son introuvable" << std::endl;
}

/*
Mode :
0 = joue une fois,
1 = boucle une fois,
-1 = boucle infinie
*/
void AssetsManager::PlayMusic(std::string id, int mode)
{
    if (musicMap.count(id))
        Mix_PlayMusic(musicMap[id], mode);
    else
        std::cout << "[Music] " << id << " : musique introuvable" << std::endl;
}

bool AssetsManager::LoadMusic(std::string path, std::string id)
{
    Mix_Music* music = Mix_LoadMUS(path.c_str());
    if (!music)
    {
        SDL_Log("[Music] Erreur chargement musique: %s", Mix_GetError());
        return false;
    }
    
    musicMap[id] = music;
    return true;
}

bool AssetsManager::LoadSound(std::string path, std::string id)
{
    Mix_Chunk* sound = Mix_LoadWAV(path.c_str());
    if (!sound)
    {
        SDL_Log("[Sound] Erreur chargement son: %s", Mix_GetError()); //y a besoin du %s sinon il rale
        return false;
    }

    soundMap[id] = sound;
    return true;
}

SDL_Texture* AssetsManager::LoadTexture(SDL_Renderer* renderer, std::string path, std::string id)
{
    if (textureMap.count(id))
        return textureMap[id];

    SDL_Surface* lettuce_sur = IMG_Load(path.c_str());
    if (lettuce_sur == NULL)
    {
         std::cout << "[Image] impossible de trouver l'image au chemin suivant : " << path << std::endl;
         return nullptr;
    }


    SDL_Texture* lettuce_tex = SDL_CreateTextureFromSurface(renderer, lettuce_sur);
    if (lettuce_tex == NULL)
    {
        std::cout << "[Image] impossible de creer la texture : " << path << std::endl;
        return nullptr;
    }

    SDL_FreeSurface(lettuce_sur);


    textureMap[id] = lettuce_tex;
    return lettuce_tex;
}

void AssetsManager::DeleteAllTexture()
{
    for (auto& pair : textureMap)
    {
        SDL_DestroyTexture(pair.second);
    }

    textureMap.clear();
}

void AssetsManager::DeleteAllSound()
{
    for (auto& pair : soundMap)
    {
        Mix_FreeChunk(pair.second);
    }

    soundMap.clear();
}

void AssetsManager::DeleteAllMusic()
{
    for (auto& pair : musicMap)
    {
        Mix_FreeMusic(pair.second);
    }

    musicMap.clear();
}

