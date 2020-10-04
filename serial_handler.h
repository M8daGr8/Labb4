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
    Colour GetColour(void);
    bool HasNewValues(void);
    void PrintWelcome(void);
    void PrintHelp(void);
  private:
    UART uart;
    String message;
    Colour colour;
    uint32_t fadeRate;
    
    void SetColour(String desiredColour);
    void SetFadeRate(String desiredFadeRate);
};
#endif
