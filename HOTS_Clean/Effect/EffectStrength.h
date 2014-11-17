#ifndef EFFECTSTRENGTH_H
#define EffectSTRENGTH_H

#include <exception>
#include "stdafx.h"
#include "Effect.h"

/** 
*	Class EffectStrength . Derived from Effect . Used to handle all strength-related events .
* @author Armand
*
**/

class EffectStrength : public Effect
{
    public:
    	/**
    	* Default constructor
    	* Does nothing atm
    	*
    	**/
    	EffectStrength();
    	/**
    	* Constructor
    	* Does nothing atm
    	*
    	**/
		EffectStrength();
		/**
    	* Destructor
    	* Does nothing atm
    	*
    	**/
    	~EffectStrength();
    	/**
			* increaseStrength . Used everytime we need to increase the strength of a card
			* @param Card* card The target of the modification
			* @param unsigned int modifier The amount of the modification
			*
			**/
		void increaseStrength(Card* card,unsigned int modifier);
			/**
			* decreaseStrength . Used everytime we need to decrease the strength of a card
			* @param Card* card The target of the modification
			* @param unsigned int modifier The amount of the modification
			*
			**/
		void decreaseStrength(Card* card,unsigned int modifier);
			/** i wonder if we need this one
			* increaseBaseStrength . Used everytime we need to increase the base strength of a card
			* @param Card* card The target of the modification
			* @param unsigned int modifier The amount of the modification
			*
			**/
		void increaseBaseStrength(Card* card,unsigned int modifier);
			/** i wonder if we need this one
			* decreaseBaseStrength . Used everytime we need to decrease the base strength of a card
			* @param Card* card The target of the modification
			* @param unsigned int modifier The amount of the modification
			*
			**/
		void decreaseBaseStrength(Card* card,unsigned int modifier);
    protected:

    private:


};

#endif // EFFECTSTRENGTH_H
