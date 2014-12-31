/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2014  <copyright holder> <email>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "GameEngine.h"

Engine::GameEngine::GameEngine() : Server(1337,100)
{


    //corresCardId = NULL;
    //corresBoardId = NULL;  
    turn = 0;
}

Engine::GameEngine::GameEngine(std::list<iCard*>* deckPlayer0,std::list<iCard*>* deckPlayer1,iHero* heroPlayer0,iHero* heroPlayer1) : Server(1337,100)
{
    deckPlayer0=deckPlayer0;
    deckPlayer1=deckPlayer1;
    heroPlayer0=heroPlayer0;
    heroPlayer1=heroPlayer1;
    turn = 0;
    player0=nullptr;
    player1=nullptr;
    addEventListener(this, Polycode::ServerEvent::EVENT_CLIENT_CONNECTED);
    addEventListener(this, Polycode::ServerEvent::EVENT_CLIENT_DISCONNECTED);
    addEventListener(this, Polycode::ServerEvent::EVENT_CLIENT_DATA);
    /*
    for (int i=0;i<16;i++){
	    boards[i] = getBoard();
    }*/

}

Engine::GameEngine::GameEngine ( const GameEngine& other ) : Server(1337,100)
{

}

Engine::GameEngine::~GameEngine() 
{

}

Engine::GameEngine& Engine::GameEngine::operator= ( const Engine::GameEngine& other ) 
{

}

bool Engine::GameEngine::operator== ( const GameEngine& other ) const 
{

}

Engine::iGameSimulator* Engine::GameEngine::getSimulator ( void ) 
{
 	Engine::GameSimulator* gameSimulator=new GameSimulator(this, getCurrentPlayer());

	return dynamic_cast<iGameSimulator*> (gameSimulator);

}

iBoard* Engine::GameEngine::getBoard ( void ) 
{
 	Board* board = new Board();

	return dynamic_cast<iBoard*> (board);

}

void Engine::GameEngine::useCard(	int originIHMBoard, int originPosition, //-------------- DOUBT HERE
									int destinationIHMBoard, int destinationPosition)
{  	
	int idOriginBoard=originIHMBoard;
	int idDestinationBoard=destinationIHMBoard;

	if((idOriginBoard-1)/7!=turn%2)
	{//if the actions comes from a board that doesn't belong to the active player
		throw std::logic_error( "you cann't use that board right now" ); 
	}

  	iCard* playedCard = boards[idOriginBoard]->getCardX(originPosition);
  	//Player* activePlayer = (turn%2) ? (players->end()) : (players->begin()); 
	/* Decide on what is the action performed
	Timy-whymy-bubbly stuff . Abandon hope all ye who enter here . 
	*/
	if (playedCard->getType()=="beast")
	{
		if(	idOriginBoard==PLAYER0_BOARD||//this test is obsolete for now but i don't know how it's gonna be later 
			idOriginBoard==PLAYER1_BOARD)
		{//if it is an attack 
			if(	idOriginBoard==PLAYER0_BOARD&&idDestinationBoard==PLAYER1_BOARD||
				idOriginBoard==PLAYER1_BOARD&&idDestinationBoard==PLAYER0_BOARD)
			{//if it is an attack on a beast
				beastAttackBeast(idOriginBoard,idDestinationBoard,dynamic_cast<iBeast*> (playedCard),originPosition,destinationPosition);
			}
			if(	idOriginBoard==PLAYER0_BOARD&&idDestinationBoard==PLAYER1_HERO||
				idOriginBoard==PLAYER1_BOARD&&idDestinationBoard==PLAYER0_HERO)
			{//if it is an attack on the hero
				beastAttackHero(idOriginBoard,idDestinationBoard,dynamic_cast<iBeast*> (playedCard),originPosition,destinationPosition);
			}

		} 
		else if (	idOriginBoard==PLAYER0_HAND&&idDestinationBoard==PLAYER0_BOARD||
					idOriginBoard==PLAYER1_HAND&&idDestinationBoard==PLAYER1_BOARD)
		{//if the Beast is being played
			playBeast(idOriginBoard,idDestinationBoard,dynamic_cast<iBeast*> (playedCard),originPosition,destinationPosition);
		}
	}
	else if (playedCard->getType()=="spell")
	{
		if (idOriginBoard==PLAYER0_HAND||idOriginBoard==PLAYER1_HAND)
		{//if the spell is played from the hand
			playSpell(idOriginBoard,idDestinationBoard, playedCard,originPosition,destinationPosition);
		}
	}
}

