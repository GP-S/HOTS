#include "Effect_Test.h"

#define NUMBER 6

static unsigned int etape = 0;
static const std::string effectTypes[NUMBER] = {"attackCount","attackCountMax","attack","damage","hp","hpMax"};


void printEtape(std::string text){
	std::cout << std::endl;
	etape++;
	std::cout << "***etape " << etape << text << " *** " << std::endl;
}

void printEffect(Effect *effect){

	std::cout << "Effect: " << std::endl;
		
	std::cout <<	" cost value: " << effect->costVal();
	std::cout <<	" affinity: " << effect->getAffinity();
	std::cout <<	" value: " << effect->getValue();		
	std::cout <<	" type: " << effect->getType() << std::endl;

}


void printCapacity(Capacity *capacity){

	std::cout << "Capacity: " << std::endl;

	std::cout <<	" active: " << capacity->getActive();	

	if(capacity->getDurabilty() == -1)
		std::cout <<	" durabilty: infinity";
	else
		std::cout <<	" durabilty: " << capacity->getDurabilty();

	std::cout <<	" type: " << capacity->getType(); << std::endl; 
}

/*==================================================================================*/
/*===================================MAIN===========================================*/
/*==================================================================================*/

int main(int argc, char **argv){


/*=================================etape  1=========================================*/
/*I instance some effects and capacities*/
	printEtape(": Instanciation of effects and capacities");

	Effect *effect = new Effect();
	Capacity *capacity = new Capacity();

	Effect *anotherEffect = new Effect("another type","another affinity",0);
	Capacity *anotherCapacity = new Capacity("something like a type",0);
	

/*=================================etape  2=========================================*/
/*I initialise all effects and capacities*/
	printEtape(": Intialisation of effects and capacities");

	for(size_t i = 0; i < NUMBER; i++){

		effect->setType(effectTypes[i]);
		effect->setAffinity("none");
		effect->setValue(i);

		printEffect(effect);
	}

	for(size_t i = 0; i < NUMBER; i++){

		capacity->setType(effectTypes[i]);
		if(i%2)
			capacity->setActive(true);
		else
			capacity->setActive(false);

		if(i<NUMBER/2)
			capacity->setDurabilty(-1);
		else
			capacity->setDurabilty(i);

		printCapacity(capacity);
	}

	capacity->setEffect(effect);
	anotherCapacity->setEffect(anotherEffect);

	printEffect(anotherEffect);
	printCapacity(anotherCapacity);

/*=================================etape  3=========================================*/
/*I try to get the effect of capacity*/
	printEtape(": Get the effect of capacity");

	printEffect(anotherCapacity->getEffect());
	printEffect(capacity->getEffect());

/*=================================etape  4=========================================*/
/*I decrease the durability of capacity by one*/
	printEtape(": Decrease the durability of capacity");

	capacity->decreaseDurability();
	anotherCapacity->decreaseDurability();

	printCapacity(capacity);
	printCapacity(anotherCapacity);

/*=================================etape  5=========================================*/
/*iEffect and iCapacity*/
	printEtape(": iEffect and iCapacity");




/*=================================etape  5=========================================*/

//destructor
//~Effect();
//~Capacity();


/*=================================etape  6=========================================*/

	printEtape(": End of the effect test, all tests well done");
	return 0;
}
