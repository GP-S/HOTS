/*
 * HOTS a complex card game
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

#ifndef ISIMULATORFACTORY_H
#define ISIMULATORFACTORY_H

#include "iGameSimulator.h"

namespace Engine{
  class iSimulatorFactory
  {
  public:
    /** Creates a simulator with the curent state of the game **/
    virtual iGameSimulator* getSimulator(void)=0;

  };
}

#endif //ISIMULATORFACTORY_H