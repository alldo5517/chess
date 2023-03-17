#pragma once
#include "SDL.h"
#include "Board.h"

class Game
{
private:

	Board* board;
	
public:

	static int boardTopLeftX;
	static int boardTopLeftY;
	
	void update();
	void render();
	void init();
	~Game();
};

