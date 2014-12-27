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

#ifndef IBOARD_H
#define IBOARD_H

#include <list>

#include "icard.h"

namespace IHM
{

class IBoard
{
public:
    virtual void addCard ( ICard* card, int pos ) =0;
    virtual void addCard (std::list<ICard*> cards, int pos )=0;
    virtual void deleteCard ( int ) =0;
    virtual ICard* operator[] ( int i ) =0;
};

}

#endif // IBOARd_H