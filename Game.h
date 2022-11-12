#pragma once
#include "Cell.h"

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Game
{
private:
	bool isEnd;
	bool gameRunning;
	bool startSimulation;
	int howManyCellsAlive;
	bool mouseHeld;

	//Game logic
	Cell tableOfCells[50][50];
	int howBigSquareTableIs;

	//SFML VISUALISATION
	//Window
	sf::RenderWindow* window;
	int widthOfWindow;
	int heightOfWindow;
	sf::VideoMode videoMode;
	sf::Event ev;

	//Mouse positions
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//Cells
	int heighOfOneCell;
	int widthOfOneCell;

	//Resources
	sf::Font font;

	//Text
	sf::Text uiText;

	//Texture
	sf::Texture texture;

	//Game objects
	//sf::RectangleShape enemy;
	//std::vector < sf::RectangleShape> enemies;

	void bornCell(int x, int y); //born new cell at this position
	void nextSnapShot(); //use 4 rules of gameOfLife and born/kill cells, than reset neighbors
	void countNeighbors(int x, int y);	//count neighbors in 1 cell
	void countNeighborsInEveryCell();	//count neighbors in all cells
	void checkNeighborsInEveryCell();	//print how many neighbors have all cells
	void printCells();	//print table of cells
	void changeColorOfAllCells();
	void bornCellsByMouse();
	void countAliveCells();
public:
	//Constructor
	Game();
	virtual ~Game();

	void start();

	//Accesors
	bool getEndGame();

	void pollEvents();

	void updateMousePositions();
	void updateText();
	void updateCells();
	void update();

	void renderText(sf::RenderTarget& target);
	void renderCells(sf::RenderTarget& target);
	void render();
};


/*
	TO DO:
	grid of squares
	TEXT

*/
