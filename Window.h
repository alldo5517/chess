#pragma once
#include "SDL.h"
#undef main

#include "Game.h"
#include <vector>


#define MIN_WINDOW_WIDTH 400
#define MIN_WINDOW_HEIGHT 400

//defines for the default background color fo the window.
#define BACKGROUND_RED 122
#define BACKGROUND_GREEN 122
#define BACKGROUND_BLUE 122


class Window
{
public:
	void update(float deltaTime);
	void clean();
	void render();
	bool running();

	Window();
	~Window();
		
	void init(const char* title, int xpos, int ypos, bool fullscreen);
	static SDL_Renderer* renderer;
	static int screenHeight;
	static int screenWidth;
	
private:
	bool isRunning;
	SDL_Window* window;
	bool frozen;
	Game* game;
};

