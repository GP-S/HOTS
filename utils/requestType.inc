namespace Network {
  //Request from player to GE
  constexpr int PLAYON=10;
  constexpr int ENDTURN=11;

  //Request from GE to player fo card
  constexpr int SETTITLE=20;
  constexpr int SETTYPE=21;
  constexpr int SETDESCRIP=22; //FIXME CRADE
  constexpr int SETCAPA=23;
  
  //FIXME CRADE
  constexpr int SETATTACK=24;
  constexpr int SETCOST=25;
  constexpr int SETDEFENSE=26;
  
  constexpr int SETIMAGEID=27;
  
  constexpr int CREATE=29;

  //Request from GE to player for Board
  constexpr int ADDCARD=30;
  constexpr int REMOVECARD=31;
  constexpr int SETNBCARD=32;
  constexpr int MOVECARD=33;
  
  //Request from GE to player
  constexpr int SETSHARD=40;
  constexpr int SETMAXSHARD=41;
  
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
    int incomingReference;
    int attack;
    int defense;
    int cost;
    char title[20];
    char description[255];
    int imageID;
  } CreateCardStructType;
  
  typedef struct CreateCardAnswerStruct {
    int serverRef;
    int clientRef;
  } CreateCardAnswerStructType;
  
  typedef struct SetNumericalAttributeStruct {
    void* card;
    int newVal;
  } SetNumericalAttributeStructType;
  
}