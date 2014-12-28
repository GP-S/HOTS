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

#include "card.h"


IHM::PolycodeGUI::Card::Card() : ScenePrimitive ( ScenePrimitive::TYPE_BOX, CARD_WIDTH, CARD_THICK, CARD_HEIGHT ) {

    minifiedCard = new ScenePrimitive ( ScenePrimitive::TYPE_BOX, CARD_WIDTH, CARD_THICK, CARD_HEIGHT/2 );
    addChild ( minifiedCard );
    minifiedCard->visible=false;
    minifiedCard->visibilityAffectsChildren=false;
    minified=false;

    const std::string font = "Script";
    const Color textColor = Color ( 1.0,1.0,1.0,1.0 );


    title = "CardName";
    cost = 10;
    def = 10;
    att=10;
    description="Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim \
veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse \
cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";



    this->setMaterialByName ( "CubeMaterial" );

    image = new ScenePrimitive ( ScenePrimitive::TYPE_PLANE, CARD_WIDTH-2*textMargin, CARD_HEIGHT/2-2*textMargin );
    image->setPosition ( 0,CARD_THICK/2+textElevation/2,-CARD_HEIGHT/4+textMargin );
    image->loadTexture ( "Resources/polycode_logo.png" );
    image->alphaTest=true;
    minifiedCard->addChild ( image );


    titleLabel = new SceneLabel ( title, 17,font,Label::ANTIALIAS_FULL,textScale );
    titleLabel->setColor ( textColor );
    titleLabel->setPosition ( 0,CARD_THICK/2+textElevation );
    titleLabel->setPitch ( -90 );
    minifiedCard->addChild ( titleLabel );

    attackLabel = new SceneLabel ( "", 25,font,Label::ANTIALIAS_FULL,textScale*1.5 );
    attackLabel->setColor ( textColor );
    setAttack ( att );
    attackLabel->setPitch ( -90 );
    minifiedCard->addChild ( attackLabel );

    defenseLabel = new SceneLabel ( "", 25,font,Label::ANTIALIAS_FULL,textScale*1.5 );
    defenseLabel->setColor ( textColor );
    setDefense ( def );
    defenseLabel->setPitch ( -90 );
    minifiedCard->addChild ( defenseLabel );

    costLabel = new SceneLabel ( "", 25,font,Label::ANTIALIAS_FULL,textScale*1.5 );
    costLabel->setColor ( textColor );
    setCost ( cost );
    costLabel->setPitch ( -90 );
    this->addChild ( costLabel );

    setDescription ( description );


    rotationQuat=Quaternion ( 0,0,0,1 );
    hidden=true;
    hovered=false;
    tween=nullptr;
    rotTween=nullptr;
}

IHM::PolycodeGUI::Card::Card ( std::string title, int cost, int attack, int defense, std::string description, int imageId ) : Card() {
    setTitle ( title );
    setCost ( cost );
    setDefense ( defense );
    setDescription ( description );
    setImageId ( imageId );
}



IHM::PolycodeGUI::Card::~Card() {
    delete titleLabel;
    delete attackLabel;
    delete defenseLabel;
    delete costLabel;
    delete minifiedCard;
    delete image;
    for ( std::list<SceneLabel*>::iterator i = descriptionLabels.begin(); i!=descriptionLabels.end(); ++i ) {
        delete *i;
    }

}



void IHM::PolycodeGUI::Card::moveTo ( Vector3 destination,bool elevate /* = true */ ) { //FIXME memory leak
    hovered=false;

    int elevation = elevate ? 30 : 0;
    BezierCurve* curve = new BezierCurve();
    curve->addControlPoint3dWithHandles ( position.x,position.y-elevation,
                                          position.z,position.x,position.y,
                                          position.z,position.x,position.y+elevation,position.z );
    curve->addControlPoint3dWithHandles ( destination.x,destination.y+elevation,destination.z,
                                          destination.x,destination.y,destination.z,
                                          destination.x,destination.y-elevation, destination.z );
    if ( tween ) {
        delete tween;
    }
    tween = new BezierPathTween ( &position,curve,Tween::EASE_INOUT_SINE,2.5,false );
}

