
#pragma once
/* Définie les structure utile du programme et autre cst*/
#include "sond.h"

#define INCPOID 1
#define DECPOID 1
#define INCSEUIL 1
#define DECSEUIL 1

struct chaine
{
	sond* probe;
	int poid;
	chaine* suivant;
	chaine* precedent;
};

chaine* AddEntete(chaine* base, sond* probe);
