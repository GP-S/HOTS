#include "Effect.h"



Effect::Effect(){


}

Effect::Effect(std::string type,std::string affinity,int value){//complete this

	this->type=type;
	this->affinity=affinity;
	this->value=value;

}


Effect::~Effect(){


}

std::string Effect::getType(){

	return type;

}
std::string Effect::getAffinity(){

	return affinity;

}
int Effect::getValue(){

	return value;

}

void Effect::setType(std::string type){

	this->type=type;
}

void Effect::setAffinity(std::string affinity){

	this->affinity=affinity;
}

void Effect::setValue(int value){

	this->value=value;

}