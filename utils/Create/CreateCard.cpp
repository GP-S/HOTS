#include "CreateCard.h"

#define nbeffecthero  7
#define nbeffectbeast 5
#define nbeffectspell 1

static const std::string nameeffecthero[nbeffecthero] =		{	"hp","hpMax","attack","attackCount",
																"attackCountMax","shards","shardsMax"
															};

static const std::string nameeffectbeast[nbeffectbeast] =	{	"hp","hpMax","attack","attackCount",
																"attackCountMax"
															};

static const std::string nameeffectspell[nbeffectspell] =	{	"damage"
															};


Beast* newBeast(std::string name,int hp,int attack,std::string race){

	Beast beast = new Beast(name,hp,attack,race);
	int value = 0;

	for(size_t i = 0; i < nbeffectbeast; i++){

		if(nameeffectbeast[i] == "hp" | nameeffectbeast[i] == "hpMax")
			value = hp;
		else if(nameeffectbeast[i] == "attack")
			value = attack;
		else if(nameeffectbeast[i] == "attackCountMax")
			value = 1;
		else
			value = 0;

		Effect *effect = new Effect(nameeffectbeast[i],"none",value);
		Capacity *capa = new Capacity(nameeffectbeast[i],-1);

		capa->setActive(true);
		capa->setEffect(effect);
		beast->addCapacity(capa);
	}
	beast->calculateCost();

	return beast;
}

Spell* newSpell(std::string name,int damage){

	Spell spell = new Spell(name,hp,attack,race);
	int value = 0;

	for(size_t i = 0; i < nbeffectspell; i++){

		if(nameeffectspell[i] == "damage")
			value = damage;
		else
			value = 0;

		Effect *effect = new Effect(nameeffectspell[i],"none",value);
		Capacity *capa = new Capacity(nameeffectspell[i],0);

		capa->setActive(true);
		capa->setEffect(effect);
		spell->addCapacity(capa);
	}
	spell->calculateCost();

	return spell;
}

Hero* newHero(std::string name,int hp){

	Hero* hero = new Hero(name,hp,0);
	int value = 0;

	for(size_t i = 0; i < nbeffecthero; i++){

		if(nameeffecthero[i] == "hp" | nameeffecthero[i] == "hpMax")
			value = hp;
		else
			value = 0;

		Effect *effect = new Effect(nameeffecthero[i],"none",value);
		Capacity *capa = new Capacity(nameeffecthero[i],-1);

		capa->setActive(true);
		capa->setEffect(effect);
		hero->addCapacity(capa);
	}
	return hero;
}

