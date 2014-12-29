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

float Effect::costVal(iCard *card = NULL){

	if(card == NULL)
		return (float)value/2.0;


	if((Card*)card->getType == "beast"){

		if(type == "hpMax")
			return (float)value/2.5;

		if(type == "attack")
			return (float)value/2.5;
		
		if(type == "attackCountMax"){
			float attack = (iBeast*)card->getBaseAttack();
			float life = (iBeast*)card->getHp();

			return ((value*value-1)*(attack+(life-1)))/7.5;
		}

	}

	if((Card*)card->getType == "spell"){

		if(type == "damage")
			return 1.0+(value*value)/10.0;

	}

}