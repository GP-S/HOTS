#ifndef BOARD_TEST_H
#define BOARD_TEST_H

#include "../../Card/Card.h"
#include "../../Card/Spell.h"
#include "../../Card/Creature.h"
#include "../../Card/Beast.h"
#include "../../Card/Capacity.h"
#include "../../Card/Hero.h"
#include "../../Effect/Effect.h"
#include "../../Board/Board.h"
// #include "../../Board/RegulatedBoard.h"

#include "../../Card/iCard.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <string>


#include "../../utils/CreateDeck.h"

void printEtape(std::string text);
void printBoard(Board *board, std::string name);
// void printTimeBoard(RegulatedBoard *board, std::string name);
void printCard(Card *card);
void printListCard(std::list<Card*> *listCard);
void printSizeBoard(Board *board, std::string name);

#endif //BOARD_TEST_H
