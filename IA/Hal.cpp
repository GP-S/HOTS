#include "Hal.h"


Hal::Hal()
{
	neurNetwork = new NeuralNetwork(PoolofState, NULL);
}

Hal::Hal(char * WeightPAth)
{
	PoolofState->push_back(presentState);
	savePath = WeightPAth;
	neurNetwork = new NeuralNetwork( PoolofState, WeightPAth);
}


Hal::~Hal()
{
}

void Hal::survive()
{
	neurNetwork->saveWeight(savePath);
}

void Hal::play()
{
	test();

}

State * Hal::simresult(int boardOrigin, int PlaceOri, int boardFinal, int FinalPlace) 
{
	State *finalState = new State();

	return finalState;
}

void Hal::test() //I will kill myself for writing this one
{
	size_t j = 0;
	for (size_t i = 0; i < MAXCARDINHAND; i++) //play card in hand
	{
		if (!(*PoolofState->begin())->playerHand[i].isOrnOt) continue; //if the card doesn't eist then nothing to do
		while (true)
		{
			if ((*PoolofState->begin())->playerBattleField[i].isOrnOt) continue; //if their already a card //if the card doesn't eist then nothing to do
			PoolofState->push_front(simresult(2, i, 1, j)); //on my board
			PoolofState->push_front(simresult(2, i, 8, j)); //on ennemy board
			if (++j > MAXCARDONBF) break;
		}
		PoolofState->push_front(simresult(2, i, 14, 0));//on hero

	}
	for (size_t i = 0; i < MAXCARDONBF; i++) //play card on board
	{
		if (!(*PoolofState->begin())->playerBattleField[i].isOrnOt) continue; //if the card doesn't eist then nothing to do
		while (true)
		{
			/*if ((*PoolofState->begin())->playerBattleField[i].isOrnOt) //if their already a card //if the card doesn't eist then nothing to do
				PoolofState->push_front(Simresult(, i, , j)); //on my board*/
			if ((*PoolofState->begin())->ennemyBattleField[i].isOrnOt)
				PoolofState->push_front(simresult(1, i, 8, j)); //on ennemy board
			if (++j > MAXCARDONBF) break;
		}
		PoolofState->push_front(simresult(1, i, 14, 0));//on hero
	}
}
