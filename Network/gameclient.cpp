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

#include "gameclient.h"

namespace Network {
  GameClient::GameClient ( std::string serverAddress, int port , IHM::IIHM* ihm) : serverAddress(Address(serverAddress,port)), ihm(ihm), Client(0,1) {
    Connect(serverAddress,port);
    addEventListener(this, ClientEvent::EVENT_SERVER_DISCONNECTED);
    addEventListener(this, ClientEvent::EVENT_SERVER_DATA);
  }

  void GameClient::handleEvent ( Polycode::Event* event ) {
    if (event->getDispatcher() == this){
      ClientEvent* e = event;
      switch(e->getEventCode()){
	case ClientEvent::EVENT_SERVER_DISCONNECTED:
	  Services()->getCore()->Shutdown();
	  break;
	case ClientEvent::EVENT_SERVER_DATA:
	  switch(e->dataType){
	    case SETTITLE:
	      setTitleExecute((SetTitleStructType*)e->data);
	      break;
	    case SETTYPE:
	      
	      break;
	    case SETDESCRIP:
	      setDescriptionExecute((SetDescriptionStructType*)e->data);
	      break;
	    case SETCAPA:
	      
	      break;
	    case ADDCARD:
	      addCardExecute((AddCardStructType*) e->data);
	      break;
	    case MOVECARD:
	      moveCardExecute((MoveCardStructType*) e->data);
	      break;
	    case REMOVECARD:
	      removeCardExecute((RemoveCardStructType*) e->data);
	      break;
	    case SETNBCARD:
	      
	      break;
	    case SETSHARD:
	      setShardsExecute((SetShardStructType*) e->data);
	      break;
	    case SETMAXSHARD:
	      setMaxShardsExecute((SetShardStructType*) e->data);
	      break;
	    case CREATE:
	      createCardExecute((CreateCardStructType*) e->data);
	  }
	  break;
      }
    }
  }
  
void GameClient::endTurnRequest() {
  sendData(serverAddress, "0", sizeof("0"), ENDTURN);
}

void GameClient::playOnRequest ( int boardOrigin, int cardOrigine, int boardArr, int placeArr ) {
  PlayOnStructType request = {boardOrigin,cardOrigine,boardArr,placeArr};
  sendData(serverAddress, &request, sizeof(request), PLAYON);
}

void GameClient::addCardExecute ( AddCardStructType* request ) {

	ihm->getBoard(request->boardDestination)->addCard(request->card,request->cardDestination);
}

void GameClient::moveCardExecute ( MoveCardStructType* request ) {
	IHM::ICard* movedCard= (ihm->getBoard(request->boardOrigin))[request->cardOrigin];
	ihm->getBoard(request->boardOrigin)->deleteCard(request->cardOrigin);
	ihm->getBoard(request->boardDestination)->addCard(movedCard,request->cardDestination);
}

void GameClient::removeCardExecute ( RemoveCardStructType* request ) {

	ihm->getBoard(request->board)->deleteCard(request->position);
}

void GameClient::setDescriptionExecute ( SetDescriptionStructType* request ) {

	dynamic_cast<IHM::ICard*> (request->card)->setDescription(request->description);
}

void GameClient::setTitleExecute ( SetTitleStructType* request ) {

	dynamic_cast<IHM::ICard*> (request->card)->setTitle(request->title);
}

void GameClient::setMaxShardsExecute ( Network::SetShardStructType* request ) {
  ihm->setMaxShards( request->playerId,request->shards);
}

void GameClient::setShardsExecute ( Network::SetShardStructType* request ) {
  ihm->setShards( request->playerId,request->shards);
}

void GameClient::createCardExecute ( Network::CreateCardStructType* request ) {
  IHM::ICard* card=ihm->createCard( request->title,request->cost,request->attack,request->defense,request->description,request->imageID);
  CreateCardAnswerStructType answer = {request->incomingReference, (int) card};
  sendData(serverAddress,&answer,sizeof(CreateCardAnswerStructType),CREATE);
}

}