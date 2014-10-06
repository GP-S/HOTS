#ifndef ARTEFACT_H
#define ARTEFACT_H

#include "Carte.h"


class Artefact : public Carte
{
    public:
        Artefact();
        ~Artefact();
		bool isAlive();
    protected:
    private:
};

#endif // ARTEFACT_H
