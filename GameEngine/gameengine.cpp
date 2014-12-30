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

Engine::GameEngine::GameEngine() : Server(1337,100)
{


    //corresCardId = NULL;
    //corresBoardId = NULL;  
    turn = 0;
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

Engine::IGameSimulator* Engine::GameEngine::getSimulator ( void ) 
{
 	Engine::GameSimulator* gameSimulator=new GameSimulator();

	return dynamic_cast<IGameSimulator*> (gameSimulator);

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
				beastAttackBeast(idOriginBoard,idDestinationBoard,(iBeast*) playedCard,originPosition,destinationPosition);
			}
			if(	idOriginBoard==PLAYER0_BOARD&&idDestinationBoard==PLAYER1_HERO||
				idOriginBoard==PLAYER1_BOARD&&idDestinationBoard==PLAYER0_HERO)
			{//if it is an attack on the hero
				beastAttackHero(idOriginBoard,idDestinationBoard,(iBeast*) playedCard,originPosition,destinationPosition);
			}

		} 
		else if (	idOriginBoard==PLAYER0_HAND&&idDestinationBoard==PLAYER0_BOARD||
					idOriginBoard==PLAYER1_HAND&&idDestinationBoard==PLAYER1_BOARD)
		{//if the Beast is being played
			playBeast(idOriginBoard,idDestinationBoard,(iBeast*) playedCard,originPosition,destinationPosition);
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
	foreach(std::list<iCard*>, listCardsProccedWhenTurnEnds, itCard){
		foreach(std::list<iCapacity*>, itList->capaList, itCapa){
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
									int originPosition, int destinationPosition)
{

	//verify if the owner has enough shards
	Hero* currentHero=(Hero*) (idOriginBoard==PLAYER0_HAND) ? boards[PLAYER0_HERO]->getCardX(0)
															: boards[PLAYER1_HERO]->getCardX(0);
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
		IHM::iCard* playedCardIHMCurrent = (getCurentPlayerCards())[(playedCard)];
		IHM::iCard* playedCardIHMNonCurrent = (getNonCurentPlayerCards())[(playedCard)];
		currentHero->decreaseShards(playedCard->getCost);
		setShardsRequest(getCurentPlayer(), getCurrentPlayerNumber(), currentHero->getShards());
		setShardsRequest(getNonCurentPlayer(), getCurrentPlayerNumber(), currentHero->getShards());
		boards[idOriginBoard]->deleteCardX(originPosition);
		removeCardRequest(getCurentPlayer(), idOriginBoard, originPosition);
		removeCardRequest(getNonCurentPlayer(), getOppositeBoard(idOriginBoard), originPosition);
		boards[idDestinationBoard]->addCardX(playedCard,destinationPosition);
		addCardRequest(getCurentPlayer(),playedCardIHMCurrent, idDestinationBoard, destinationPosition);
		addCardRequest(getNonCurentPlayer(),playedCardIHMNonCurrent, getOppositeBoard(idDestinationBoard), destinationPosition);
		//returns the state to the IHM
	}
}

void Engine::GameEngine::playSpell(	int idOriginBoard,int idDestinationBoard,Card* playedCard,
									int originPosition, int destinationPosition)
{
	//verify if the owner has enough shards
	Hero* currentHero=(Hero*) (idOriginBoard==PLAYER0_HAND) ? boards[PLAYER0_HERO]->getCardX(0)
															: boards[PLAYER1_HERO]->getCardX(0);
	if (!currentHero->getShards()>=playedCard->getCost())
	{
		throw std::logic_error( "you don't have enough shards to play that" ); 
	}
	else
	{
		//move the card
		IHM::iCard* playedCardIHMCurrent = (getCurentPlayerCards())[(playedCard)];
		IHM::iCard* playedCardIHMNonCurrent = (getNonCurentPlayerCards())[(playedCard)];
		currentHero->decreaseShards(playedCard->getCost);
		setShardsRequest(getCurentPlayer(), getCurrentPlayerNumber(), currentHero->getShards());
		setShardsRequest(getNonCurentPlayer(), getCurrentPlayerNumber(), currentHero->getShards());
		boards[idOriginBoard]->deleteCardX(originPosition);
		removeCardRequest(getCurentPlayer(), idOriginBoard, originPosition);
		removeCardRequest(getNonCurentPlayer(), getOppositeBoard(idOriginBoard), originPosition);
		
		Creature* target=(Creature*) boards[idDestinationBoard]->getCardX(destinationPosition);
		IHM::iCard* targetIHMCurrent = (getCurentPlayerCards())[(target)];
		IHM::iCard* targetIHMNonCurrent = (getNonCurentPlayerCards())[(target)];
		target->takeDamage(playedCard->getTotal("damage"));
		int newHP = target->getTotal("hp");
		setDefenseRequest ( getCurentPlayer(), targetIHMCurrent, newHP );
		setDefenseRequest ( getCurentNonPlayer(), targetIHMNonCurrent,newHP);
		if (!target.isAlive())
		{
			//kills the target
			if(idDestinationBoard == PLAYER1_BOARD)
			{//if the target is in the board of player 1
				boards[idDestinationBoard]->deleteCardX(destinationPosition);
				removeCardRequest(getCurentPlayer(), idDestinationBoard, destinationPosition);
				removeCardRequest(getNonCurentPlayer(), getOppositeBoard(idDestinationBoard), destinationPosition);
				boards[PLAYER1_CIMETERY]->addCardX(target,0);
				addCardRequest(getCurentPlayer(),targetIHMCurrent, PLAYER1_CIMETERY, 0);
				addCardRequest(getNonCurentPlayer(),targetIHMNonCurrent, getOppositeBoard(PLAYER1_CIMETERY), 0);

			}
			else if (idDestinationBoard == PLAYER0_BOARD)
			{
				boards[idDestinationBoard]->deleteCardX(destinationPosition);
				removeCardRequest(getCurentPlayer(), idDestinationBoard, destinationPosition);
				removeCardRequest(getNonCurentPlayer(), getOppositeBoard(idDestinationBoard), destinationPosition);
				boards[PLAYER0_CIMETERY]->addCardX(target,0);
				addCardRequest(getCurentPlayer(),targetIHMCurrent, PLAYER0_CIMETERY, 0);
				addCardRequest(getNonCurentPlayer(),targetIHMNonCurrent, getOppositeBoard(PLAYER0_CIMETERY), 0);
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
		iBeast* target=(iBeast*) boards[idDestinationBoard]->getCardX(destinationPosition);
		IHM::iCard* playedCardIHMCurrent = (getCurentPlayerCards())[(playedCard)];
		IHM::iCard* playedCardIHMNonCurrent = (getNonCurentPlayerCards())[(playedCard)];
		IHM::iCard* targetIHMCurrent = (getCurentPlayerCards())[(target)];
		IHM::iCard* targetIHMNonCurrent = (getNonCurentPlayerCards())[(target)];
		target->takeDamage(playedCard->getTotal("attack"));
		playedCard->takeDamage(target->getTotal("attack"));
		int newHP= target->getTotal("hp");
		setDefenseRequest ( getCurentPlayer(), playedCardIHMCurrent, newHP);
		setDefenseRequest ( getCurentNonPlayer(), playedCardIHMNonCurrent,newHP );
		setDefenseRequest ( getCurentPlayer(), targetIHMCurrent,newHP );
		setDefenseRequest ( getCurentNonPlayer(), targetIHMNonCurrent,newHP );
		//check for validity of the state (kill creatures etc)
		if (!target.isAlive())
		{
			//kills the target
			if(idDestinationBoard == PLAYER1_BOARD)// MODIFY THIS AND ALL THE LINES LIKE THAT
			{//if player0 is playing, target belongs to player 1
				boards[idDestinationBoard]->deleteCardX(destinationPosition);
				removeCardRequest(getCurentPlayer(), idDestinationBoard, destinationPosition);
				removeCardRequest(getNonCurentPlayer(), getOppositeBoard(idDestinationBoard), destinationPosition);
				boards[PLAYER1_CIMETERY]->addCardX(target,0);
				addCardRequest(getCurentPlayer(),targetIHMCurrent, PLAYER1_CIMETERY, 0);
				addCardRequest(getNonCurentPlayer(),targetIHMNonCurrent, getOppositeBoard(PLAYER1_CIMETERY), 0);
			}
			else
			{
				boards[idDestinationBoard]->deleteCardX(destinationPosition);
				removeCardRequest(getCurentPlayer(), idDestinationBoard, destinationPosition);
				removeCardRequest(getNonCurentPlayer(), getOppositeBoard(idDestinationBoard), destinationPosition);
				boards[PLAYER0_CIMETERY]->addCardX(target,0);
				addCardRequest(getCurentPlayer(),targetIHMCurrent, PLAYER0_CIMETERY, 0);
				addCardRequest(getNonCurentPlayer(),targetIHMNonCurrent, getOppositeBoard(PLAYER0_CIMETERY), 0);
			}
		}
		if (!playedCard.isAlive())
		{
			//kills the attacker
			if(idDestinationBoard == PLAYER1_BOARD)
			{
				boards[idOriginBoard]->deleteCardX(originPosition);
				removeCardRequest(getCurentPlayer(), idOriginBoard, originPosition);
				removeCardRequest(getNonCurentPlayer(), getOppositeBoard(idOriginBoard), originPosition);
				boards[PLAYER0_CIMETERY]->addCardX(playedCard,0);
				addCardRequest(getCurentPlayer(),targetIHMCurrent, PLAYER0_CIMETERY, 0);
				addCardRequest(getNonCurentPlayer(),targetIHMNonCurrent, getOppositeBoard(PLAYER0_CIMETERY), 0);
			}
			else
			{
				boards[idOriginBoard]->deleteCardX(originPosition);
				removeCardRequest(getCurentPlayer(), idOriginBoard, originPosition);
				removeCardRequest(getNonCurentPlayer(), getOppositeBoard(idOriginBoard), originPosition);
				boards[PLAYER1_CIMETERY]->addCardX(playedCard,0);
				addCardRequest(getCurentPlayer(),targetIHMCurrent, PLAYER1_CIMETERY, 0);
				addCardRequest(getNonCurentPlayer(),targetIHMNonCurrent, getOppositeBoard(PLAYER1_CIMETERY), 0);
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
		IIHM::iCard* playedCardIHMCurrent = (getCurentPlayerCards())[(playedCard)];
		IHM::iCard* playedCardIHMNonCurrent = (getNonCurentPlayerCards())[(playedCard)];
		IHM::iCard* targetIHMCurrent = (getCurentPlayerCards())[(target)];
		IHM::iCard* targetIHMNonCurrent = (getNonCurentPlayerCards())[(target)];
		target->takeDamage(playedCard->getTotal("attack"));
		playedCard->takeDamage(target->getTotal("attack"));
		int newHP= target->getTotal("hp");
		setDefenseRequest ( getCurentPlayer(), playedCardIHMCurrent, newHP);
		setDefenseRequest ( getCurentNonPlayer(), playedCardIHMNonCurrent,newHP );
		setDefenseRequest ( getCurentPlayer(), targetIHMCurrent,newHP );
		setDefenseRequest ( getCurentNonPlayer(), targetIHMNonCurrent,newHP );

		//check for validity of the state (kill creatures etc)
		if (!target.isAlive())
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
		if (!playedCard.isAlive())
		{
			if(idDestinationBoard == PLAYER0_BOARD)
			{
				boards[idOriginBoard]->deleteCardX(originPosition);
				removeCardRequest(getCurentPlayer(), idOriginBoard, originPosition);
				removeCardRequest(getNonCurentPlayer(), getOppositeBoard(idOriginBoard), originPosition);
				boards[PLAYER0_CIMETERY]->addCardX(playedCard,0);
				addCardRequest(getCurentPlayer(),playedCardIHMCurrent, PLAYER0_CIMETERY, 0);
				addCardRequest(getNonCurentPlayer(),playedCardIHMNonCurrent, getOppositeBoard(PLAYER0_CIMETERY), 0);
			}
			else
			{
				boards[idOriginBoard]->deleteCardX(originPosition);
				removeCardRequest(getCurentPlayer(), idOriginBoard, originPosition);
				removeCardRequest(getNonCurentPlayer(), getOppositeBoard(idOriginBoard), originPosition);
				boards[PLAYER1_CIMETERY]->addCardX(playedCard,0);
				addCardRequest(getCurentPlayer(),playedCardIHMCurrent, PLAYER1_CIMETERY, 0);
				addCardRequest(getNonCurentPlayer(),playedCardIHMNonCurrent, getOppositeBoard(PLAYER1_CIMETERY), 0);
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
			Card* drawnCard = boards[PLAYER0_DECK]->takeCardX(0);
			IHM::iCard* drawnCardIHMCurrent = (getCurentPlayerCards())[(drawnCard)];
			IHM::iCard* drawnCardIHMNonCurrent = (getNonCurentPlayerCards())[(drawnCard)];
			removeCardRequest(getCurentPlayer(), PLAYER0_DECK, 0);
			removeCardRequest(getNonCurentPlayer(), getOppositeBoard(PLAYER0_DECK), 0);
			if (!boards[PLAYER0_HAND]->isFull())
			{//if the hand isn't full
				//adds the card the the hand
				boards[PLAYER0_HAND]->addCardX(drawnCard, 0);
				addCardRequest(getCurentPlayer(),drawnCardIHMCurrent, PLAYER0_HAND, 0);
				addCardRequest(getNonCurentPlayer(),drawnCardIHMNonCurrent, getOppositeBoard(PLAYER0_HAND), 0);
			}
		}	
	}
	else
	{
		for (int i=0;i<cardsDrawn;i++)
		{
			//takes the first card of the deck
			Card* drawnCard = boards[PLAYER1_DECK]->takeCardX(0);
			IHM::iCard* drawnCardIHMCurrent = (getCurentPlayerCards())[(drawnCard)];
			IHM::iCard* drawnCardIHMNonCurrent = (getNonCurentPlayerCards())[(drawnCard)];
			removeCardRequest(getCurentPlayer(), PLAYER1_DECK, 0);
			removeCardRequest(getNonCurentPlayer(), getOppositeBoard(PLAYER1_DECK), 0);
			if (!boards[PLAYER1_HAND]->isFull())
			{//if the hand isn't full
				//adds the card the the hand
				boards[PLAYER1_HAND]->addCardX(drawnCard, 0);
				addCardRequest(getCurentPlayer(),drawnCardIHMCurrent, PLAYER1_HAND, 0);
				addCardRequest(getNonCurentPlayer(),drawnCardIHMNonCurrent, getOppositeBoard(PLAYER1_HAND), 0);
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
		boards[PLAYER0_HERO]->getCardX(0)->setMaxShards(
			boards[PLAYER0_HERO]->getCardX(0)->getMaxShards()+1);
		//transmit to IHM
		setMaxShardsRequest(getCurentPlayer(), getCurrentPlayerNumber(),
			boards[PLAYER0_HERO]->getCardX(0)->getMaxShards());
		setMaxShardsRequest(getNonCurentPlayer(), getCurrentPlayerNumber(), 
			boards[PLAYER0_HERO]->getCardX(0)->getMaxShards());
		//reset the shards of the player
		boards[PLAYER0_HERO]->getCardX(0)->setShards(
			boards[PLAYER0_HERO]->getCardX(0)->getMaxShards());
		//transmit to IHM
		setShardsRequest(getCurentPlayer(), getCurrentPlayerNumber(),
			boards[PLAYER0_HERO]->getCardX(0)->getShards());
		setShardsRequest(getNonCurentPlayer(), getCurrentPlayerNumber(), 
			boards[PLAYER0_HERO]->getCardX(0)->getShards());
		//reset the attack count of the board
		foreach(std::list<iCard*>, matchBoard->getIHMObject(PLAYER0_BOARD), itCard){
			itCard->resetAttackCount();		
		}
		playerDraws(getCurrentPlayerNumber,1);
	}
	else
	{//if it is player 1's turn
		//increase the max shards of player 1
		boards[PLAYER1_HERO]->getCardX(0)->setMaxShards(
			boards[PLAYER1_HERO]->getCardX(0)->getMaxShards()+1);
		//transmit to IHM
		setMaxShardsRequest(getCurentPlayer(), getCurrentPlayerNumber(),
			boards[PLAYER1_HERO]->getCardX(0)->getMaxShards());
		setMaxShardsRequest(getNonCurentPlayer(), getCurrentPlayerNumber(), 
			boards[PLAYER1_HERO]->getCardX(0)->getMaxShards());
		//reset the shards of the player
		boards[PLAYER1_HERO]->getCardX(0)->setShards(
			boards[PLAYER1_HERO]->getCardX(0)->getMaxShards());
		//transmit to IHM
		setShardsRequest(getCurentPlayer(), getCurrentPlayerNumber(),
			boards[PLAYER1_HERO]->getCardX(0)->getShards());
		setShardsRequest(getNonCurentPlayer(), getCurrentPlayerNumber(), 
			boards[PLAYER1_HERO]->getCardX(0)->getShards());
		//reset the attack count of the board
		foreach(std::list<iCard*>, matchBoard->getIHMObject(PLAYER1_BOARD), itCard){
			itCard->resetAttackCount();		
		}
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
    if(event->getDispatcher()==this){
      ServerEvent *e = (ServerEvent*)event;
      switch (e->getEventCode()){
      case ServerEvent::EVENT_CLIENT_DATA:
         switch(e->dataType){
	   case Network::PLAYON: {
	     Network::PlayOnStructType* playon = (Network::PlayOnStructType*) e->data;
	     if(getCurrentPlayer()->clientID==e->client->clientID)
	      useCard(playon->boardOrigin,playon->cardOrigin,playon->boardDestination,playon->cardDestination);
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

void Engine::GameEngine::initDeck ( Polycode::ServerClient* client ) {

	
  
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
  
