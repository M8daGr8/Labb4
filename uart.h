#ifndef UART_H_INCLUDED
#define UART_H_INCLUDED

#include <Arduino.h>

class UART{
  public:
    UART(void);
    void Begin(uint16_t bauds = 9600);
    bool Read(void);
    String GetMessage(void);
  private:
    String message;
    
};
#endif
