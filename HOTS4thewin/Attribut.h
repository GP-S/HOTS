#ifndef ATTRIBUT_H
#define ATTRIBUT_H


class Attribut
{
    public:
				 Attribut();
				 Attribut(Ttype type, int val, char duree);
				 ~Attribut();
				 void	 setType(Ttype inType);
		Ttype	 getType();
        void	 setVal(int inVal);
        int		 getVal();
        void	 setDuree(char inDuree);
        char	 getDuree();
		void	 setSuiv( Attribut * suiv);
		
		Attribut *suiv();
	protected:

    private:
		Ttype		type;
        int			val;
        char		duree;
        //thibault : a re réfléchir

		Attribut * attSuiv; //Parceque
};

#endif // ATTRIBUT_H
