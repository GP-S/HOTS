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
      void playCard ( int originBoard, int originPosition, 
                      int destinationBoard, int destinationPosition );//done .
      void endTurn ( void );
  
  protected:
      Board* boards;
      Player* players;
      IHM* ihm;
      IA* ia;
      Match<Card>* corresCardId;
      Match<Board>* corresBoardId;
      int turn;
      std::list<Card*>*  listCardsProccedWhenAttacked; //when I get attacked 
      std::list<Card*>*  listCardsProccedWhenHurt; // when I get hurt
      std::list<Card*>*  listCardsProccedWhenHealed; // when I get healed
      std::list<Card*>*  listCardsProccedWhenSpawned; // when I spawn
      std::list<Card*>*  listCardsProccedWhenDied; // when I die 
      std::list<Card*>*  listCardsProccedWhenAttacking; // when I attack
      std::list<Card*>*  listCardsProccedWhenHurting; // when I hurt
      std::list<Card*>*  listCardsProccedWhenHealing; // when I heal
      std::list<Card*>*  listCardsProccedWhenSpawn; // when something else spawn
      std::list<Card*>*  listCardsProccedWhenKilling; // when I kill
      std::list<Card*>*  listCardsProccedWhenSomethingAttacks; // when something else attacks
      std::list<Card*>*  listCardsProccedWhenSomethingDies; // when something else dies
      std::list<Card*>*  listCardsProccedWhenSomethingHealed;// when something else gets healed
      std::list<Card*>*  listCardsProccedWhenSomethingHurt; // when something else gets hurt
      std::list<Card*>*  listCardsProccedWhenTurnBegins; // when turn begins
      std::list<Card*>*  listCardsProccedWhenTurnEnds; // when turn ends

  };
}
#endif // GAMEENGINE_H
