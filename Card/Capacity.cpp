#include "Capacity.h" 


Capacity::Capacity()
{

}

Capacity::Capacity(std::string type,int value)
{
    this.type=type;
    this.value=value;
}


Capacity::~Capacity()
{

}


std::string	Capacity::getType()
{
    return type;
}

int	Capacity::getValue()
{
    retun value;
}

void Capacity::setType(std::string type)
{
    this.type=type;
}

void Capacity::setValue(int value)
{
    this.value=value;
}

void Capacity::setActive(bool active)
{
    this.active=active;
}

bool Capacity::getActive()
{
    return active;
}