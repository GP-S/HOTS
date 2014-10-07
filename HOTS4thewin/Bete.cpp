#include "stdafx.h"
#include "Bete.h"

Bete::Bete()
{
    //ctor
}

Bete::Bete(string name)
{
	nom = name;
	type = Carte_crea;
}


Bete::~Bete()
{
    //dtor
}

bool Bete::isAlive(){
	return this->findByType(Att_vie)->getVal()>0;
}