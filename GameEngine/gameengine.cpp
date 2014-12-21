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

Engine::GameEngine::GameEngine() {

	boards = new std::list<Board*>();
	players = new std::list<Player*>();
	ihm = new IHM();
    ia = new IA();


    
    //corresCardId = NULL;
    //corresBoardId = NULL;
    
    turn = 0;

}

Engine::GameEngine::GameEngine ( const GameEngine& other ) {


}

Engine::GameEngine::~GameEngine() {

}

Engine::GameEngine& GameEngine::operator= ( const GameEngine& other ) {

}

bool Engine::GameEngine::operator== ( const GameEngine& other ) const {

}

std::list<GameSimulator*> Engine::GameEngine::getSimulator ( void ) {

  std::list<GameSimulator*> gameSimulators;

	foreach(size_t i = 0; i < boards[OWNER_HAND].getSize(); i++){
    if(boards[OWNER_HAND].getCardX(i).getCost() < /*Get mana disponible*/){

        GameSimulator *gameSimulator = new gameSimulator();
        gameSimulator.setListCard();
        gameSimulators.push_back(gameSimulator);
    }
	}

}

void Engine::GameEngine::useCard(IHMBoard* originIHMBoard, int originPosition, 
	IHMBoard* destinationIHMBoard, int destinationPosition){
  	
	int idOriginBoard=matchBoard->getIHMObjectPosition(originIHMBoard);
	int idDestinationBoard=matchBoard->getIHMObjectPosition(destinationIHMBoard);

	if(idOriginBoard/7!=turn%2)//if the actions comes from a board that doesn't belong to the active player
	{
		throw std::logic_error( "you cann't use that board right now" ); 
	}


  	Card* playedCard = matchBoard->getGEObject(idOriginBoard)->getCardX(originPosition);
  	Player* activePlayer = (turn%2) ? (players->end()) : (players->begin()); 
		/* Decide on what is the action performed
		Timy-whymy-bubbly stuff . Abandon hope all ye who enter here . 
		*/
		if (playedCard->getType()=="Beast")
		{
			if(idOriginBoard==1&&(idDestinationBoard==8||idDestinationBoard==14)||
					idOriginBoard==8&&(idDestinationBoard==1||idDestinationBoard==7))
			{//if it is an attack 
				//verify if the creacture can attack .
				if (playedCard->canAttack()) {		
					//verify if the target is valid
					//apply damage to both Creatures
					Creature* target=matchBoard->getGEObject(idDestinationBoard)->getCardX(destinationPosition);
					target->takeDamage(playedCard->getTotal("attack"));
					playedCard->takeDamage(target->getTotal("attack"));
					//check for validity of the state (kill creatures etc)
					if (!target.isAlive())
						{
							//kills the target

						}
					if (!playedCard.isAlive())
						{
							//kills the attacker
						}
					//returns the state to the IHM
				}

			} 
			else if (idOriginBoard==3&&idDestinationBoard==1||idOriginBoard==10&&idDestinationBoard==8)
			{//if the Beast is being played
				//verify if the owner has enough shards
				if (!activePlayer.getShards()>=playedCard.getCost())
				{
					throw std::logic_error( "you don't have enough shards" ); 
				}
				else
				{
					//verify if the board isn't full
					if(matchBoard->getGEObject(idDestinationBoard)->isFull())
					{
						throw std::logic_error( "destination board is full" ); 
  					}
					//move the card
					matchBoard->getGEObject(idOriginBoard)->takeCardX(originPosition);
  					matchBoard->getGEObject(idDestinationBoard)->addCardX(playedCard,destinationPosition);
					//returns the state to the IHM
				}
			}
		}
		else if (playedCard->getType()=="Spell")
		{
			if (idOriginBoard==3||idOriginBoard==10)
			{//if the spell is played from the hand
				//verify if the owner has enough mana
				//verify if the target is legit 
				//apply the effect of the spell
				//check for the validity of the state
				//returns state to the IHM

			}
		}

}

void Engine::GameEngine::endTurn(){

	
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
  
}
//DO NOT TOUCH THIS PLEASE
/*		Player1_board : 1,
        Player1_deck : 2,
        Player1_hand : 3,
        Player1_cimetery : 4,
        Player1_equipment : 5,
		Player1_trap : 6,
		Player1_Hero : 7,
        Player2_board : 8,
        Player2_deck : 9,
        Player2_hand : 10,
        Player2_cimetery : 11,
        Player2_equipment : 12,
        Player2_trap : 13,
        Player2_Hero : 14,*/

/*
	played card = beast
		1-8 / 8-1 => attack
		3-1 / 10-8 => play
	played card = spell
		3-X /10-X => play

		/*
  	if(destinationBoard->isFull()){
			throw std::logic_error( "destination board is full" ); 
  	}
  	destinationBoard->addCardX(playedCard,destinationPosition);

*/


