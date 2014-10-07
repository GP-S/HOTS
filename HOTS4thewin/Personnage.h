#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "Carte.h"
#include "Board.h"


class Personnage : public Carte
{
    public:
        Personnage();
        ~Personnage();
		bool isAlive();
		void setBoard(Board * Board, Ttype Type);
		Board * getBoard(Ttype Type);
    protected:
		Board * Deck;
		Board * Pioche;
		Board * Hand;
		Board * ZoneCombat;
    private:
};

#endif // PERSONNAGE_H