void Engine::GameEngine::endTurn()
{
//-------- this will be a generic function later
	/*
	//event and effect.proc() not done yet . cannot do this .
	std::for_each(listCardsProccedWhenTurnEnds->begin(), listCardsProccedWhenTurnEnds->end(), [] (iCard* itCard) { 
		std::for_each(itCard->capaList->begin(), itCard->capaList->end(), [] (iCapacity* itCapa) { 
			
			if(itCapa->getEvent()->timeMask.when_turn_ends==1){

				itCapa->getEffect()->proc();
			} 
		}); 
	});
//--------
	turn++; 
	*/
	beginTurn();
}

void Engine::GameEngine::playBeast(	int idOriginBoard,int idDestinationBoard,iBeast* playedCard,
									int originPosition, int destinationPosition)
{

	//verify if the owner has enough shards
	iHero* currentHero=dynamic_cast<iHero*> ((idOriginBoard==PLAYER0_HAND) ? boards[PLAYER0_HERO]->getCardX(0): boards[PLAYER1_HERO]->getCardX(0));
	int currentHeroShards= currentHero->getTotal("shards");														
	if (!currentHeroShards>=playedCard->getCost())
	{
		throw std::logic_error( "you don't have enough shards to play that" ); 
	}
	else
	{
		//verify if the board isn't full
		if(boards[idDestinationBoard]->isFull())
		{
			throw std::logic_error( "destination board is full" ); 
		}	
		//move the card
		void* playedCardIHMCurrent = (getCurrentPlayerCards())[(playedCard)];
		void* playedCardIHMNonCurrent = (getNonCurrentPlayerCards())[(playedCard)];
		currentHero->decreaseShards(playedCard->getCost());
		setShardsRequest(getCurrentPlayer(), getCurrentPlayerNumber(), currentHeroShards);
		setShardsRequest(getNonCurrentPlayer(), getCurrentPlayerNumber(), currentHeroShards);
		boards[idOriginBoard]->deleteCardX(originPosition);
		removeCardRequest(getCurrentPlayer(), idOriginBoard, originPosition);
		removeCardRequest(getNonCurrentPlayer(), getOppositeBoard(idOriginBoard), originPosition);
		boards[idDestinationBoard]->addCardX(playedCard,destinationPosition);
		addCardRequest(getCurrentPlayer(),playedCardIHMCurrent, idDestinationBoard, destinationPosition);
		addCardRequest(getNonCurrentPlayer(),playedCardIHMNonCurrent, getOppositeBoard(idDestinationBoard), destinationPosition);
		//returns the state to the IHM
	}
}

void Engine::GameEngine::playSpell(	int idOriginBoard,int idDestinationBoard,iCard* playedCard,
									int originPosition, int destinationPosition)
{
	//verify if the owner has enough shards
	iHero* currentHero=dynamic_cast<iHero*> ((idOriginBoard==PLAYER0_HAND) ? boards[PLAYER0_HERO]->getCardX(0): boards[PLAYER1_HERO]->getCardX(0));
	int currentHeroShards= currentHero->getTotal("shards");															
	if (!currentHeroShards>=playedCard->getCost())
	{
		throw std::logic_error( "you don't have enough shards to play that" ); 
	}
	else
	{
		//move the card
		void* playedCardIHMCurrent = (getCurrentPlayerCards())[(playedCard)];
		void* playedCardIHMNonCurrent = (getNonCurrentPlayerCards())[(playedCard)];
		currentHero->decreaseShards(playedCard->getCost());
		setShardsRequest(getCurrentPlayer(), getCurrentPlayerNumber(), currentHeroShards);
		setShardsRequest(getNonCurrentPlayer(), getCurrentPlayerNumber(), currentHeroShards);
		boards[idOriginBoard]->deleteCardX(originPosition);
		removeCardRequest(getCurrentPlayer(), idOriginBoard, originPosition);
		removeCardRequest(getNonCurrentPlayer(), getOppositeBoard(idOriginBoard), originPosition);
		
		iCreature* target=dynamic_cast<iCreature*> (boards[idDestinationBoard]->getCardX(destinationPosition));
		void* targetIHMCurrent = (getCurrentPlayerCards())[(target)];
		void* targetIHMNonCurrent = (getNonCurrentPlayerCards())[(target)];
		target->takeDamage(playedCard->getTotal("damage"));
		int newHP = target->getTotal("hp");
		setDefenseRequest ( getCurrentPlayer(), targetIHMCurrent, newHP );
		setDefenseRequest ( getNonCurrentPlayer(), targetIHMNonCurrent,newHP);
		if (!target->isAlive())
		{
			//kills the target
			if(idDestinationBoard == PLAYER1_BOARD)
			{//if the target is in the board of player 1
				boards[idDestinationBoard]->deleteCardX(destinationPosition);
				removeCardRequest(getCurrentPlayer(), idDestinationBoard, destinationPosition);
				removeCardRequest(getNonCurrentPlayer(), getOppositeBoard(idDestinationBoard), destinationPosition);
				boards[PLAYER1_CIMETERY]->addCardX(target,0);
				addCardRequest(getCurrentPlayer(),targetIHMCurrent, PLAYER1_CIMETERY, 0);
				addCardRequest(getNonCurrentPlayer(),targetIHMNonCurrent, getOppositeBoard(PLAYER1_CIMETERY), 0);

			}
			else if (idDestinationBoard == PLAYER0_BOARD)
			{
				boards[idDestinationBoard]->deleteCardX(destinationPosition);
				removeCardRequest(getCurrentPlayer(), idDestinationBoard, destinationPosition);
				removeCardRequest(getNonCurrentPlayer(), getOppositeBoard(idDestinationBoard), destinationPosition);
				boards[PLAYER0_CIMETERY]->addCardX(target,0);
				addCardRequest(getCurrentPlayer(),targetIHMCurrent, PLAYER0_CIMETERY, 0);
				addCardRequest(getNonCurrentPlayer(),targetIHMNonCurrent, getOppositeBoard(PLAYER0_CIMETERY), 0);
			}
			else if (idDestinationBoard == PLAYER0_HERO)
			{
				throw std::logic_error( "Player 1 wins !" ); 
			}
			else if (idDestinationBoard == PLAYER1_HERO)
			{
				throw std::logic_error( "Player 0 wins !" ); 
			}
		}
		//returns the state to the IHM
	}
}

