#include "Neurone.h"
#include "iostream"
#include "NeurMono.h"


Neurone::Neurone()
{
	entryTab = NULL;
	treshold = 0;
}

Neurone::Neurone(unsigned char * entryTab, char * weitghList, int treshold)
{
	this->entryTab = entryTab;
	this->treshold = treshold;
	this->setWeightTab(weitghList);
}


Neurone::~Neurone()
{
}

void Neurone::setentryTab(unsigned char * tab)
{
	this->entryTab = entryTab;
}

void Neurone::setWeightTab(char * tab)
{
	try
	{
		if (tab == NULL) throw "null pointer for setWeightTab in Neuronne";
		for (int i = 0; i < nb_entry; this->weightTab[i] = tab[i++]);
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

int Neurone::getOutPut()
{
	int res = 0;
	for (int i = 0; i < nb_entry; i++)
	{
		res += weightTab[i] * entryTab[i];
	}
	return res>0?1:0;
}

void NeurMono::learn(int eval)
{

}
