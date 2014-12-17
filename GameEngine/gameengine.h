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


static const OWNER_BOARD = 1;
static const OWNER_DECK = 2;
static const OWNER_HAND = 3;
static const OWNER_CIMETERY = 4;
static const OWNER_EQUIPMENT = 5;
static const OWNER_TRAP = 6;
static const OWNER_HERO = 7;
static const ENNEMI_BOARD = 8;
static const ENNEMI_DECK = 9;
static const ENNEMI_HAND = 10;
static const ENNEMI_CIMETERY = 11;
static const ENNEMI_EQUIPMENT = 12;
static const ENNEMI_TRAP = 13;
static const ENNEMI_HERO = 14;
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
      void playCard ( int originBoard, int originPosition, 
                      int destinationBoard, int destinationPosition );//done .
      void endTurn ( void );
  
  protected:
      std::list<Board*> *boards;
      std::list<Player*> *players;
      IHM *ihm;
      IA *ia;
      UnknownTemplate<Card>* corresCardId;
      UnknownTemplate<Board>* corresBoardId;
      unsigned int turn;

  };
}
#endif // GAMEENGINE_H
