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

#include "gameengine.h"

Engine::GameEngine::GameEngine() 
{
	boards = new std::list<Board*>();
	players = new std::list<Player*>();

    //corresCardId = NULL;
    //corresBoardId = NULL;  
    turn = 0;
}

Engine::GameEngine::GameEngine ( const GameEngine& other ) 
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

std::list<GameSimulator*> Engine::GameEngine::getSimulator ( void ) 
{
 	std::list<GameSimulator*> gameSimulators;
	for(size_t i = 0; i < boards[OWNER_HAND].getSize(); i++)
	{
	    if(boards[OWNER_HAND].getCardX(i).getCost() < /*FIXME TODO Get mana disponible*/)
		{
	        GameSimulator *gameSimulator = new gameSimulator();
	        gameSimulator.setListCard();
	        gameSimulators.push_back(gameSimulator);
	    }
	}
}

void Engine::GameEngine::useCard(	int originIHMBoard, int originPosition, //-------------- DOUBT HERE
									int destinationIHMBoard, int destinationPosition)
{  	
	int idOriginBoard=originIHMBoard;
	int idDestinationBoard=destinationIHMBoard;

	if(idOriginBoard/7!=turn%2)
	{//if the actions comes from a board that doesn't belong to the active player
		throw std::logic_error( "you cann't use that board right now" ); 
	}

  	Card* playedCard = boards[idOriginBoard]->getCardX(originPosition);
  	Player* activePlayer = (turn%2) ? (players->end()) : (players->begin()); 
	/* Decide on what is the action performed
	Timy-whymy-bubbly stuff . Abandon hope all ye who enter here . 
	*/
	if (playedCard->getType()=="beast")
	{
		if(	idOriginBoard==PLAYER1_BOARD||//this test is obsolete for now but i don't know how it's gonna be later 
			idOriginBoard==PLAYER2_BOARD)
		{//if it is an attack 
			if(	idOriginBoard==PLAYER1_BOARD&&idDestinationBoard==PLAYER2_BOARD||
				idOriginBoard==PLAYER2_BOARD&&idDestinationBoard==PLAYER1_BOARD)
			{//if it is an attack on a beast
				beastAttackBeast(idOriginBoard,idDestinationBoard,(iBeast*) playedCard,originPosition,destinationPosition);
			}
			if(	idOriginBoard==PLAYER1_BOARD&&idDestinationBoard==PLAYER2_HERO||
				idOriginBoard==PLAYER2_BOARD&&idDestinationBoard==PLAYER1_HERO)
			{//if it is an attack on the hero
				beastAttackHero(idOriginBoard,idDestinationBoard,(iBeast*) playedCard,originPosition,destinationPosition);
			}

		} 
		else if (	idOriginBoard==PLAYER1_HAND&&idDestinationBoard==PLAYER1_BOARD||
					idOriginBoard==PLAYER2_HAND&&idDestinationBoard==PLAYER2_BOARD)
		{//if the Beast is being played
			playBeast(idOriginBoard,idDestinationBoard,(iBeast*) playedCard,originPosition,destinationPosition);
		}
	}
	else if (playedCard->getType()=="spell")
	{
		if (idOriginBoard==PLAYER1_HAND||idOriginBoard==PLAYER2_HAND)
		{//if the spell is played from the hand
			playSpell(idOriginBoard,idDestinationBoard, playedCard,originPosition,destinationPosition);
		}
	}
}

void Engine::GameEngine::endTurn()
{
//-------- this will be a generic function later
	foreach(std::list<Card*>, listCardsProccedWhenTurnEnds, itCard){
		foreach(std::list<Capacity*>, itList->capaList, itCapa){
			if(itCapa->getEvent()->timeMask.when_turn_ends==1){
				itCapa->getEffect()->proc();
			}
		}
	}
//--------
	turn++; 
	beginTurn();
}

void Engine::GameEngine::playBeast(	int idOriginBoard,int idDestinationBoard,iBeast* playedCard,
									int originPosition, int destinationPosition){

	//verify if the owner has enough shards
	Hero* currentHero=(Hero*) (idOriginBoard==PLAYER1_HAND) ? boards[PLAYER1_HERO]->getCardX(0)
															: boards[PLAYER2_HERO]->getCardX(0);
	if (!currentHero->getShards()>=playedCard->getCost())
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
		int playerNumber = (idOriginBoard==PLAYER1_HAND) ? 1 : 2;
		IHM::iCard* playedCardIHM = (matchBoard->getIHMObject(idOriginBoard))[originPosition]; //-------------- DOUBT HERE
		currentHero->decreaseShards(playedCard->getCost);
		IHM::setShards(playerNumber,currentHero->getShards());
		boards[idOriginBoard]->deleteCardX(originPosition);
		matchBoard->getIHMObject(idOriginBoard)->deleteCard(originPosition);
		boards[idDestinationBoard]->addCardX(playedCard,destinationPosition);
		matchBoard->getIHMObject(idDestinationBoard)->addCard(playedCardIHM,destinationPosition);
		//returns the state to the IHM
	}
}