void Engine::GameEngine::beastAttackBeast(	int idOriginBoard,int idDestinationBoard,iBeast* playedCard,
											int originPosition, int destinationPosition)
{
	//verify if the creacture can attack .
	if (!playedCard->canAttack()) 
	{	
		throw std::logic_error( "you cann't attack with that right now" ); 
	}
	else
	{
		//verify if the target is valid
		//apply damage to both Creatures
		playedCard->increaseAttackCount();
		iBeast* target=dynamic_cast<iBeast*> (boards[idDestinationBoard]->getCardX(destinationPosition));
		void* playedCardIHMCurrent = (getCurrentPlayerCards())[(playedCard)];
		void* playedCardIHMNonCurrent = (getNonCurrentPlayerCards())[(playedCard)];
		void* targetIHMCurrent = (getCurrentPlayerCards())[(target)];
		void* targetIHMNonCurrent = (getNonCurrentPlayerCards())[(target)];
		target->takeDamage(playedCard->getTotal("attack"));
		playedCard->takeDamage(target->getTotal("attack"));
		int newHPTarget= target->getTotal("hp");
		int newHPPlayedCard= playedCard->getTotal("hp");
		setDefenseRequest ( getCurrentPlayer(), playedCardIHMCurrent, newHPPlayedCard);
		setDefenseRequest ( getNonCurrentPlayer(), playedCardIHMNonCurrent,newHPPlayedCard );
		setDefenseRequest ( getCurrentPlayer(), targetIHMCurrent,newHPTarget );
		setDefenseRequest ( getNonCurrentPlayer(), targetIHMNonCurrent,newHPTarget );
		//check for validity of the state (kill creatures etc)
		if (!target->isAlive())
		{
			//kills the target
			if(idDestinationBoard == PLAYER1_BOARD)// MODIFY THIS AND ALL THE LINES LIKE THAT
			{//if player0 is playing, target belongs to player 1
				boards[idDestinationBoard]->deleteCardX(destinationPosition);
				removeCardRequest(getCurrentPlayer(), idDestinationBoard, destinationPosition);
				removeCardRequest(getNonCurrentPlayer(), getOppositeBoard(idDestinationBoard), destinationPosition);
				boards[PLAYER1_CIMETERY]->addCardX(target,0);
				addCardRequest(getCurrentPlayer(),targetIHMCurrent, PLAYER1_CIMETERY, 0);
				addCardRequest(getNonCurrentPlayer(),targetIHMNonCurrent, getOppositeBoard(PLAYER1_CIMETERY), 0);
			}
			else
			{
				boards[idDestinationBoard]->deleteCardX(destinationPosition);
				removeCardRequest(getCurrentPlayer(), idDestinationBoard, destinationPosition);
				removeCardRequest(getNonCurrentPlayer(), getOppositeBoard(idDestinationBoard), destinationPosition);
				boards[PLAYER0_CIMETERY]->addCardX(target,0);
				addCardRequest(getCurrentPlayer(),targetIHMCurrent, PLAYER0_CIMETERY, 0);
				addCardRequest(getNonCurrentPlayer(),targetIHMNonCurrent, getOppositeBoard(PLAYER0_CIMETERY), 0);
			}
		}
		if (!playedCard->isAlive())
		{
			//kills the attacker
			if(idDestinationBoard == PLAYER1_BOARD)
			{
				boards[idOriginBoard]->deleteCardX(originPosition);
				removeCardRequest(getCurrentPlayer(), idOriginBoard, originPosition);
				removeCardRequest(getNonCurrentPlayer(), getOppositeBoard(idOriginBoard), originPosition);
				boards[PLAYER0_CIMETERY]->addCardX(playedCard,0);
				addCardRequest(getCurrentPlayer(),targetIHMCurrent, PLAYER0_CIMETERY, 0);
				addCardRequest(getNonCurrentPlayer(),targetIHMNonCurrent, getOppositeBoard(PLAYER0_CIMETERY), 0);
			}
			else
			{
				boards[idOriginBoard]->deleteCardX(originPosition);
				removeCardRequest(getCurrentPlayer(), idOriginBoard, originPosition);
				removeCardRequest(getNonCurrentPlayer(), getOppositeBoard(idOriginBoard), originPosition);
				boards[PLAYER1_CIMETERY]->addCardX(playedCard,0);
				addCardRequest(getCurrentPlayer(),targetIHMCurrent, PLAYER1_CIMETERY, 0);
				addCardRequest(getNonCurrentPlayer(),targetIHMNonCurrent, getOppositeBoard(PLAYER1_CIMETERY), 0);
			}
		}
		//returns the state to the IHM
	}
}

