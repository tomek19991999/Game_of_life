#include "Game.h"
using namespace std;


void Game::bornCell(int x, int y)
{
	tableOfCells[x][y].bornCell();
}

void Game::nextSnapShot()
{

	//use rules of game - kill or born new cells
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
	//count alive cells
	countAliveCells();

	//reset neighbors of all cells
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

void Game::changeColorOfAllCells()
{
	for (int x = 0; x < howBigSquareTableIs; x++) {
		for (int y = 0; y < howBigSquareTableIs; y++)
		{
			tableOfCells[x][y].changeColor();
		}
	}
}

void Game::bornCellsByMouse()
{	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::isButtonPressed(sf::Mouse::Right)) {}
	else
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->mouseHeld = true;

			//Born cell when pressed by mouse
			for (int x = 0; x < howBigSquareTableIs; x++) {
				for (int y = 0; y < howBigSquareTableIs; y++) {
					if (tableOfCells[x][y].returnShape().getGlobalBounds().contains((this->mousePosView))) tableOfCells[x][y].bornCell();
				}
			}
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
			this->mouseHeld = true;

			//Kill cell when pressed by mouse
			for (int x = 0; x < howBigSquareTableIs; x++) {
				for (int y = 0; y < howBigSquareTableIs; y++) {
					if (tableOfCells[x][y].returnShape().getGlobalBounds().contains((this->mousePosView))) tableOfCells[x][y].killCell();
				}
			}
		}
	}
}

void Game::countAliveCells()
{
	//count alive cells
	howManyCellsAlive = 0;
	for (int x = 0; x < howBigSquareTableIs; x++) {
		for (int y = 0; y < howBigSquareTableIs; y++) {
			if (tableOfCells[x][y].isCellAlive() == 1) howManyCellsAlive++;
		}
	}
}

Game::Game()
{	
	//Initialisation Variables
	isEnd = 0;
	gameRunning = false;
	howBigSquareTableIs = 50;
	startSimulation = false;
	howManyCellsAlive = 0;
	mouseHeld = false;

	//Calculating size of one cell
	widthOfWindow = 800;
	heightOfWindow = 800;
	heighOfOneCell = heightOfWindow / howBigSquareTableIs;
	widthOfOneCell = widthOfWindow / howBigSquareTableIs;

	//SFML
	window = nullptr;

	//set dead cell to every place in the table, set size of cell, set positon of cell
	float tempHeighPosition=0;
	float tempWidthPosition = 0;
	for (int x = 0; x < howBigSquareTableIs; x++) {
		for (int y = 0;  y< howBigSquareTableIs; y++) {
			tableOfCells[x][y].killCell();
			tableOfCells[x][y].setSizeOfCell(heighOfOneCell, widthOfOneCell);
			tableOfCells[x][y].setPositionOfCell(tempWidthPosition, tempHeighPosition);
			//set heigh position
			if (y == howBigSquareTableIs-1) tempHeighPosition = 0;
			else  tempHeighPosition += static_cast<float>(heighOfOneCell);
			//set width position
			if(y == howBigSquareTableIs - 1) tempWidthPosition += static_cast<float>(widthOfOneCell);
		}
	}

	//Initialisation Window

	this->videoMode.width = widthOfWindow;
	this->videoMode.height = heightOfWindow;
	this->window = new sf::RenderWindow(this->videoMode, "Game of life", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);

	//Initialisation Fonts
	if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		std::cout << "ERROR::GAME::INITFONTS::Failed to load font!" << std::endl;
	}

	//Initialisation Text
	this->uiText.setFont(this->font);
	this->uiText.setCharacterSize(24);
	uiText.setFillColor(sf::Color::White);
	uiText.setOutlineThickness(1.f);
	uiText.setOutlineColor(sf::Color::Black);
	this->uiText.setString("NONE");

	//Initialisation Texture
	if (!this->texture.loadFromFile("Textures/texture1.jpg"))
	{
		std::cout << "ERROR::GAME::INITFONTS::Failed to load texture!" << std::endl;
	}
}

Game::~Game()
{
	delete this->window;
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
	bornCell(4, 3);
	bornCell(4, 2);
	bornCell(1, 1);
	bornCell(1, 2);
	bornCell(1, 3);
	bornCell(1, 4);
	countNeighborsInEveryCell();
	//checkNeighborsInEveryCell();
	printCells();
	nextSnapShot();
	printCells();
}

bool Game::getEndGame()
{
	return isEnd;
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
		{
			this->window->close();
			this->isEnd = true;
		}
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
			{
				this->window->close();
				this->isEnd = true;
			}
			if (this->ev.key.code == sf::Keyboard::Space)
				if (startSimulation == false)startSimulation = true;
				else startSimulation = false;
			break;
		}
	}
}

void Game::updateMousePositions()
{
	//updates the mouse positions 
	//mouse position is relative to window (Vector2i)
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
	//std::cout << "\nx: " << this->mousePosView.x << "  y: " << this->mousePosView.y << "     xWindow: " << this->mousePosWindow.x << "  yWindow: " << this->mousePosWindow.y;
}

void Game::updateText()
{
	std::stringstream ss;

	if (startSimulation == false)
	{
		ss << "Left mouse button -> born cell\nRight mouse button -> kill cell\nESC -> quit" << std::endl;
	}
	ss << "Press space to start/stop simulation"<<endl;
	ss << "Cells: " << this->howManyCellsAlive;

	this->uiText.setString(ss.str());
}

void Game::updateCells()
{
	if (this->isEnd == false)
	{
		countNeighborsInEveryCell();
		nextSnapShot();
		changeColorOfAllCells();
	}

}

void Game::update()
{	
	pollEvents();
	if(this->isEnd == false)
	{
		if (startSimulation == false)
		{
			this->updateMousePositions();
			this->updateText();
			changeColorOfAllCells();
			this->bornCellsByMouse();
			this->countAliveCells();
		}
		else
		{
			this->updateMousePositions();
			this->updateText();
			this->updateCells();
		}
	}
}

void Game::renderText(sf::RenderTarget& target)
{
	target.draw(this->uiText);
}

void Game::renderCells(sf::RenderTarget& target)
{
	for (int x = 0; x < howBigSquareTableIs; x++) {
		for (int y = 0; y < howBigSquareTableIs; y++)
		{
			target.draw(tableOfCells[x][y].returnShape());
		}
	}
}

void Game::render()
{
	//printCells();
	this->window->clear();
	
	this->renderCells(*this->window);
	this->renderText(*this->window);

	this->window->display();
}