void Engine::GameEngine::playSpell(	int idOriginBoard,int idDestinationBoard,Card* playedCard,
									int originPosition, int destinationPosition)
{
	//verify if the owner has enough shards
	Hero* currentHero=(Hero*) (idOriginBoard==PLAYER1_HAND) ? boards[PLAYER1_HERO]->getCardX(0)
															: boards[PLAYER2_HERO]->getCardX(0);
	if (!currentHero->getShards()>=playedCard->getCost())
	{
		throw std::logic_error( "you don't have enough shards to play that" ); 
	}
	else
	{
		//move the card
		int playerNumber = (idOriginBoard==PLAYER1_HAND) ? 1 : 2;
		IHM::iCard* playedCardIHM = (matchBoard->getIHMObject(idOriginBoard))[originPosition]; //-------------- DOUBT HERE
		currentHero->decreaseShards(playedCard->getCost);
		IHM::setShards(playerNumber,currentHero->getShards());
		boards[idOriginBoard]->deleteCardX(originPosition);
		matchBoard->getIHMObject(idOriginBoard)->deleteCard(originPosition);
		
		Creature* target=(Creature*) boards[idDestinationBoard]->getCardX(destinationPosition);
		IHM::iCard* targetIHM = (matchBoard->getIHMObject(idDestinationBoard))[destinationPosition];
		target->takeDamage(playedCard->getTotal("damage"));
		targetIHM->setDefense(target->getTotal("hp"));
		if (!target.isAlive())
		{
			//kills the target
			if(idDestinationBoard == PLAYER2_BOARD)
			{//if the target is either in the board or hero of player 1
				boards[idDestinationBoard]->deleteCardX(destinationPosition);
				matchBoard->getIHMObject(idDestinationBoard)->deleteCard(destinationPosition);
				boards[PLAYER2_CIMETERY]->addCardX(target,0);
				matchBoard->getIHMObject(PLAYER2_CIMETERY)->addCard(targetIHM,0);
			}
			else if (idDestinationBoard == PLAYER1_BOARD)
			{
				boards[idDestinationBoard]->deleteCardX(destinationPosition);
				matchBoard->getIHMObject(idDestinationBoard)->deleteCard(destinationPosition);
				boards[PLAYER1_CIMETERY]->addCardX(target,0);
				matchBoard->getIHMObject(PLAYER1_CIMETERY)->addCard(targetIHM,0);
			}
			else if (idDestinationBoard == PLAYER1_HERO)
			{
				throw std::logic_error( "Player 2 wins !" ); 
			}
			else if (idDestinationBoard == PLAYER2_HERO)
			{
				throw std::logic_error( "Player 1 wins !" ); 
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
		iBeast* target=(iBeast*) boards[idDestinationBoard]->getCardX(destinationPosition);
		IHM::iCard* playedCardIHM = (matchBoard->getIHMObject(idOriginBoard))[originPosition];
		IHM::iCard* targetIHM = (matchBoard->getIHMObject(idDestinationBoard))[destinationPosition];
		target->takeDamage(playedCard->getTotal("attack"));
		playedCard->takeDamage(target->getTotal("attack"));
		playedCardIHM->setDefense(playedCard->getTotal("hp"));
		targetIHM->setDefense(target->getTotal("hp"));
		//check for validity of the state (kill creatures etc)
		if (!target.isAlive())
		{
			//kills the target
			if(!turn%2)
			{//if player1 is playing, target belongs to player 2
				boards[idDestinationBoard]->deleteCardX(destinationPosition);
				matchBoard->getIHMObject(idDestinationBoard)->deleteCard(destinationPosition);
				boards[PLAYER2_CIMETERY]->addCardX(target,0);
				matchBoard->getIHMObject(PLAYER2_CIMETERY)->addCard(targetIHM,0);
			}
			else
			{
				boards[idDestinationBoard]->deleteCardX(destinationPosition);
				matchBoard->getIHMObject(idDestinationBoard)->deleteCard(destinationPosition);
				boards[PLAYER1_CIMETERY]->addCardX(target,0);
				matchBoard->getIHMObject(PLAYER1_CIMETERY)->addCard(targetIHM,0);
			}
		}
		if (!playedCard.isAlive())
		{
			//kills the attacker
			if(!turn%2)
			{
				boards[idOriginBoard]->deleteCardX(originPosition);
				matchBoard->getIHMObject(idOriginBoard)->deleteCard(originPosition);
				boards[PLAYER1_CIMETERY]->addCardX(playedCard,0);
				matchBoard->getIHMObject(PLAYER1_CIMETERY)->addCard(playedCardIHM,0);
			}
			else
			{
				boards[idOriginBoard]->deleteCardX(originPosition);
				matchBoard->getIHMObject(idOriginBoard)->deleteCard(originPosition);
				boards[PLAYER2_CIMETERY]->addCardX(playedCard,0);
				matchBoard->getIHMObject(PLAYER2_CIMETERY)->addCard(playedCardIHM,0);
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
		Hero* target=(Hero*) boards[idDestinationBoard]->getCardX(destinationPosition);
		IHM::iCard* playedCardIHM = (matchBoard->getIHMObject(idOriginBoard))[originPosition];
		IHM::iCard* targetIHM = (matchBoard->getIHMObject(idDestinationBoard))[destinationPosition];
		target->takeDamage(playedCard->getTotal("attack"));
		playedCard->takeDamage(target->getTotal("attack"));
		playedCardIHM->setDefense(playedCard->getTotal("hp"));
		targetIHM->setDefense(target->getTotal("hp"));
		//check for validity of the state (kill creatures etc)
		if (!target.isAlive())
		{
			//kills the target
			if(!turn%2)
			{//if player1 is playing, target belongs to player 2
				throw std::logic_error( "Player 1 wins !" ); 
			}
			else
			{
				throw std::logic_error( "Player 2 wins !" ); 
			}
		}
		if (!playedCard.isAlive())
		{
			if(!turn%2)
			{
				boards[idOriginBoard]->deleteCardX(originPosition);
				matchBoard->getIHMObject(idOriginBoard)->deleteCard(originPosition);
				boards[PLAYER1_CIMETERY]->addCardX(playedCard,0);
				matchBoard->getIHMObject(PLAYER1_CIMETERY)->addCard(playedCardIHM,0);
			}
			else
			{
				boards[idOriginBoard]->deleteCardX(originPosition);
				matchBoard->getIHMObject(idOriginBoard)->deleteCard(originPosition);
				boards[PLAYER2_CIMETERY]->addCardX(playedCard,0);
				matchBoard->getIHMObject(PLAYER2_CIMETERY)->addCard(playedCardIHM,0);
			}
		}
		//returns the state to the IHM
	}	
}

void Engine::GameEngine::playerDraws(int playerNumber,int cardsDrawn){//this should work for v1 since there is no effect that makes a player draw .

	if(!(playerNumber%2))
	{//if it is the Player1
		for (int i=0;i<cardsDrawn)
		{
			//takes the first card of the deck
			Card* cardDrawn = boards[PLAYER1_DECK]->takeCardX(0);
			IHM::iCard* cardDrawnIHM = (matchBoard->getIHMObject(PLAYER1_DECK))[0];
			matchBoard->getIHMObject(PLAYER1_DECK)->deleteCard(0);
			if (!boards[PLAYER1_HAND]->isFull())
			{//if the hand isn't full
				//adds the card the the hand
				boards[PLAYER1_HAND]->addCardX(cardDrawn, 0);
				matchBoard->getIHMObject(PLAYER1_HAND)->addCard(cardDrawnIHM, 0);
			}
		}	
	}
	else
	{
		for (int i=0;i<cardsDrawn)
		{
			//takes the first card of the deck
			Card* cardDrawn = boards[PLAYER2_DECK]->takeCardX(0);
			IHM::iCard* cardDrawnIHM = (matchBoard->getIHMObject(PLAYER2_DECK))[0];
			matchBoard->getIHMObject(PLAYER2_DECK)->deleteCard(0);
			if (!boards[PLAYER2_HAND]->isFull())
			{//if the hand isn't full
				//adds the card the the hand
				boards[PLAYER2_HAND]->addCardX(cardDrawn, 0);
				matchBoard->getIHMObject(PLAYER2_HAND)->addCard(cardDrawnIHM, 0);
			}
		}
	}
}

void Engine::GameEngine::beginTurn()
{
	//procs the effect of the beginning of the turn .

	//makes the current player draw
	if(!(turn%2))
	{//if it is player 1's turn
		//increase the max shards of player 1
		boards[PLAYER1_HERO]->getCardX(0)->setMaxShards(
			boards[PLAYER1_HERO]->getCardX(0)->getMaxShards()+1);
		//transmit to IHM
		IHM::setMaxShards(1,currentHero->getMaxShards());
		//reset the shards of the player
		boards[PLAYER1_HERO]->getCardX(0)->setShards(
			boards[PLAYER1_HERO]->getCardX(0)->getMaxShards());
		//transmit to IHM
		IHM::setShards(1,currentHero->getShards());
		//reset the attack count of the board
		foreach(std::list<Card*>, matchBoard->getIHMObject(PLAYER1_BOARD), itCard){
			itCard->resetAttackCount();		
		}
		playerDraws(1,1);
	}
	else
	{//if it is player 2's turn
		//increase the max shards of player 2
		boards[PLAYER2_HERO]->getCardX(0)->setMaxShards(
			boards[PLAYER2_HERO]->getCardX(0)->getMaxShards()+1);
		//transmit to IHM
		IHM::setMaxShards(2,currentHero->getMaxShards());
		//reset the shards of the player
		boards[PLAYER2_HERO]->getCardX(0)->setShards(
			boards[PLAYER2_HERO]->getCardX(0)->getMaxShards());
		//transmit to IHM
		IHM::setShards(2,currentHero->getShards());		
		//reset the attack count of the board
		foreach(std::list<Card*>, matchBoard->getIHMObject(PLAYER2_BOARD), itCard){
			itCard->resetAttackCount();		
		}

		playerDraws(2,1);
	}
}

void Engine::GameEngine::shuffleDeck(int playerNumber){//heavy tests for this please .
	if(!(playerNumber%2))
	{//if it is the Player1
  		srand ( unsigned ( time(0) ) );//initialize random
		std::vector<iCard*> v{ std::begin(matchBoard->getIHMObject(PLAYER1_DECK)), std::end(matchBoard->getIHMObject(PLAYER1_DECK)) };//copies the deck in a vector for random access
		std::random_shuffle ( v.begin(), v.end() );// shuffles with algorithm.shuffle
		std::copy(v.begin(), v(), std::back_inserter( matchBoard->getIHMObject(PLAYER1_DECK)));//copies the vector back to a list
	}
	else
	{
  		srand ( unsigned ( std::time(0) ) );
		std::vector<iCard*> v{ begin(matchBoard->getIHMObject(PLAYER2_DECK)), end(matchBoard->getIHMObject(PLAYER2_DECK)) };
		std::random_shuffle ( v.begin(), v.end() );
		std::copy(v.begin(), v(), back_inserter( matchBoard->getIHMObject(PLAYER2_DECK)));		
	}
}

void Engine::GameEngine::handleEvent ( Polycode::Event* event ) {
  using namespace Polycode;
    if(event->getDispatcher()==this){
      ServerEvent *e = (ServerEvent*)event;
      switch (e->getEventCode()){
      case ServerEvent::EVENT_CLIENT_DATA:
         switch(e->dataType){
	   case Network::PLAYON:
	     Network::PlayOnStructType* playon = (Network::PlayOnStructType*)e->data;
	     if(*getCurentPlayer()==*e->client)
	      useCard(playon->boardOrigin,playon->cardOrigin,playon->boardDestination,playon->cardDestination);
	     break;
	   case Network::ENDTURN:
	     if(*getCurentPlayer()==*e->client)
	      endTurn();
	     break;
	 }
         break;
      case ServerEvent::EVENT_CLIENT_CONNECTED:
	if(player0==nullptr){
	  player0=e->client;
	  initDeck(player0);
	}
	else if(player1==nullptr){
	  player1=e->client;
	  initDeck(player1);
	}
	break;
      case ServerEvent::EVENT_CLIENT_DISCONNECTED:
	
	break;     
      }
    }
}

Polycode::ServerClient*& Engine::GameEngine::getCurentPlayer() {
  if(turn%2)
    return player0;
  else
    return player1;
}



void Engine::GameEngine::initDeck ( Polycode::ServerClient* player ) {
  
}

void Engine::GameEngine::addCardRequest ( Polycode::ServerClient* client, void* card, int board, int position ) {

}
void Engine::GameEngine::moveCardRequest ( Polycode::ServerClient* client, int originBoard, int originPosition, int destinationBoard, int destinationPosition ) {

}

void Engine::GameEngine::removeCardRequest ( Polycode::ServerClient* client, int board, int position ) {

}

void Engine::GameEngine::setDescriptionRequest ( Polycode::ServerClient* client, void* card, std::string Description ) {

}

void Engine::GameEngine::setTitleRequest ( Polycode::ServerClient* client, void* card, std::string title ) {

}
