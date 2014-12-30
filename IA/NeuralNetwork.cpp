#include "NeuralNetwork.h"
#include "time.h"

NeuralNetwork::NeuralNetwork()
{
}

NeuralNetwork::NeuralNetwork(State * present, char* path)
{
	char weightList[NBAGENT*nb_entry];
	if (path == NULL) {
		srand(time(NULL));
		for (size_t i = 0; i < NBAGENT*nb_entry; i++) weightList[i] = (char)rand();
	}
	else if(loadObject(path,(void*) weightList, sizeof(weightList))){
		//error
	};
	for (size_t i = 0; i < NBAGENT; i++){
		neurones.push_back( new NeurMono ((char*)present, weightList, 100, new Agent()));
	}
}


NeuralNetwork::~NeuralNetwork()
{

}

void NeuralNetwork::saveWeight()
{

}

void NeuralNetwork::learn(std::list<Agent*> wished)
{
}

void NeuralNetwork::update()
{
	//send request update to the list of agent
	//update output of each neurone
	//write a list of agent
}

std::list<Agent*> NeuralNetwork::getOutput()
{
	return std::list<Agent*>();
}
