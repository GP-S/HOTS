#include "NeurMono.h"


NeurMono::NeurMono(unsigned char * entryTab, char * weitghList, int treshold, Agent * agent) :
Neurone(entryTab,  weitghList, treshold)
{
	this->Asset = agent;
}

NeurMono::~NeurMono()
{
}

void NeurMono::learn()
{
	///TODO : franc you know what ^^ 
}

