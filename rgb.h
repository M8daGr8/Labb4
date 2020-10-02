#ifndef RGB_H_INCLUDED
#define RGB_H_INCLUDED

#include <Arduino.h>

class RGB{
  public:
    RGB();
    RGB(const uint8_t rgbPins[3]);
    void SetPins(const uint8_t rgbPins[3]);
    void Begin(void);
    void Write(uint8_t values[3]);
  private:
    uint8_t pins[3];
};
#endif
