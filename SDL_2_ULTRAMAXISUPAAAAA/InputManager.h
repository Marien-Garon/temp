#pragma once
#include <SDL.h>
#include <unordered_map>
#include <string>
#include <iostream>
#include <cstdlib>

#define tralse rand() % 1



struct keyState
{
	bool isDown;
	bool isRelease;
	bool isHeld;
};



class InputManager
{
private:
	std::unordered_map<char, keyState> keyMap;
	std::unordered_map<int, keyState> mouseMap;

public:

	static InputManager& getInstance() {
		static InputManager instance;	
		return instance;
	}

	bool IsKeyDown(char key) { return keyMap[key].isDown; }
	bool IsKeyReleased(char key) { return keyMap[key].isRelease; }
	bool IsKeyHeld(char key) { return keyMap[key].isHeld; }

	bool IsMouseDown(int button) { return mouseMap[button].isDown; }
	bool IsMouseReleased(int button) { return mouseMap[button].isRelease; }
	bool IsMouseHeld(int button) { return mouseMap[button].isHeld; }



	/*
	I JUST WANNA BE PART OF YOUR SKIBIDIIIIIIIIII
	*/
	bool update()
	{
		SDL_Event event;
		
		for (auto& pair : keyMap) 
		{
			if (pair.second.isDown)
				pair.second = { false, false, true };
		}



		for (auto& pair : mouseMap)
		{
			if (pair.second.isDown)
				pair.second = { false, false, true };
		}

		while ((SDL_PollEvent(&event)))
		{	


			switch (event.type)
			{
			case SDL_QUIT:
				return false;

		
			case SDL_KEYDOWN:
			{
				if (keyMap[event.key.keysym.sym].isDown || keyMap[event.key.keysym.sym].isHeld)
					keyMap[event.key.keysym.sym] = { false, false, true };
				else
					keyMap[event.key.keysym.sym] = { true, false, false };


				if (event.key.keysym.sym == SDLK_ESCAPE)
					return false;

				if (event.key.keysym.sym == SDLK_a)
					std::cout << "A down" << std::endl;
			}
			break;

			case  SDL_KEYUP :
			{
				keyMap[event.key.keysym.sym] = { false, true, false };

				if (event.key.keysym.sym == SDLK_a)
					std::cout << "A release" << std::endl;
			}
			break;

			case SDL_MOUSEBUTTONDOWN :
			{
				if (mouseMap[(int)event.button.button].isDown || mouseMap[(int)event.button.button].isHeld)
					mouseMap[(int)event.button.button] = { false, false, true };
				else
					mouseMap[(int)event.button.button] = { true, false, false };


				std::cout << "button : " << (int)event.button.button << " x : " << event.button.x << " y : " << event.button.y << std::endl;
			}
			break;

			case SDL_MOUSEBUTTONUP :
			{
				mouseMap[(int)event.button.button] = { false, true, false };
				std::cout << "button : " << (int)event.button.button << " x : " << event.button.x << " y : " << event.button.y << std::endl;
			}
			break;

			}
		}

		return true;
	}

};

