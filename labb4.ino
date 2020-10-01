#include "init.h"
#include "state_machine.h"

void setup() {
  InitUart(115200);
  InitPins();
}

void loop(){
  pot.Read();
  btnOne.Read();
  btnTwo.Read();
  
  StateMachine();
}
