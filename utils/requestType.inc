#ifndef REQUEST_TYPE_INC
#define REQUEST_TYPE_INC

namespace Network {
  //Request from player to GE
  constexpr unsigned short PLAYON=10;
  constexpr unsigned short ENDTURN=11;

  //Request from GE to player fo card
  constexpr unsigned short SETTITLE=20;
  constexpr unsigned short SETTYPE=21;
  constexpr unsigned short SETDESCRIP=22; //FIXME CRADE
  constexpr unsigned short SETCAPA=23;
  
  //FIXME CRADE
  constexpr unsigned short SETATTACK=24;
  constexpr unsigned short SETCOST=25;
  constexpr unsigned short SETDEFENSE=26;
  
  constexpr unsigned short SETIMAGEID=27;
  
  constexpr unsigned short CREATE=29;

  //Request from GE to player for Board
  constexpr unsigned short ADDCARD=30;
  constexpr unsigned short REMOVECARD=31;
  constexpr unsigned short SETNBCARD=32;
  constexpr unsigned short MOVECARD=33;
  
  //Request from GE to player
  constexpr unsigned short SETSHARD=40;
  constexpr unsigned short SETMAXSHARD=41;
  
  // Simulation Requests
  constexpr unsigned short SIMULATECARD=50;
  constexpr unsigned short SIMULATIONEND=51;
  
  typedef struct PlayOnStruct {
    int boardOrigin;
    int cardOrigin;
    int boardDestination;
    int cardDestination;
  } PlayOnStructType;
  
  typedef struct SetTitleStruct {
    void* card;
    char title[20];
  } SetTitleStructType;
  
  typedef struct SetDescriptionStruct {
    void* card;
    char description[255];
  } SetDescriptionStructType;
  
  typedef struct AddCardStruct {
    void* card;
    int boardDestination;
    int cardDestination;
  } AddCardStructType;
  
  typedef struct RemoveCardStruct {
    int board;
    int position;
  } RemoveCardStructType;
  
  typedef struct MoveCardStruct {
    int boardOrigin;
    int cardOrigin;
    int boardDestination;
    int cardDestination;
  } MoveCardStructType;
  
  typedef struct SetShardStruct {
    int playerId;
    int shards;
  } SetShardStructType;
  
  typedef struct CreateCardStruct {
    void* incomingReference;
    int attack;
    int defense;
    int cost;
    char title[20];
    char description[255];
    int imageID;
  } CreateCardStructType;
  
  typedef struct CreateCardAnswerStruct {
    void* serverRef;
    void* clientRef;
  } CreateCardAnswerStructType;
  
  typedef struct SetNumericalAttributeStruct {
    void* card;
    int newVal;
  } SetNumericalAttributeStructType;
  
}

#endif // REQUEST_TYPE_INC