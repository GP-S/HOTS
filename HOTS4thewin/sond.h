#pragma once
class sond
{
public:
	sond();
	sond(int * input);
	~sond();
	float sond::get_output();
	void sond::update();
private :
	int * input;
	int output;
};

