#include "stdafx.h"
#include "Sort.h"

Sort::Sort()
{
    //ctor
}

Sort::~Sort()
{
    //dtor
}

Sort::Sort(string name){
	nom = name;
	type = Carte_sort;
	degat = 0;
}

bool Sort::isAlive(){
	return 0;
}

