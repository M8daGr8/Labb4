#ifndef POT_H_INCLUDED
#define POT_H_INCLUDED

#include <Arduino.h>

class Pot{
  public:
    Pot(uint8_t potPin);
    void Begin(void);
    void Read(void);
    uint8_t GetValue(void);
  private:
    uint8_t pin;
    uint8_t value;
};
#endif
