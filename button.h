#ifndef BTN_H_INCLUDED
#define BTN_H_INCLUDED

#include <Arduino.h>

class Btn{
  public:
    Btn(uint8_t buttonPin, uint32_t debounceDelay = 25);
    void Begin(void);
    void Read(void);
    bool IsPressed(void);
  private:
    uint8_t pin;
    bool state;
    bool lastState;
    uint32_t prevMillis;
    uint32_t dbDelay;
};
#endif
