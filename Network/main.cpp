#include <iostream>
#include <Polycode.h>
//#include </home/thibault/HOTS/Dependencies/Polycode/Core/Contents/include/Polycode.h>
#include "PolycodeView.h"
#include "HelloPolycodeApp.h"
using namespace Polycode;

int main(){
 //client(port, rate)

 std::cout<<"yop\n";
 PolycodeView * v = new PolycodeView("test");
 HelloPolycodeApp * n = new HelloPolycodeApp(v);
 while(n->Update()) {}
 return 0; 
}