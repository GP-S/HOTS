#ifndef EFFECT_H
#define EFFECT_H

#include <string>
#include <list>
#include <iostream>
#include <iterator>
#include <stdexcept>


class Effect : 
{
    public:
        Effect();
		Effect();
       	~Effect();
		std::string Effect::getType();
		std::string Effect::getAffinity();
		int Effect::getValue();
		void Effect::setType(std::string type);
		void Effect::setAffinity(std::string affinity);
		void Effect::setValue(int value);
		
    protected:
    	std::string type;
    	std::string affinity;
    	int	value;

    private:

};

#endif // EFFECT_H
