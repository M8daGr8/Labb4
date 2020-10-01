#include "button.h"

Btn::Btn(uint8_t buttonPin, uint32_t debounceDelay = 25){
  pin = buttonPin;
  dbDelay = debounceDelay;
}

void Btn::Begin(void){
  pinMode(pin, INPUT); 
  
  state = digitalRead(pin);
  lastState = state;
  prevMillis = millis();
}

void Btn::Read(void){
  state = digitalRead(pin);

  if(state != lastState)
    prevMillis = millis();
  lastState = state;
  
  if(millis() - prevMillis >= dbDelay)
    if(state)
      return;
  state = false;
}
bool Btn::IsPressed(void){
  return state;
}
