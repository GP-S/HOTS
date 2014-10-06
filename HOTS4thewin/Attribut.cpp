#include "stdafx.h"
#include "Attribut.h"

Attribut::Attribut()
{
    //ctor
}

Attribut::Attribut(Ttype typ, int vale, char dure){
	type = typ;
	val = vale;
	duree = dure;
}

Attribut::~Attribut()
{
    //dtor
}

void Attribut::setType(Ttype inType){
    type = inType;
}

Ttype Attribut::getType(){
    return type;
}

void Attribut::setVal(int inVal){
    val = inVal;
}

int Attribut::getVal(){
    return val;
}

void Attribut::setDuree(char inDuree){
    duree = inDuree;
}

char Attribut::getDuree(){
    return duree;
}

void Attribut::setSuiv(Attribut * suiv){
	attSuiv = suiv;
}

Attribut * Attribut::suiv(){
	return attSuiv;
}