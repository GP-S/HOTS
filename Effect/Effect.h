#ifndef EFFECT_H
#define EFFECT_H

#include <string>

class Effect
{
    public:
        Effect();
        ~Effect();
		void setValue(int val);
		int getValue();
		std::string getType();
		
    protected:

    private:
		int value;
		std::string type;
};

#endif // EFFECT_H
