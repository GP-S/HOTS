#include "Board.h"


Board::Board(){
  
  listCard = new std::list<iCard*>();
  size_max = listCard->max_size();

}

Board::Board(std::list<iCard*> *listcard){
  
  listCard = listcard;
  size_max = listCard->max_size();

}

iCard* Board::getCardX(unsigned int x){
  
  if(listCard->size() < x)
    throw std::logic_error( "the number is to big" );
  
  std::list<iCard*>::iterator it;
  
  it = listCard->begin();

  for(size_t i = 0; i < x; i++)
    it++;
  
  return *it;  

}

iCard* Board::takeCardX(unsigned int x){
  
  if(listCard->size() < x)
    throw std::logic_error( "the number is to big" );
  
  std::list<iCard*>::iterator it;
  iCard*card;
  
  it = listCard->begin();

  for(size_t i = 0; i < x; i++)
    it++;

  card = *it;
  
  listCard->erase(it);

  return card;  
  
}

void Board::deleteCardX(unsigned int x){
  
  if(listCard->size() < x)
    throw std::logic_error( "the number is to big" );
  
  std::list<iCard*>::iterator it;
  
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

void Board::addCardX(iCard*card,unsigned int x){
  
  if(listCard->size() < x){
    listCard->push_back(dynamic_cast<iCard*> (card));
  }
  else{
    std::list<iCard*>::iterator it;

    it = listCard->begin();

    for(size_t i = 0; i < x; i++)
      it++;
    
    listCard->insert(it, dynamic_cast<iCard*> (card));
  }
}

void Board::addCardX(std::list<iCard*> *listcard, unsigned int x){
  
  if(listCard->size() < x)
    throw std::logic_error( "the number is to big" );
    
  if(size_max < listCard->size()+listcard->size())
    throw std::logic_error( "the listcard is too big" );
  
  std::list<iCard*>::iterator it;
  
  it = listCard->begin();
  
  for(size_t i = 0; i < x; i++)
    it++;

  listCard->splice(it, *listcard);
  
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

std::list<iCard*>::iterator Board::begin(){

  return listCard->begin();
}

std::list<iCard*>::iterator Board::end(){

  return listCard->end();
}
