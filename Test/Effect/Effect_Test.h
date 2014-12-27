#ifndef EFFECT_TEST_H
#define EFFECT_TEST_H

#include "../../Effect/Effect.h"
#include "../../Card/Capacity.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <string>

#include "../../utils/tool.inc"


void printEtape(std::string text);
void printEffect(Effect *effect,unsigned int max);
void printCapacity(Capacity *capacity,unsigned int max);

#endif //EFFECT_TEST_H