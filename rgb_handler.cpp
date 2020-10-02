#include "rgb_handler.h"

RGBHandler::RGBHandler(const uint8_t rgbPins[3]){
  rgb.SetPins(rgbPins);
  
  for(int i = 0; i < sizeof(currentValues) / sizeof(currentValues[0]); i++)
    currentValues[i] = 0;
}
void RGBHandler::Begin(void){
  rgb.Begin();
  colour = purple;

  sameColour = false;
  for(int i = 0; i < sizeof(dir) / sizeof(dir[0]); i++)
    dir[i] = -1;
  fadeRate = 5;
  prevMillis = millis();
}

void RGBHandler::ChangeColour(Colour desiredColour){
  if(colour != desiredColour)
    sameColour = false;
  colour = desiredColour;
}
void RGBHandler::SetFadeRate(uint8_t newFadeRate){
  fadeRate = newFadeRate;
}
void RGBHandler::SetDirection(uint8_t newDir[3]){
  for(int i = 0; i < sizeof(dir) / sizeof(dir[0]); i++)
    dir[i] = newDir[i];
}
void RGBHandler::TurnOffLeds(void){
  const uint8_t off[3] = { 0, 0, 0 };
  rgb.Write(off);
}
void RGBHandler::Loop(void){
  if(millis() - prevMillis >= fadeRate){
    if(!sameColour)
      TurnOffLeds();
    
    
    
    for(int i = 0; i < sizeof(currentValues) / sizeof(currentValues[0]); i++){
      if(currentValues[i] < colours[colour][i])
        currentValues[i] += 1;
      else if(currentValues[i] > colours[colour][i])
        currentValues[i] -= 1;
    }
    
    rgb.Write(currentValues);
    
    sameColour = true;
    prevMillis = millis();
  }
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

void RainbowCycle(void){
  while(true){
    if(colour >= sizeof(colours) / sizeof(colours[0]))
      colour = 0;
        
    while(values[0] != colours[colour][0] || values[1] != colours[colour][1] || values[2] != colours[colour][2]){
      if(millis() - prevMillis >= fadeRate){
        for(int i = 0; i < sizeof(values) / sizeof(values[0]); i++){
          if(values[i] < colours[colour][i])
            values[i] += 1;
          else if(values[i] > colours[colour][i])
            values[i] -= 1;
        }
        for(int i = 0; i < sizeof(leds) / sizeof(leds[0]); i++){
          analogWrite(leds[i], 0);
          analogWrite(leds[i], values[i]);
        }
        ReadInputPins();
        prevMillis = millis();
      }
      
      if(digitalRead(btnOne) || digitalRead(btnTwo)){
        for(int i = 0; i < sizeof(leds) / sizeof(leds[0]); i++)
          analogWrite(leds[i], 0); 
        return;
      }
    }
    colour++;
  }
}
*/
