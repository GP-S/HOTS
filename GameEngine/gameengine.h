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

#include "gamesimulator.h"

#include <vector>
#include <list>
#include <iterator>
#include <algorithm>    
#include <vector>

#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

#include <Polycode.h>
#include <PolyServer.h>
#include <requestType.inc>


namespace Engine
{
  class GameEngine : public ISimulatorFactory, public IGameSolver, public Polycode::Server {
  public:
      GameEngine();
      GameEngine ( const GameEngine& other );
      ~GameEngine();
      GameEngine& operator= ( const GameEngine& other );
      bool operator== ( const GameEngine& other ) const;
      IGameSimulator* getSimulator ( void );
      void useCard ( int originBoard, int originPosition, 
                      int destinationBoard, int destinationPosition );//done .
      void endTurn ( void );
      virtual void handleEvent ( Polycode::Event* event );
      //isLegit()
      //
      

    
  protected:
      Match<iCard,void> matchCardPlayer0;
      Match<iCard,void> matchCardPlayer1;
      
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
      
      iBoard* boards[16];
      //Player* players[2];
      
      Polycode::ServerClient* player0;
      Polycode::ServerClient* player1;
      
      unsigned int turn;
      
    Polycode::ServerClient*& getCurrentPlayer();
    Polycode::ServerClient*& getNonCurrentPlayer();
    Match<iCard,void>* getCurrentPlayerCards();
    Match<iCard,void>* getNonCurrentPlayerCards();
    int getCurrentPlayerNumber();
    void initDeck ( Polycode::ServerClient* player );
    
    void setTitleRequest(Polycode::ServerClient* client, void* card, std::string title);
    void setDescriptionRequest(Polycode::ServerClient* client, void* card, std::string Description);
    void removeCardRequest(Polycode::ServerClient* client, int board, int position);
    void addCardRequest(Polycode::ServerClient* client, void* card, int board, int position);
    void moveCardRequest(Polycode::ServerClient* client, int originBoard, int originPosition, int destinationBoard, int destinationPosition);
    void setShardsRequest(Polycode::ServerClient* client, int playerId, int shards);
    void setMaxShardsRequest(Polycode::ServerClient* client, int playerId, int shards);
    void setAttackRequest(Polycode::ServerClient* client, void* card, int newVal);
    void setDefenseRequest(Polycode::ServerClient* client, void* card, int newVal);
    void setCostRequest(Polycode::ServerClient* client, void* card, int newVal);
    void setImageIDRequest(Polycode::ServerClient* client, void* card, int newVal);

  private:
      void procEffectByType(int type);
      void playBeast(int idOriginBoard,int idDestinationBoard,iBeast* playedCard,int originPosition, int destinationPosition);
      void playSpell(int idOriginBoard,int idDestinationBoard,iCard* playedCard,int originPosition, int destinationPosition);
      void beastAttackBeast(int idOriginBoard,int idDestinationBoard,iBeast* playedCard,int originPosition, int destinationPosition);
      void beastAttackHero(int idOriginBoard,int idDestinationBoard,iBeast* playedCard,int originPosition, int destinationPosition);
      void playerDraws(int playerNumber,int cardsDrawn);
      void beginTurn(); 
      void shuffleDeck(int playerNumber);//this doesn't work at all . do it over .
      
  };


}
#endif // GAMEENGINE_H
