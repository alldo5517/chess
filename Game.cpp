#include "Game.h"
// #include "Window.h"
int Game::boardTopLeftX;
int Game::boardTopLeftY;

Game::~Game() {
	delete(board);
}

void Game::render() {
	board->render();
}

void Game::update() {

}

void Game::init() {
	boardTopLeftX = boardTopLeftY = 0;
	board = new Board();
	board->init();
}