void Engine::GameEngine::beastAttackHero(	int idOriginBoard,int idDestinationBoard,iBeast* playedCard,
											int originPosition, int destinationPosition)
{
	//verify if the creacture can attack .
	if (!playedCard->canAttack()) 
	{	
		throw std::logic_error( "you cann't attack with that right now" ); 
	}
	else
	{		
		//verify if the target is valid
		//apply damage to both Creatures
		playedCard->increaseAttackCount();
		iHero* target=dynamic_cast<iHero*> (boards[idDestinationBoard]->getCardX(destinationPosition));
		void* playedCardIHMCurrent = (getCurrentPlayerCards())[(playedCard)];
		void* playedCardIHMNonCurrent = (getNonCurrentPlayerCards())[(playedCard)];
		void* targetIHMCurrent = (getCurrentPlayerCards())[(target)];
		void* targetIHMNonCurrent = (getNonCurrentPlayerCards())[(target)];
		target->takeDamage(playedCard->getTotal("attack"));
		playedCard->takeDamage(target->getTotal("attack"));
		int newHP= target->getTotal("hp");
		setDefenseRequest ( getCurrentPlayer(), playedCardIHMCurrent, newHP);
		setDefenseRequest ( getNonCurrentPlayer(), playedCardIHMNonCurrent,newHP );
		setDefenseRequest ( getCurrentPlayer(), targetIHMCurrent,newHP );
		setDefenseRequest ( getNonCurrentPlayer(), targetIHMNonCurrent,newHP );

		//check for validity of the state (kill creatures etc)
		if (!target->isAlive())
		{
			//kills the target
			if(idDestinationBoard == PLAYER1_HERO)
			{//if player1 is playing, target belongs to player 2
				throw std::logic_error( "Player 0 wins !" ); 
			}
			else
			{
				throw std::logic_error( "Player 1 wins !" ); 
			}
		}
		if (!playedCard->isAlive())
		{
			if(idDestinationBoard == PLAYER0_BOARD)
			{
				boards[idOriginBoard]->deleteCardX(originPosition);
				removeCardRequest(getCurrentPlayer(), idOriginBoard, originPosition);
				removeCardRequest(getNonCurrentPlayer(), getOppositeBoard(idOriginBoard), originPosition);
				boards[PLAYER0_CIMETERY]->addCardX(playedCard,0);
				addCardRequest(getCurrentPlayer(),playedCardIHMCurrent, PLAYER0_CIMETERY, 0);
				addCardRequest(getNonCurrentPlayer(),playedCardIHMNonCurrent, getOppositeBoard(PLAYER0_CIMETERY), 0);
			}
			else
			{
				boards[idOriginBoard]->deleteCardX(originPosition);
				removeCardRequest(getCurrentPlayer(), idOriginBoard, originPosition);
				removeCardRequest(getNonCurrentPlayer(), getOppositeBoard(idOriginBoard), originPosition);
				boards[PLAYER1_CIMETERY]->addCardX(playedCard,0);
				addCardRequest(getCurrentPlayer(),playedCardIHMCurrent, PLAYER1_CIMETERY, 0);
				addCardRequest(getNonCurrentPlayer(),playedCardIHMNonCurrent, getOppositeBoard(PLAYER1_CIMETERY), 0);
			}
		}
		//returns the state to the IHM
	}	
}

