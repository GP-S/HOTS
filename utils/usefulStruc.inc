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
        when_attacked : 1,
        when_hurted : 1,
        when_healed : 1,
        when_spawned : 1,
        when_died : 1,
		while_attacking : 1,
        while_hurting : 1,
        while_healing : 1,
        while_spawning : 1,
        while_killing : 1,
		andmuchmore : 6;

}timeMask;


#endif //USEFULSTRUC_INC