// HOTS4thewin.cpp : définit le point d'entrée pour l'application console.
//



#include "stdafx.h"
#include "listeObj.h"
#include "ihc.h"
#include "GGC.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Personnage *J1 = new Personnage();
	Personnage *J2 = new Personnage();
	 
	cout << "--------------------------------Gen de Deck--------------------------------" << endl;
	Board *deck(new Board(genDeck(24)));
	//printBoard(ZoneCombatJ2);
	printDeck(deck);
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "--------------------------------Gen d'un main------------------------------" << endl;
	Board *hand(new Board(deck->pioche(5)));
	printBoard(hand);
	cout << "--------------------------------test de pioche-----------------------------" << endl;
	hand->addCard(deck->pioche(1));
	printBoard(hand);
	cout << "--------------------------------test de défausse---------------------------" << endl;
	deck->pioche(30);
	printBoard(deck);

	system("pause");
	return 0;
}

