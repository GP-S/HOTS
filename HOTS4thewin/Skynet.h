#pragma once
#include "Agent.h"
#include "reseau.h"
class Skynet
{
public:
	Skynet();
	~Skynet();
private:
	Agent * PoolOfAgent;
	reseau * reseauNeur;

};

