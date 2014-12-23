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

#ifndef IIHM_H
#define IIHM_H

#include <string>

#include "iboard.h"
#include "icard.h"

namespace IHM
{
class IIHM
{
public:
    virtual ICard* createCard() =0;
    virtual ICard* createCard ( std::string title, int cost,int attack,int defense,std::string description,int imageId ) =0;

    virtual IBoard* getBoard(int numBoard, int numPlayer)=0;
    
    static constexpr int STOCK = 0;
    static constexpr int HAND = 1;
    static constexpr int BATTLEGROUND = 2;
    static constexpr int GRAVEYARD = 3;
    
};
}

#endif // IIHM_H