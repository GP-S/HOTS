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
	return 0;
}