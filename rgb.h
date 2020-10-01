#ifndef RGB_H_INCLUDED
#define RGB_H_INCLUDED

#include <Arduino.h>

class RGB{
  public:
    RGB(uint8_t rgbPins[3]);
    void Begin(void);
    void Write(uint8_t colour[3], uint8_t dir, uint8_t fadeRate);
    bool Loop(void);
  private:
    uint8_t pins[3];
    uint8_t currentValues[3] = { 0, 0, 0 };
    uint8_t desiredColour[3] = { 0, 0, 0 };
    uint8_t dir;
    uint8_t fadeRate;
    uint32_t prevMillis;
};
#endif
