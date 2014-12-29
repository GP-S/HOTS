#include <Polycode.h>
#include "PolycodeView.h"

using namespace Polycode;

class HelloPolycodeApp : public EventHandler {
public:
    HelloPolycodeApp(PolycodeView *view);
    ~HelloPolycodeApp();
   
   void handleEvent(Event *e);
    bool Update();
   
   static const int EVENT_LABEL = 44;

private:
   Server *server;
   Client* client;
   Scene *scene;
    Core *core;
};