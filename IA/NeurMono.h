#ifndef NEURMON_H
#define NEURMON_H


#include "Neurone.h"
#include "Agent.h"

class NeurMono :
	public Neurone
{
public:
	/**
	* Default constructor
	*
	**/
	NeurMono() : Neurone() { Asset = NULL; }
	/**
	* Constructor
	* @param unsigned char* entryTab List of all entry vector
	* @param unsigned char* weitghList List of all weight corresponding to the entry
	* @param Agent * agent referance to the neurone's agent assigned
	* @param int treshold try to guess...
	**/
	NeurMono(unsigned char * entryTab, char * weitghList, int treshold, Agent * agent);
	/**
	* Default destructor
	*
	**/
	~NeurMono();
	/**
	* calculate the output of the Neurone;
	* @return int value of the output
	**/
	int getOutPut();
	/**
	* learning function for the neuronne
	* @param eval evaluation of the current decision
	**/
	void learn(int eval);
protected :
	Agent * Asset;
};

#endif //neurmono.h