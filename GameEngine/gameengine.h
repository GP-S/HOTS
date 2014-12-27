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

#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "isimulatorfactory.h"
#include "igamesolver.h"
#include "../Board/iBoard.h"
#include "../Card/iCard.h"
#include "../utils/usefulStruc.inc"
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>    
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand


static const PLAYER1_BOARD = 1;
static const PLAYER1_DECK = 2;
static const PLAYER1_HAND = 3;
static const PLAYER1_CIMETERY = 4;
static const PLAYER1_EQUIPMENT = 5;
static const PLAYER1_TRAP = 6;
static const PLAYER1_HERO = 7;
static const PLAYER2_BOARD = 8;
static const PLAYER2_DECK = 9;
static const PLAYER2_HAND = 10;
static const PLAYER2_CIMETERY = 11;
static const PLAYER2_EQUIPMENT = 12;
static const PLAYER2_TRAP = 13;
static const PLAYER2_HERO = 14;
//static const justInCase = 15; //unused
//static const justInCase2 = 16; //unused


namespace Engine
{
  class GameEngine : public ISimulatorFactory, public IGameSolver {
  public:
      GameEngine();
      GameEngine ( const GameEngine& other );
      ~GameEngine();
      GameEngine& operator= ( const GameEngine& other );
      bool operator== ( const GameEngine& other ) const;
      IGameSimulator getSimulator ( void );
      void useCard ( int originBoard, int originPosition, 
                      int destinationBoard, int destinationPosition );//done .
      void endTurn ( void );
      //isLegit()
      //
      
  
  protected:
      Board* boards;
      Player* players;
      IHM* ihm;
      IA* ia;
      Match<Card>* matchCard;
      Match<Board>* matchBoard;
      std::list<Card*>* listCardsProccedWhenAttacked; //when I get attacked 
      std::list<Card*>* listCardsProccedWhenHurt; // when I get hurt
      std::list<Card*>* listCardsProccedWhenHealed; // when I get healed
      std::list<Card*>* listCardsProccedWhenSpawned; // when I spawn
      std::list<Card*>* listCardsProccedWhenDied; // when I die 
      std::list<Card*>* listCardsProccedWhenAttacking; // when I attack
      std::list<Card*>* listCardsProccedWhenHurting; // when I hurt
      std::list<Card*>* listCardsProccedWhenHealing; // when I heal
      std::list<Card*>* listCardsProccedWhenSpawn; // when something else spawn
      std::list<Card*>* listCardsProccedWhenKilling; // when I kill
      std::list<Card*>* listCardsProccedWhenSomethingHealed;// when something else gets healed
      std::list<Card*>* listCardsProccedWhenSomethingAttacks; // when something else attacks
      std::list<Card*>* listCardsProccedWhenSomethingDies; // when something else dies
      std::list<Card*>* listCardsProccedWhenSomethingHurt; // when something else gets hurt
      std::list<Card*>* listCardsProccedWhenTurnBegins; // when turn begins
      std::list<Card*>* listCardsProccedWhenTurnEnds; // when turn ends
      std::list<Board*> *boards;
      std::list<Player*> *players;
      IHM *ihm;
      IA *ia;
      unsigned int turn;

  private:
      void procEffectByType(int type);
      void playBeast(int idOriginBoard,int idDestinationBoard,Beast* playedCard,int originPosition, int destinationPosition);
      void playSpell(int idOriginBoard,int idDestinationBoard,Spell* playedCard,int originPosition, int destinationPosition);
      void beastAttackBeast(int idOriginBoard,int idDestinationBoard,Beast* playedCard,int originPosition, int destinationPosition);
      void beastAttackHero(int idOriginBoard,int idDestinationBoard,Beast* playedCard,int originPosition, int destinationPosition);
      void playerDraws(int playerNumber,int cardsDrawn);
      void beginTurn(); //needs the ihm return
      void shuffleDeck(int playerNumber);//heavy tests for this please .
  };


}
#endif // GAMEENGINE_H
