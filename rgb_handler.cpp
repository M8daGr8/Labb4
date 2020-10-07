#include "rgb_handler.h"

RGBHandler::RGBHandler(const uint8_t rgbPins[3]){
  rgb.SetPins(rgbPins);
  
  for(int i = 0; i < sizeof(currentValues) / sizeof(currentValues[0]); i++)
    currentValues[i] = 0;
}
void RGBHandler::Begin(void){
  rgb.Begin();
  colour = rainbow;

  sameColour = false;
  for(int i = 0; i < sizeof(dir) / sizeof(dir[0]); i++)
    dir[i] = -1;
  fadeRate = 5;
  prevMillis = millis();
}

void RGBHandler::SetColour(Colour desiredColour){
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
void RGBHandler::Loop(void){
  if(millis() - prevMillis >= fadeRate){
    if(colour == rainbow)
      RainbowCycle();
    else
      ChooseValues(colour);
    
    rgb.Write(currentValues);
    
    sameColour = false;
    prevMillis = millis();
  }
}

void RGBHandler::ChooseValues(uint8_t desiredColour){
  for(int i = 0; i < sizeof(currentValues) / sizeof(currentValues[0]); i++){
    if(currentValues[i] < colours[desiredColour][i])
      currentValues[i] += 1;
    else if(currentValues[i] > colours[desiredColour][i])
      currentValues[i] -= 1;
  }
}

void RGBHandler::RainbowCycle(void){
  static uint8_t currentColour = 0;
  
  if(currentColour >= sizeof(colours) / sizeof(colours[0]))
    currentColour = 0;
        
  ChooseValues(currentColour);
      
  if(currentValues[0] == colours[currentColour][0] 
  && currentValues[1] == colours[currentColour][1] 
  && currentValues[2] == colours[currentColour][2])
    currentColour++;
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
*/
