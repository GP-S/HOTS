#include "stdafx.h"
#include "Personnage.h"

Personnage::Personnage()
{
	//ctor
}

Personnage::~Personnage()
{
    //dtor
}

bool Personnage::isAlive(){
	return 0;
}

void Personnage::setBoard(Board * Board, Ttype Type)
{
	switch (Type){
	case Board_hand :
		Hand = Board;
		break;
	case Board_pioche:
		Pioche = Board;
		break;
	case Board_Deck :
		Deck = Board;
		break;
	case Board_board:
		ZoneCombat = Board;
		break;
	default :
		cout << "Personnage::set_Board erreur de type \n";
		break;	

	}
}

Board * Personnage::getBoard(Ttype Type)
{
	switch (Type){
	case Board_hand:
		return Hand;
		break;
	case Board_pioche:
		return Pioche;
		break;
	case Board_Deck:
		return Deck;
		break;
	case Board_board:
		return ZoneCombat;
		break;
	default:
		cout << "Personnage::getBoard erreur de type \n";
		break;
	}
}