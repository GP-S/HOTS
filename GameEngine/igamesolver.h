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

#ifndef IGAMESOLVER_H
#define IGAMESOLVER_H
namespace Engine{
  class IGameSolver {
  public:
    
      static constexpr int PLAYER1_BOARD = 1;
      static constexpr int PLAYER1_DECK = 2;
      static constexpr int PLAYER1_HAND = 3;
      static constexpr int PLAYER1_CIMETERY = 4;
      static constexpr int PLAYER1_EQUIPMENT = 5;
      static constexpr int PLAYER1_TRAP = 6;
      static constexpr int PLAYER1_HERO = 7;
      static constexpr int PLAYER2_BOARD = 8;
      static constexpr int PLAYER2_DECK = 9;
      static constexpr int PLAYER2_HAND = 10;
      static constexpr int PLAYER2_CIMETERY = 11;
      static constexpr int PLAYER2_EQUIPMENT = 12;
      static constexpr int PLAYER2_TRAP = 13;
      static constexpr int PLAYER2_HERO = 14;
      //static constexpr int justInCase = 15; //unused
      //static constexpr int justInCase2 = 16; //unused
    
    /** This method allows a player to move a card
    * @param int originBoard The identifier of the board where the card making 
    *   	the action is
    * @param int originPosition The position of the origin card in the board
    * @param int destinationBoard The id of the destination board
    * @param int destinationPosition The position of the action destination in 
    * 	the board
    * */
    virtual void useCard(int originBoard, int originPosition, int 
  destinationBoard, int destinationPosition) =0;
    
    /** Ends the player's turn **/
    virtual void endTurn(void)=0;
    

  };
}
#endif // IGAMESOLVER_H
