#ifndef IASTRUCT_INC
#define IASTRUCT_INC

//---Shouldn't be there
#define MAXCARDINHAND 10
#define MAXCARDONBF 10
//---



typedef struct Descriptor{
	int isOrnOt; //one if the card exist
	int attack; //strengh
	int life;
	int lifeMax;
	int dommage; //that can deal whithout attacking
	int price;
} Descriptor;

typedef struct State {
	Descriptor playerHand[MAXCARDINHAND];
	Descriptor playerBattleField[MAXCARDONBF];
	Descriptor ennemyHand[MAXCARDINHAND];
	Descriptor ennemyBattleField[MAXCARDONBF];
} State;

typedef struct Action { //=playOnStruct maybe to delete
	int boardOrigin;
	int cardOrigin;
	int boardDestination;
	int cardDestination;
} Action;

typedef struct Movement{
	Action ToPlay;
	State FinalState;
} Movement;
#endif // !IASTRUCT_H
