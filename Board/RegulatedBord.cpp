#include "RegulatedBoard.h"

Card * takeCardX(unsigned int x, unsigned int y){
  
  /**
   * We have two positions to consider : x, the position in the regulated list and y, 
   * the position in the list by arrival time. 
   */
  
  std::list<Card>::iterator it1;
  std::list<Card>::iterator it2;
  Card* pointerCard1;
  Card* pointerCard2;
  
  it1 = listCard.begin();
  it1 += x;
  pointerCard1 = it1;
  
  it2 = CardByArrivalTime.begin();
  it2 += y;
  pointerCard2 = it2;
  
  if(*pointerCard1 == *pointerCard2){
    
    listcard.erase(it1);
    CarByArrivalTime.erase(it2);
    
    return pointerCard1 ;
    
  }
  
  else{
  
  /* RETURN ERROR */
 
  }
  
}

void 

