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
		for (Carte * temp = J1->getBoard(Board_board)->getFirstCard(); temp != NULL; temp = temp->getSuiv()) temp->findByType(Att_CanAttak)->setVal(1);
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
		for (Carte * temp = J2->getBoard(Board_board)->getFirstCard(); temp != NULL; temp = temp->getSuiv()) temp->findByType(Att_CanAttak)->setVal(1);
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
	if (tour / 2 >= 8) over = true;
}

}

void useCard(Personnage * J1, int choix, Personnage * J2){
	Carte * temp ;
	Carte * Carte;
	int pose;
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
		else
		{
			if (Carte->findByType(Att_cible)->getVal() == Cible_choix)
			{
				cout << "Quelle est la cible (1,2,3,4 ... 0 pour le perso adverse)";
				cin >> choix;
				if (choix == 0) J2->findByType(Att_vie)->setVal(J2->findByType(Att_vie)->getVal() - Carte->findByType(Att_degats)->getVal());
				else
				{
					temp = J2->getBoard(Board_board)->getCardX(choix);
					temp->findByType(Att_vie)->setVal(temp->findByType(Att_vie)->getVal() - Carte->findByType(Att_degats)->getVal());
					if (!temp->isAlive()) delete J2->getBoard(Board_board)->takeCardX(choix);
				}
			}
			else
			{
				temp = J2->getBoard(Board_board)->getFirstCard();
				pose = 1;
				while (temp != NULL)
				{
					temp->findByType(Att_vie)->setVal(temp->findByType(Att_vie)->getVal() - Carte->findByType(Att_degats)->getVal());
					if (!temp->isAlive())
					{
						temp = temp->getSuiv();
						delete J2->getBoard(Board_board)->takeCardX(pose);
					}
					else
					{
						temp = temp->getSuiv();
						pose++;
					}
				}
			}
			delete Carte;
		}
	}
}

bool attaque(Personnage * J1, int choix, Personnage * J2)
{
	int numCrea = choix;
	if(!choix){
        cout<<"TG Armand!\n";
        return false;
	}
	Carte * Card = J1->getBoard(Board_board)->getCardX(choix);
	if (Card->findByType(Att_CanAttak)->getVal() == 0)
	{
		cout << "Cette Crea ne peut attaquer pour le moment\n";
		system("pause");
		return false;
	}
	Card->findByType(Att_CanAttak)->setVal(1);
	cout << "tapeki?\t(1,2,3... ou 0 pour le perso adverse)\n";
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
			Cible = J2->getBoard(Board_board)->takeCardX(choix);
			delete Cible;
		}
		if (!Card->isAlive())
		{
			Card = J1->getBoard(Board_board)->takeCardX(numCrea);
			delete Card;
		}
		return true;
	}
}
