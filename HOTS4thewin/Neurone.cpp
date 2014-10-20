#include "stdafx.h"
#include "structure.h"
#include "Neurone.h"



Neurone::Neurone()
{

}

Neurone::Neurone(chaine* dend, std::string C)
{
	Dendrite = dend;
	seuil = 100;
	niveau = 0;
	Id = C;
}

Neurone::~Neurone()
{
}


bool Neurone::reponse()
{
	niveau = 0;
	for (chaine* suiv = Dendrite; suiv != NULL; suiv = suiv->suivant)
	{
		niveau += suiv->probe->get_output() * suiv->poid;
	}
	return niveau >= seuil ? true : false;
}

void Neurone::update()
{
}

/*Incrémente tous les poids du neuronne de façon proportionnel 
(plus le produit poid*entrée est grand plus le poid sera augmenté)*/
void Neurone::IncrPoids()
{
	int nv_inc = 1;
	chaine* suiv = Dendrite;
	chaine* Dmax = Dendrite;
	//On parcours la liste des dendrite dans un sens en augmentant l'incrémentation à chaque maximum local
	for (; suiv != NULL; suiv = suiv->suivant)
	{
		if (suiv->probe->get_output() * suiv->poid >= Dmax->poid * Dmax->probe->get_output())
		{
			Dmax = suiv;
			nv_inc++;
		}
		suiv->poid += nv_inc*INCPOID;
	}
	//même chose dans l'autre sens
	nv_inc = 1;
	Dmax = NULL;
	for (; suiv != NULL; suiv = suiv->precedent)
	{
		if (suiv->probe->get_output() * suiv->poid >= Dmax->poid * Dmax->probe->get_output())
		{
			Dmax = suiv;
			nv_inc++;
		}
		suiv->poid += nv_inc*INCPOID;
	}
}

void Neurone::DecrPoids()
{
	int nv_dec = 1;
	chaine* suiv = Dendrite;
	chaine* Dmin = Dendrite;
	//On parcours la liste des dendrite dans un sens en augmentant le décrément à chaque maximum local
	for (; suiv != NULL; suiv = suiv->suivant)
	{
		if (suiv->probe->get_output() * suiv->poid >= Dmin->poid * Dmin->probe->get_output())
		{
			Dmin = suiv;
			nv_dec++;
		}
		suiv->poid -= nv_dec*DECPOID;
	}
	//même chose dans l'autre sens
	nv_dec = 1;
	Dmin = NULL;
	for (; suiv != NULL; suiv = suiv->precedent)
	{
		if (suiv->probe->get_output() * suiv->poid >= Dmin->poid * Dmin->probe->get_output())
		{
			Dmin = suiv;
			nv_dec++;
		}
		suiv->poid -= nv_dec*DECPOID;
	}
}

void Neurone::incrementSeuil()
{
	seuil += INCSEUIL;
}

void Neurone::decrmenttSeuil()
{
	seuil -= DECSEUIL;
}

void Neurone::state()
{
	int i = 0;
	chaine* suiv = Dendrite;
	std::cout << "Seuil : " << seuil << " Niveau : " << niveau << " Axone : " << reponse() << "\n";
	for (chaine* suiv = Dendrite; suiv != NULL; suiv = suiv->suivant)
	{
		std::cout << "poids sonde " << i++ << " : " << suiv->poid << "\n";
	}
}

std::string Neurone::getId()
{
	std::cout << "Neurone : " << Id << "\n";
	return Id;
}