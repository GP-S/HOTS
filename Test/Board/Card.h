#ifndef CARD_H
#define CARD_H



/**
* The class Board is .
* @author Nicolas Léger
*/

class Card
{

protected:
	int strength;
	int life;
	
public:
	
	/** 
	* Constructor which puts ints to zero. 
	*/
	Card();
	
	/** 
	* Create a Card and initialize it with a strength and a life.  
	* @param int strength is the strength of the creature.
	* @param int life is the life of the creature.
	*/
	Card(int strength,int life);
	
	/** 
	* Return the strength of the card.
	* @return int the strength.
	*/
	int getStrength();
	
	/** 
	* Return the strength of the card.
	* @return int the strength.
	*/
	int getLife();
	
	/** 
	* Set the strength of the creature.  
	* @param int strength.
	*/
	void setStrength(int strength);

	/** 
	* Set the life of the creature.  
	* @param int life.
	*/
	void setLife(int life);
	
	/**
 	* Destructor.
 	*/
	~Card();

};

#endif //CARD_H