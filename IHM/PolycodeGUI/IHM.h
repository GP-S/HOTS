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
#include "../../GameEngine/igamesolver.h"

using namespace Polycode;
namespace IHM
{
namespace PolycodeGUI
{

class IHM : public EventHandler, public IIHM
{
public:
    IHM ( PolycodeView *view, Engine::IGameSolver *solver );
    ~IHM();
    bool Update();
    void handleEvent ( Event *event );
    virtual ICard* createCard ( std::string title, int cost, int attack, int defense, std::string description, int imageId );
    virtual ICard* createCard();
    virtual IBoard* getBoard ( int numBoard, int numPlayer );
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
    
    // Game Engine Interface
    Engine::IGameSolver* solver;
    
    // Event Handling
    Card* hovered;
    SceneEntity *selected;
    int selectedBoard, selectedPos;
    int selectedPlayer;
    
    // HUD
    UIButton* button;
    SceneLabel* p1Shards;
    SceneLabel* p0Shards;
    int p0MaxShards, p0CurentShards, p1MaxShards, p1CurentShards;

private:
    void initBoard();
    void createLights();
    int getBoardNo(Board*);
    int getBoardPlayer(Board*);
};

}
}

#endif //POLYCODEGUI_IHM_H