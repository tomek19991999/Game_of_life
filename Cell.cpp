#include "Cell.h"

Cell::Cell()
{
	isAlive = false;
	howManyNeighbors = 0;
	cellShape.setOutlineThickness(1.f);
}

void Cell::bornCell()
{
	isAlive = true;
}

void Cell::killCell()
{
	isAlive = false;
}

void Cell::changeColor()
{
	if(isAlive) 
	{
		this->cellShape.setFillColor(sf::Color::White);
		cellShape.setOutlineColor(sf::Color::Red);
	}
	else
	{
		this->cellShape.setFillColor(sf::Color::Black);
		cellShape.setOutlineColor(sf::Color::Red);
	}
	
}

void Cell::setSizeOfCell(int heighOfCell, int widthOfCell)
{
	heighOfCell = static_cast<float>(heighOfCell);
	widthOfCell = static_cast<float>(widthOfCell);
	cellShape.setSize(sf::Vector2f(heighOfCell, widthOfCell));
}

void Cell::setPositionOfCell(float widthOfCell, float heighOfCell)
{
	cellShape.setPosition(widthOfCell, heighOfCell);
}

sf::RectangleShape Cell::returnShape()
{
	return cellShape;
}



bool Cell::isCellAlive()
{
	return isAlive;
}

int Cell::returnNeighbors()
{
	return howManyNeighbors;
}

void Cell::addNeighbor()
{
	howManyNeighbors++;
}

void Cell::resetNeighbors()
{
	howManyNeighbors = 0;
}
