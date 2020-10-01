#include "rgb.h"

RGB::RGB(uint8_t rgbPins[3]){
  for(uint8_t i = 0; i < sizeof(pins) / sizeof(pins[0]); i++)
    pins[i] = rgbPins[i];
    
  dir = 1;
  fadeRate = 5;
}
void RGB::Begin(void){
  for(uint8_t i = 0; i < sizeof(pins) / sizeof(pins[0]); i++){
    pinMode(pins[i], OUTPUT); 
    analogWrite(pins[i], 0);
  }
  prevMillis = millis();
}
bool RGB::Loop(void){
  return false;
}

/*
void RGB::UpdateBrightness(void){
  if(millis() - prevMillis >= fadeRate){
    if(brightness >= 255 || brightness <= 10)
      dir *= -1;
    brightness += dir;
    prevMillis = millis();
  }
}

void RGB::SetFadeRate(uint8_t newFadeRate){
  fadeRate = newFadeRate;
}

void RGB::ChooseLED(uint8_t led){
  prevLed = currentLed;
  if(led >= sizeof(pins) / sizeof(pins[0]))
    led = (sizeof(pins) / sizeof(pins[0]));
  else if(led < 0)
    led = 0;
  currentLed = led;
}

void RGB::TurnOffLED(void){
  if(prevLed != currentLed)
    analogWrite(pins[prevLed], 0);
}

void RGB::ShowLED(void){    
  analogWrite(pins[currentLed], brightness);
}
*/
