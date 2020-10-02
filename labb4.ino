#include "init.h"
#include "state_machine.h"

void setup() {
  InitUart();
  InitPins();
}

void loop(){
  pot.Read();
  btnOne.Read();
  btnTwo.Read();
  
  if(uart.Read())
    Serial.println(uart.GetMessage());
  
  rgbHandler.SetFadeRate(pot.GetValue());
  if(btnOne.IsPressed())
    rgbHandler.ChangeColour(red);
  else if(btnTwo.IsPressed())
    rgbHandler.ChangeColour(blue);
  else
    rgbHandler.ChangeColour(purple);
  rgbHandler.Loop();

  StateMachine();
}