void Engine::GameEngine::playerDraws(int playerNumber,int cardsDrawn){//this should work for v1 since there is no effect that makes a player draw .

	if(!(playerNumber%2))
	{//if it is the Player1
		for (int i=0;i<cardsDrawn;i++)
		{
			//takes the first card of the deck
			iCard* drawnCard = boards[PLAYER0_DECK]->takeCardX(0);
			void* drawnCardIHMCurrent = (getCurrentPlayerCards())[(drawnCard)];
			void* drawnCardIHMNonCurrent = (getNonCurrentPlayerCards())[(drawnCard)];
			removeCardRequest(getCurrentPlayer(), PLAYER0_DECK, 0);
			removeCardRequest(getNonCurrentPlayer(), getOppositeBoard(PLAYER0_DECK), 0);
			if (!boards[PLAYER0_HAND]->isFull())
			{//if the hand isn't full
				//adds the card the the hand
				boards[PLAYER0_HAND]->addCardX(drawnCard, 0);
				addCardRequest(getCurrentPlayer(),drawnCardIHMCurrent, PLAYER0_HAND, 0);
				addCardRequest(getNonCurrentPlayer(),drawnCardIHMNonCurrent, getOppositeBoard(PLAYER0_HAND), 0);
			}
		}	
	}
	else
	{
		for (int i=0;i<cardsDrawn;i++)
		{
			//takes the first card of the deck
			iCard* drawnCard = boards[PLAYER1_DECK]->takeCardX(0);
			void* drawnCardIHMCurrent = (getCurrentPlayerCards())[(drawnCard)];
			void* drawnCardIHMNonCurrent = (getNonCurrentPlayerCards())[(drawnCard)];
			removeCardRequest(getCurrentPlayer(), PLAYER1_DECK, 0);
			removeCardRequest(getNonCurrentPlayer(), getOppositeBoard(PLAYER1_DECK), 0);
			if (!boards[PLAYER1_HAND]->isFull())
			{//if the hand isn't full
				//adds the card the the hand
				boards[PLAYER1_HAND]->addCardX(drawnCard, 0);
				addCardRequest(getCurrentPlayer(),drawnCardIHMCurrent, PLAYER1_HAND, 0);
				addCardRequest(getNonCurrentPlayer(),drawnCardIHMNonCurrent, getOppositeBoard(PLAYER1_HAND), 0);
			}
		}
	}
}

void Engine::GameEngine::beginTurn()
{
	//procs the effect of the beginning of the turn .

	//makes the current player draw
	if(!(turn%2))
	{//if it is player 0's turn
		//increase the max shards of player 0
		iHero* currentHero = dynamic_cast<iHero*> (boards[PLAYER0_HERO]->getCardX(0));
		currentHero->setMaxShards(
			currentHero->getTotal("maxShards")+1);
		//transmit to IHM
		setMaxShardsRequest(getCurrentPlayer(), getCurrentPlayerNumber(),
			currentHero->getTotal("maxShards"));
		setMaxShardsRequest(getNonCurrentPlayer(), getCurrentPlayerNumber(), 
			currentHero->getTotal("maxShards"));
		//reset the shards of the player
		currentHero->setShards(
			currentHero->getTotal("maxShards"));
		//transmit to IHM
		setShardsRequest(getCurrentPlayer(), getCurrentPlayerNumber(),
			currentHero->getTotal("shards"));
		setShardsRequest(getNonCurrentPlayer(), getCurrentPlayerNumber(), 
			currentHero->getTotal("shards"));
		//reset the attack count of the board
		std::for_each(boards[PLAYER0_BOARD]->begin(), boards[PLAYER0_BOARD]->end(), [] (iCard* itCard) {
			dynamic_cast<iBeast*> (itCard)->resetAttackCount();	
		});
		playerDraws(getCurrentPlayerNumber(),1);
	}
	else
	{//if it is player 1's turn
		iHero* currentHero = dynamic_cast<iHero*> (boards[PLAYER1_HERO]->getCardX(0));
		//increase the max shards of player 
		currentHero->setMaxShards(
			currentHero->getTotal("maxShards")+1);
		//transmit to IHM
		setMaxShardsRequest(getCurrentPlayer(), getCurrentPlayerNumber(),
			currentHero->getTotal("maxShards"));
		setMaxShardsRequest(getNonCurrentPlayer(), getCurrentPlayerNumber(), 
			currentHero->getTotal("maxShards"));
		//reset the shards of the player
		currentHero->setShards(
			currentHero->getTotal("maxShards"));
		//transmit to IHM
		setShardsRequest(getCurrentPlayer(), getCurrentPlayerNumber(),
			currentHero->getTotal("shards"));
		setShardsRequest(getNonCurrentPlayer(), getCurrentPlayerNumber(), 
			currentHero->getTotal("shards"));
		//reset the attack count of the board
		std::for_each(boards[PLAYER1_BOARD]->begin(), boards[PLAYER1_BOARD]->end(), [] (iCard* itCard) {
			dynamic_cast<iBeast*> (itCard)->resetAttackCount();	
		});
		playerDraws(getCurrentPlayerNumber(),1);
	}
}

