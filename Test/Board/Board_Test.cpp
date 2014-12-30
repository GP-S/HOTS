#include "Board_Test.h"

static unsigned int etape = 0;


void printEtape(std::string text){
	std::cout << std::endl;
	etape++;
	std::cout << "***etape: " << etape << text << " *** " << std::endl;
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

	std::cout <<	" name: " << card->getName();
	std::cout <<	" type: " << card->getType();
	std::cout <<	" cost: " << card->getCost() << std::endl;
}

void printListCard(std::list<Card*> *listCard){

	std::cout << "Card: " << std::endl;

	foreach(std::list<Card*>,listCard,it){
		std::cout <<	" name: " << (*it)->getName();
		std::cout <<	" type: " << (*it)->getType();
		std::cout <<	" cost: " << (*it)->getCost() << std::endl;
	}
}

void printSizeBoard(Board *board, std::string name){
	std::cout << "Board " << name << " maxSize: " << board->getMaxSize() << " Size: " << board->getSize() << std::endl;
}

/*==================================================================================*/
/*===================================MAIN===========================================*/
/*==================================================================================*/

int main(int argc, char **argv){


/*=================================etape  1=========================================*/
/*Instance of some card, and three board: hand, cemetery and deck*/
 	printEtape(": Instanciation of cards, hand, cemetery and deck donne");	// etape 1
 	std::list<Card*> *deck = newDeck();

// 	Card *card;
// 	Card *tmpCard;

// 	card = (Card*)malloc(NUMBER*sizeof(Card));
// 	tmpCard = (Card*)malloc(NUMBER*sizeof(Card));

// 	Board *hand = new Board();
// 	Board *cemetery = new Board();
// 	Board *deck = new Board();

// /*==================================================================================*/
// /*Initialisation of all cards*/
// 	printEtape(": Initialisation of all cards done");	// etape 2

// 	for(size_t i = 0; i < NUMBER; i++){
// 		card[i].setName("alpha");
// 		card[i].setType("beast");
// 	}

// 	printCard(card,NUMBER);

// /*==================================================================================*/
// /*Set the max size of all board*/
// 	printEtape(": Set max size of all board done");	// etape 3

// 	deck->setMaxSize(NUMBER);
// 	hand->setMaxSize(NUMBER);
// 	cemetery->setMaxSize(7);

// 	printSizeBoard(deck,"deck");
// 	printSizeBoard(hand,"hand");
// 	printSizeBoard(cemetery,"cemetery");


// /*==================================================================================*/
// /*I try to put a card in some invalides positions*/
// 	//hand->addCardX(&card[6],6);
// 	//hand->addCardX(&card[0],12);
	


// /*==================================================================================*/
// /*I put all cards in the deck*/
// 	printEtape(": Fill the deck with all cards");	// etape 4

// 	for(size_t i = 0; i < NUMBER; i++){
// 		if(!deck->isFull())
// 			deck->addCardX(&card[i],i);
// 		else
// 			std::cout << "The board " << "deck" << " is full !" << std::endl;
		
// 	}

// 	printBoard(deck,"deck");

// /**/

// 	for(size_t i = 0; i < NUMBER; i++){
// 		tmpCard[i] = *deck->getCardX(i);
// 	}

// 	printEtape(": getCardX");	// etape 5
// 	printCard(tmpCard,NUMBER);

// /*==================================================================================*/
// /*I delete the first Card of deck*/
// 	printEtape(": Delete the first card of deck");	// etape 6

// 	deck->deleteCardX(0);

// 	printSizeBoard(deck,"deck");
// 	printBoard(deck,"deck");

// /*==================================================================================*/
// /*I add a card at the first position of deck*/
// 	printEtape(": Add a card at the top of deck");	// etape 7

// 	deck->addCardX(&card[0],0);

// 	printSizeBoard(deck,"deck");
// 	printBoard(deck,"deck");

// /*==================================================================================*/
// /*I take all cards from deck and I put them into hand*/
// 	printEtape(": Take all cards from deck and put them into hand");	// etape 8

// 	for(size_t i = 0; i < NUMBER; i++){
// 		tmpCard[i] = *deck->takeCardX(0);

// 		if(!hand->isFull())
// 			hand->addCardX(&tmpCard[i],i);
// 		else
// 			std::cout << "The board " << "hand" << " is full !" << std::endl;

// 		std::cout << "loop number: " << i << std::endl;
// 		printSizeBoard(deck,"deck");
// 		//printBoard(deck,"deck");
// 		printSizeBoard(hand,"hand");
// 		//printBoard(hand,"hand");
// 	}

// /*==================================================================================*/
// /*I take all cards from hand and I put them into cemetery, if i can't place it on battle, I keep it in hand*/
// 	printEtape(": Take all cards from hand and put them into cemetery");	// etape 9

// 	for(size_t i = 0; i < NUMBER; i++){
// 		tmpCard[i] = *hand->takeCardX(0);

// 		std::cout << "loop number: " << i << std::endl;

// 		if(!cemetery->isFull())
// 			cemetery->addCardX(&tmpCard[i],i);
// 		else{
// 			std::cout << "The board " << "cemetery" << " is full !" << std::endl;
// 			hand->addCardX(&tmpCard[i],0);
// 		}
// 		printSizeBoard(hand,"hand       ");
// 		//printBoard(hand,"hand");
// 		printSizeBoard(cemetery,"cemetery");
// 		//printBoard(cemetery,"cemetery");
// 	}

// /*==================================================================================*/
// /*I add the list of cards to deck*/
// 	printEtape(": add list of cards to deck");	// etape 10

// 	std::list<Card*> *listCard = new std::list<Card*>();


// 	for(size_t i = 0; i < NUMBER; i++){
// 		listCard->push_back(&card[i]);
// 	}


// 	printCard(card,NUMBER);
// 	foreach(std::list<Card*>, listCard, it){
// 		printCard(*it,1);
// 		//std::cout << "hello" << std::endl;
// 	}

// 	deck->setMaxSize(2*NUMBER);

// 	deck->addListCardX(listCard,NUMBER/2);

// 	printSizeBoard(deck,"deck");
// 	printBoard(deck,"deck");

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
