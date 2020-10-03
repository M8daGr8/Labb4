#ifndef UART_H_INCLUDED
#define UART_H_INCLUDED

#include <Arduino.h>

class UART{
  public:
    UART(uint32_t bauds = 9600);
    void Begin(void);
    void SetBauds(uint32_t bauds);
    bool Read(void);
    String GetMessage(void);
  private:
    uint32_t baud;
    String message;
    
};
#endif
