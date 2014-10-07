#ifndef CARTE_H
#define CARTE_H

#include <string>
//#include <tchar.h>
//#include <stdlib.h>
#include <iostream>
#include "Attribut.h"

using namespace std;

class Carte
{
    public:
				  Carte();
				  Carte(string name, Ttype typ);
				  ~Carte();
		void	  addAttribut(Attribut * att);
		Carte	  *getPrec();
		Carte	  *getSuiv();
		void	  setPrec(Carte* prec);
		void	  setSuiv(Carte* suiv);
		string	  getName();
		virtual   bool isAlive() = 0;
		Attribut  *findByType(Ttype type);
		Ttype	  getType();

    

    protected:
        string		nom;
        //char		type;
        short int	degat;
        Attribut	*liste_Att;
		Ttype		type;
		Carte		*cartePrec;
		Carte		*carteSuiv;
};

#endif // CARTE_H
