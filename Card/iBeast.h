#ifndef IBEAST_H
#define IBEAST_H


class iBeast : public iCreature
{
    public:
        

        /**
        * Destructor
        * Does nothing atm
        *
        **/
        virtual ~Beast() {};

        /**
        * getRace
        * Basic geter
        *
        **/
		virtual std::string getRace() = 0;
        
        /**
        * setRace
        * Basic seter
        *
        **/
		virtual void setRace(std::string race) = 0;


};

#endif // IBEAST_H