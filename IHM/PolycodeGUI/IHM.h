#ifndef POLYCODEGUI_IHM_H
#define POLYCODEGUI_IHM_H

#include <iostream>
#include <typeinfo>

#include <Polycode.h>
#include "PolycodeView.h"
#include "PolycodeUI.h"
#include "Polycode3DPhysics.h"

#include "../iihm.h"
#include "card.h"
#include "board.h"
#include "iGameSolver.h"
#include <gameclient.h>

using namespace Polycode;
namespace IHM
{
namespace PolycodeGUI
{

class IHM : public EventHandler, public IIHM
{
public:
    IHM ( PolycodeView *view, std::string serverAddress, int serverPort);
    ~IHM();
    bool Update();
    void handleEvent ( Event *event );
    virtual ICard* createCard ( std::string title, int cost, int attack, int defense, std::string description, int imageId );
    virtual ICard* createCard();
    virtual IBoard* getBoard ( int numBoard);
    virtual void setMaxShards ( int playerNumber, int maxShards );
    virtual void setShards ( int playerNumber, int shards );

protected:
    // Core system
    Core *core;
    CollisionScene *scene;
    ScenePrimitive* ground;

    // Boards
    Board* p0Stock;
    Board* p0Hand;
    Board* p0Graveyard;
    Board* p0Battlefield;
    Board* p0Hero;

    Board* p1Stock;
    Board* p1Hand;
    Board* p1Graveyard;
    Board* p1Battlefield;
    Board* p1Hero;
    
    
    // Event Handling
    Card* hovered;
    SceneEntity *selected;
    int selectedBoard, selectedPos;
    
    // HUD
    UIButton* button;
    SceneLabel* p1Shards;
    SceneLabel* p0Shards;
    int p0MaxShards, p0CurentShards, p1MaxShards, p1CurentShards;
    
    // Network
    Network::GameClient* client;

private:
    void initBoard();
    void createLights();
    int getBoardNo(Board* board);
};

}
}

#endif //POLYCODEGUI_IHM_H