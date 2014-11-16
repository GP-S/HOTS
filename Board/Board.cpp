#include "Board.h"


/** 
* Constructor which puts listCard to NULL. 
*/
Board::Board(){
  
  listCard = NULL;

}


/** 
* Create a board and initialize it with the pointer of listCard.  
* @param std::list<Card> *listCard pointer of a list of card.
*/
Board::Board(std::list<Card> *listCard){
  
  this.listCard = listCard;

}


/** 
* Get the card which is at the Xth position.
* @param unsigned int x position of the wanted card.
* @return Card the pointer of the card.
*/
Card * Board::getCardX(unsigned int x){
  
  std::list<Card>::iterator it;
  
  it = listCard.begin();
  it += x;
  
  return *it;  

}


/** 
* Take the card which is at the Xth position and erase it of the deck.
* @param unsigned int x position of the wanted card.
* @return Card the pointer of the card.
*/
Card * takeCardX(unsigned int x){
  
  std::list<Card>::iterator it;
  Card card;
  
  it = listCard.begin();
  it += x;
  card = it;
  
  listcard.erase(it);
  
  return *card;  
  
}


/** 
* Return the size of the list.
*/
unsigned int getSize(){
  
  return listCard.size;
  
}


/** 
* Return the maximum size of the list.  
*/
unsigned int getMaxSize(){
  
  return listCard.max_size;
  
}


/** 
* Set the maximum size of the list to the value size.  
* @param unsigned int size.
*/
void setMaxSize(unsigned int size){
  
  listCard.max_size = size;
  
}

/**
 * Add a card at the Xth position of a board.
 * @param Card *card pointer of the target card, unsigned int x wanted position.
 */
void addCardX(Card *card,unsigned int x){
  
  std::list<Card>::iterator it;
  
  it = listCard.begin();
  it += x;
  insert(it, 1, *card);
  
}

/**
 * Add a list of cards at the Xth position of a board.
 * @param std::list<Card> *listCard pointer of the list of cards, unsigned int x wanted position. 
 */
void addListCardX(std::list<Card> *listCard,unsigned int x){
  
  std::list<Card>::iterator it;
  
  it = this.listCard.begin();
  it += x;
  
  this.listCard.splice(it,listeCard);
  
}

/**
 * Destructor.
 */
~Board();
