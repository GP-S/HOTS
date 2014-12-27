#include "Player.h"

		
Player::Player(){


}
Player::Player(std::string name, int shards, int maxShards){

	this->name=name;
	this->shards=shards;
	this->maxShards=maxShards;
}
Player::~Player(){


}
std::string Player::getName(){

	return name;
}
int Player::getShards(){

	return shards;
}
int Player::getMaxShards(){

	return maxShards;
}
void Player::setName(std::string name){

	this->name=name;
}
void Player::setShards(int newShards){

	this->shards=newShards>10 ? 10 : newShards;
}
void Player::setMaxShards(int newMaxShards){

	this->maxShards=newMaxShards>10 ? 10 : newMaxShards;
}