#ifndef AGENT_H
#define AGENT_H

#include <string>
#include "IAStruct.inc"


/**
* Class Agent .
* @author Thibault
* @resume PickUp the better list of game's instruction
* in order to satisfy his own mission and rate its action
**/

class Agent
{
public:
	/**
	* Default constructor
	*
	**/
	Agent();
	/**
	* Default destructor
	*
	**/
	virtual ~Agent();
	/*
	* Search the best combination of action in a list of states
	* resulting for different actions
	**/
	void search(/*some list of state*/);

protected:
	/**
	* Auto evaluation of the agent
	* @return his mark(which can be negative)
	**/
	int autoEval();
	Movement *proposition;
	int satisfaction;
	const std::string order; //destroy, save, protect, powerup...
	//const placeMask targetAvailable;
};

#endif //AGENT_H
