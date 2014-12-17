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

Card* RegulatedBoard::takeCardX(unsigned int x){

  /**
   * We have two positions to consider : x, the position in the regulated
list and y,
   * the position in the list by arrival time.
   */

  std::list<Card*>::iterator it1;
  std::list<Card*>::iterator it2;
  Card* pointerCard1;
  Card* pointerCard2;

  it1 = listCard->begin();

  for(size_t i = 0; i < x; i++)
    it1++;

  pointerCard1 = *it1;

  it2 = cardByArrivalTime->begin();

  bool endwork = false;
  while(!endwork){
    if(*it2 == pointerCard1){
      pointerCard2 = *it2;
      endwork = true;
    }
    it2++;
  }

  listCard->erase(it1);
  cardByArrivalTime->erase(it2);

  return pointerCard1;


}

void RegulatedBoard::deletCardX(unsigned int x){

  std::list<Card*>::iterator it1;
  std::list<Card*>::iterator it2;
  Card* pointerCard1;
  Card* pointerCard2;

  it1 = listCard->begin();
  for(size_t i = 0; i < x; i++)
    it1++;

  pointerCard1 = *it1;

  it2 = cardByArrivalTime->begin();
  bool endwork = false;

  while(!endwork){
    if(*it2 == pointerCard1){
      pointerCard2 = *it2;
      endwork = true;
    }
    it2++;
  }

  listCard->erase(it1);
  cardByArrivalTime->erase(it2);

}

void RegulatedBoard::addCardX(Card *card,unsigned int x){

  std::list<Card*>::iterator it;
  it = listCard->begin();
  for(size_t i = 0; i < x; i++)
    it++;

  listCard->insert(it,card);
  cardByArrivalTime->push_back(card);

}


unsigned int RegulatedBoard::CardArrivalByTime(Card *card){

  unsigned int arrival = 0;

  std::list<Card*>::iterator it1;
  std::list<Card*>::iterator it2;
  it1 = listCard->begin();
  bool endwork = false;
  bool finish = false;

  while(!finish){
    it2 = cardByArrivalTime->begin();
    std::cout << "*it1,*it2: " << *it1 << "," << *it2 << std::endl;
    arrival = 1;

    while(!endwork){
      if(*it2 == *it1){
        endwork = true;
        finish = true;
        std::cout << "it2 = it1" << std::endl;
        break;
      }
      if(it2 == cardByArrivalTime->end() & !endwork)
        endwork = true;
        finish = false;
        std::cout << "endwork = true, finish = false" << std::endl;
      it2++;
      arrival++;
      std::cout << "arrival = " << arrival << std::endl;
    }

    if(it1 == listCard->end()){
      finish = true;
      //throw error;
    }

    it1++;
  }


  return arrival;

}

RegulatedBoard::~RegulatedBoard(){
  listCard->erase(listCard->begin(),listCard->end());
  cardByArrivalTime->erase(cardByArrivalTime->begin(),cardByArrivalTime->end());
  std::cout << "EXTERMINATE (regulatedBoard) not yet" << std::endl;
}