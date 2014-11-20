#include "RegulatedBoard.h"

/**
* To do :
* Put some method...
* REDIFINE OPERATORS == AND != (and I don't succeed in this task (Yes, I tried
* to overload == with my CodeBlock and I have had odd answers of my PC)
*
*/

/*

// Proposition of a method which return the position in the list of the arrival by time
// if we need it.


Card * positionByArrivalTime(*Card wantedCar1d){
  
  std::list<Card>::iterator it;
  bool state = 0;
  while(state){
    if(it != card)
      it++;
    else 
      state = 1; 
  }
  card = it;
  return *card;
} 
*/

Card * takeCardX(unsigned int x){
  
  std::list<Card>::iterator it;
  Card card;
  
  it = listCard.begin();
  it += x;
  card = it;
  
  listcard.erase(it);
  /**
   * How will we erase the card of CardByArrivalTime ? Has the card the same position in the two lists (CardBy.. and listcard) ?
   * If not, we need to create a method which return the position of the card in CardByArrivalTime. 
   */
  
  CardByArrivalTime.erase(it);
  
  return *card; 
  
}

/**
 *  I'll finish this section when I'll have the precedent answers.
 * 
 */
