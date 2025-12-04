#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include "InputManager.h"
#include "Image.h"
#include "Circle.h"

class Game 
{
private:

	SDL_Renderer* renderer;
	SDL_Window* window;


public:

	void HandleInput();

	void init();

	void Update();

	void Close();

};

