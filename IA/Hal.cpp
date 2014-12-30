#include "Hal.h"



Hal::Hal()
{
	neurNetwork = new NeuralNetwork(presentState, NULL);
}

Hal::Hal(char * WeightPAth)
{
	savePath = WeightPAth;
	neurNetwork = new NeuralNetwork(presentState, WeightPAth);
}


Hal::~Hal()
{
}

void Hal::survive()
{
	neurNetwork->saveWeight(savePath);
}

void * Hal::play()
{
	return NULL;
}
