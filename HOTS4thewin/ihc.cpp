#include "stdafx.h"
#include "Board.h"
#include "ihc.h"

void printBoard(Board *board)
{

	for (int i = 0; i <= 7; i++){
		Carte *TempCard = board->getFirstCard();
		for (; TempCard != NULL; TempCard = TempCard->getSuiv()){
			switch (i){
			case 0 :
				cout << "+--------+";
				break;
			case 2 :
				cout << "| cout: " << TempCard->findByType(Att_price)->getVal() << "|";
				break;
			case 1 :
				cout << "|" << TempCard->getName() << "|";
				break;
			case 3 :
				cout << "|        |";
				break;
			case 4 :
				if (TempCard->getType() == Carte_sort) cout << "|degat: " << TempCard->findByType(Att_degats)->getVal() <<"|";
				else if (TempCard->getType() == Carte_crea) cout << "|force: " << TempCard->findByType(Att_attaque)->getVal() <<"|";
				else;
				break;
			case 5:
				if (TempCard->getType() == Carte_crea) cout << "|PV:    " << TempCard->findByType(Att_vie)->getVal()<<"|";
				else if (TempCard->getType() == Carte_sort) cout << "|deg " << correpRepartitonDegat[TempCard->findByType(Att_cible)->getVal() - 1] << "|";
				else;
				break;
			case 6:
				cout << "|        |";
				break;
			case 7:
				cout << "+--------+";
			default:

				break;
			}
			cout << " ";
		}
		cout << "\n";

	}
}

void printDeck(Board *board)
{
	for (int j = 0; j <= 42; j += 7){

		Carte *Carte1 = board->getFirstCard();
		for (int k = 0; k < j; (Carte1 = Carte1->getSuiv()) + k++);

		for (int i = 0; i <= 7; i++){
			Carte *TempCard = Carte1;
			for (int k = 0; TempCard != NULL && k<7 ; (TempCard = TempCard->getSuiv()) + k++){
				switch (i){
				case 0:
					cout << "+--------+";
					break;
				case 2:
					cout << "| cout: " << TempCard->findByType(Att_price)->getVal() << "|";
					break;
				case 1:
					cout << "|" << TempCard->getName() << "|";
					break;
				case 3:
					cout << "|        |";
					break;
				case 4:
					if (TempCard->getType() == Carte_sort) cout << "|degat: " << TempCard->findByType(Att_degats)->getVal() << "|";
					else if (TempCard->getType() == Carte_crea) cout << "|force: " << TempCard->findByType(Att_attaque)->getVal() << "|";
					else;
					break;
				case 5:
					if (TempCard->getType() == Carte_crea) cout << "|PV:    " << TempCard->findByType(Att_vie)->getVal() << "|";
					else if (TempCard->getType() == Carte_sort) cout << "|deg " << correpRepartitonDegat[TempCard->findByType(Att_cible)->getVal() - 1] << "|";
					else;
					break;
				case 6:
					cout << "|        |";
					break;
				case 7:
					cout << "+--------+";
				default:

					break;
				}
				cout << " ";
			}
			cout << "\n";

		}
	}
}