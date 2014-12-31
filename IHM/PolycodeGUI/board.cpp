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

#include "board.h"

IHM::PolycodeGUI::Board::Board() : ScenePrimitive ( ScenePrimitive::TYPE_BOX,Card::CARD_WIDTH,Card::CARD_THICK+0.1, Card::CARD_HEIGHT ) {
    visible=false;
    stacked=true;
    hidden=true;
    minified=false;
    hoverable=false;
    size=0;
    color=Color ( 1.,1.,1.,0.5 );
}

IHM::PolycodeGUI::Board::Board ( unsigned int size, bool hide,bool mini, bool hover ) : ScenePrimitive ( ScenePrimitive::TYPE_BOX,
            size==0?Card::CARD_WIDTH: ( Card::CARD_WIDTH*size+0.8* ( size-1 ) ),Card::CARD_THICK+0.1, Card::CARD_HEIGHT/ ( mini?2:1 ) + ( mini?1.6:0 ) ) {
    this->size=size;
    stacked=size==0;
    hidden=hide;
    minified=mini;
    visible=false;
    hoverable=hover;
    color=Color ( 1.,1.,1.,0.5 );
}

IHM::PolycodeGUI::Board::~Board() {
}

void IHM::PolycodeGUI::Board::addCard ( ICard* card, int pos ) {
   /* if ( typeid ( card ) !=typeid ( Card ) ) {
        throw std::invalid_argument ( "This card is incompatible with this UI" );
    }*/
    Card* realCard = (Card*) card;
    if ( cards.size() >=size && size!=0 ) {
        throw std::length_error ( "Board is full" );
    }

    if ( stacked ) {
        realCard->moveTo ( position+Vector3 ( 0,-0.1,0 ) );
        if ( cards.size() !=0 ) {
            Card* last=cards.back();
            last->moveTo ( position+Vector3 ( 0,-Card::CARD_THICK/2,0 ),false );
        }
        cards.push_back ( realCard );
    } else {
        int index = pos;

        //std::cout<<"new :"<<index<<std::endl;

        index=index>cards.size() ?cards.size() :index;
        index=index<0?0:index;


        realCard->moveTo ( position+Vector3 ( ( ( int ) ( index-round ( size/2 ) ) ) * ( Card::CARD_WIDTH+0.8 ),0,0 ) );

        for ( int i=0; i<index; i++ ) {
            Card* current=cards[i];
            current->moveTo ( position+Vector3 ( ( ( int ) ( i-round ( size/2 ) ) ) * ( Card::CARD_WIDTH+0.8 ),0,0 ),false );
        }
        for ( int i=index; i<cards.size(); i++ ) {
            Card* current=cards[i];
            current->moveTo ( position+Vector3 ( ( ( int ) ( ( i+1 )-round ( size/2 ) ) ) * ( Card::CARD_WIDTH+0.8 ),0,0 ),false );
        }
        cards.insert ( cards.begin() +index, realCard );
    }

    if ( hidden ) {
        realCard->hide();
    } else {
        realCard->show();
    }

    if ( minified ) {
        realCard->minify();
    } else {
        realCard->maximize();
    }
}

void IHM::PolycodeGUI::Board::addCard ( std::list< IHM::ICard* > cards, int pos ) {
    for(std::list<IHM::ICard*>::iterator i = cards.begin(), e=cards.end(); i!=e; ++i)
    {
        addCard ( *i,pos );
    }
}

void IHM::PolycodeGUI::Board::deleteCard ( int index ) {
    if ( index>=cards.size() ) {
        throw std::out_of_range ( "Out of board" );
    }
    cards.erase ( cards.begin() +index );
    if ( stacked && index==cards.size() && index!=0 ) {
        Card* last=cards.back();
        last->moveTo ( position+Vector3 ( 0,-0.1,0 ),false );
    }

    if ( !stacked )
        for ( int i=0; i<cards.size(); i++ ) {
            Card* current=cards[i];
            current->moveTo ( position+Vector3 ( ( ( int ) ( i-round ( size/2 ) ) ) * ( Card::CARD_WIDTH+0.8 ),0,0 ),false );
        }
}

IHM::ICard* IHM::PolycodeGUI::Board::operator[] ( int i ) {
    if ( i>=cards.size() ) {
        throw std::out_of_range ( "Out of board" );
    }
    return (ICard*) cards[i];
}

int IHM::PolycodeGUI::Board::getPlace ( Vector3 pos ) {
    if ( stacked ) {
        return cards.size()-1;
    }
    int index = round ( size/2 ) +round ( ( pos.x-position.x ) / ( Card::CARD_WIDTH+0.8 ) );
    //std::cout<<"old : "<<index<<std::endl;
    index=index>=cards.size() ?cards.size()-1:index;
    index=index<0?0:index;
    //std::cout<<index<<std::endl;
    return index;
}

bool IHM::PolycodeGUI::Board::getHoverable() {
    return hoverable;
}


