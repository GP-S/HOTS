#include "Effect_Test.h"

#define NUMBER 6

static unsigned int etape = 0;
static const std::string effectTypes[NUMBER] = {"attackCount","attackCountMax","attack","damage","hp","hpMax"};


void printEtape(std::string text){
	std::cout << std::endl;
	etape++;
	std::cout << "***etape: " << etape << text << " *** " << std::endl;
}

void printEffect(Effect *effect,unsigned int max){

	std::cout << "Effect: " << std::endl;
	for(size_t i = 0; i < max; i++){

		if(max != 1)
			std::cout <<	" effect[" << i << "] = ";
		
		std::cout <<	" type: " << effect[i].getType();
		std::cout <<	" affinity: " << effect[i].getAffinity();
		std::cout <<	" value: " << effect[i].getValue();		
		std::cout <<	" cost value: " << effect[i].costVal() << std::endl;
	} 
}


void printCapacity(Capacity *capacity,unsigned int max){

	std::cout << "Capacity: " << std::endl;
	for(size_t i = 0; i < max; i++){

		if(max != 1)
			std::cout <<	" capacity[" << i << "] = ";
		
		std::cout <<	" type: " << capacity[i].getType();

		if(capacity[i].getDurabilty() == -1)
			std::cout <<	" durabilty: infinity";
		else
			std::cout <<	" durabilty: " << capacity[i].getDurabilty();

		std::cout <<	" active: " << capacity[i].getActive() << std::endl;
	} 
}

/*==================================================================================*/
/*===================================MAIN===========================================*/
/*==================================================================================*/

int main(int argc, char **argv){


/*=================================etape  1=========================================*/
/*I instance some effects and capacities*/
	printEtape("Instanciation of effects and capacities");
	// Effect *effect;
	// Capacity *capacity;

	Effect *effect = new Effect();
	Capacity *capacity = new Capacity();

//	effect = (Effect*)malloc(NUMBER*sizeof(Effect));
//	capacity = (Capacity*)malloc(NUMBER*sizeof(Capacity));
	

/*=================================etape  2=========================================*/
/*I initialise all effects and capacities*/
	printEtape("Intialisation of effects and capacities");

	effect->setType(effectTypes[0]);
	effect->setAffinity("none");
	effect->setValue(0);

	printEffect(effect,1);

	// for(size_t i = 0; i < NUMBER; i++){
	// 	effect[i].setType(effectTypes[i]);
	// 	effect[i].setAffinity("nome");
	// 	effect[i].setValue(i);
	// }

	// printEffect(effect,NUMBER);

	// for(size_t i = 0; i < NUMBER; i++){

	// 	capacity[i].setType(effectTypes[i]);
	// 	if(i%2)
	// 		capacity[i].setActive(true);
	// 	else
	// 		capacity[i].setActive(false);

	// 	if(i<NUMBER/2)
	// 		capacity[i].setDurabilty(-1);
	// 	else
	// 		capacity[i].setDurabilty(i);

	// 	capacity[i].setEffect(&effect[i]);
	// }

	// printCapacity(capacity,NUMBER);

/*=================================etape  3=========================================*/
/*I try to get the effect of all capacity*/
	printEtape("Get the effect of capacity");

	for(size_t i = 0; i < NUMBER; i++)
		printEffect(capacity[i].getEffect(),NUMBER);


/*=================================etape  4=========================================*/
/*I create one more effect and capacity with the other constructor*/
	printEtape("Create effect and capacity with the other constructor");

	Effect *anotherEffect = new Effect("another type","another affinity",0);
	Capacity *anotherCapacity = new Capacity("something like a type",0);

	printEffect(anotherEffect,1);
	printCapacity(anotherCapacity,1);

/*=================================etape  5=========================================*/
/*I decrease all the durability of all capacity by one*/
	printEtape("Decrease the durability of capacity");

	std::cout << "before: " << std::endl;
	printCapacity(capacity,NUMBER);

	for(size_t i = 0; i < NUMBER; i++)
		capacity[i].decreaseDurability();

	std::cout << "after: " << std::endl;
	printCapacity(capacity,NUMBER);

/*=================================etape  6=========================================*/

//destructor
//~Effect();
//~Capacity();


/*=================================etape  7=========================================*/

	printEtape("End of the effect test, all tests well done");
	return 0;
}
