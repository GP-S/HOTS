#include "IHM.h"


IHM::PolycodeGUI::IHM::IHM ( PolycodeView* view, string serverAddress, int serverPort ) {

    core = new POLYCODE_CORE ( view, 1920,1080,false,true,0,0,90, 0, true );

    CoreServices::getInstance()->getResourceManager()->addArchive ( "Resources/default.pak" );
    CoreServices::getInstance()->getResourceManager()->addDirResource ( "default", false );
    CoreServices::getInstance()->getResourceManager()->addDirResource ( "Resources", false );
    
    CoreServices::getInstance()->getResourceManager()->addArchive ( "UIThemes.pak" );
    CoreServices::getInstance()->getConfig()->loadConfig("Polycode", "UIThemes/dark_retina/theme.xml");
    CoreServices::getInstance()->getResourceManager()->addDirResource("UIThemes/dark_retina/");
    
    scene = new CollisionScene();
    scene->doVisibilityChecking ( true );
    
    Scene *screen = new Scene(Scene::SCENE_2D_TOPLEFT);
       
    button = new UIButton("End of Turn",100,26);
    button->setScale(2,2);
    screen->addChild(button);
    button->setPosition(core->getXRes()-2*button->getWidth()-20,core->getYRes()/2-2*button->getHeight()/2);
    screen->rootEntity.processInputEvents = true;
    
    p1Shards = new SceneLabel("0/0", 17,"Script",Label::ANTIALIAS_FULL,1.6);
    p1Shards->setColorInt(255,255,255,255);
    p1Shards->setPosition(10,10);
    screen->addChild(p1Shards);
    
    p0Shards = new SceneLabel("0/0", 17,"Script",Label::ANTIALIAS_FULL,1.6);
    p0Shards->setColorInt(255,255,255,255);
    p0Shards->setPosition(core->getXRes()-2*p0Shards->getWidth()-10,core->getYRes()-2*p0Shards->getHeight()-10);
    screen->addChild(p0Shards);

    ground = new ScenePrimitive ( ScenePrimitive::TYPE_PLANE, 192,108 );
    ground->setMaterialByName ( "GroundMaterial" );
    scene->addEntity ( ground );

    initBoard();

    /*
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
    */



    createLights();


    scene->getDefaultCamera()->setPosition ( 0,130,1 );
    scene->getDefaultCamera()->lookAt ( Vector3 ( 0,0,0 ) );

    button->addEventListener(this, UIEvent::CLICK_EVENT);
    core->getInput()->addEventListener ( this, InputEvent::EVENT_MOUSEMOVE );
    core->getInput()->addEventListener ( this, InputEvent::EVENT_MOUSEDOWN );
    
    client = new Network::GameClient(serverAddress,serverPort,this);

}

IHM::PolycodeGUI::IHM::~IHM() {


}

void IHM::PolycodeGUI::IHM::handleEvent ( Event *e ) {
    if(e->getDispatcher() == button) {
      switch(e->getEventCode()){
	case UIEvent::CLICK_EVENT:
	  client->endTurnRequest();
	  break;
      }
    }
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
                            hovered= (Card*) ( * ( Board* ) res.entity ) [index];
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
                        selected= (SceneEntity*)( * ( Board* ) res.entity ) [index];
			selectedBoard=getBoardNo((Board*) res.entity);
			selectedPos=index;
                    } else {
			int index= ( ( Board* ) res.entity )->getPlace ( res.position );
			if(selectedBoard!=getBoardNo(( Board* ) res.entity)){
			  client->playOnRequest(selectedBoard,selectedPos,
					   getBoardNo(( Board* ) res.entity), index);
			}
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

IHM::IBoard* IHM::PolycodeGUI::IHM::getBoard ( int numBoard) {
    switch ( numBoard ) {
      case Engine::IGameSolver::PLAYER0_DECK :
        return p0Stock;
      case Engine::IGameSolver::PLAYER1_DECK :
	return p1Stock;
      case Engine::IGameSolver::PLAYER0_HAND :
        return p0Hand;
      case Engine::IGameSolver::PLAYER1_HAND :
	return p1Hand;
      case Engine::IGameSolver::PLAYER0_CIMETERY :
        return p0Graveyard;
      case Engine::IGameSolver::PLAYER1_CIMETERY :
	return p1Graveyard;
      case Engine::IGameSolver::PLAYER0_BOARD :
        return p0Battlefield;
      case Engine::IGameSolver::PLAYER1_BOARD :
	return p1Battlefield;
      case Engine::IGameSolver::PLAYER0_HERO :
        return p0Hero;
      case Engine::IGameSolver::PLAYER1_HERO :
	return p1Hero;
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
    
    p0Hero = new Board (1,false,true,false);
    p0Hero->setPosition( 0, Card::CARD_THICK/2+10, Card::CARD_HEIGHT/2+10+10);
    scene->addCollisionChild( p0Hero, CollisionEntity::SHAPE_MESH);
    

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
    
    p1Hero = new Board (1,false,true,false);
    p1Hero->setPosition( 0, Card::CARD_THICK/2+10, -(Card::CARD_HEIGHT/2+10+10));
    scene->addCollisionChild( p1Hero, CollisionEntity::SHAPE_MESH);
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

int IHM::PolycodeGUI::IHM::getBoardNo ( ::IHM::PolycodeGUI::Board* board ) {
  if(board==p0Battlefield)
    return Engine::IGameSolver::PLAYER0_BOARD;
  if(board==p0Graveyard)
    return Engine::IGameSolver::PLAYER0_CIMETERY;
  if(board==p0Hand)
    return Engine::IGameSolver::PLAYER0_HAND;
  if(board==p0Hero)
    return Engine::IGameSolver::PLAYER0_HERO;
  if(board==p0Stock)
    return Engine::IGameSolver::PLAYER0_DECK;
  if(board==p1Battlefield)
    return Engine::IGameSolver::PLAYER1_BOARD;
  if(board==p1Graveyard)
    return Engine::IGameSolver::PLAYER1_CIMETERY;
  if(board==p1Hand)
    return Engine::IGameSolver::PLAYER1_HAND;
  if(board==p1Hero)
    return Engine::IGameSolver::PLAYER1_HERO;
  if(board==p1Stock)
    return Engine::IGameSolver::PLAYER1_DECK;
}

void IHM::PolycodeGUI::IHM::setMaxShards ( int playerNumber, int maxShards ) {
  if(playerNumber==0){
    p0MaxShards=maxShards;
    p0Shards->setText(std::to_string(p0CurentShards) + "/" + std::to_string(p0MaxShards));
    p0Shards->setPosition(core->getXRes()-2*p0Shards->getWidth()-10,core->getYRes()-2*p0Shards->getHeight()-10);
  } else {
    p1MaxShards=maxShards;
    p1Shards->setText(std::to_string(p1CurentShards) + "/" + std::to_string(p1MaxShards));
    p1Shards->setPosition(10,10);
  }
  
}

void IHM::PolycodeGUI::IHM::setShards ( int playerNumber, int shards ) {
  if(playerNumber==0){
    p0CurentShards=shards;
    p0Shards->setText(std::to_string(p0CurentShards) + "/" + std::to_string(p0MaxShards));
    p0Shards->setPosition(core->getXRes()-2*p0Shards->getWidth()-10,core->getYRes()-2*p0Shards->getHeight()-10);
  } else {
    p1CurentShards=shards;
    p1Shards->setText(std::to_string(p1CurentShards) + "/" + std::to_string(p1MaxShards));
    p1Shards->setPosition(10,10);
  }
}


