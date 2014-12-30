#ifndef HAL_H
#define HAL_H

#include "list"

#include "IAStruct.inc"
#include "NeurMono.h"
#include "NeuralNetwork.h"
#include "StupidAgent.h"



class Hal //: public GameClient;
{
public:
	Hal();
	Hal(char * WeightPAth);
	~Hal();
	void survive();

private:

	void play();
	void test();
	State * simresult(int boardOrigin, int PlaceOri, int boardFinal, int FinalPlace);
	char * savePath;
	State * presentState;
	std::list<State*>*  PoolofState; 
	NeuralNetwork * neurNetwork;
	Agent * chosenOne; //Agent elicted by the IA to play this turn; //might be need to be converted in list oneday

};

#endif HAL_H