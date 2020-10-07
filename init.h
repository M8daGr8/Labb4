#include "button.h"
#include "potentiometer.h"

#include "rgb_handler.h"
#include "serial_handler.h"

#define POT_PIN A0
#define BUTTON_ONE 8
#define BUTTON_TWO 12
#define BUTTON_THREE 2

#include "interrupt.h"

const uint8_t LEDS[] = { 11, 9, 10 };

SerialHandler serialHandler(115200);
Btn btnOne(BUTTON_ONE);
Btn btnTwo(BUTTON_TWO);
Pot pot(POT_PIN);
RGBHandler rgbHandler(LEDS);

void InitSerial(){
  serialHandler.Begin();
  serialHandler.PrintWelcome();
  PrintMode();
  serialHandler.PrintHelp();  
}
void InitPins(void){  
  pinMode(BUTTON_THREE, INPUT);
  attachInterrupt(digitalPinToInterrupt(BUTTON_THREE), SetInterruptTime, RISING);
  btnOne.Begin();
  btnTwo.Begin();
  pot.Begin();
  rgbHandler.Begin();
}
