#include "stdafx.h"
#include "Threats.h"


Threats::Threats()
{
	
}

Threats::Threats(Carte * Cart)
{
	ratio = Cart->findByType(Att_attaque)->getVal() / Cart->findByType(Att_vie)->getVal();
	valCible = Cart->findByType(Att_vie)->getVal();
	Ref = Cart;
	suiv = NULL;
	prec = NULL;
}

Threats::Threats(Board* Terrain)
{
	Carte * temp = Terrain->getFirstCard();
	Threats * Last = NULL;
	for (; temp != NULL; temp = temp ->getSuiv())
	{
		if (Last = NULL){
			Last = new Threats(temp);
		}
		else{
			Last->suiv = new Threats(temp);
			Last->suiv->prec = Last;
			Last = Last->suiv;			
		}
	}
}


Threats::~Threats()
{
}

