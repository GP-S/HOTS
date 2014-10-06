#pragma once
#include "Carte.h"
class Board
{
public:
	Board();
	Board(Carte *teteList);
	
	Carte * getFirstCard();
	Carte * pioche(int nb_carte);
	int		getLength();
	void    addCard(Carte *card);
	~Board();

private:
	Ttype		type;
	Carte		*firstCard;
	Carte		*lastCard;
};

