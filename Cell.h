#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Cell
{
private:
	bool isAlive;
	int howManyNeighbors;

	//SFML
	sf::RectangleShape cellShape;

public:
	Cell();
	void bornCell();
	void killCell();
	void changeColor();
	void setSizeOfCell(int heighOfCell, int widthOfCell);
	void setPositionOfCell(float widthOfCell, float heighOfCell);

	void addNeighbor();
	void resetNeighbors();

	//accesors
	bool isCellAlive();
	int returnNeighbors();
	sf::RectangleShape returnShape();
};
