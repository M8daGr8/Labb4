#include "rgb.h"

RGB::RGB(){
  pins[0] = 11;
  pins[1] = 9;
  pins[2] = 10;
}
RGB::RGB(const uint8_t rgbPins[3]){
  for(uint8_t i = 0; i < sizeof(pins) / sizeof(pins[0]); i++)
    pins[i] = rgbPins[i];
}

void RGB::SetPins(const uint8_t rgbPins[3]){
  for(uint8_t i = 0; i < sizeof(pins) / sizeof(pins[0]); i++)
    pins[i] = rgbPins[i];
}

void RGB::Begin(void){
  for(uint8_t i = 0; i < sizeof(pins) / sizeof(pins[0]); i++){
    pinMode(pins[i], OUTPUT); 
    analogWrite(pins[i], 0);
  }
}
void RGB::Write(uint8_t values[3]){
  for(int i = 0; i < sizeof(pins) / sizeof(pins[0]); i++)
    analogWrite(pins[i], values[i]);
}
