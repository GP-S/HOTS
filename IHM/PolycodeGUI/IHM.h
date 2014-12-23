#ifndef POLYCODEGUI_IHM_H
#define POLYCODEGUI_IHM_H

#include <iostream>
#include <typeinfo>

#include <Polycode.h>
#include "PolycodeView.h"
#include "Polycode3DPhysics.h"

#include "../iihm.h"
#include "card.h"
#include "board.h"

using namespace Polycode;
namespace IHM
{
namespace PolycodeGUI
{

class IHM : public EventHandler, public IIHM
{
public:
    IHM ( PolycodeView *view );
    ~IHM();
    bool Update();
    void handleEvent ( Event *event );
    virtual ICard* createCard ( std::string title, int cost, int attack, int defense, std::string description, int imageId );
    virtual ICard* createCard();
    virtual IBoard* getBoard ( int numBoard, int numPlayer );



protected:
    Core *core;
    SceneEntity *lastEntity, *selected;
    Vector3 offset, test;
    ScenePrimitive *box2;
    CollisionScene *scene;
    Card* hovered;

    Board* p0Stock;
    Board* p0Hand;
    Board* p0Graveyard;
    Board* p0Battlefield;

    Board* p1Stock;
    Board* p1Hand;
    Board* p1Graveyard;
    Board* p1Battlefield;

private:
    void initBoard();
    void createLights();
};

}
}

#endif POLYCODEGUI_IHM_H