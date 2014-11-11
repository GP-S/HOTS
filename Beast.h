#ifndef BEAST_H
#define BEAST_H

#include "stdafx.h"
#include "Card.h"


class Beast : public Card
{
    public:
        		Beast();
				Beast(string name);
        		~Beast();
		bool 	isAlive();
		int 	getHp();
		int 	getAttack();
		void	setHp(int hp);
		void 	setAttack(int attack);
		void 	attack(Beast* target);
    protected:

    private:
    	int hp;
    	int	attack;
    	int attackCount;
};

#endif // BEAST_H
