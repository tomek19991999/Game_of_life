#pragma once
class Cell
{
private:
	bool isAlive;
	int howManyNeighbors;

public:
	Cell();
	void bornCell();
	void killCell();

	void addNeighbor();
	void resetNeighbors();

	//accesors
	bool isCellAlive();
	int returnNeighbors();
};

