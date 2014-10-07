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
		J1->findByType(Att_cristaux_cur)->setVal(++tour / 2);
		cout << "J1 pioche\n";
		J1Main->addCard(J1Pioche->pioche(1));
		system("pause");
		system("cls");
		printTable(J1, J2);
		while (choix != 3){
			cout << "Que souhaite faire J1?\n";
			cout << " 1 : Jouer Carte | 2 : Attaquer | 3 : Finir tour\n";
			cin >> choix;
			if (choix == 1){
				cout << "Quel Carte jouer?\n";
				cin >> choix;
				useCard(J1, choix, J2);
				system("cls");
				printTable(J1, J2);
				choix = 0;
			}
			else if (choix == 2){
				cout << "Quel Créture?\n";
				cin >> choix;
				attaque(J1, choix, J2);
				system("cls");
				printTable(J1, J2);
				choix = 0;
			}

		}

		JP = 2;
	}
	else{
		J2->findByType(Att_cristaux_cur)->setVal(++tour / 2);
		cout << "J2 pioche\n";
		J2Main->addCard(J2Pioche->pioche(1));
		system("pause");
		system("cls");
		printTable(J1, J2);
		while (choix != 3){
			cout << "Que souhaite faire J2?\n";
			cout << " 1 : Jouer Carte | 2 : Attaquer | 3 : Finir tour\n";
			cin >> choix;
			if (choix == 1){
				cout << "Quel Carte jouer?\n";
				cin >> choix;
				useCard(J2, choix, J1);
				system("cls");
				printTable(J1, J2);
				choix = 0;
			}
			if (choix == 2){
				cout << "Quel Créture?\n";
				cin >> choix;
				attaque(J2, choix, J1);
				system("cls");
				printTable(J1, J2);
				choix = 0;
			}
		}
		JP = 1;
	}
	if (tour / 2 >= 4) over = true;
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

bool attaque(Personnage * J1, int choix, Personnage * J2)
{
	int numCrea = choix;
	Carte * Card = J1->getBoard(Board_board)->getCardX(choix);
	cout << "tapéki?\t(1,2,3... ou 0 pour le perso adverse)\n";
	cin >> choix;
	if (choix == 0){
		J2->findByType(Att_vie)->setVal(J2->findByType(Att_vie)->getVal() - Card->findByType(Att_attaque)->getVal());
		return J1->isAlive();
	}
	else
	{
		Carte * Cible = J2->getBoard(Board_board)->getCardX(choix);
		Cible->findByType(Att_vie)->setVal(Cible->findByType(Att_vie)->getVal() - Card->findByType(Att_attaque)->getVal());
		Card->findByType(Att_vie)->setVal(Card->findByType(Att_vie)->getVal() - Cible->findByType(Att_attaque)->getVal());
		if(!Cible->isAlive())
		{
			J2->getBoard(Board_board)->takeCardX(choix);
		}
		if (!Card->isAlive())
		{
			J1->getBoard(Board_board)->takeCardX(numCrea);
		}
		return true;
	}
}