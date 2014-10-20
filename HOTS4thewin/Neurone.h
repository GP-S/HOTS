#pragma once
#include "stdafx.h"
/* Neurone standart : 
	-plusieurs entrées chacunes pondérée,
	-une sortie à 1 ou 0 selon si la somme des poid*entrées est supérieur ou non au seuil.
*/
class Neurone
{
public:
	Neurone();
	Neurone::Neurone(chaine* dend, std::string C);
	~Neurone();
	bool reponse();
	void update();
	void IncrPoids();
	void DecrPoids();
	void incrementSeuil();
	void decrmenttSeuil();
	void state();
	std::string getId();

private:
	
	chaine* Dendrite;
	int seuil;
	int niveau;
	std::string Id;
};

