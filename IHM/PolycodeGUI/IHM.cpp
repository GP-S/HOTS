#include "IHM.h"


IHM::PolycodeGUI::IHM::IHM ( PolycodeView *view ) {

    core = new POLYCODE_CORE ( view, 1920,1080,false,true,0,0,90, 0, true );

    CoreServices::getInstance()->getResourceManager()->addArchive ( "Resources/default.pak" );
    CoreServices::getInstance()->getResourceManager()->addDirResource ( "default", false );
    CoreServices::getInstance()->getResourceManager()->addDirResource ( "Resources", false );

    scene = new CollisionScene();
    scene->doVisibilityChecking ( true );

    ScenePrimitive *ground = new ScenePrimitive ( ScenePrimitive::TYPE_PLANE, 192,108 );
    ground->setMaterialByName ( "GroundMaterial" );
    scene->addEntity ( ground );

    initBoard();


    for ( int i =0; i<10; i++ ) {
        Card *card = new Card();
        scene->addCollisionChild ( card );
        p0Stock->addCard ( card,Vector3 ( 0,0,0 ) );
        card->setTitle ( "Card "+std::to_string ( i ) );
    }

    for ( int i =10; i<15; i++ ) {
        Card *card = new Card();
        scene->addCollisionChild ( card );
        p0Hand->addCard ( card,Vector3 ( 0,0,0 ) );
        card->setTitle ( "Card "+std::to_string ( i ) );
    }



    createLights();


    scene->getDefaultCamera()->setPosition ( 0,130,1 );
    scene->getDefaultCamera()->lookAt ( Vector3 ( 0,0,0 ) );

    core->getInput()->addEventListener ( this, InputEvent::EVENT_MOUSEMOVE );
    core->getInput()->addEventListener ( this, InputEvent::EVENT_MOUSEDOWN );
    lastEntity = NULL;
}

IHM::PolycodeGUI::IHM::~IHM() {


}

void IHM::PolycodeGUI::IHM::handleEvent ( Event *e ) {
    if ( e->getDispatcher() == core->getInput() ) {
        InputEvent *inputEvent = ( InputEvent* ) e;
        Ray ray = scene->projectRayFromCameraAndViewportCoordinate ( scene->getActiveCamera(), inputEvent->mousePosition );
        RayTestResult res = scene->getFirstEntityInRay ( ray.origin, ray.direction * 10000.0 );
        switch ( e->getEventCode() ) {
        case InputEvent::EVENT_MOUSEMOVE:
            if ( res.entity ) {
                if ( typeid ( *res.entity ) ==typeid ( Board ) ) {
                    if ( ( ( Board* ) res.entity )->getHoverable() ) {
                        try {
                            int index= ( ( Board* ) res.entity )->getPlace ( res.position );
                            if ( hovered )
                                if ( hovered!= ( * ( Board* ) res.entity ) [index] )
                                    try {
                                        hovered->unhover();
                                    } catch ( const std::exception& e ) {
                                        //std::cout<<e.what()<<std::endl;
                                        return;
                                    }
                            hovered= ( * ( Board* ) res.entity ) [index];
                            try {
                                hovered->hover();
                            } catch ( const std::runtime_error& e ) {
                                //hovered=nullptr;
                            }
                        } catch ( const std::out_of_range& e ) {}
                    } else if ( hovered ) {
                        try {
                            hovered->unhover();
                        } catch ( const std::runtime_error& e ) {
                            //std::cout<<e.what()<<std::endl;
                            return;
                        }
                        hovered=nullptr;
                    }
                } else if ( res.entity!=hovered && hovered ) {
                    try {
                        hovered->unhover();
                    } catch ( const std::runtime_error& e ) {
                        //std::cout<<e.what()<<std::endl;
                        return;
                    }
                    hovered=nullptr;
                }
            } else if ( hovered ) {
                try {
                    hovered->unhover();
                } catch ( const std::runtime_error& e ) {
                    //std::cout<<e.what()<<std::endl;
                    return;
                }
                hovered=nullptr;
            }
            break;

        case InputEvent::EVENT_MOUSEDOWN:

            if ( res.entity ) {
                if ( typeid ( *res.entity ) ==typeid ( Board ) ) {
                    if ( selected==NULL ) {
                        int index= ( ( Board* ) res.entity )->getPlace ( res.position );
                        selected= ( * ( Board* ) res.entity ) [index];
                        ( ( Board* ) res.entity )->deleteCard ( index );
                    } else {
                        ( ( Board* ) res.entity )->addCard ( ( Card* ) selected,res.position );
                        selected=NULL;
                    }

                }
            }

            break;
        }
    }
}

bool IHM::PolycodeGUI::IHM::Update() {

    return core->updateAndRender();
}

IHM::ICard* IHM::PolycodeGUI::IHM::createCard() {
    return new Card();
}

IHM::ICard* IHM::PolycodeGUI::IHM::createCard ( std::string title, int cost, int attack, int defense, std::string description, int imageId ) {
    return new Card ( title,cost,attack,defense,description,imageId );
}

