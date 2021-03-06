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

#include "IHM/PolycodeGUI/IHM.h"
#include "GameEngine/GameEngine.h"
#include "utils/CreateDeck.h"

#include <Polycode.h>
#include <string>
#include <iostream>

#include "PolycodeView.h"

void printHelp();

int main (int argc, char** argv){
  std::list<iCard*> *firstDeck = newDeck();
  std::list<iCard*> *secondDeck = newDeck();
  Hero* p0=newHero("Player 0");
  Hero* p1=newHero("Player 1");

    int c;
    std::string address = "127.0.0.1";
    bool single=false;
    bool server=false;
  if(argc >= 2){

      if(std::string(argv[1])=="-c"){
	if(argc == 2){
	  printHelp();
	  return 1;
	}
	address = argv[2];
      } else if (std::string(argv[1])=="--single") {
	single=true;
	server=true;
      } else if (std::string(argv[1])=="--server") {
	server=true;
      } else {
	printHelp();
	return 1;
      }
  }
  else {
    printHelp();
    return 1;
  }
	
	
  if(server)
    Engine::GameEngine *ge= new Engine::GameEngine((firstDeck),(secondDeck), p0,p1);
  
  PolycodeView *view = new PolycodeView("Hello Polycode!");
  IHM::PolycodeGUI::IHM *app = new IHM::PolycodeGUI::IHM(view, address, 1337);
  
  while(app->Update()) {}
}

void printHelp() {
  std::cout << "Usage : HOTS  --single | --server | -c <serverAddress>" << std::endl;
  std::cout << " --single : Play a single player game against an AI" << std::endl;
  std::cout << " --server : Play a two players game as the host" << std::endl;
  std::cout << " -c <serverAddress> : Play a two player game as a client to the given server" << std::endl;
}
