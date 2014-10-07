#include "stdafx.h"
#include "Bete.h"
#include "Sort.h"
#include "GGC.h"
#include <time.h>

Carte *genDeck(int nb_crea){


	Carte *temp, *first = NULL, *last = NULL;


	for (int i = 0; i < 42; i++){

		int Att, PV, Cout, nom;

		if (i < nb_crea){

			nom = rand() % 14;
			Att = 1 + (rand() % 6);
			PV = 1 + (rand() % 6);
			Cout = (Att + PV) / 2;
			
			temp = new Bete(listeNom[nom]);
			temp->addAttribut(new Attribut(Att_price, Cout, inf));
			temp->addAttribut(new Attribut(Att_vie, PV, inf));
			temp->addAttribut(new Attribut(Att_attaque, Att, inf));
			temp->addAttribut(new Attribut(Att_cible, Cible_choix, inf));
		}else{

			nom = rand() % 6 + 15;
			Att = rand() % 5 + 1;
			PV = rand() % (sizeof(listCible)/sizeof(Ttype));
			Cout = Att * (2*PV + 1)/2;

			temp = new Sort(listeNom[nom]);
			temp->addAttribut(new Attribut(Att_price, Cout, inf));
			temp->addAttribut(new Attribut(Att_degats, Att, inf));
			temp->addAttribut(new Attribut(Att_cible, listCible[PV], inf));
		}

		first == NULL ? (first = temp) : last->setSuiv(temp);
		last  == NULL ? ( last = temp) : temp->setPrec(last);
		last = temp;

	}
	return first;
}