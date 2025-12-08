#pragma once
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <string>
#include <map>
#include <unordered_map>
#include <iostream>



//Il est beau mon AssetManager nan ?
class AssetsManager
{
private:

	std::unordered_map<std::string, Mix_Chunk*> soundMap;
	std::unordered_map<std::string, Mix_Music*> musicMap;

	std::unordered_map<std::string, SDL_Texture*> textureMap;

public:

	static AssetsManager& getInstance() {
		static AssetsManager instance;
		return instance;
	}

	void PlaySoundEffect(std::string id, int mode, int volume = 64);

	void PlayMusic(std::string id, int mode);

	void SetMusicVolume(int volume) { Mix_VolumeMusic(volume); };


	void StopMusic() { Mix_HaltMusic(); };

	void PauseMusic() { Mix_PauseMusic(); };
	
	void ResumeMusic() { Mix_ResumeMusic(); };

	void StopAllSoundEffect() { Mix_HaltChannel(-1); };


	bool isMusicPlaying() { return (Mix_PlayingMusic() ? true : false); };

	bool IsMusicPaused() { return (Mix_PausedMusic() ? true : false); }


	bool LoadMusic(std::string path, std::string id);

	bool LoadSound(std::string path, std::string id);

	SDL_Texture* LoadTexture(SDL_Renderer* renderer, std::string path, std::string id);

	SDL_Texture* GetTexture(std::string id) { return (textureMap.count(id) ? textureMap[id] : nullptr); };


	void DeleteAllTexture();

	void DeleteAllSound();

	void DeleteAllMusic();

	void DeleteMusic(std::string id) { Mix_FreeMusic(musicMap[id]); };

	void DeleteTexture(std::string id) { SDL_DestroyTexture(textureMap[id]); };

	void DeleteSound(std::string id) { Mix_FreeChunk(soundMap[id]); };
};