IHM::IBoard* IHM::PolycodeGUI::IHM::getBoard ( int numBoard, int numPlayer ) {
    switch ( numBoard ) {
    case IIHM::STOCK:
        return numPlayer==0?p0Stock:p1Stock;
    case IIHM::HAND:
        return numPlayer==0?p0Hand:p1Hand;
    case IIHM::GRAVEYARD:
        return numPlayer==0?p0Graveyard:p1Graveyard;
    case IIHM::BATTLEGROUND:
        return numPlayer==0?p0Battlefield:p1Battlefield;
    default:
        throw std::invalid_argument ( "No matching board" );
    }
}

void IHM::PolycodeGUI::IHM::initBoard() {
    p0Stock = new Board();
    p0Stock->setPosition ( - ( ground->getPrimitiveParameter1() /2-Card::CARD_WIDTH/2-10 ),
                           Card::CARD_THICK/2+10,
                           ground->getPrimitiveParameter2() /2-2-Card::CARD_HEIGHT/2 );
    scene->addCollisionChild ( p0Stock,CollisionEntity::SHAPE_MESH );

    p0Graveyard = new Board ( 0,false,false,false );
    p0Graveyard->setPosition ( ( ground->getPrimitiveParameter1() /2-Card::CARD_WIDTH/2-10 ),
                               Card::CARD_THICK/2+10,
                               ground->getPrimitiveParameter2() /2-2-Card::CARD_HEIGHT/2 );
    scene->addCollisionChild ( p0Graveyard,CollisionEntity::SHAPE_MESH );

    p0Hand = new Board ( 7,false,false,true );
    p0Hand->setPosition ( 0,Card::CARD_THICK/2+10,ground->getPrimitiveParameter2() /2-7 );
    scene->addCollisionChild ( p0Hand,CollisionEntity::SHAPE_BOX );

    p0Battlefield = new Board ( 5,false,true,false );
    p0Battlefield->setPosition ( 0,Card::CARD_THICK/2+10,10 );
    scene->addCollisionChild ( p0Battlefield,CollisionEntity::SHAPE_MESH );

    p1Stock = new Board();
    p1Stock->setPosition ( ( ground->getPrimitiveParameter1() /2-Card::CARD_WIDTH/2-10 ),
                           Card::CARD_THICK/2+10,
                           - ( ground->getPrimitiveParameter2() /2-2-Card::CARD_HEIGHT/2 ) );
    scene->addCollisionChild ( p1Stock,CollisionEntity::SHAPE_MESH );

    p1Graveyard = new Board ( 0,false,false,false );
    p1Graveyard->setPosition ( - ( ground->getPrimitiveParameter1() /2-Card::CARD_WIDTH/2-10 ),
                               Card::CARD_THICK/2+10,
                               - ( ground->getPrimitiveParameter2() /2-2-Card::CARD_HEIGHT/2 ) );
    scene->addCollisionChild ( p1Graveyard,CollisionEntity::SHAPE_MESH );

    p1Hand = new Board ( 7,true,false,false );
    p1Hand->setPosition ( 0,Card::CARD_THICK/2+10,- ( ground->getPrimitiveParameter2() /2-7 ) );
    scene->addCollisionChild ( p1Hand,CollisionEntity::SHAPE_BOX );

    p1Battlefield = new Board ( 5,false,true,false );
    p1Battlefield->setPosition ( 0,Card::CARD_THICK/2+10,-10 );
    scene->addCollisionChild ( p1Battlefield,CollisionEntity::SHAPE_MESH );
}

void IHM::PolycodeGUI::IHM::createLights() {
    Entity *lights = new Entity();

    scene->addChild ( lights );

    SceneLight *light = new SceneLight ( SceneLight::SPOT_LIGHT, scene, 4000 );
    light->setPosition ( 10,120,0 );
    light->setLightColor ( 1,1,1 );
    scene->addLight ( light );
    lights->addChild ( light );
    light->lookAt ( Vector3 ( 0,0,0 ) );
    light->setScale ( 2,3,2 );
    light->enableShadows ( true );
    light->getSpotlightCamera()->frustumCulling = false;

    SceneLight *light2 = new SceneLight ( SceneLight::POINT_LIGHT, scene, 15000 );
    light2->setPosition ( -200,200,0 );
    light2->setLightColor ( 1,1,1 );
    scene->addLight ( light2 );
    lights->addChild ( light2 );
    light2->lookAt ( Vector3 ( 0,80,0 ) );
    light2->enableShadows ( true );

    light2->getSpotlightCamera()->frustumCulling = false;

    SceneLight *light3 = new SceneLight ( SceneLight::POINT_LIGHT, scene, 15000 );
    light3->setPosition ( 200,200,0 );
    light3->setLightColor ( 1,1,1 );
    scene->addLight ( light3 );
    lights->addChild ( light3 );
    light3->lookAt ( Vector3 ( 0,80,0 ) );
    light3->enableShadows ( true );

    light3->getSpotlightCamera()->frustumCulling = false;
}
