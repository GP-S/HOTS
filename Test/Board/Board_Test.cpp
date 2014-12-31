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

void printCard(Card *card){

	std::cout << "Card: " << std::endl;

	std::cout <<	" cost: " << card->getCost();
	std::cout <<	" type: " << card->getType();
	std::cout <<	" name: " << card->getName() << std::endl;
}

void printListCard(std::list<iCard*> *listCard){

	std::cout << "Card: " << std::endl;

	std::for_each(listCard->begin(),listCard->end(), [] (iCard* it){
 		std::cout <<	" cost: " << dynamic_cast<Card*>(it)->getCost();
		std::cout <<	" type: " << dynamic_cast<Card*>(it)->getType();
		std::cout <<	" name: " << dynamic_cast<Card*>(it)->getName() << std::endl;
		}
	);
}

void printSizeBoard(Board *board, std::string name){
	std::cout << "Board " << name << " size: " << board->getSize() << " maxSize: " << board->getMaxSize() << std::endl;
}

/*==================================================================================*/
/*===================================MAIN===========================================*/
/*==================================================================================*/

int main(int argc, char **argv){


/*=================================etape  1=========================================*/
/*Instance of some card, and three board: hand, cemetery and deck*/
 	printEtape(": Instanciation of hand, cemetery and deck and a list of card with newDeck");

 	std::list<iCard*> *listOfCard = newDeck();

	iCard *tmpCard;

 	Board *deck = new Board();
 	Board *hand = new Board();
 	// RegulatedBoard *battlefield = new RegulatedBoard();


/*=================================etape  2=========================================*/
/*I print all cards in the list of cards*/
	printEtape(": Some visual of all cards");

	printListCard(listOfCard);

/*=================================etape  3=========================================*/
/*Set the max size of all board*/
	printEtape(": Set max size of all board");

	hand->setMaxSize(7);
	// battlefield->setMaxSize(3);

	printSizeBoard(deck,"deck");
	printSizeBoard(hand,"hand");
	// printSizeBoard(battlefield,"battlefield");

/*=================================etape  4=========================================*/
/*I put all cards in the deck*/
	printEtape(": Fill the deck with all cards");

	std::for_each(listOfCard->begin(),listOfCard->end(), [deck] (iCard* it){
 		deck->addCardX((iCard*)it,0);
		}
	);

	printSizeBoard(deck,"deck");
	printBoard(deck,"deck");

/*=================================etape  5=========================================*/
/*I look the first 3 cards of deck*/
	printEtape(": Look first 3 cards of deck");

	for(size_t i = 0; i < 3; i++){
		tmpCard = deck->getCardX(i);
		printCard(dynamic_cast<Card*> (tmpCard));
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
/*	 destruction, il manque aussi la création d'une liste avec une liste de cartes
	Il manque aussi le fait que l'on travail avec des RegulatedBoard & des StackBoard
			*/

	printEtape(": End of the test, all tests are succesfull for the science !");
	return 0;
}
