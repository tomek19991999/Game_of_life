#pragma once
#include <iostream>
#include "Cell.h"
#include <windows.h>

class Game
{
private:
	bool isEnd;
	Cell tableOfCells[5][5];
	int howBigSquareTableIs;
	bool gameRunning;

	//Born new cell
	void bornCell(int x, int y);
	void nextSnapShot();
	void countNeighbors(int x, int y);
	void countNeighborsInEveryCell();
	void checkNeighborsInEveryCell();
	void printCells();
public:
	//Constructor
	Game();


	void start();

	//Accesors
	bool getEndGame();

	//Update data
	void update();

	//Rendering
	void render();
};

