#include "Board_Test.h"

static unsigned int etape = 0;
static size_t increm = 0;

void printEtape(std::string text){
	std::cout << std::endl;
	etape++;
	std::cout << "***etape " << etape << text << " *** " << std::endl;
}

void printBoard(Board *board, std::string name){

	std::cout << "Board " << name << ": " << std::endl;
	for(size_t i = 0; i < board->getSize(); i++){
		std::cout <<	" Card[" << i << "]";
		std::cout <<	" name: " << board->getCardX(i)->getName();
	} 
	std::cout << std::endl;
}

void printTimeBoard(RegulatedBoard *board, std::string name){

	iCard *iCard;

	std::cout << "Board " << name << ": " << std::endl;

	for(size_t i = 0; i < board->getSize(); i++){
		iCard = board->getCardX(i);
		std::cout <<	" Card[" << i << "]";
		std::cout <<	" name: " << board->getCardX(i)->getName()<< std::endl;
		std::cout <<	" arrival time: " << board->CardArrivalByTime(iCard) << std::endl;
	} 
	std::cout << std::endl;
}

void printCard(Card *card){

	std::cout << "Card: " << std::endl;

	std::cout <<	" cost: " << card->getCost();
	std::cout <<	" type: " << card->getType();
	std::cout <<	" name: " << card->getName() << std::endl;
}

void printListCard(std::list<Card*> *listCard){

	std::cout << "Card: " << std::endl;

	foreach(std::list<Card*>,listCard,it){
		std::cout <<	" cost: " << (*it)->getCost();
		std::cout <<	" type: " << (*it)->getType();
		std::cout <<	" name: " << (*it)->getName() << std::endl;
	}
}

void printSizeBoard(Board *board, std::string name){
	std::cout << "Board " << name << " size: " << board->getSize() << " maxSize: " << board->getMaxSize() << std::endl;
}

/*
	Board();
	Board(std::list<Card*> *listCard);
	virtual iCard * getCardX(unsigned int x);
	virtual iCard * takeCardX(unsigned int x);
	virtual void deleteCardX(unsigned int x);
	unsigned int getSize();
	unsigned int getMaxSize();
	void setMaxSize(unsigned int size);
	virtual void addCardX(iCard *card,unsigned int x);
	virtual void addCardX(std::list<iCard*> *listcard, unsigned int x);
	bool isFull();
	virtual ~Board();
*/

/*==================================================================================*/
/*===================================MAIN===========================================*/
/*==================================================================================*/

