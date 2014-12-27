#ifndef NEURONE_H
#define NEURONE_H

#define NULL 0
#define lengthEntryVector 5

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
	* @param unsigned char* weightList List of all weight corresponding to the entry
	* @param int treshold try to guess...
	**/
	Neurone(char *entryTab, char weightList[lengthEntryVector], int treshold);
	/**
	* Default destructor
	*
	**/
	virtual ~Neurone();
	/**
	* setter for entryTab;
	**/
	void setentryTab(char *tab);
	/**
	* setter for weightTab;
	**/
	void setWeightList(char tab[lengthEntryVector]);
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
	char* entryTab;
//	int lenghtEntryVector;
	char weightList[lengthEntryVector];
	int treshold;
	int delta;
	int calculatedOutput;
};

#endif // !NEURONE_H
