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

#ifndef IHM_ICARD_H
#define IHM_ICARD_H

#include <string>

namespace IHM
{

/**
 * This interface allows to manipulate the cards from an IHM point of view
 * @interface
 **/
class ICard
{
public:
    /** @return std::string The curent title of the card **/
    virtual std::string getTitle() =0;
    /** @param std::string newTitle The new title of the card **/
    virtual void setTitle ( std::string newTitle ) =0;

    /** @return std::string The curent description of the card **/
    virtual std::string getDescription() =0;
    /** @param std::string newDescription The new description of the card **/
    virtual void setDescription ( std::string newDescription ) =0;

    /** @return int The curent cost of the card **/
    virtual int getCost() =0;
    /** @param int newCost The new cost of the card **/
    virtual void setCost ( int newCost ) =0;

    /** @return int The curent attack of the card **/
    virtual int getAttack() =0;
    /** @param int newAttack The new attack of the card **/
    virtual void setAttack ( int newAttack ) =0;

    /** @return int The curent defense of the card **/
    virtual int getDefense() =0;
    /** @param int newDefense The new defense of the card **/
    virtual void setDefense ( int newDefense ) =0;

    /** @param int imageId The new imageId of the card **/
    virtual void setImageId ( int imageId ) =0;
};
}
#endif // IHM_ICARD_H
