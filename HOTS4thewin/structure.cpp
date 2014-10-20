#include "stdafx.h"
#include "structure.h"



chaine* AddEntete(chaine* base, sond* probe){
	chaine* nvChainon = (chaine*) malloc (sizeof(chaine));
	nvChainon->probe = probe;
	nvChainon->poid = 1;
	nvChainon->precedent = NULL;
	nvChainon->suivant = base;
	if(base !=NULL) base->precedent = nvChainon;
	return nvChainon;
}