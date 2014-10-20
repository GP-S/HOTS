#pragma once
#include "Board.h"
#include "Carte.h"
class Threats
{
public:
	Threats();
	Threats(Carte * Cart);
	Threats(Board * Terrain);
	~Threats();
	Threats* suiv;
	Threats* prec;
	int valCible;
	int ratio;
	Carte * Ref;
};

