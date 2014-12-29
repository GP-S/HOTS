#ifndef IEFFECT_H
#define IEFFECT_H

#include "iCard.h"

class iCard;

class iEffect
{
    public:


		virtual std::string getType() = 0;
		virtual std::string getAffinity() = 0;
		virtual int getValue() = 0;
		virtual void setType(std::string type) = 0;
		virtual void setAffinity(std::string affinity) = 0;
		virtual void setValue(int value) = 0;
		virtual float costVal(iCard *card = NULL) = 0;
		
    

};

#endif // IEFFECT_H
