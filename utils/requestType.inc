namespace Network {
  //Request from player to GE
  constexpr int PLAYON=10;
  constexpr int ENDTURN=11;

  //Request from GE to player fo card
  constexpr int SETTITLE=20;
  constexpr int SETTYPE=21;
  constexpr int SETDESCRIP=22;
  constexpr int SETCAPA=23;
  constexpr int CREATE=29;

  //Request from GE to player for Board
  constexpr int ADDCARD=30;
  constexpr int REMOVECARD=31;
  constexpr int SETNBCARD=32;
  constexpr int MOVECARD=33;
  
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
  
}