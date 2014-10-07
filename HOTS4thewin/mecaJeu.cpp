#include "stdafx.h"
#include "Personnage.h"
#include "ihc.h"
#include "mecaJeu.h"
#include <time.h>


void play(Personnage * J1, Personnage * J2){
	bool over = false;
	Board * J1Main = J1->getBoard(Board_hand);
	Board * J1Pioche = J1->getBoard(Board_pioche);
	Board * J2Main = J2->getBoard(Board_hand);
	Board * J2Pioche = J2->getBoard(Board_pioche);
	Board * J1B = J1->getBoard(Board_board);
	Board * J2B = J2->getBoard(Board_board);

	int JP = 1; //>personnage jouant;
	int tour = 1; // nb de tour;
	int choix = 0;

	//init
	J1Main->addCard(J1Pioche->pioche(4));
	J2Main->addCard(J2Pioche->pioche(4));

	printTable(J1, J2);

	while (!over){
		choix = 0;
		if (JP == 1){
			J1->findByType(Att_cristaux_cur)->setVal(++tour/2);
			cout << "J1 pioche\n";
			J1Main->addCard(J1Pioche->pioche(1));
			system("pause");
			system("cls");
			printTable(J1, J2);
			cout << "Que souhaite faire J1?\n";
			while (choix != 2){
				cout << " 1 : Jouer Carte | 2 : Attaquer | 3 : Finir tour\n";
				cin >> choix;
				if (choix == 1){
					cout << "Quel Carte jouer?\n";
					cin >> choix;
					useCard(J1, choix, J2);
					system("cls");
					printTable(J1, J2);
				}
				if (choix == 2){
					cout << "Quel Créture?\n";
					cin >> choix;
					Attaque(J1, choix, J2);
					system("cls");
					printTable(J1, J2);
				}
			}

			JP = 2;
		}
		else{
			++tour;
			JP = 1;
		}
		if (tour/2 >= 4) over = true;
	}

}

void useCard(Personnage * J1, int choix, Personnage * J2){
	Carte * Carte;
	int valcarte = J1->getBoard(Board_hand)->getCardX(choix)->findByType(Att_price)->getVal();
	if (valcarte > J1->findByType(Att_cristaux_cur)->getVal())
	{
		cout << "Cette carte coute trop cher\n";
		system("pause");
	}
	else
	{
		J1->findByType(Att_cristaux_cur)->setVal(J1->findByType(Att_cristaux_cur)->getVal() - valcarte);

		if ((Carte = J1->getBoard(Board_hand)->takeCardX(choix)) == NULL) return;
		if (Carte->getType() == Carte_crea)
		{
			J1->getBoard(Board_board)->addCard(Carte);
		}
	}
}

void Attaque(Personnage * J1, int choix, Personnage * J2)
{


}