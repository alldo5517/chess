#include "Window.h"
#include "SDL_image.h"
#include <iostream>

int Window::screenHeight = 0;
int Window::screenWidth = 0;
SDL_Renderer* Window::renderer = nullptr;
Window::Window() {
	frozen = true;
}

Window::~Window() {

}

void Window::update(float  deltaTime) {
	game->update();
}

void Window::clean() {
	delete(game);

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);	//error here
	SDL_Quit();


	std::cout << "Succesfully cleaned!\n";
}

bool Window::running() {
	return isRunning;
}


void Window::render() {
	SDL_SetRenderDrawColor(renderer, BACKGROUND_RED, BACKGROUND_GREEN, BACKGROUND_BLUE, 255);
	SDL_RenderClear(renderer);

	game->render();


	SDL_RenderPresent(Window::renderer);

}
void Window::init(const char* title, int xpos, int ypos, bool fullscreen) {
	int flags = 0;
	flags = SDL_WINDOW_RESIZABLE;
	if (fullscreen) {
		flags = flags | SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems Initialized!\n";
		window = SDL_CreateWindow(title, xpos, ypos, Window::screenWidth, Window::screenHeight , flags);
		if (window) {
			std::cout << "Window Created!\n";
			SDL_SetWindowMinimumSize(window, MIN_WINDOW_WIDTH, MIN_WINDOW_HEIGHT);
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 121, 121, 121, 255);
			std::cout << "Renderer created!\n";
			SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
		}
		int imgFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imgFlags) & imgFlags))
		{
			printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
			isRunning = false;
		}
		else {
			isRunning = true;

			game = new Game();
			game->init();

		}


	}

	else {
		isRunning = false;
		fprintf(stderr, "Something failed in SDL setup\n");
	}

}