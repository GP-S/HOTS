#include "stdafx.h"
#include "Carte.h"

Carte::Carte()
{
	nom = "";
	type = Carte_dafuck;
	degat = -1;
	//liste_Att = NULL;

	//cout << "Constructeur par défault de Carte Classe appelé\n";
	//Thibault : constructeur par défault... Oui aller on fait les choses bien
}

Carte::Carte(string name, Ttype typ){
	nom = name;
	type = typ;
	degat = 0;
	//liste_Att = NULL;
}


Carte::~Carte()
{
}

void Carte::addAttribut(Attribut * att){
	
	if (liste_Att != NULL){
		Attribut * suiv = liste_Att;
		for (; suiv->suiv() != NULL; suiv = suiv->suiv());
		suiv->setSuiv(att);
	}
	else
	{
		liste_Att = att;
	}

}


Carte *Carte::getPrec()
{
	return cartePrec;
}

Carte *Carte::getSuiv()
{
	return carteSuiv;
}

void Carte::setPrec(Carte *prec)
{
	cartePrec = prec;
}

void Carte::setSuiv(Carte *suiv)
{
	carteSuiv = suiv;
	//if(suiv != NULL) carteSuiv->setPrec(this);
}

Attribut *Carte::findByType(Ttype type)
{
	Attribut *temp = liste_Att;
	while (temp->getType() != type) temp = temp->suiv();
	return temp;
}

Ttype Carte::getType()
{
	return type;
}

string Carte::getName()
{
	return nom;
}