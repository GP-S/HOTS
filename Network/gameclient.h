/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2014  Nicolas Belouin <email>
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

#ifndef GAMECLIENT_H
#define GAMECLIENT_H

#include <list>
#include <Polycode.h>
#include <PolyClient.h>
#include <icard.h>
#include <iihm.h>
#include "requestType.inc"

using namespace Polycode;

namespace Network {
  
  class GameClient : public Client
  {
  public:
      GameClient ( std::string serverAdress, int port,  IHM::IIHM* ihm);
      virtual void handleEvent ( Event* event );
      void playOnRequest ( int boardOrigin, int cardOrigine, int boardArr, int placeArr);
      void endTurnRequest ( );
      
  private:
      Address serverAddress;
      std::list<IHM::ICard*> Cards;
      IHM::IIHM *ihm;
      
      void setTitleExecute(SetTitleStructType* request);
      void setDescriptionExecute(SetDescriptionStructType* request); // FIXME CRADE
      void addCardExecute(AddCardStructType* request);
      void removeCardExecute(RemoveCardStructType* request);
      void moveCardExecute(MoveCardStructType* request);
      void setShardsExecute ( SetShardStructType* request );
      void setMaxShardsExecute ( SetShardStructType* request );
      void createCardExecute ( CreateCardStructType* request );
      void setImageIdExecute( SetNumericalAttributeStructType* request);
      void setAttackExecute( SetNumericalAttributeStructType* request);
      void setDefenseExecute ( SetNumericalAttributeStructType* request);
      void setCostExecute( SetNumericalAttributeStructType* request);
  };
}
#endif // GAMECLIENT_H
