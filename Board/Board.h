#ifndef BOARD_H
#define BOARD_H


#include "Carte.h"


class Board
{
public:
	Board();
	Board(Carte *teteList);
	
	Carte * getFirstCard();
	Carte * getCardX(int x);
	Carte * takeCardX(int x);
	Carte * pioche(int nb_carte);
	int		getLength();
	void    addCard(Carte *card);
	~Board();

private:
	std::list<Card>	listCard;
};

#endif // BOARD_H
