#include "uart.h"

UART::UART(uint32_t bauds = 9600){
  baud = bauds;
  message = "";
}
void UART::Begin(void){
  Serial.begin(baud);
}
void UART::SetBauds(uint32_t bauds){
  baud = bauds;
}
bool UART::Read(void){
  if(Serial.available()){
    char letter = Serial.read();
    if(letter != 10)
      message += letter;
    else
      return true; 
  }
  return false;
}
String UART::GetMessage(void){
  String msg = message;
  message = "";
  return msg;
}
