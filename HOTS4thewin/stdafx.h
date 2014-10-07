// stdafx.h�: fichier Include pour les fichiers Include syst�me standard,
// ou les fichiers Include sp�cifiques aux projets qui sont utilis�s fr�quemment,
// et sont rarement modifi�s
//

#pragma once

//#include "targetver.h"

#include <stdio.h>
//#include <tchar.h>
#include <stdlib.h>
#include <iostream>
#include <string>

// TODO: faites r�f�rence ici aux en-t�tes suppl�mentaires n�cessaires au programme


using namespace std;

#define inf -1



/* liste de tout les type de trucs*/
enum Ttype
{
	// Liste des type de plateaux
	Board_hand,
	Board_pioche,
	Board_board,
	Board_tomb,
	Board_totem,
	Board_trap,
	Board_joueur,
	Board_Deck,

	// Liste des types de carte
	Carte_dafuck,
	Carte_perso,
	Carte_sort,
	Carte_crea,

	// Liste des type d'attribut

	Att_vie,
	Att_vie_max,
	Att_degats,
	Att_attaque,
	Att_price,
	Att_cible,

	Att_cristaux_cur,
	Att_cristaux_max,

	// Liste des type de ciblage

	Cible_Alea = 1,
	Cible_tous,
	Cible_choix,
	Cible_joueur,
	Cible_crea,
	Cible_AleaDist
	
};

/*Tableau de conversion enum->string pour le ciblage*/
const string correpRepartitonDegat[3] = { "Alea", "Tous", "cibl" };