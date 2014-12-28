#ifndef EFFECT_H
#define EFFECT_H

#include <string>
#include <list>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include "iEffect.h"


class Effect : public iEffect
{
    public:
    	Effect();
		Effect(std::string type,std::string affinity,int value);
    	~Effect();
		std::string getType();
		std::string getAffinity();
		int getValue();
		void setType(std::string type);
		void setAffinity(std::string affinity);
		void setValue(int value);
		float costVal(iCard *card = NULL);
		
    protected:
    	std::string type;
    	std::string affinity;
    	int	value;

    private:

};

#endif // EFFECT_H
