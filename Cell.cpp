#include "Cell.h"

Cell::Cell()
{
	isAlive = false;
	howManyNeighbors = 0;
}

void Cell::bornCell()
{
	isAlive = true;
}

void Cell::killCell()
{
	isAlive = false;
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
