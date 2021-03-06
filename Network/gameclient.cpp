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
#include <iostream>

namespace Network {
  GameClient::GameClient ( std::string serverAddress, int port , IHM::IIHM* ihm) : serverAddress(Address(serverAddress,port)), ihm(ihm), Client(0,1) {
    Connect(serverAddress,port);
    std::cout<<"Here Come The Network"<<std::endl;
    addEventListener(this, ClientEvent::EVENT_SERVER_DISCONNECTED);
    addEventListener(this, ClientEvent::EVENT_SERVER_DATA);
  }

  void GameClient::handleEvent ( Polycode::Event* event ) {
    	Client::handleEvent(event);
	
    if (event->getDispatcher() == this){
      ClientEvent* e = dynamic_cast<ClientEvent*> (event);
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
	    case SETDESCRIP: //FIXME CRADE
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
	      break;
	    case SETDEFENSE:
	      setDefenseExecute((SetNumericalAttributeStructType*) e->data);
	      break;
	    case SETATTACK:
	      setAttackExecute((SetNumericalAttributeStructType*) e->data);
	      break;
	    case SETCOST:
	      setCostExecute((SetNumericalAttributeStructType*) e->data);
	      break;
	    case SETIMAGEID:
	      setImageIdExecute((SetNumericalAttributeStructType*) e->data);
	      break;
	      
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
  sendData(serverAddress,(char*) &request, sizeof(request), PLAYON);
}

void GameClient::addCardExecute ( AddCardStructType* request ) {
	try {
	ihm->getBoard(request->boardDestination)->addCard( static_cast<IHM::ICard*> (request->card),request->cardDestination);
	} catch (std::exception e) {
	  std::cout << e.what() << std::endl;
	}
}

void GameClient::moveCardExecute ( MoveCardStructType* request ) {
	IHM::ICard* movedCard= (*ihm->getBoard(request->boardOrigin))[request->cardOrigin];
	ihm->getBoard(request->boardOrigin)->deleteCard(request->cardOrigin);
	ihm->getBoard(request->boardDestination)->addCard(movedCard,request->cardDestination);
}

void GameClient::removeCardExecute ( RemoveCardStructType* request ) {
	try {
	ihm->getBoard(request->board)->deleteCard(request->position);
	}
	catch (std::exception e) {
	  std::cout << e.what() << std::endl;
	}
}

void GameClient::setDescriptionExecute ( SetDescriptionStructType* request ) { // FIXME CRADE

	static_cast<IHM::ICard*> (request->card)->setDescription(request->description);
}

void GameClient::setTitleExecute ( SetTitleStructType* request ) {

	static_cast<IHM::ICard*> (request->card)->setTitle(request->title);
}

void GameClient::setMaxShardsExecute ( Network::SetShardStructType* request ) {
  ihm->setMaxShards( request->playerId,request->shards);
}

void GameClient::setShardsExecute ( Network::SetShardStructType* request ) {
  ihm->setShards( request->playerId,request->shards);
}

void GameClient::createCardExecute ( Network::CreateCardStructType* request ) {
  IHM::ICard* card=ihm->createCard( request->title,request->cost,request->attack,request->defense,request->description,request->imageID);
  CreateCardAnswerStructType answer = {request->incomingReference, (void*) card};
  sendData(serverAddress,(char*) &answer,sizeof(CreateCardAnswerStructType),CREATE);
}

void GameClient::setAttackExecute ( SetNumericalAttributeStructType* request ) { //FIXME CRADE
  static_cast<IHM::ICard*> (request->card)->setAttack(request->newVal);
}

void GameClient::setCostExecute ( SetNumericalAttributeStructType* request ) { //FIXME CRADE
  static_cast<IHM::ICard*> (request->card)->setCost(request->newVal);
}

void GameClient::setDefenseExecute ( SetNumericalAttributeStructType* request ) { //FIXME CRADE
  static_cast<IHM::ICard*> (request->card)->setDefense(request->newVal);
}

void GameClient::setImageIdExecute ( SetNumericalAttributeStructType* request ) {
  static_cast<IHM::ICard*> (request->card)->setImageId(request->newVal);
}

}