#ifndef SORT_H
#define SORT_H

#include "Carte.h"


class Sort : public Carte
{
    public:
        Sort();
		Sort(string name);
        ~Sort();
		bool isAlive();
    protected:
    private:
};

#endif // SORT_H
