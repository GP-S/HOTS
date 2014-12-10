
#include "RegulatedBoard.h"

RegulatedBoard::RegulatedBoard(){
  
  listCard = new std::list<Card*>();
  cardByArrivalTime = new std::list<Card*>();
  size_max = listCard->max_size();

}

RegulatedBoard::RegulatedBoard(std::list<Card*> *listcard){
  
  listCard = listcard;
  cardByArrivalTime = listcard;
  size_max = listcard->max_size();

}

Card* RegulatedBoard::takeCardX(unsigned int x, unsigned int y){
  
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
  
    /*
     * we need to discuss about this point... (how to erase ? Redefine erase ?)
     */
    Card newHostOfThisCard = new Card();
    newHostOfThisCard = *pointerCard1; 
  
    listcard.erase(it1);
    // Problem with the erase : the second deleting (suppression).
    CarByArrivalTime.erase(it2);

    return &newHostOfThisCard;

   
  }
  
  else{
  
  /* RETURN ERROR */
 
  }
  
}

void RegulatedBoard::deletCardX(unsigned int positionListCard, unsigned int positionByArrivalTime){
  
  /**
   * We have two positions to consider : x, the position in the regulated list and y, 
   * the position in the list by arrival time. 
   */
  
  std::list<Card>::iterator it1;
  std::list<Card>::iterator it2;
  Card* pointerCard1;
  Card* pointerCard2;
  
  it1 = listCard.begin();
  it1 += positionListCard;
  pointerCard1 = it1;
  
  it2 = CardByArrivalTime.begin();
  it2 += positionByArrivalTime;
  pointerCard2 = it2;
  
  if(*pointerCard1 == *pointerCard2){
    
    
    listcard.erase(it1);
    CarByArrivalTime.erase(it2);
    
    /*
     * Do we need a particular return ? (Depends on the error's return)
     */
    
  }
  
  else{
  
  /* RETURN ERROR */
 
  }
  
}

void RegulatedBoard::addCardX(Card *card,unsigned int position){
  
  std::list<Card>::iterator it;
  it = listcard.begin();
  it += position;
  
  listcard.insert(it,card);
  CardByArrivalTime.push_back(card);
  
}
  
RegulatedBoard::~RegulatedBoard(){
  listCard->erase(listCard->begin(),listCard->end());
  std::cout << "EXTERMINATE (board) not yet" << std::endl;
}