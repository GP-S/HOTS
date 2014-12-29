
#include "requestType.inc"

//ces méthode sont a planter coté client ou serveur le send data semble etre surchargé diff en fonction de la classe à la quel il appartient il y a aussi un send reliable data

//Player->GE
void playOnRequest(int boardOrigin, int cardOrigine, int boardArr, int placeArr){
 char data[4] = {(char)boardOrigin, (char)cardOrigine, (char)boardArr, (char)placeArr}; 
 sendData(char* ServerAddress, data, sizeof(data), PLAYON);
}

void endTurnRequest(){
  sendData(char* ServerAddress, "0", sizeof("0"), ENDTURN);
}

//GE->PLayer for card
void setTitle(char* title){
  sendData(CLIENt* cli, title, sizeof(char[20]), SETTITLE);
}

void setType(char* title){
  sendData(CLIENt* cli, title, sizeof(char[20]), SETTITLE);
}

void setDescrip(char * Descript){
  sendData(CLIENt* cli, Descript, sizeof(char[100]), SETDESCRIPT);
}

void create(iCard* card){//a mettre dans un factory? on cré une carte client avec un num unique qu'on posera plus tard dans un board
  char idnumber[4] = {(char)card>>24, (char)card>>16, (char)card >> 8, (char) card};
  sendData(char* ServerAddress, idnumber, sizeof(idnumber), CREATE);
}

void setCapacity(char* type, int durability, bool isActive,placeMask, timeMask ,int effectVal){
  char * durab = {(char)durability>>24, (char)durability>>16,
    (char)durability >> 8, (char) durability};//oChoa soit bourrin comme ça soit convertion en string mais penser au signe -
  char  pMask[2] = { (char)placeMask >> 8, (char) placeMask};
  char * effectV = std::to_string(effectVal);//oChoa soit convertion en string mais penser au signe soit bourrin

  char * mess = type+durab+(char)isActive+pMask+tMask+effectV;
  sendData(CLIENt* cli, mess, sizeof(mess), SETCAPA);
}

void moveCard(int boardOrigin, int cardOrigine, int boardArr, int placeArr){
 char data[4] = {(char)boardOrigin, (char)cardOrigine, (char)boardArr, (char)placeArr}; 
 sendData(char* ServerAddress, data, sizeof(data), MOVECARD);
}

void addCard( int cardid, int boardArr, int placeArr){ 
 char data[6] = {(char)cardid>>24, (char)cardid>>16, (char)cardid>>8, (char)cardid, (char)boardArr, (char)placeArr}; 
 sendData(char* ServerAddress, data, sizeof(data), ADDCARD);
}

void removeCard( int boardOrigin, int cardOrigine){
 char data[4] = {(char)boardOrigin, (char)cardOrigine )};
 sendData(CLIENt* cli, data, sizeof(data), ADDCARD);
}

void setNbCard( int nb){//les joueurs on besoin de connaitre le nb de carte dans chaque deck
   sendData(CLIENt* cli, std::to_string(nb), sizeof(std::to_string(nb)), SETNBCARD);
}
