#include "Game.h"

void Game::loop()
{
	AssetsManager& am = AssetsManager::getInstance();

	SDL_Event event;
	std::vector<SDL_KeyboardEvent> key;
	InputManager& im = InputManager::getInstance();

	
	SDL_Rect rect = { 100, 100, 50, 50 };
	SDL_Rect rect1 = { 200, 200, 50, 50 };
	Circle circle = { rect };
	Circle circle1 = { rect1 };

	//SDL_Rect rect3 = { 0, 0, 410, 300 };
	//Image img = { renderer, "../image/lettuce.png", rect3 };

	am.PlayMusic("mellow", -1);
	am.SetMusicVolume(0);

	static int lastTicks = SDL_GetTicks();

	while (im.update())
	{
		int currentTicks = SDL_GetTicks();

		float deltaTime = (currentTicks - lastTicks) / 1000.0f;

		lastTicks = currentTicks;

		const float velocity = 300.0f;
		float deplacement = velocity * deltaTime;



		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		circle.Draw(renderer);
		circle1.Draw(renderer);
		//img.Draw(renderer);
		SDL_RenderPresent(renderer);


		if (im.IsKeyHeld('z')) 
		{
			std::cout << "z pressed" << std::endl;
			circle.Move({ 0, -deplacement });
			//circle.SetPositionAnchor(circle.GetPositionAnchor(0, 0).x, circle.GetPositionAnchor(0, 0).y - deplacement, 0, 0);
			circle1.SetPositionAnchor(circle1.GetPositionAnchor(0, 0).x, circle1.GetPositionAnchor(0, 0).y + deplacement, 0, 0);
		}

		
		if (im.IsKeyHeld('s'))
		{
			std::cout << "s pressed" << std::endl;
			circle.Move({ 0, deplacement });
			//circle.SetPositionAnchor(circle.GetPositionAnchor(0, 0).x, circle.GetPositionAnchor(0, 0).y + deplacement, 0, 0);
			circle1.SetPositionAnchor(circle1.GetPositionAnchor(0, 0).x, circle1.GetPositionAnchor(0, 0).y - deplacement, 0, 0);
		}

		if (im.IsKeyHeld('q'))
		{
			std::cout << "q pressed" << std::endl;
			circle.Move({ -deplacement, 0 });
			//circle.SetPositionAnchor(circle.GetPositionAnchor(0, 0).x - deplacement, circle.GetPositionAnchor(0, 0).y, 0, 0);
			circle1.SetPositionAnchor(circle1.GetPositionAnchor(0, 0).x + deplacement, circle1.GetPositionAnchor(0, 0).y, 0, 0);
		}

		if (im.IsKeyHeld('d'))
		{
			std::cout << "d pressed" << std::endl;
			circle.Move({ deplacement, 0 });
			//circle.SetPositionAnchor(circle.GetPositionAnchor(0, 0).x + deplacement, circle.GetPositionAnchor(0, 0).y, 0, 0);
			circle1.SetPositionAnchor(circle1.GetPositionAnchor(0, 0).x - deplacement, circle1.GetPositionAnchor(0, 0).y, 0, 0);
		}

		if (im.IsKeyDown('p'))
		{
			std::cout << "pow" << std::endl;
			am.PlaySoundEffect("pow", 0);
		}

		if (circle.isCollided(&circle1))
			std::cout << "COLLISION" << std::endl; //marche pas très bien avec un cercle enft



		if (SDL_GetTicks() - currentTicks < 60)
		{
			SDL_Delay(60 - (SDL_GetTicks() - currentTicks));
		}
	}
}

bool Game::init()
{

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
	{
		std::cout << "SDL_Init_Error :  " << SDL_GetError() << std::endl;
		return false;
	}

	if (IMG_Init(IMG_INIT_PNG) == 0) {
		std::cout << "Error SDL2_image Initialization";
		return false;
	}

	SDL_CreateWindowAndRenderer(800, 800, SDL_WINDOW_RESIZABLE, &window, &renderer);


	if (!window)
	{
		std::cout << "SDL_CreateWindow_Error : " << SDL_GetError() << std::endl;
		SDL_Quit();
		return false;
	}

	if (!renderer) 
	{
		std::cout << "Renderer_error : " << SDL_GetError() << std::endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return false;
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) 
	{
		std::cout << "Audio error : " << SDL_GetError() << std::endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return false;
	}

	AssetsManager& am = AssetsManager::getInstance();

	am.LoadSound("../assets/pow.wav", "pow");
	am.LoadMusic("../assets/Lastraveler  Mellow.mp3", "mellow");

	return true;
}



void Game::Close()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	Mix_CloseAudio();
	IMG_Quit();
	SDL_Quit();
}

