#include "stdafx.h"
#include "Carte.h"
#include "Board.h"
#include "time.h"


Board::Board()
{
	firstCard	= NULL;
	lastCard	= NULL;
}

Board::Board(Carte *teteList)
{
	firstCard = teteList;
	lastCard  = teteList;
	for (; lastCard != NULL && lastCard->getSuiv() != NULL; lastCard = lastCard->getSuiv());
}

Board::~Board()
{
	 
}

Carte * Board::getFirstCard()
{
	return firstCard;
}

int Board::getLength()
{
	Carte *temp = firstCard;
	int i = 0;
	while (temp != NULL && ++i) temp = temp->getSuiv();
	return i;
}

void Board::addCard(Carte * card)
{
	if (lastCard != NULL){
		card->setPrec(lastCard);
		card->setSuiv(NULL);
		lastCard->setSuiv(card);
		lastCard = card;
	}
}


Carte * Board::pioche(int nb_carte)
{
	srand(time(NULL));

	Carte * first = firstCard;
	int pose = 0;
	int num = rand()%this->getLength();
	while (pose++ != num) first = first->getSuiv();

	/* on test si on pioche la première ou dernière carte du board
	et si besoin on modifie les pinteurs firstCard et lastCard 
	et puis on détache first (ou temp) de la liste chainée... Trivial*/
	first->getPrec() != NULL ? first->getPrec()->setSuiv(first->getSuiv()) : firstCard = first->getSuiv();
	first->getSuiv() != NULL ? first->getSuiv()->setPrec(first->getSuiv()) : lastCard  = first->getPrec();
	
	first->setSuiv(NULL);
	cout << "nb carte : " << this->getLength() << "  " << num << endl;
	if (nb_carte > 1){
		Carte *temp;
		Carte *last = first;

		for (int i = 1; i < nb_carte; i++)
		{
			pose = 0;
			cout << "nb carte : " << this->getLength() << "  " << num << endl;
			temp = firstCard;
			num = rand() % this->getLength();
			while (pose++ != num) temp = temp->getSuiv();

			//Même chose
			if (temp->getPrec() != NULL && temp->getSuiv() != NULL)
			{
				temp->getPrec()->setSuiv(temp->getSuiv());
				temp->getSuiv()->setPrec(temp->getPrec());
			}
			else if (temp->getPrec() == NULL && temp->getSuiv() != NULL)
			{			
				firstCard = temp->getSuiv();
				temp->getSuiv()->setPrec(temp->getPrec());
			}
			else if (temp->getPrec() != NULL && temp->getSuiv() == NULL)
			{
				lastCard = temp->getPrec();
				temp->getPrec()->setSuiv(temp->getSuiv());
			}
			else
			{
				firstCard = NULL;
				lastCard  = NULL;
			}
			
			last->setSuiv(temp);
			temp->setPrec(last);
			temp->setSuiv(NULL);
			last = temp;

		}
	}
	return first;
}