int IHM::PolycodeGUI::Card::getAttack() {
    return att;
}

int IHM::PolycodeGUI::Card::getDefense() {
    return def;
}

std::string IHM::PolycodeGUI::Card::getDescription() {
    return description;
}

std::string IHM::PolycodeGUI::Card::getTitle() {
    return title;
}

void IHM::PolycodeGUI::Card::setAttack ( int newAttack ) {
    att=newAttack;
    attackLabel->setText ( std::to_string ( att ) );
    attackLabel->setPosition ( - ( CARD_WIDTH/2-attackLabel->getWidth() /2-textMargin ),
                               CARD_THICK/2+textElevation,
                               - ( CARD_HEIGHT/2-textMargin - textScale )
                             );
    if(att<0)
      attackLabel->visible=false;
}

void IHM::PolycodeGUI::Card::setCost ( int newCost ) {
    cost=newCost;
    costLabel->setText ( std::to_string ( cost ) );
    costLabel->setPosition ( 0,CARD_THICK/2+textElevation,- ( CARD_HEIGHT/2-textMargin- textScale/2 ) );
    if(cost<0)
      costLabel->visible=false;
}



void IHM::PolycodeGUI::Card::setDefense ( int newDefense ) {
    def=newDefense;
    defenseLabel->setText ( std::to_string ( def ) );
    defenseLabel->setPosition ( ( CARD_WIDTH/2-defenseLabel->getWidth() /2-textMargin ),
                                CARD_THICK/2+textElevation,
                                - ( CARD_HEIGHT/2-textMargin- textScale )
                              );
    if(def<0)
      defenseLabel->visible=false;
}

void IHM::PolycodeGUI::Card::setDescription ( std::string newDescription ) {
    Number descriptionScale = 1.5;
    description=newDescription;
    for ( std::list<SceneLabel*>::iterator i = descriptionLabels.begin(); i!=descriptionLabels.end(); ++i ) {
        delete *i;
    }
    descriptionLabels.clear();
    int maxchar=floor ( ( CARD_WIDTH-2*textMargin ) *descriptionScale );
    int maxlines= floor ( CARD_HEIGHT/2/ ( textScale/descriptionScale )-2*textMargin );
    maxlines=maxlines>description.size() /maxchar+1?description.size() /maxchar+1:maxlines;
    for ( int i =0; i<maxlines; i++ ) {
        SceneLabel *descriptionText = new SceneLabel ( description.substr ( i*maxchar,maxchar ),16,"Script",Label::ANTIALIAS_FULL,textScale/descriptionScale );
        descriptionLabels.push_front ( descriptionText );
        descriptionText->setPosition ( 0,CARD_THICK/2+textElevation,textScale*descriptionLabels.size() /descriptionScale+textMargin );
        descriptionText->setPitch ( -90 );
        addChild ( descriptionText );
    }

}

void IHM::PolycodeGUI::Card::setTitle ( std::string newTitle ) {
    title=newTitle;
    titleLabel->setText ( title );
}

void IHM::PolycodeGUI::Card::toggleMinified() {
    visibilityAffectsChildren=minified;
    visible=minified;
    costLabel->visible=cost<0 ? false : minified;
    for ( std::list<SceneLabel*>::iterator i = descriptionLabels.begin(); i!=descriptionLabels.end(); ++i ) {
        ( *i )->visible=minified;
    }
    if ( minified ) {
        minifiedCard->setScaleZ ( 1 );
        setScaleZ ( 1 );
        setPositionZ ( getPosition().z+CARD_HEIGHT/4 );
        minifiedCard->setPositionZ ( minifiedCard->getPosition().z-CARD_HEIGHT/2 );
    } else {
        minifiedCard->setScaleZ ( 2 );
        setScaleZ ( 0.5 );
        setPositionZ ( getPosition().z-CARD_HEIGHT/4 );
        minifiedCard->setPositionZ ( minifiedCard->getPosition().z+CARD_HEIGHT/2 );
    }
    minified=!minified;
}

