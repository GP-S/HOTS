#include "RegulatedBoard.h"

RegulatedBoard::RegulatedBoard(){

  listCard = new std::list<iCard*>();
  cardByArrivalTime = new std::list<iCard*>();
  size_max = listCard->max_size();

}

RegulatedBoard::RegulatedBoard(std::list<iCard*> *listcard){

  listCard = listcard;
  cardByArrivalTime = listcard;
  size_max = listcard->max_size();

}

iCard* RegulatedBoard::takeCardX(unsigned int x){

  /**
   * We have two positions to consider : x, the position in the regulated
   * list and y, the position in the list by arrival time.
   */
   
  if(listCard->size() < x)
    throw std::logic_error( "the number is to big" );

  std::list<iCard*>::iterator it1;
  std::list<iCard*>::iterator it2;
  iCard* pointerCard1;
  iCard* pointerCard2;
  
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

  std::list<iCard*>::iterator it1;
  std::list<iCard*>::iterator it2;
  iCard* pointerCard1;
  iCard* pointerCard2;

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

void RegulatedBoard::addCardX(iCard*card,unsigned int x){

  if(listCard->size() < x){
    listCard->push_back(dynamic_cast<iCard*> (card));
    cardByArrivalTime->push_back(dynamic_cast<iCard*> (card));
  }
  else{
    std::list<iCard*>::iterator it;
    it = listCard->begin();
    for(size_t i = 0; i < x; i++)
      it++;

    listCard->insert(it,dynamic_cast<iCard*> (card));
    cardByArrivalTime->push_back(dynamic_cast<iCard*> (card));
  }
}


void RegulatedBoard::addCardX(std::list<iCard*> *list, unsigned int x) {

	std::list<iCard*>::iterator it;
	it = listCard->begin();

  if(this->listCard->size() < x)
    for(size_t i = 0; i < x; i++)
      it++;

  else
    it = this->listCard->end();


	this->listCard->splice(it, *list);
	this->listCard->splice(this->listCard->end(), *list);
	/*this->cardByArrivalTime->insert(this->cardByArrivalTime->end, //maybe onde day...
								  ((std::list<iCard*>)list)->begin(),
								  ((std::list<iCard*>)list)->end());
  */
}

unsigned int RegulatedBoard::CardArrivalByTime(iCard*card){

  unsigned int arrival = 0;
  bool finish = false;

  std::list<iCard*>::iterator it1;
  std::list<iCard*>::iterator it2;
  it1 = listCard->begin();
  it2 = cardByArrivalTime->begin();
  
  while(dynamic_cast<iCard*> (card) != *it1){
    
    if(it1 == listCard->end())
      throw std::logic_error( "no finding card" );
      
    it1++;
  }

  while(!finish){

    if(*it2 == *it1){
      finish = true;
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