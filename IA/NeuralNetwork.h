#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include "list"
#include "string"
#include "file_manager.h"
#include "NeurMono.h"

//mmmh may be need to be interfaced... in order to be able to test different kind of neuronne need to think about it

#define NBAGENT 4
//list of agent that should be created :
//attack
//life
//lifemax
//cost
const std::string listOrder[NBAGENT] = { "attack","life","lifemax","cost" };

class NeuralNetwork
{
public:
	NeuralNetwork();
	NeuralNetwork(State * present, char * path);
	void saveWeight();
	~NeuralNetwork();
	/**
	* Take the satifaction of HAL, learn, update andsend back new proposition;
	* @param bool satisfied true if the last move was good false if not.
	* @param ChosenOne the agent which was chosen if there was multiple possibilities
	* @return return the list of agent allowed to play this turn
	**/
	void learn(std::list<Agent*> expectedOutPut);
	void update();
	std::list<Agent*> getOutput();

private:

	std::list<NeurMono*> neurones;
	std::list<Agent*> Output;
};

#endif // !NEURALNETWORK_H