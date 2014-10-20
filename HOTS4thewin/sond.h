#pragma once
class sond
{
public:
	sond();
	sond(float * input);
	~sond();
	float sond::get_output();
	void sond::update();
private :
	float * input;
	float output;
};

