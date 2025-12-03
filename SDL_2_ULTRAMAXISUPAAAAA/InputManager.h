#pragma once
#include <SDL.h>
#include <unordered_map>
#include <string>
#include <iostream>

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

	void update()
	{
		SDL_Event event;

		while ((SDL_PollEvent(&event) != 0))
		{
			if (event.type == SDL_QUIT)
				break;


			else if (event.type == SDL_KEYDOWN)
			{

				keyMap[event.key.keysym.sym] = { true, false, true };

				if (event.key.keysym.sym == SDLK_ESCAPE)
					break;

				if (event.key.keysym.sym == SDLK_a)
					std::cout << "A down" << std::endl;
			}
			else if (event.type == SDL_KEYUP)
			{
				keyMap[event.key.keysym.sym] = { false, true, false };

				if (event.key.keysym.sym == SDLK_a)
					std::cout << "A release" << std::endl;
			}


			else if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				mouseMap[(int)event.button.button] = { true, false, true };
				std::cout << "button : " << (int)event.button.button << " x : " << event.button.x << " y : " << event.button.y << std::endl;
			}
			else if (event.type == SDL_MOUSEBUTTONUP)
			{
				mouseMap[(int)event.button.button] = { false, true, false };
				std::cout << "button : " << (int)event.button.button << " x : " << event.button.x << " y : " << event.button.y << std::endl;
			}
		}
	}

};

