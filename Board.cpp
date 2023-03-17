#include "Board.h"
#include "Game.h"
#include "Window.h"

int Board::boxXWidth;
int Board::boxYHeight;
int Board::boardXBoxes;
int Board::boardYBoxes;

void Board::render() {
	renderBoard();
}

void Board::renderBoard() {
	SDL_Rect drawRect;
	drawRect.w = boxXWidth;
	drawRect.h = boxYHeight;
	for(int i = 0; i < boardXBoxes; i++){
		for(int j = 0; j < boardYBoxes; j++){
			// sum row + col, even will be white, odd will be black. 
			SDL_Color currentColor = (i + j) % 2 == 0 ? boardColor1 : boardColor2;
			drawRect.x = Game::boardTopLeftX + i * boxXWidth;
			drawRect.y = Game::boardTopLeftY + j * boxYHeight;

			SDL_SetRenderDrawColor(Window::renderer, currentColor.r, currentColor.g, currentColor.b, currentColor.a);
			SDL_RenderFillRect(Window::renderer, &drawRect);
		}
	}
}

void Board::update() {

}

void Board::init() {
	boxXWidth = 8;
	boxYHeight = 8;
	boardXBoxes = 20;
	boardYBoxes = 20;

	boardColor1 = {255, 255, 255, 255};
	boardColor2 = {0, 0, 0, 255};
}