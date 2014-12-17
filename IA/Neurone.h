#ifndef NEURONE_H
#define NEURONE_H


#define nb_entry 100
#define NULL 0

/**
* Class Neurone .
* @author Thibault
*
**/


class Neurone
{
public:
	/**
	* Default constructor
	*
	**/
	Neurone();
	/**
	* Constructor
	* @param unsigned char* entryTab List of all entry vector
	* @param unsigned char* weitghList List of all weight corresponding to the entry
	* @param int treshold try to guess...
	**/
	Neurone(unsigned char* entryTab, char * weightList, int treshold);
	/**
	* Default destructor
	*
	**/
	virtual ~Neurone();
	/**
	* setter for entryTab;
	**/
	void setentryTab(unsigned char * tab);
	/**
	* setter for weightTab;
	**/
	void setWeightList(char * tab);
	/**
	* setter for treshold;
	**/
	void setTreshold(int treshold);
	/**
	* calculate the output of the Neurone;
	**/
	virtual int getOutput();
	/**
	* learning function for the neuronne
	**/
	virtual void learn(int eval);

protected:
	unsigned char *entryTab;
	int lenghtEntryVector;
	char weightList[lenghtEntryVector];
	int treshold;
	int delta;
	int calculatedOutput;
};

#endif // !NEURONE_H
