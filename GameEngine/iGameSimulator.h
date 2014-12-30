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
#ifndef IGAMESIMULATOR_H
#define IGAMESIMULATOR_H

#include "iGameSolver.h"
namespace Engine{
  class iGameSimulator : public iGameSolver
  {
  public:
    /** Reset the state of the simulator to its creation's state **/
    virtual void resetState()=0;
  };
}

#endif //IGAMESIMULATOR_H