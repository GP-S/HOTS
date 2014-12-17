#ifndef NEURMON_H
#define NEURMON_H


#include "Neurone.h"
#include "Agent.h"

/**
* Class Neurone .
* @author Thibault
* @author Francois
**/

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
	NeurMono(unsigned char * entryTab, char * weightList, int treshold, Agent * agent);
	/**
	* Default destructor
	*
	**/
	~NeurMono();
	/**
	* calculate the output of the Neurone (=calculaated output);
	* @return int value of the output
	**/
	int getOutput();
	/**
	* learning function for the neuronne
	* @param expectedOutput which is calculated the turn after the decision 
	**/
	void learn(int expectedOutput);
protected :
	Agent * Asset;
	int calculatedOutput;
	int HighAverage;
	int HA;
	int LowAverage;
	int LA;
	int Average;
};

#endif //neurmono.h
