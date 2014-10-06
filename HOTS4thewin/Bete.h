#ifndef BETE_H
#define BETE_H

#include "stdafx.h"
#include "Carte.h"


class Bete : public Carte
{
    public:
        Bete();
		Bete(string name);
        ~Bete();
		bool isAlive();
    protected:
    private:
};

#endif // BETE_H
