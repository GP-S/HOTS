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

#ifndef CARD_H
#define CARD_H

#include <string>
#include <list>
#include <iostream>

#include <Polycode.h>
#include "PolycodeView.h"
#include "Polycode3DPhysics.h"

#include "../icard.h"

using namespace Polycode;
namespace IHM
{
namespace PolycodeGUI
{

class Card : public ScenePrimitive, public IHM::ICard
{
public:
    Card();
    Card ( std::string title, int cost,int attack,int defense,std::string description,int imageId );
    ~Card();

    void moveTo ( Vector3 destination, bool elevate=true );

    std::string getTitle();
    void setTitle ( std::string newTitle );

    std::string getDescription();
    void setDescription ( std::string newDescription );

    int getCost();
    void setCost ( int newCost );

    int getAttack();
    void setAttack ( int newAttack );

    int getDefense();
    void setDefense ( int newDefense );

    void toggleMinified();
    void minify();
    void maximize();

    void turnOver();
    void hide();
    void show();

    void hover();
    void unhover();

    void setImageId ( int imageId );

    static constexpr Number CARD_WIDTH = 15;
    static constexpr Number CARD_HEIGHT = 25;
    static constexpr Number CARD_THICK = 2;

protected:
    SceneLabel *titleLabel, *costLabel, *attackLabel, *defenseLabel;
    std::list<SceneLabel*> descriptionLabels;
    ScenePrimitive *minifiedCard;
    std::string title, description;
    int cost, att, def;
    bool hidden, hovered,minified;

    const Number textElevation = 0.1;
    const Number textMargin = 0.8;
    const Number textScale = 1.6;
    ScenePrimitive* image;


    BezierPathTween* tween;
    QuaternionTween* rotTween;
};

}
}

#endif // CARD_H
