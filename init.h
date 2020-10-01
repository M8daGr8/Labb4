#include "uart.h"
#include "button.h"
#include "potentiometer.h"
#include "rgb.h"
#include "interrupt.h"

#define POT_PIN A0
#define BUTTON_ONE 8
#define BUTTON_TWO 12
#define BUTTON_THREE 2

const uint8_t LEDS[] = { 11, 9, 10 };

Btn btnOne(BUTTON_ONE);
Btn btnTwo(BUTTON_TWO);
Pot pot(POT_PIN);
RGB rgb(LEDS);

void InitUart(uint16_t bauds = 9600){  
  
}
void InitPins(void){  
  attachInterrupt(digitalPinToInterrupt(BUTTON_THREE), ChangeState, HIGH);
  btnOne.Begin();
  btnTwo.Begin();
  pot.Begin();
  rgb.Begin();
}