void Engine::GameEngine::shuffleDeck(int playerNumber){//this doesn't work at all . do it over .
	if(!(playerNumber%2))
	{//if it is the Player1
  		/*srand ( unsigned ( time(0) ) );//initialize random
		std::vector<iCard*> v{ std::begin(matchBoard->getIHMObject(PLAYER0_DECK)), std::end(matchBoard->getIHMObject(PLAYER0_DECK)) };//copies the deck in a vector for random access
		std::random_shuffle ( v.begin(), v.end() );// shuffles with algorithm.shuffle
		std::copy(v.begin(), v(), std::back_inserter( matchBoard->getIHMObject(PLAYER0_DECK)));//copies the vector back to a list*/
	}
	else
	{
  		/*srand ( unsigned ( std::time(0) ) );
		std::vector<iCard*> v{ begin(matchBoard->getIHMObject(PLAYER1_DECK)), end(matchBoard->getIHMObject(PLAYER1_DECK)) };
		std::random_shuffle ( v.begin(), v.end() );
		std::copy(v.begin(), v(), back_inserter( matchBoard->getIHMObject(PLAYER1_DECK)));	*/	
	}
}


void Engine::GameEngine::handleEvent ( Polycode::Event* event ) {
  using namespace Polycode;
  Server::handleEvent(event);
    if(event->getDispatcher()==this){
      ServerEvent *e = (ServerEvent*)event;
      switch (e->getEventCode()){
      case ServerEvent::EVENT_CLIENT_DATA:
         switch(e->dataType){
	   case Network::PLAYON: {
	     Network::PlayOnStructType* playon = (Network::PlayOnStructType*) e->data;
	     if(getCurrentPlayer()->clientID==e->client->clientID)
	       if(e->client->clientID==player0->clientID)
		useCard(playon->boardOrigin,playon->cardOrigin,playon->boardDestination,playon->cardDestination);
	       else
		useCard(getOppositeBoard(playon->boardOrigin),getOppositeBoard(playon->cardOrigin),getOppositeBoard(playon->boardDestination),getOppositeBoard(playon->cardDestination));
	     }
	     break;
	   case Network::ENDTURN:
	     if(getCurrentPlayer()->clientID==e->client->clientID)
	      endTurn();
	     break;
	   case Network::CREATE: {
	     Network::CreateCardAnswerStructType* answer = (Network::CreateCardAnswerStructType*) e->data;
	     if(e->client->clientID==player0->clientID){
	       matchCardPlayer0.add((iCard*)answer->serverRef,(void*)answer->clientRef);
	     }
	     else if(e->client->clientID==player1->clientID) {
	       matchCardPlayer1.add((iCard*)answer->serverRef,(void*)answer->clientRef);
	     }}
	     break;
	 }
         break;
      case ServerEvent::EVENT_CLIENT_CONNECTED:
	std::cout << "Here Comes the client" << std::endl;
	if(player0==nullptr){
	  player0=e->client;
	}
	else if(player1==nullptr){
	  player1=e->client;
	  initDecks();
	} else {
	  DisconnectClient(e->client);
	}
	break;
      case ServerEvent::EVENT_CLIENT_DISCONNECTED:
	
	break;     
      }
    }
}

Polycode::ServerClient* Engine::GameEngine::getCurrentPlayer() {
  if(turn%2)
    return player0;
  else
    return player1;
}

Polycode::ServerClient* Engine::GameEngine::getNonCurrentPlayer() {
  if(turn%2)
    return player1;
  else
    return player0;
}

Match<iCard,void>& Engine::GameEngine::getCurrentPlayerCards() {
	if(turn%2)
    return matchCardPlayer0;
  else
    return matchCardPlayer1;
}

Match<iCard,void>& Engine::GameEngine::getNonCurrentPlayerCards() {
	if(turn%2)
    return matchCardPlayer1;
  else
    return matchCardPlayer0;
}

