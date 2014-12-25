#include "Neurone.h"
#include "iostream"
#define lengthEntryVector 5
#define nb_entry lengthEntryVector


Neurone::Neurone()
{
	int i;
	for(i=0;i<lengthEntryVector;i++){
	  entryTab[i] = 0;
	}
	treshold = 0;
}

Neurone::Neurone(char entryTab[lengthEntryVector], char weightTab[lengthEntryVector], int treshold)
{
  

	this->setentryTab(entryTab);
	this->treshold = treshold;
	this->setWeightList(weightTab);
}


Neurone::~Neurone()
{
}

void Neurone::setentryTab(char tab[lengthEntryVector])
{
	this->setentryTab(entryTab);
}

void Neurone::setWeightList(char tab[lengthEntryVector])
{
	try
	{
		if (tab == NULL) throw "null pointer for setWeightList in Neuronne";
		for (int i = 0; i < lengthEntryVector; this->weightList[i] = tab[i++]);
	}
	catch (const char *exception)
	{
			std::cerr << "\n*** " << exception << " ***\n";
	}
}

void Neurone::setTreshold(int treshold)
{
	this->treshold = treshold;
}

int Neurone::getOutput()
{
	int res = 0;
	for (int i = 0; i < nb_entry; i++)
	{
		res += weightList[i] * entryTab[i];
	}
	return res>0?1:0;
}

void Neurone::learn(int eval)
{

}
