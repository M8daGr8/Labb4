#ifndef RGB_HANDLER_H_INCLUDED
#define RGB_HANDLER_H_INCLUDED

#include <Arduino.h>
#include "rgb.h"

enum Colour{
  purple = 0,
  blue = 1,
  cyan = 2,
  green = 3,
  yellow = 4,
  orange = 5,
  red = 6
};

class RGBHandler{
  public:
    RGBHandler(const uint8_t rgbPins[3]);
    void Begin(void);
    void ChangeColour(Colour desiredColour);
    void SetFadeRate(uint8_t newFadeRate);
    void SetDirection(uint8_t newDir[3]);
    void TurnOffLeds(void);
    void Loop(void);
  private:
    RGB rgb;
    Colour colour;

    uint8_t currentValues[3];
    bool sameColour;
    uint8_t dir[3];
    uint8_t fadeRate;
    uint32_t prevMillis;
    const byte colours[7][3] = { 
      { 255, 0, 255 },  // <-- PURPLE
      { 0, 255, 0 },    // <-- BLUE
      { 0, 255, 255 },  // <-- CYAN
      { 0, 0, 255 },    // <-- GREEN
      { 255, 255, 0 },  // <-- YELLOW
      { 255, 165, 0 },  // <-- ORANGE
      { 255, 0, 0 }     // <-- RED
    };
};
#endif