int Engine::GameEngine::getCurrentPlayerNumber(){
	if(turn%2)
    return 0;
  else
    return 1;
}

int Engine::GameEngine::getOppositeBoard(int boardNumber){

	return ((boardNumber+6)%14)+1;
}

void Engine::GameEngine::initDecks () {

	int attack ;
	int defense;
	int cost ;
	std::string title ;
	std::string description ;
	int imageID ;
	std::for_each(deckPlayer0->begin(), deckPlayer0->end(), [&] (iCard* itCard) mutable {
		//attack,defense,cost,title,description,imageID,matchCardPlayer0,matchCardPlayer1,boards,player0,player1
		void* itCardIHM;
		matchCardPlayer0.add(itCard,itCardIHM);
		matchCardPlayer1.add(itCard,itCardIHM);
		if(itCard->getType()=="beast")
		{		
			attack = itCard->getTotal("attack");
			defense = itCard->getTotal("hp");
		}
		else if (itCard->getType()=="spell")
		{
			attack = itCard->getTotal("damage");
			defense = -1;
		}
		cost = itCard->getCost();
		title = itCard->getName();
		description = itCard->getType();
		imageID = 0; //pending . WIP .
		CreateCardRequest (player0, itCardIHM, attack,defense,cost,  title,  description,  imageID);
		CreateCardRequest (player1, itCardIHM, attack,defense,cost,  title,  description,  imageID);
		boards[PLAYER0_DECK]->addCardX(itCard,0);
		addCardRequest ( player0, itCardIHM, PLAYER0_DECK, 0 );
		addCardRequest ( player1, itCardIHM, getOppositeBoard(PLAYER0_DECK), 0 );
	});
	std::for_each(deckPlayer1->begin(), deckPlayer1->end(), [&] (iCard* itCard) mutable {
		
		void* itCardIHM;
		matchCardPlayer0.add(itCard,itCardIHM);
		matchCardPlayer1.add(itCard,itCardIHM);
		if(itCard->getType()=="beast")
		{		
			attack = itCard->getTotal("attack");
			defense = itCard->getTotal("hp");
		}
		else if (itCard->getType()=="spell")
		{
			attack = itCard->getTotal("damage");
			defense = -1;
		}
		cost = itCard->getCost();
		title = itCard->getName();
		description = itCard->getType();
		imageID = 0; //pending . WIP .
		CreateCardRequest (player0, itCardIHM, attack,defense,cost,  title,  description,  imageID);
		CreateCardRequest (player1, itCardIHM, attack,defense,cost,  title,  description,  imageID);
		boards[PLAYER1_DECK]->addCardX(itCard,0);
		addCardRequest ( player0, itCardIHM, PLAYER1_DECK, 0 );
		addCardRequest ( player1, itCardIHM, getOppositeBoard(PLAYER1_DECK), 0 );
	});
  	
  	void* heroPlayer0IHM;
  	matchCardPlayer0.add(heroPlayer0,heroPlayer0IHM);
	matchCardPlayer1.add(heroPlayer0,heroPlayer0IHM);
	attack = heroPlayer0->getTotal("attack");
	defense = heroPlayer0->getTotal("hp");
	cost = heroPlayer0->getCost();
	title = heroPlayer0->getName();
	description = heroPlayer0->getType();
	imageID = 0; //pending . WIP .
	CreateCardRequest (player0, heroPlayer0IHM, attack,defense,cost,  title,  description,  imageID);
	CreateCardRequest (player1, heroPlayer0IHM, attack,defense,cost,  title,  description,  imageID);
	boards[PLAYER0_HERO]->addCardX(heroPlayer0,0);
	addCardRequest ( player0, heroPlayer0IHM, PLAYER0_HERO, 0 );
	addCardRequest ( player1, heroPlayer0IHM, getOppositeBoard(PLAYER0_HERO), 0 );

    void* heroPlayer1IHM;
	matchCardPlayer0.add(heroPlayer1,heroPlayer1IHM);
	matchCardPlayer1.add(heroPlayer1,heroPlayer1IHM);
	attack = heroPlayer1->getTotal("attack");
	defense = heroPlayer1->getTotal("hp");
	cost = heroPlayer1->getCost();
	title = heroPlayer1->getName();
	description = heroPlayer1->getType();
	imageID = 0; //pending . WIP .
	CreateCardRequest (player0, heroPlayer1IHM, attack,defense,cost,  title,  description,  imageID);
	CreateCardRequest (player1, heroPlayer1IHM, attack,defense,cost,  title,  description,  imageID);
	boards[PLAYER1_HERO]->addCardX(heroPlayer1,0);
	addCardRequest ( player0, heroPlayer1IHM, PLAYER1_HERO, 0 );
	addCardRequest ( player1, heroPlayer1IHM, getOppositeBoard(PLAYER1_HERO), 0 );

  	playerDraws(0,3);
  	playerDraws(1,4);
  	beginTurn();

}

