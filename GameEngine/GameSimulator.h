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

#ifndef GAMESIMULATOR_H
#define GAMESIMULATOR_H

#include <stdexcept>
#include <Polycode.h>
#include "iGameSolver.h"
#include "GameEngine.h"

namespace Engine {
  class GameEngine;
  
  class GameSimulator : public iGameSolver
  {
  public:
    GameSimulator( Engine::GameEngine* server, Polycode::ServerClient* client );
    ~GameSimulator();
    virtual void endTurn ( void );
    virtual void useCard ( int originBoard, int originPosition, int destinationBoard, int destinationPosition );

  private:
    void playBeast(int idOriginBoard,int idDestinationBoard,iBeast* playedCard,int originPosition, int destinationPosition);
      void playSpell(int idOriginBoard,int idDestinationBoard,iCard* playedCard,int originPosition, int destinationPosition);
      void beastAttackBeast(int idOriginBoard,int idDestinationBoard,iBeast* playedCard,int originPosition, int destinationPosition);
      void beastAttackHero(int idOriginBoard,int idDestinationBoard,iBeast* playedCard,int originPosition, int destinationPosition);
    GameEngine* server;
    Polycode::ServerClient* client;
  };

}
#endif // GAMESIMULATOR_H