void IHM::PolycodeGUI::Card::turnOver() { //FIXME Memory leak
    BezierCurve *w=new BezierCurve(), *x=new BezierCurve(), *y=new BezierCurve(), *z=new BezierCurve();
    hidden=!hidden;
    if ( hidden ) {
        w->addControlPoint2d ( rotationQuat.w,rotationQuat.w );
        x->addControlPoint2d ( rotationQuat.x,rotationQuat.x );
        y->addControlPoint2d ( rotationQuat.y,rotationQuat.y );
        z->addControlPoint2d ( rotationQuat.z,rotationQuat.z );

        w->addControlPoint2d ( 0.,0. );
        x->addControlPoint2d ( 0.,0. );
        y->addControlPoint2d ( 0.,0. );
        z->addControlPoint2d ( 1.,1. );
    } else {
        w->addControlPoint2d ( rotationQuat.w,rotationQuat.w );
        x->addControlPoint2d ( rotationQuat.x,rotationQuat.x );
        y->addControlPoint2d ( rotationQuat.y,rotationQuat.y );
        z->addControlPoint2d ( rotationQuat.z,rotationQuat.z );

        w->addControlPoint2d ( 1.,1. );
        x->addControlPoint2d ( 0.,0. );
        y->addControlPoint2d ( 0.,0. );
        z->addControlPoint2d ( 0.,0. );
    }
    if ( rotTween ) {
        delete rotTween;
    }
    rotTween = new QuaternionTween ( &rotationQuat,w,x,y,z,Tween::EASE_INOUT_SINE,2.5,false );
}

void IHM::PolycodeGUI::Card::hide() {
    if ( !hidden ) {
        turnOver();
    }
}

void IHM::PolycodeGUI::Card::show() {
    if ( hidden ) {
        turnOver();
    }
}

void IHM::PolycodeGUI::Card::maximize() {
    if ( minified ) {
        toggleMinified();
    }
}

void IHM::PolycodeGUI::Card::minify() {
    if ( !minified ) {
        toggleMinified();
    }
}


void IHM::PolycodeGUI::Card::setImageId ( int imageId ) {
    image->loadTexture ( "Resources/Cards/"+std::to_string ( imageId ) +".png" );
}

void IHM::PolycodeGUI::Card::hover() {
    if ( tween )
        if ( tween->isComplete() ) {
            delete tween;
            tween = nullptr;
        } else {
            throw std::runtime_error ( "Not Yet" );
        }
    if ( !hovered ) {
        BezierCurve* curve = new BezierCurve();
        curve->addControlPoint3dWithHandles ( position.x,position.y,position.z,position.x,position.y,position.z,position.x,position.y,position.z );

        curve->addControlPoint3dWithHandles ( position.x,position.y,position.z- ( CARD_HEIGHT/2+4 ),
                                              position.x,position.y,position.z- ( CARD_HEIGHT/2+4 ),
                                              position.x,position.y,position.z- ( CARD_HEIGHT/2+4 ) );

        tween = new BezierPathTween ( &position,curve,Tween::EASE_INOUT_SINE,0.5,false );
        hovered=true;
    }
}

void IHM::PolycodeGUI::Card::unhover() {
    if ( tween )
        if ( tween->isComplete() ) {
            delete tween;
            tween = nullptr;
        } else {
            throw std::runtime_error ( "Not Yet" );
        }
    if ( hovered ) {
        BezierCurve* curve = new BezierCurve();
        curve->addControlPoint3dWithHandles ( position.x,position.y,position.z,position.x,position.y,position.z,position.x,position.y,position.z );

        curve->addControlPoint3dWithHandles ( position.x,position.y,position.z+ ( CARD_HEIGHT/2+4 ),
                                              position.x,position.y,position.z+ ( CARD_HEIGHT/2+4 ),
                                              position.x,position.y,position.z+ ( CARD_HEIGHT/2+4 ) );

        tween = new BezierPathTween ( &position,curve,Tween::EASE_INOUT_SINE,0.5,false );
        hovered=false;
    }
}

int IHM::PolycodeGUI::Card::getCost() {
  return cost;
}
