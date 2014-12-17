#infdef USEFULSTRUC_INC
#def USEFULSTRUC_INC

/**
* Some struct used by target, GE and IA
* @author Thibault
*/

#define allPlace 0xFFFF
#define allennemiPlace 0x7F

typedef struct
{
    unsigned short 
        ennemi_board : 1,
        ennemi_deck : 1,
        ennemi_hand : 1,
        ennemi_cimetery : 1,
        ennemi_equipment : 1,
		ennemi_trap : 1,
		ennemi_Hero : 1,
		justInCase : 1, //unused
		owner_board : 1,
        owner_deck : 1,
        owner_hand : 1,
        owner_cimetery : 1,
        owner_equipment : 1,
		owner_trap : 1,
		owner_Hero : 1,
		justInCase2 : 1; //unused

}placeMask;

typedef struct
{
    unsigned short 
        when_attacked : 1, //when I get attacked 
        when_hurt : 1, // when I get hurt
        when_healed : 1, // when I get healed
        when_spawned : 1, // when I spawn
        when_died : 1, // when I die 
		while_attacking : 1, // when I attack
        while_hurting : 1, // when I hurt
        while_healing : 1, // when I heal
        when_spawn : 1, // when something else spawn
        while_killing : 1, // when I kill
        when_something_attacks : 1, // when something else attacks
        when_something_dies : 1, // when something else dies
        when_something_healed : 1,// when something else gets healed
        when_something_hurt : 1, // when something else gets hurt
		andmuchmore : 2;

}timeMask;


#endif //USEFULSTRUC_INC