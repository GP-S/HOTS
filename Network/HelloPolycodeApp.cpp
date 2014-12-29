#include "HelloPolycodeApp.h"
#include <random>
#include <time.h>

HelloPolycodeApp::HelloPolycodeApp(PolycodeView *view) : EventHandler() {

   core = new POLYCODE_CORE(view, 640,480,false,true,0,0,90, 0, true);

   CoreServices::getInstance()->getResourceManager()->addArchive("Resources/default.pak");
   CoreServices::getInstance()->getResourceManager()->addDirResource("default", false);

   scene = new Scene(Scene::SCENE_2D);
   scene->getActiveCamera()->setOrthoSize(640,480);
   
   server = new Server(5554, 100);
   server->addEventListener(this, ServerEvent::EVENT_CLIENT_CONNECTED);
   server->addEventListener(this, ServerEvent::EVENT_CLIENT_DISCONNECTED);
   server->addEventListener(this, ServerEvent::EVENT_CLIENT_DATA);

   client = new Client(0, 1);
   client->Connect("127.0.0.1", 5554);
   client->sendData(Address("127.0.0.1", 5554), "Hello", sizeof("Hello"), EVENT_LABEL);
   client->addEventListener(this, ClientEvent::EVENT_SERVER_DISCONNECTED);

   Services()->getInput()->addEventListener(this, InputEvent::EVENT_KEYDOWN);
}

HelloPolycodeApp::~HelloPolycodeApp() {
}

void HelloPolycodeApp::handleEvent(Event *e) {
   if (e->getDispatcher() == server){
      ServerEvent *event = (ServerEvent*)e;
      switch (e->getEventCode()){
      case ServerEvent::EVENT_CLIENT_DATA:
         if (event->dataType == EVENT_LABEL){
            SceneLabel *label = new SceneLabel(event->data, 12);
            label->setPosition(rand() % 100, rand() % 200);
            scene->addEntity(label);
         }
         break;
      }
   }

   if (e->getDispatcher() == Services()->getInput()){
      InputEvent *iE = (InputEvent*)e;
      if (iE->getKey() == KEY_SPACE){
         srand(time(0));
         client->sendData(Address("127.0.0.1", 5554), "Hello", sizeof("Hello"), EVENT_LABEL);
      }
   }
}

bool HelloPolycodeApp::Update() {
    return core->updateAndRender();
}