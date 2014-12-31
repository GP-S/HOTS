/*
This file is not updated, it doesn't work.
It use an old version of GameEngine

*/


#include "GameEngine_Test.h"

static unsigned int etape = 0;

void printEtape(std::string text){
	std::cout << std::endl;
	etape++;
	std::cout << "***etape: " << etape << text << " *** " << std::endl;
}

/*class GameEngine : public ISimulatorFactory, public IGameSolver {
  public:
      GameEngine();
      GameEngine ( const GameEngine& other );
      ~GameEngine();
      GameEngine& operator= ( const GameEngine& other );
      bool operator== ( const GameEngine& other ) const;
      IGameSimulator& getSimulator ( void );
      void useCard ( int originBoard, int originPosition, 
                      int destinationBoard, int destinationPosition );//done .
      void endTurn ( void );
      //isLegit()
    
  protected:
      Match<iCard,IHM::ICard>* matchCard;
      Match<iBoard,IHM::IBoard>* matchBoard;
      std::list<iCard*>* listCardsProccedWhenAttacked; //when I get attacked 
      std::list<iCard*>* listCardsProccedWhenHurt; // when I get hurt
      std::list<iCard*>* listCardsProccedWhenHealed; // when I get healed
      std::list<iCard*>* listCardsProccedWhenSpawned; // when I spawn
      std::list<iCard*>* listCardsProccedWhenDied; // when I die 
      std::list<iCard*>* listCardsProccedWhenAttacking; // when I attack
      std::list<iCard*>* listCardsProccedWhenHurting; // when I hurt
      std::list<iCard*>* listCardsProccedWhenHealing; // when I heal
      std::list<iCard*>* listCardsProccedWhenSpawn; // when something else spawn
      std::list<iCard*>* listCardsProccedWhenKilling; // when I kill
      std::list<iCard*>* listCardsProccedWhenSomethingHealed;// when something else gets healed
      std::list<iCard*>* listCardsProccedWhenSomethingAttacks; // when something else attacks
      std::list<iCard*>* listCardsProccedWhenSomethingDies; // when something else dies
      std::list<iCard*>* listCardsProccedWhenSomethingHurt; // when something else gets hurt
      std::list<iCard*>* listCardsProccedWhenTurnBegins; // when turn begins
      std::list<iCard*>* listCardsProccedWhenTurnEnds; // when turn ends
      std::list<iBoard*> *boards;
      std::list<Player*> *players;
      IHM::IIHM *ihm;
      IA *ia;
      unsigned int turn;

  private:
      void procEffectByType(int type);
      void playBeast(int idOriginBoard,int idDestinationBoard,iBeast* playedCard,int originPosition, int destinationPosition);
      void playSpell(int idOriginBoard,int idDestinationBoard,iCard* playedCard,int originPosition, int destinationPosition);
      void beastAttackBeast(int idOriginBoard,int idDestinationBoard,iBeast* playedCard,int originPosition, int destinationPosition);
      void beastAttackHero(int idOriginBoard,int idDestinationBoard,iBeast* playedCard,int originPosition, int destinationPosition);
      void playerDraws(int playerNumber,int cardsDrawn);
      void beginTurn(); 
      void shuffleDeck(int playerNumber);//heavy tests for this please .
  };*/

/*==================================================================================*/
/*===================================MAIN===========================================*/
/*==================================================================================*/

int main(int argc, char **argv){


/*=================================etape  1=========================================*/
/**/
	printEtape("Instanciation of GameEngine");
	GameEngine *gameengine;

	gameengine = (GameEngine*)malloc(sizeof(GameEngine));


/*=================================etape  6=========================================*/

//destructor
//~Effect();
//~Capacity();


/*=================================etape  7=========================================*/

	printEtape("End of the effect test, all tests well done");
	return 0;
}
