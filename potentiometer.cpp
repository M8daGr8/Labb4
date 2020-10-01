#include "potentiometer.h"

Pot::Pot(uint8_t potPin){
  pin = potPin;
  value = 0;
}
void Pot::Begin(void){
  pinMode(pin, INPUT); 
}
void Pot::Read(void){
  value = map(analogRead(pin), 0, 1023, 2, 20);
}
uint8_t Pot::GetValue(void){
  return value;
}
