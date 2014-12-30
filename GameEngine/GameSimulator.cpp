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

#include "GameSimulator.h"

namespace Engine {
GameSimulator::GameSimulator ( GameEngine* server, Polycode::ServerClient* client ) : server ( server ) , client(client){
}

GameSimulator::~GameSimulator() {
  server->SimulationEndRequest(client);
}

void GameSimulator::endTurn ( void ) {

}

void GameSimulator::useCard ( int originIHMBoard, int originPosition, int destinationIHMBoard, int destinationPosition ) {
    int idOriginBoard=originIHMBoard;
    int idDestinationBoard=destinationIHMBoard;

    if ( ( idOriginBoard-1 ) /7!=server->turn%2 ) {
        //if the actions comes from a board that doesn't belong to the active player
        throw std::logic_error ( "you cann't use that board right now" );
    }

    iCard* playedCard = server->boards[idOriginBoard]->getCardX ( originPosition );
    //Player* activePlayer = (turn%2) ? (players->end()) : (players->begin());
    /* Decide on what is the action performed
    Timy-whymy-bubbly stuff . Abandon hope all ye who enter here .
    */
    if ( playedCard->getType() =="beast" ) {
        if (	idOriginBoard==PLAYER0_BOARD|| //this test is obsolete for now but i don't know how it's gonna be later
                idOriginBoard==PLAYER1_BOARD ) {
            //if it is an attack
            if (	idOriginBoard==PLAYER0_BOARD&&idDestinationBoard==PLAYER1_BOARD||
                    idOriginBoard==PLAYER1_BOARD&&idDestinationBoard==PLAYER0_BOARD ) {
                //if it is an attack on a beast
                beastAttackBeast ( idOriginBoard,idDestinationBoard,dynamic_cast<iBeast*> ( playedCard ),originPosition,destinationPosition );
            }
            if (	idOriginBoard==PLAYER0_BOARD&&idDestinationBoard==PLAYER1_HERO||
                    idOriginBoard==PLAYER1_BOARD&&idDestinationBoard==PLAYER0_HERO ) {
                //if it is an attack on the hero
                beastAttackHero ( idOriginBoard,idDestinationBoard,dynamic_cast<iBeast*> ( playedCard ),originPosition,destinationPosition );
            }

        } else if (	idOriginBoard==PLAYER0_HAND&&idDestinationBoard==PLAYER0_BOARD||
                    idOriginBoard==PLAYER1_HAND&&idDestinationBoard==PLAYER1_BOARD ) {
            //if the Beast is being played
            playBeast ( idOriginBoard,idDestinationBoard,dynamic_cast<iBeast*> ( playedCard ),originPosition,destinationPosition );
        }
    } else if ( playedCard->getType() =="spell" ) {
        if ( idOriginBoard==PLAYER0_HAND||idOriginBoard==PLAYER1_HAND ) {
            //if the spell is played from the hand
            playSpell ( idOriginBoard,idDestinationBoard, playedCard,originPosition,destinationPosition );
        }
    }
}

void GameSimulator::playBeast (	int idOriginBoard,int idDestinationBoard,iBeast* playedCard,int originPosition, int destinationPosition ) {

    //verify if the owner has enough shards
    iHero* currentHero=dynamic_cast<iHero*> ( ( idOriginBoard==PLAYER0_HAND ) ? server->boards[PLAYER0_HERO]->getCardX ( 0 ) : server->boards[PLAYER1_HERO]->getCardX ( 0 ) );
    int currentHeroShards= currentHero->getTotal ( "shards" );
    if ( !currentHeroShards>=playedCard->getCost() ) {
        throw std::logic_error ( "you don't have enough shards to play that" );
    } else {
        //verify if the board isn't full
        if ( server->boards[idDestinationBoard]->isFull() ) {
            throw std::logic_error ( "destination board is full" );
        }
        //move the card
        void* playedCardIHMCurrent = ( server->getCurrentPlayerCards() ) [ ( playedCard )];
        void* playedCardIHMNonCurrent = ( server->getNonCurrentPlayerCards() ) [ ( playedCard )];
        currentHero->decreaseShards ( playedCard->getCost() );
        server->setShardsRequest ( client, server->getCurrentPlayerNumber(), currentHeroShards );
        server->removeCardRequest ( client, idOriginBoard, originPosition );
        server->addCardRequest ( client,playedCardIHMCurrent, idDestinationBoard, destinationPosition );
        //returns the state to the IHM
    }
}

void GameSimulator::playSpell (	int idOriginBoard,int idDestinationBoard,iCard* playedCard,int originPosition, int destinationPosition ) {
    //verify if the owner has enough shards
    iHero* currentHero=dynamic_cast<iHero*> ( ( idOriginBoard==PLAYER0_HAND ) ? server->boards[PLAYER0_HERO]->getCardX ( 0 ) : server->boards[PLAYER1_HERO]->getCardX ( 0 ) );
    int currentHeroShards= currentHero->getTotal ( "shards" );
    if ( !currentHeroShards>=playedCard->getCost() ) {
        throw std::logic_error ( "you don't have enough shards to play that" );
    } else {
        //move the card
        void* playedCardIHMCurrent = ( server->getCurrentPlayerCards() ) [ ( playedCard )];
        void* playedCardIHMNonCurrent = ( server->getNonCurrentPlayerCards() ) [ ( playedCard )];

        server->setShardsRequest ( client, server->getCurrentPlayerNumber(), currentHeroShards );
        server->removeCardRequest ( client, idOriginBoard, originPosition );

        iCreature* target=dynamic_cast<iCreature*> ( server->boards[idDestinationBoard]->getCardX ( destinationPosition ) );
        void* targetIHMCurrent = ( server->getCurrentPlayerCards() ) [ ( target )];
        void* targetIHMNonCurrent = ( server->getNonCurrentPlayerCards() ) [ ( target )];
        int damage = playedCard->getTotal ( "damage" );
        int newHP = target->getTotal ( "hp" );
        server->setDefenseRequest ( client, targetIHMCurrent, newHP-damage );
        if ( newHP-damage<0 ) {
            //kills the target
            if ( idDestinationBoard == PLAYER1_BOARD ) {
                //if the target is in the board of player 1
                server->removeCardRequest ( client, idDestinationBoard, destinationPosition );
                server->addCardRequest ( client,targetIHMCurrent, PLAYER1_CIMETERY, 0 );
            } else if ( idDestinationBoard == PLAYER0_BOARD ) {
                server->removeCardRequest ( client, idDestinationBoard, destinationPosition );
                server->addCardRequest ( client,targetIHMCurrent, PLAYER0_CIMETERY, 0 );
            }

        }
        //returns the state to the IHM
    }
}

void GameSimulator::beastAttackBeast (	int idOriginBoard,int idDestinationBoard,iBeast* playedCard, int originPosition, int destinationPosition ) {
    //verify if the creacture can attack .
    if ( !playedCard->canAttack() ) {
        throw std::logic_error ( "you cann't attack with that right now" );
    } else {
        //verify if the target is valid
        //apply damage to both Creatures
        playedCard->increaseAttackCount();
        iBeast* target=dynamic_cast<iBeast*> ( server->boards[idDestinationBoard]->getCardX ( destinationPosition ) );
        void* playedCardIHMCurrent = ( server->getCurrentPlayerCards() ) [ ( playedCard )];
        void* playedCardIHMNonCurrent = ( server->getNonCurrentPlayerCards() ) [ ( playedCard )];
        void* targetIHMCurrent = ( server->getCurrentPlayerCards() ) [ ( target )];
        void* targetIHMNonCurrent = ( server->getNonCurrentPlayerCards() ) [ ( target )];
        int attGiven= playedCard->getTotal ( "attack" );
        int attTaken= target->getTotal ( "attack" );
        int newHP= target->getTotal ( "hp" );
        int newHPme = playedCard->getTotal ( "hp" );
        server->setDefenseRequest ( client, playedCardIHMCurrent, newHPme-attTaken );
        server->setDefenseRequest ( client, targetIHMCurrent,newHP-attGiven );
        //check for validity of the state (kill creatures etc)
        if ( newHP-attGiven<0 ) {
            //kills the target
            if ( idDestinationBoard == PLAYER1_BOARD ) { // MODIFY THIS AND ALL THE LINES LIKE THAT
                //if player0 is playing, target belongs to player 1
                server->removeCardRequest ( client, idDestinationBoard, destinationPosition );
                server->addCardRequest ( client,targetIHMCurrent, PLAYER1_CIMETERY, 0 );
            } else {
                server->removeCardRequest ( client, idDestinationBoard, destinationPosition );
                server->addCardRequest ( client,targetIHMCurrent, PLAYER0_CIMETERY, 0 );
            }
        }
        if ( newHPme-attTaken<0 ) {
            //kills the attacker
            if ( idDestinationBoard == PLAYER1_BOARD ) {
                server->removeCardRequest ( client, idOriginBoard, originPosition );
                server->addCardRequest ( client,targetIHMCurrent, PLAYER0_CIMETERY, 0 );
            } else {
                server->removeCardRequest ( client, idOriginBoard, originPosition );
                server->addCardRequest ( client,targetIHMCurrent, PLAYER1_CIMETERY, 0 );
            }
        }
        //returns the state to the IHM
    }
}

void GameSimulator::beastAttackHero (	int idOriginBoard,int idDestinationBoard,iBeast* playedCard, int originPosition, int destinationPosition ) {
    //verify if the creacture can attack .
    if ( !playedCard->canAttack() ) {
        throw std::logic_error ( "you cann't attack with that right now" );
    } else {
        //verify if the target is valid
        //apply damage to both Creatures
        playedCard->increaseAttackCount();
        iHero* target=dynamic_cast<iHero*> ( server->boards[idDestinationBoard]->getCardX ( destinationPosition ) );
        void* playedCardIHMCurrent = ( server->getCurrentPlayerCards() ) [ ( playedCard )];
        void* playedCardIHMNonCurrent = ( server->getNonCurrentPlayerCards() ) [ ( playedCard )];
        void* targetIHMCurrent = ( server->getCurrentPlayerCards() ) [ ( target )];
        void* targetIHMNonCurrent = ( server->getNonCurrentPlayerCards() ) [ ( target )];
        int attGiven= playedCard->getTotal ( "attack" );
        int attTaken= target->getTotal ( "attack" );
        int newHP= target->getTotal ( "hp" );
        int newHPme = playedCard->getTotal ( "hp" );
        server->setDefenseRequest ( client, playedCardIHMCurrent, newHPme-attTaken );
        server->setDefenseRequest ( client, targetIHMCurrent,newHP-attGiven );

        //check for validity of the state (kill creatures etc)

        if ( newHPme-attTaken<0 ) {
            //kills the attacker
            if ( idDestinationBoard == PLAYER1_BOARD ) {
                server->removeCardRequest ( client, idOriginBoard, originPosition );
                server->addCardRequest ( client,targetIHMCurrent, PLAYER0_CIMETERY, 0 );
            } else {
                server->removeCardRequest ( client, idOriginBoard, originPosition );
                server->addCardRequest ( client,targetIHMCurrent, PLAYER1_CIMETERY, 0 );
            }
        }
        //returns the state to the IHM
    }
}


}