#include "Game.h"
using namespace std;


void Game::bornCell(int x, int y)
{
	tableOfCells[x][y].bornCell();
}

void Game::nextSnapShot()
{
	for (int x = 0; x < howBigSquareTableIs; x++) {
		for (int y = 0; y < howBigSquareTableIs; y++)
		{
			if (tableOfCells[x][y].isCellAlive() == true && tableOfCells[x][y].returnNeighbors() < 2) tableOfCells[x][y].killCell();		//1st rule
			else if (tableOfCells[x][y].isCellAlive() == true && tableOfCells[x][y].returnNeighbors() == 2) {}								//2nd rule
			else if (tableOfCells[x][y].isCellAlive() == true && tableOfCells[x][y].returnNeighbors() == 2) {}								//2nd rule
			else if (tableOfCells[x][y].isCellAlive() == true && tableOfCells[x][y].returnNeighbors() > 3) tableOfCells[x][y].killCell(); 	//3rn rule
			else if (tableOfCells[x][y].isCellAlive() == false && tableOfCells[x][y].returnNeighbors() == 3) tableOfCells[x][y].bornCell(); //4th rule
		}
	}
	for (int x = 0; x < howBigSquareTableIs; x++) {
		for (int y = 0; y < howBigSquareTableIs; y++) {
			tableOfCells[x][y].resetNeighbors();
		}
	}
}

void Game::countNeighbors(int x, int y)
{

	for (int i = -1; i <= 1; i++) {
		for (int i2 = -1; i2 <= 1; i2++) {
			if ((i == 0 && i2 == 0) || (x + i)<0 || (x + i) > howBigSquareTableIs-1 || (y + i2) < 0 || (y + i2) > howBigSquareTableIs - 1) {}
			else
			{
				if (tableOfCells[x +i][y + i2].isCellAlive() == true) tableOfCells[x][y].addNeighbor();
			}
		}
	}

	//cout << tableOfCells[1][4].returnNeighbors();
}

void Game::countNeighborsInEveryCell()
{
	for (int x = 0; x < howBigSquareTableIs; x++) {
		for(int y=0; y<howBigSquareTableIs;y++)
		{
			countNeighbors(x, y);
		}
	}
}

void Game::checkNeighborsInEveryCell()
{
	for (int x = 0; x < howBigSquareTableIs; x++) {
		for (int y = 0; y < howBigSquareTableIs; y++) {
			cout<<"Cell x:"<<x<<" y: "<<y<<" neighbors: " << tableOfCells[x][y].returnNeighbors() << endl;
		}
	}
}

void Game::printCells()
{
	system("cls");
	for (int y = 0; y < howBigSquareTableIs; y++) {
		for (int x = 0; x < howBigSquareTableIs; x++) {
			if (tableOfCells[x][y].isCellAlive() == true) cout << "1 ";
			else if (tableOfCells[x][y].isCellAlive()==false) cout << "0 ";
			if (x == (howBigSquareTableIs - 1)) cout << endl;
		}
	}
}

Game::Game()
{
	isEnd = 0;
	gameRunning = false;
	howBigSquareTableIs = 5;
	//set dead cell to every place in the table
	for (int x = 0; x < howBigSquareTableIs; x++) {
		for (int y = 0;  y< howBigSquareTableIs; y++) {
			tableOfCells[x][y].killCell();
		}
	}
}

void Game::start()
{	
	/*
		Table visualization
		  0 1 2 3 4 
		  ---------→x
		0|□ □ □ □ □
		1|□ □ ■ □ □
		2|□ □ ■ □ □
		3|□ □ ■ ■ □
		4|□ □ □ □ □
		 ↓

		 GAME RULES
		  <2 neighbors	-> DIE
		  2,3 neighbors -> SURVIVE
		  >3 neighbors	-> DIE
		  3 neighbors	-> BORN NEW

	*/
	bornCell(2, 1);
	bornCell(2, 2);
	bornCell(2, 3);	
	bornCell(3, 3);
	countNeighborsInEveryCell();
	//checkNeighborsInEveryCell();
	printCells();
	Sleep(2000);
	nextSnapShot();
	printCells();

}

bool Game::getEndGame()
{
	return isEnd;
}

void Game::update()
{	
	if (gameRunning == false) {
		bornCell(2, 1);
		bornCell(2, 2);
		bornCell(2, 3);
		bornCell(3, 3);
		gameRunning=true;
		printCells();
	}
	Sleep(2000);
	if (this->isEnd == false)
	{
		countNeighborsInEveryCell();
		nextSnapShot();
	}
}

void Game::render()
{
	printCells();
}
