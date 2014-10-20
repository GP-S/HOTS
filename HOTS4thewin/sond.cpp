#include "stdafx.h"
#include "sond.h"


sond::sond()
{
	output = 0;
}

sond::sond(float * input)
{
	this->input = input;
	output = 0;
}





sond::~sond()
{
}



float sond::get_output()
{
	output = *input;
	return output;
}
