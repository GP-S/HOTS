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

Carte * Board::getCardX(int x)
{
	Carte * temp = firstCard;
	int i = 0;
	while (++i < x && temp != NULL) temp = temp->getSuiv();
	return i == x ? temp : NULL;
}

Carte * Board::takeCardX(int x)
{
	Carte * temp = firstCard;
	int i = 0;
	while (++i < x && temp != NULL) temp = temp->getSuiv();
	if (i == x){
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
			lastCard = NULL;
		}
		temp->setSuiv(NULL);
		temp->setPrec(NULL);
		return temp;
	}
	return NULL;
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
	}
	else{
		firstCard = card;
	}
	for (lastCard = card; lastCard->getSuiv() != NULL; lastCard = lastCard->getSuiv());
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
	if (first->getPrec() != NULL && first->getSuiv() != NULL)
	{
		first->getPrec()->setSuiv(first->getSuiv());
		first->getSuiv()->setPrec(first->getPrec());
	}
	else if (first->getPrec() == NULL && first->getSuiv() != NULL)
	{
		firstCard = first->getSuiv();
		first->getSuiv()->setPrec(first->getPrec());
	}
	else if (first->getPrec() != NULL && first->getSuiv() == NULL)
	{
		lastCard = first->getPrec();
		first->getPrec()->setSuiv(first->getSuiv());
	}
	else
	{
		firstCard = NULL;
		lastCard = NULL;
		return 0;
	}
	first->setPrec(NULL);
	first->setSuiv(NULL);


	/* Même histoire mais pour les N suivants.*/
	if (nb_carte > 1){
		Carte *temp;
		Carte *last = first;

		for (int i = 1; i < nb_carte; i++)
		{
			pose = 0;
			//cout << "nb carte : " << this->getLength() << "  " << num << endl;
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
				return 0;
			}
			
			last->setSuiv(temp);
			temp->setPrec(last);
			temp->setSuiv(NULL);
			last = temp;

		}
	}
	return first;
}