#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>
#include <vector>
#include "InputManager.h"
#include "Image.h"
#include "Rectangle.h"
#include "Circle.h"

class Game 
{
private:

	SDL_Renderer* renderer;
	SDL_Window* window;


public:

	void loop();

	bool init();

	//void Update();

	void Close();

};

