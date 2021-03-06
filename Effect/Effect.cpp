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

float Effect::costVal(iCard *card){

	if(card == NULL)
		return (float)value/2.0;
	
	if(type == "attack" | type == "hpMax")
		return (float)value/2.5;

	if(type == "damage")
		return 1+(0.9*value*value*value)/(10*value+1);

	else
		return 0.0;

}