void Engine::GameEngine::addCardRequest ( Polycode::ServerClient* client, void* card, int board, int position ) {
  Network::AddCardStructType request = {card,board,position};
  sendData(client->connection->address, (char*) &request, sizeof(Network::AddCardStructType), Network::ADDCARD);
}
void Engine::GameEngine::moveCardRequest ( Polycode::ServerClient* client, int originBoard, int originPosition, int destinationBoard, int destinationPosition ) {
  Network::MoveCardStructType request = {originBoard,originPosition,destinationBoard,destinationPosition};
  sendData(client->connection->address, (char*) &request, sizeof(Network::MoveCardStructType), Network::MOVECARD);
}

void Engine::GameEngine::removeCardRequest ( Polycode::ServerClient* client, int board, int position ) {
  Network::RemoveCardStructType request = {board,position};
  sendData(client->connection->address, (char*) &request, sizeof(Network::RemoveCardStructType),Network::REMOVECARD);
}

void Engine::GameEngine::setDescriptionRequest ( Polycode::ServerClient* client, void* card, std::string Description ) {
  Description = Description.substr(0,254);
  Network::SetDescriptionStructType request = { card};
  strcpy(request.description,Description.c_str());
  sendData(client->connection->address, (char*) &request, sizeof(Network::SetDescriptionStructType),Network::SETDESCRIP);
}

void Engine::GameEngine::setTitleRequest ( Polycode::ServerClient* client, void* card, std::string title ) {
  Network::SetTitleStructType request = { card};
  title=title.substr(0,19);
  strcpy(request.title, title.c_str());
  sendData(client->connection->address, (char*) &request, sizeof(Network::SetTitleStructType),Network::SETTITLE);
}

void Engine::GameEngine::setMaxShardsRequest ( Polycode::ServerClient* client, int playerId, int shards ) {
  Network::SetShardStructType request = { playerId, shards};
  sendData(client->connection->address, (char*) &request, sizeof(Network::SetShardStructType), Network::SETMAXSHARD);
}

void Engine::GameEngine::setShardsRequest ( Polycode::ServerClient* client, int playerId, int shards ) {
  Network::SetShardStructType request = { playerId, shards};
  sendData(client->connection->address, (char*) &request, sizeof(Network::SetShardStructType), Network::SETSHARD);
}

void Engine::GameEngine::setAttackRequest ( Polycode::ServerClient* client, void* card, int newVal ) {
  Network::SetNumericalAttributeStructType request = { card, newVal };
  sendData(client->connection->address, (char*) &request, sizeof(Network::SetNumericalAttributeStructType),Network::SETATTACK);
}

void Engine::GameEngine::setCostRequest ( Polycode::ServerClient* client, void* card, int newVal ) {
  Network::SetNumericalAttributeStructType request = { card, newVal };
  sendData(client->connection->address, (char*) &request, sizeof(Network::SetNumericalAttributeStructType),Network::SETCOST);
}

void Engine::GameEngine::setDefenseRequest ( Polycode::ServerClient* client, void* card, int newVal ) {
  Network::SetNumericalAttributeStructType request = { card, newVal };
  sendData(client->connection->address, (char*) &request, sizeof(Network::SetNumericalAttributeStructType),Network::SETDEFENSE);
}

void Engine::GameEngine::setImageIDRequest ( Polycode::ServerClient* client, void* card, int newVal ) {
  Network::SetNumericalAttributeStructType request = { card, newVal };
  sendData(client->connection->address, (char*) &request, sizeof(Network::SetNumericalAttributeStructType),Network::SETIMAGEID);
}

void Engine::GameEngine::CreateCardRequest (Polycode::ServerClient* client, void* card, int attack,
    int defense, int cost, std::string title, std::string description, int imageID){
	description=description.substr(0,254);
	title=title.substr(0,19);
	Network::CreateCardStructType request = {card,attack,defense,cost};
	strcpy(request.description,description.c_str());
	strcpy(request.title,title.c_str());
	request.imageID=imageID;
	sendData(client->connection->address, (char*) &request, sizeof(Network::CreateCardStructType),Network::CREATE);
}
  
void Engine::GameEngine::SimulationEndRequest ( Polycode::ServerClient* client ) {
  sendData(client->connection->address, "0", sizeof("0"), Network::SIMULATIONEND);
}
