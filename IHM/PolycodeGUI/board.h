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

#ifndef IHM_POLYCODE_BOARD_H
#define IHM_POLYCODE_BOARD_H

#include <iostream>
#include <string>
#include <list>

#include <Polycode.h>
#include "PolycodeView.h"
#include "Polycode3DPhysics.h"

#include "card.h"
#include "../iboard.h"


using namespace Polycode;
namespace IHM
{
namespace PolycodeGUI
{
class Board :  public ScenePrimitive, public IHM::IBoard
{
public:
    Board();
    Board ( unsigned int size, bool hide=false, bool mini=true, bool hover=false );
    virtual ~Board();

    void addCard ( ICard* card, int pos );
    virtual void addCard ( std::list< ICard* > cards, int pos );
    void deleteCard ( int );
    int getPlace ( Vector3 pos );
    ICard* operator[] ( int i );
    bool getHoverable();



protected:
    bool hidden;
    bool minified;
    bool stacked;
    bool hoverable;
    std::vector<Card*> cards;


private:
    unsigned int size;
};
}
}
#endif // IHM_POLYCODE_BOARD_H
