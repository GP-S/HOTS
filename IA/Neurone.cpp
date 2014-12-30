#include "Neurone.h"
#include "iostream"



Neurone::Neurone()
{
	int i;
	treshold = 0;
}

Neurone::Neurone(char *entryTab, char * weightTab, int treshold)
{
	this->entryTab = entryTab;
	this->setWeightList(weightTab);
	this->treshold = treshold;
}


Neurone::~Neurone()
{
}

void Neurone::setentryTab(char* tab)
{
	//this->setentryTab(entryTab); ...Are you kidding me?
	this->entryTab = tab;
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
