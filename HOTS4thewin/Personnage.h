#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "Carte.h"


class Personnage : public Carte
{
    public:
        Personnage();
        ~Personnage();
		bool isAlive();
    protected:
    private:
};

#endif // PERSONNAGE_H
