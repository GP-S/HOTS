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
#include "GameEngine/gameengine.h"
#include "utils/creatdeck.h"

#include <Polycode.h>
#include "PolycodeView.h"

int main (int argc, char** argv){
  std::list<Card*> *firstDeck = newDeck();
  std::list<Card*> *secondDeck = newDeck();

  Engine::GameEngine *ge= new Engine::GameEngine();
  
  PolycodeView *view = new PolycodeView("Hello Polycode!");
  IHM::PolycodeGUI::IHM *app = new IHM::PolycodeGUI::IHM(view, ge);
  
  while(app->Update()) {}
}