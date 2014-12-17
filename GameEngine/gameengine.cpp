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

void Engine::GameEngine::playCard(Board* originBoard, int originPosition, 
	Board* destinationBoard, int destinationPosition){
  	
  	if(destinationBoard->isFull()){
			throw std::logic_error( "destination board is full" ); 
  	}
  	Card* playedCard = originBoard->takeCardX(originPosition);
  	destinationBoard->addCardX(playedCard,destinationPosition);




}

void Engine::GameEngine::endTurn(void){
  
}

