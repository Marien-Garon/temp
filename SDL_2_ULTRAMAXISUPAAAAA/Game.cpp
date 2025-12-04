#include "Game.h"

void Game::HandleInput()
{
	SDL_Event event;
	std::vector<SDL_KeyboardEvent> key;
	InputManager im = InputManager::getInstance();

	
	SDL_Rect rect = { 100, 100, 50, 50 };
	Circle circle = { rect };


	SDL_GetTicks();

	while (true)
	{
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		im.update();

		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		circle.Draw(renderer);
		SDL_RenderPresent(renderer);
		//if (im.IsKeyDown('a'))
		//	std::cout << "a : down" << std::endl;
		//if (im.IsKeyReleased('a'))
		//	std::cout << "a : released" << std::endl;
		//if (im.IsMouseDown(0))
		//	std::cout << "Clic gauche" << std::endl;

		if (im.IsKeyDown('z')) 
		{
			std::cout << "z pressed" << std::endl;
			circle.SetPosition(circle.GetPosition(0, 0).x, circle.GetPosition(0, 0).y - 1, 0, 0);
		}
		
		if (im.IsKeyDown('s'))
		{
			std::cout << "s pressed" << std::endl;
			circle.SetPosition(circle.GetPosition(0, 0).x, circle.GetPosition(0, 0).y + 1, 0, 0);
		}

		if (im.IsKeyDown('q'))
		{
			std::cout << "q pressed" << std::endl;
			circle.SetPosition(circle.GetPosition(0, 0).x - 1, circle.GetPosition(0, 0).y, 0, 0);
		}

		if (im.IsKeyDown('d'))
		{
			std::cout << "d pressed" << std::endl;
			circle.SetPosition(circle.GetPosition(0, 0).x + 1, circle.GetPosition(0, 0).y, 0, 0);
		}
	}
}

void Game::init()
{

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
	{
		std::cout << "SDL_Init_Error :  " << SDL_GetError() << std::endl;
		return;
	}

	if (IMG_Init(IMG_INIT_PNG) == 0) {
		std::cout << "Error SDL2_image Initialization";
		return;
	}

	SDL_CreateWindowAndRenderer(800, 800, SDL_WINDOW_RESIZABLE, &window, &renderer);


	if (!window)
	{
		std::cout << "SDL_CreateWindow_Error : " << SDL_GetError() << std::endl;
		SDL_Quit();
		return;
	}

	if (!renderer) {
		std::cout << "Renderer_error : " << SDL_GetError() << std::endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return;
	}

}

void Game::Update()
{
	SDL_Rect rect = { 0, 0, 410, 300 };

	Image img = { renderer, "../image/lettuce.png", rect };
	img.Draw(renderer);

	SDL_RenderPresent(renderer);
	HandleInput();
}

void Game::Close()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	IMG_Quit();
	SDL_Quit();
}