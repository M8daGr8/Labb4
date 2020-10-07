#include "init.h"
#include "state_machine.h"

void setup() {
  InitSerial();
  InitPins();
}

void loop(){
  CheckInterruptTime();
  
  serialHandler.ReadInput();
  pot.Read();
  btnOne.Read();
  btnTwo.Read();

  StateMachine();
  
  rgbHandler.Loop();
}
