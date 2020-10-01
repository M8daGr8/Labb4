#include "uart.h"


UART::UART(void){
  
}
void UART::Begin(uint16_t bauds = 9600){
  Serial.begin(bauds);
}
bool UART::Read(void){
  return false;
}
String UART::GetMessage(void){
    return message;
}
