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
   * list and y, the position in the list by arrival time.
   */
   
  if(listCard->size() < x)
    throw std::logic_error( "the number is to big" );

  std::list<Card*>::iterator it1;
  std::list<Card*>::iterator it2;
  Card* pointerCard1;
  Card* pointerCard2;
  
  it1 = listCard->begin();

  for(size_t i = 0; i < x; i++)
    it1++;

  pointerCard1 = *it1;

  it2 = cardByArrivalTime->begin();

  bool finish = false;
  
  while(!finish){
    if(*it2 == pointerCard1){
      pointerCard2 = *it2;
      finish = true;
    }
    if(it2 == cardByArrivalTime->end() & !finish)
      throw std::logic_error( "no corresponding card between listCard and cardByArrivalTime" );
    
    it2++;
  }

  listCard->erase(it1);
  cardByArrivalTime->erase(it2);

  return pointerCard1;


}

void RegulatedBoard::deletCardX(unsigned int x){


  if(listCard->size() < x)
    throw std::logic_error( "the number is to big" );

  std::list<Card*>::iterator it1;
  std::list<Card*>::iterator it2;
  Card* pointerCard1;
  Card* pointerCard2;

  it1 = listCard->begin();
  for(size_t i = 0; i < x; i++)
    it1++;

  pointerCard1 = *it1;

  it2 = cardByArrivalTime->begin();
  bool finish = false;

  while(!finish){
    if(*it2 == pointerCard1){
      pointerCard2 = *it2;
      finish = true;
    }
    if(it2 == cardByArrivalTime->end() & !finish)
      throw std::logic_error( "no corresponding card between listCard and cardByArrivalTime" );
    
    it2++;
  }

  listCard->erase(it1);
  cardByArrivalTime->erase(it2);

}

void RegulatedBoard::addCardX(Card *card,unsigned int x){

  if(listCard->size() < x){
    listCard->push_back(card);
    cardByArrivalTime->push_back(card);
  }
  else{
    std::list<Card*>::iterator it;
    it = listCard->begin();
    for(size_t i = 0; i < x; i++)
      it++;

    listCard->insert(it,card);
    cardByArrivalTime->push_back(card);
  }
}


void RegulatedBoard::addCardX(std::list<Card*> *list, unsigned int x) {

	std::list<Card*>::iterator it;
	it = listCard->begin();
	this->listCard->size() < x ? it = this->listCard->end : std::advance(it, x);
	this->listCard->insert(it,
						 list->begin(),
						 list->end());
	this->cardByArrivalTime->insert(this->cardByArrivalTime->end,
								  list->begin(),
								  list->end());
  
}

unsigned int RegulatedBoard::CardArrivalByTime(Card *card){

  unsigned int arrival = 1;
  bool finish = false;

  std::list<Card*>::iterator it1;
  std::list<Card*>::iterator it2;
  it1 = listCard->begin();
  
  while(card != *it1){
    
    if(it1 == listCard->end())
      throw std::logic_error( "no finding card" );
      
    it1++;
  }

  while(!finish){
    if(*it2 == *it1){
      finish = true;
      std::cout << "it2 = it1" << std::endl;
      break;
    }
    if(it2 == cardByArrivalTime->end() & !finish)
      throw std::logic_error( "no corresponding card between listCard and cardByArrivalTime" );
      
    it2++;
    arrival++;
  }

  return arrival;

}

RegulatedBoard::~RegulatedBoard(){
  listCard->erase(listCard->begin(),listCard->end());
  cardByArrivalTime->erase(cardByArrivalTime->begin(),cardByArrivalTime->end());
  std::cout << "EXTERMINATE (regulatedBoard) not yet" << std::endl;
}
