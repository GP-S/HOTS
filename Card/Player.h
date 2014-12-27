#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <list>
#include <iostream>


/** 
* Class Player . Naive implementation for tests purposes
* @author Armand
*
**/

class Player
{
		public :

			Player();
			Player(std::string name, int shards, int maxShards);
			~Player();
			std::string getName();
			int getShards();
			int getMaxShards();
			void setName(std::string name);
			void setShards(int shards);//shards cannot be over 10
			void setMaxShards(int maxShards);//maxShards cannot be over 10

		protected :

			std::string	name;
			int shards; ///WHY?
			int maxShards; ///MCA
};
#endif // PLAYER_H