#ifndef SERIAL_HANDLER_H_INCLUDED
#define SERIAL_HANDLER_H_INCLUDED

#include <Arduino.h>

class SerialHandler{
  public:
    
  private:
    enum Color{
      purple = 'p',
      blue = 'b',
      cyan = 'c',
      green = 'g',
      yellow = 'y',
      orange = 'o',
      red = 'r'
    };
    byte fadeRate;
    byte colors[3];
}


void CheckInput(){
  
}

void SplitMessage(){
  
}
