#include "Capacity.h" 


Capacity::Capacity()
{

}

Capacity::Capacity(std::string type,int durabilty)
{
    this->type=type;
    this->durabilty=durabilty;
}


Capacity::~Capacity()
{

}


std::string	Capacity::getType()
{
    return type;
}

int	Capacity::getDurabilty()
{
    return durabilty;
}

void Capacity::setType(std::string type)
{
    this->type=type;
}

void Capacity::setDurabilty(int durabilty)
{
    this->durabilty = durabilty;
}

void Capacity::setActive(bool active)
{
    this->active=active;
}

bool Capacity::getActive()
{
    return active;
}

void Capacity::decreaseDurability(){

    if(durabilty != -1)
	   durabilty--;
}



Effect* Capacity::getEffect(){

	return effect;
}

void Capacity::setEffect(Effect* effect){

	this->effect=effect;
}