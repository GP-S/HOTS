#include "Board.h"


Board::Board(){
  
  listCard = new std::list<Card*>();
  size_max = listCard->max_size();

}

Board::Board(std::list<Card*> *listcard){
  
  listCard = listcard;
  size_max = listCard->max_size();

}

Card * Board::getCardX(unsigned int x){
  
  std::list<Card*>::iterator it;
  
  it = listCard->begin();

  for(size_t i = 0; i < x; i++)
    it++;
  
  return *it;  

}

Card * Board::takeCardX(unsigned int x){
  
  std::list<Card*>::iterator it;
  Card *card;
  
  it = listCard->begin();

  for(size_t i = 0; i < x; i++)
    it++;

  card = *it;
  
  listCard->erase(it);

  return card;  
  
}

void Board::deleteCardX(unsigned int x){
  
  std::list<Card*>::iterator it;
  
  it = listCard->begin();

  for(size_t i = 0; i < x; i++)
    it++;
  
  listCard->erase(it);
  
}

unsigned int Board::getSize(){
  
   return listCard->size();
  
}

unsigned int Board::getMaxSize(){
  
  return size_max;
  
}

void Board::setMaxSize(unsigned int size){
  
  size_max = size;
  
}

void Board::addCardX(Card *card,unsigned int x){
  
  std::list<Card*>::iterator it;

  it = listCard->begin();

  for(size_t i = 0; i < x; i++)
    it++;
    
  listCard->insert(it, card);
}

void Board::addListCardX(std::list<Card*> *listcard, unsigned int x){
  
  std::list<Card*>::iterator it;
  
  it = listCard->begin();
  
  for(size_t i = 0; i < x; i++)
    it++;
  
  listCard->splice(it,*listcard);
  
}

bool Board::isFull(){
  
  if(listCard->size() == size_max)
    return 1;
  else
    return 0;
  
}

  Board::~Board(){
    listCard->erase(listCard->begin(),listCard->end());
    std::cout << "EXTERMINATE (board) not yet" << std::endl;
  }