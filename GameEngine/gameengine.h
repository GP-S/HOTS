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

/*  attaque . vérifie cible . résoud . 
*  IHM . IHMBoard + pos . GEBoard + pos . GECard (x2) .. check . resolution sur les GEObjects. appeller sur les IHMObjects 
*
*
*
*
*/
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
      //isLegit()
      //
      
  
  protected:
      Board* boards;
      Player* players;
      IHM* ihm;
      IA* ia;
      Match<Card>* matchCard;
      Match<Board>* matchBoard;
      int turn;
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
      UnknownTemplate<Card>* corresCardId;
      UnknownTemplate<Board>* corresBoardId;
      unsigned int turn;

  private:
      void procEffectByType(int type);
  };


}
#endif // GAMEENGINE_H

/*      Player1_board : 1,
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