int main(int argc, char **argv){


/*=================================etape  1=========================================*/
/*Instance of some card, and three board: hand, cemetery and deck*/
 	printEtape(": Instanciation of hand, cemetery and deck and a list of card with newDeck");

 	std::list<Card*> *listOfCard = newDeck();

	iCard *tmpCard;

 	Board *deck = new Board();
 	Board *hand = new Board();
 	RegulatedBoard *battlefield = new RegulatedBoard();


/*=================================etape  2=========================================*/
/*I print all cards in the list of cards*/
	printEtape(": Some visual of all cards");

	printListCard(listOfCard);

/*=================================etape  3=========================================*/
/*Set the max size of all board*/
	printEtape(": Set max size of all board");

	hand->setMaxSize(7);
	battlefield->setMaxSize(3);

	printSizeBoard(deck,"deck");
	printSizeBoard(hand,"hand");
	printSizeBoard(battlefield,"battlefield");


// /*==================================================================================*/
// /*I try to put a card in some invalides positions*/
// 	//hand->addCardX(&card[6],6);
// 	//hand->addCardX(&card[0],12);
	


/*=================================etape  4=========================================*/
/*I put all cards in the deck*/
	printEtape(": Fill the deck with all cards");

//	deck->addCardX(reinterpret_cast <std::list<iCard*> *> (listOfCard),0);
//	deck->addCardX((iCard*)listOfCard->front(),0);
	

	for(std::list<Card*>::iterator it = listOfCard->begin(); it != listOfCard->end(); ++it){
		deck->addCardX((iCard*)(*it),0);
	}

	printSizeBoard(deck,"deck");
	printBoard(deck,"deck");

/*=================================etape  5=========================================*/
/*I look the first 3 cards of deck*/
	printEtape(": Look first 3 cards of deck");

	for(size_t i = 0; i < 3; i++){
		tmpCard = deck->getCardX(i);
		printCard((Card*)tmpCard);
	}


/*=================================etape  6=========================================*/
/*I delete the first Card of deck*/
	printEtape(": Delete the first card of deck");

	deck->deleteCardX(0);

	printSizeBoard(deck,"deck");
	printBoard(deck,"deck");

/*=================================etape  7=========================================*/
/*I take all cards I can from deck and I put them into hand*/
	printEtape(": Take all posible cards from deck and put them into hand");	// etape 8

	increm = 0;

	while(!hand->isFull()){
		tmpCard = deck->takeCardX(0);

		hand->addCardX(tmpCard,increm++);

	}


	printSizeBoard(deck,"deck");
	//printBoard(deck,"deck");
	printSizeBoard(hand,"hand");
	//printBoard(hand,"hand");

/*=================================etape  8=========================================*/
/*I take all cards from hand and I put them into battlefield, if I can't place it on battle, I put it into hand*/
	printEtape(": Take all cards from hand and put them into battlefield, if it's not possible the card is returned into hand");

	for(size_t i = 0; i < 7; i++){
		tmpCard = hand->takeCardX(0);

		if(!battlefield->isFull())
			battlefield->addCardX(tmpCard,i);
		
		else
			hand->addCardX(tmpCard,0);

	}

	printSizeBoard(hand,"hand       ");
	//printBoard(hand,"hand");
	printSizeBoard(battlefield,"battlefield");
	printBoard(battlefield,"battlefield");

/*=================================etape  9=========================================*/
/*I delete the first card in battlefield, and I put another card in first position of battlefield*/
	printEtape(": Delete the first card in battlefield,Put another card in first position of battlefield");

	battlefield->deleteCardX(0);

	printSizeBoard(battlefield,"battlefield");
	printBoard(battlefield,"battlefield");
	printTimeBoard(battlefield,"battlefield");

	tmpCard = hand->takeCardX(0);
	battlefield->addCardX(tmpCard,0);


	printSizeBoard(battlefield,"battlefield");
	printBoard(battlefield,"battlefield");
	printTimeBoard(battlefield,"battlefield");

/*=================================etape  9=========================================*/
/*I add the list of cards to deck*/
	// printEtape(": add list of cards to deck");	// etape 10

	// std::list<Card*> *listCard = new std::list<Card*>();


	// for(size_t i = 0; i < NUMBER; i++){
	// 	listCard->push_back(&card[i]);
	// }


	// printCard(card,NUMBER);
	// foreach(std::list<Card*>, listCard, it){
	// 	printCard(*it,1);
	// 	//std::cout << "hello" << std::endl;
	// }

	// deck->setMaxSize(2*NUMBER);

	// deck->addListCardX(listCard,NUMBER/2);

	// printSizeBoard(deck,"deck");
	// printBoard(deck,"deck");

// /*==================================================================================*/
// /*I delete the cemetery*/
// 	printEtape(": Delete the cemetery");	// etape 11

// 	printSizeBoard(cemetery,"cemetery");
// 	printBoard(cemetery,"cemetery");

// 	delete cemetery;

// 	printSizeBoard(cemetery,"cemetery");
// 	printBoard(cemetery,"cemetery");

// /*==================================================================================*/
// /*I create a new RegulatedBoard and I initialise it*/
// 	printEtape(": RegulatedBoard: a new age ->battlefield");	// etape 12
// 	RegulatedBoard *battlefield = new RegulatedBoard();
// 	battlefield->setMaxSize(7);

// 	printSizeBoard(battlefield,"battlefield");

// /*==================================================================================*/
// /*I fill the battlefield by the end*/
// 	printEtape(": Fill the battlefield by the end");	// etape 13
	
// 	for(size_t i = 0; i < 7; i++)
// 		battlefield->addCardX(&card[i],i);

// 	printBoard(battlefield,"battlefield");

// 	std::cout << "card arrival by time: " << battlefield->CardArrivalByTime(&card[2]) << std::endl;


// /**/

/*==================================================================================*/
/*	 destruction, il manque aussi la création d'une liste avec une liste de cartes
	Il manque aussi le fait que l'on travail avec des RegulatedBoard & des StackBoard
			*/

	printEtape(": End of the test, all tests are succesfull for the science !");	// etape 10
	return 0;
}
