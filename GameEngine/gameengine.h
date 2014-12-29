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
#include "match.h"
#include "../Board/iBoard.h"
#include "../Card/iCard.h"
#include "../Card/iHero.h"
#include "../Card/iCreature.h"
#include "../Card/iBeast.h"
#include "../utils/usefulStruc.inc"
#include "../IHM/iihm.h"
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>    
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <Polycode.h>


namespace Engine
{
  class GameEngine : public ISimulatorFactory, public IGameSolver, public Polycode::Server {
  public:
      GameEngine();
      GameEngine ( const GameEngine& other );
      ~GameEngine();
      GameEngine& operator= ( const GameEngine& other );
      bool operator== ( const GameEngine& other ) const;
      IGameSimulator& getSimulator ( void );
      void useCard ( int originBoard, int originPosition, 
                      int destinationBoard, int destinationPosition );//done .
      void endTurn ( void );
      virtual void handleEvent ( Polycode::Event* event );
      //isLegit()
      //
      
      static constexpr int PLAYER1_BOARD = 1;
      static constexpr int PLAYER1_DECK = 2;
      static constexpr int PLAYER1_HAND = 3;
      static constexpr int PLAYER1_CIMETERY = 4;
      static constexpr int PLAYER1_EQUIPMENT = 5;
      static constexpr int PLAYER1_TRAP = 6;
      static constexpr int PLAYER1_HERO = 7;
      static constexpr int PLAYER2_BOARD = 8;
      static constexpr int PLAYER2_DECK = 9;
      static constexpr int PLAYER2_HAND = 10;
      static constexpr int PLAYER2_CIMETERY = 11;
      static constexpr int PLAYER2_EQUIPMENT = 12;
      static constexpr int PLAYER2_TRAP = 13;
      static constexpr int PLAYER2_HERO = 14;
      //static constexpr int justInCase = 15; //unused
      //static constexpr int justInCase2 = 16; //unused
    
  protected:
      Match<iCard,IHM::ICard>* matchCard;
      Match<iBoard,IHM::IBoard>* matchBoard;
      std::list<iCard*>* listCardsProccedWhenAttacked; //when I get attacked 
      std::list<iCard*>* listCardsProccedWhenHurt; // when I get hurt
      std::list<iCard*>* listCardsProccedWhenHealed; // when I get healed
      std::list<iCard*>* listCardsProccedWhenSpawned; // when I spawn
      std::list<iCard*>* listCardsProccedWhenDied; // when I die 
      std::list<iCard*>* listCardsProccedWhenAttacking; // when I attack
      std::list<iCard*>* listCardsProccedWhenHurting; // when I hurt
      std::list<iCard*>* listCardsProccedWhenHealing; // when I heal
      std::list<iCard*>* listCardsProccedWhenSpawn; // when something else spawn
      std::list<iCard*>* listCardsProccedWhenKilling; // when I kill
      std::list<iCard*>* listCardsProccedWhenSomethingHealed;// when something else gets healed
      std::list<iCard*>* listCardsProccedWhenSomethingAttacks; // when something else attacks
      std::list<iCard*>* listCardsProccedWhenSomethingDies; // when something else dies
      std::list<iCard*>* listCardsProccedWhenSomethingHurt; // when something else gets hurt
      std::list<iCard*>* listCardsProccedWhenTurnBegins; // when turn begins
      std::list<iCard*>* listCardsProccedWhenTurnEnds; // when turn ends
      std::list<iBoard*> *boards;
      std::list<Player*> *players;
      IHM::IIHM *ihm;
      IA *ia;
      unsigned int turn;

  private:
      void procEffectByType(int type);
      void playBeast(int idOriginBoard,int idDestinationBoard,iBeast* playedCard,int originPosition, int destinationPosition);
      void playSpell(int idOriginBoard,int idDestinationBoard,iCard* playedCard,int originPosition, int destinationPosition);
      void beastAttackBeast(int idOriginBoard,int idDestinationBoard,iBeast* playedCard,int originPosition, int destinationPosition);
      void beastAttackHero(int idOriginBoard,int idDestinationBoard,iBeast* playedCard,int originPosition, int destinationPosition);
      void playerDraws(int playerNumber,int cardsDrawn);
      void beginTurn(); 
      void shuffleDeck(int playerNumber);//heavy tests for this please .
  };


}
#endif // GAMEENGINE_H
