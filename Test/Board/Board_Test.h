#ifndef BOARD_TEST_H
#define BOARD_TEST_H

#include "../../Card.h"
#include "../../Board/Board.h"
#include "../../Board/RegulatedBoard.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <string>

#include "../../utils/tool.inc"

void printEtape(std::string text);
void printBoard(Board *board, std::string name);
void printCard(Card *card,unsigned int max);
void printSizeBoard(Board *board, std::string name);

#endif //BOARD_TEST_H
