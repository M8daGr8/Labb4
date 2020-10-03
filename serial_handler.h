#ifndef SERIAL_HANDLER_H_INCLUDED
#define SERIAL_HANDLER_H_INCLUDED

#include <Arduino.h>
#include "uart.h"
#include "rgb_handler.h"

class SerialHandler{
  public:
    SerialHandler(uint32_t bauds);
    void Begin(void);
    void ReadInput(void);
    uint32_t GetFadeRate(void);
    uint8_t GetColour(void);
    void SplitInput(void);
    void PrintWelcome(void);
    void PrintHelp(void);
  private:
    UART uart;
    String message;
    uint32_t fadeRate;
    Colour colour;
    
    void SetColour(String desiredColour);
    void SetFadeRate(String desiredFadeRate);
};
#endif
