// HOTS4thewin.cpp : définit le point d'entrée pour l'application console.
//



#include "stdafx.h"
#include "listeObj.h"
#include "ihc.h"
#include "GGC.h"
#include "mecaJeu.h"

int main(int argc, char* argv[])
{
	Personnage *J1 = new Personnage();
	Personnage *J2 = new Personnage();
	 
	/*cout << "--------------------------------Gen de Deck--------------------------------" << endl;
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
	printBoard(deck);*/

	//En vrai faudra faire autremant
	J1->setBoard(new Board(genDeck(15)), Board_pioche);
	J1->setBoard(new Board(), Board_hand);
	J1->setBoard(new Board(), Board_board);
	J1->addAttribut(new Attribut(Att_cristaux_cur, 0, -1));
	J1->addAttribut(new Attribut(Att_vie, 25, -1));
	
	J2->setBoard(new Board(genDeck(25)), Board_pioche);
	J2->setBoard(new Board(), Board_board);
	J2->setBoard(new Board(), Board_hand);
	J2->addAttribut(new Attribut(Att_cristaux_cur, 0, -1));
	J2->addAttribut(new Attribut(Att_vie, 25, -1));

	play(J1,J2);



	system("pause");
	return 0;
}

