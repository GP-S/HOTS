#pragma once
#include "Threats.h"
#include "Board.h"
class Agent
{
public:
	Agent();
	Agent(Board* Hand, Board* Terrain, Threats* listOfTreats);
	virtual ~Agent();

protected:

	Board* Hand, *Terrain;
	Threats* listOfTreats;

};

