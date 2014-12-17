#include "Neurone.h"
#include "iostream"


Neurone::Neurone()
{
	entryTab = NULL;
	treshold = 0;
}

Neurone::Neurone(unsigned char * entryTab, char * weitghTab, int treshold)
{
	this->entryTab = entryTab;
	this->treshold = treshold;
	this->setWeightList(weitghTab);
}


Neurone::~Neurone()
{
}

void Neurone::setentryTab(unsigned char * tab)
{
	this->entryTab = entryTab;
}

void Neurone::setWeightList(char * tab)
{
	try
	{
		if (tab == NULL) throw "null pointer for setWeightList in Neuronne";
		for (int i = 0; i < lenghtEntryVector; this->weightList[i] = tab[i++]);
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
