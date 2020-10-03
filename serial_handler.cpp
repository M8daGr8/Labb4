#include "serial_handler.h"

SerialHandler::SerialHandler(uint32_t bauds){
  uart.SetBauds(bauds);
  message = "";
  fadeRate = 5;
  colour = 7;
}
void SerialHandler::Begin(void){
  uart.Begin();
}
void SerialHandler::ReadInput(void){
  if(uart.Read())
    message = uart.GetMessage();
}
uint8_t SerialHandler::GetColour(void){
  return colour;
}
uint32_t SerialHandler::GetFadeRate(void){
  return fadeRate;
}
void SerialHandler::SetColour(String desiredColour){
  Serial.print("\tNew colour:\t");
  
  if(desiredColour.indexOf("purple") >= 0){
    colour = 0;
    Serial.println("Purple"); 
  }
  else if(desiredColour.indexOf("blue") >= 0){
    colour = 1;
    Serial.println("Blue");
  }
  else if(desiredColour.indexOf("cyan") >= 0){
    colour = 2;
    Serial.println("Cyan");
  }
  else if(desiredColour.indexOf("green") >= 0){
    colour = 3;
    Serial.println("Green");
  }
  else if(desiredColour.indexOf("yellow") >= 0){
    colour = 4;
    Serial.println("Yellow");
  }
  else if(desiredColour.indexOf("orange") >= 0){
    colour = 5;
    Serial.println("Orange");
  }
  else if(desiredColour.indexOf("red") >= 0){
    colour = 6;
    Serial.println("Red");
  }
  else{
    colour = 7;
    Serial.println("Rainbow"); 
  }
}
void SerialHandler::SetFadeRate(String desiredFadeRate){
  int number = desiredFadeRate.toInt();
  if(number <= 0)
    number = 5;
  fadeRate = number;
  Serial.println("\tNew Faderate:\t" + String(fadeRate) + " ms");
}
void SerialHandler::SplitInput(void){
  message.toLowerCase();
  String request = message;
  message = "";
  
  if(request == "")
    return;

  Serial.println(">> " + request + "\n");
  
  if(request.indexOf("help") >= 0 || request[0] == 'h'){
    PrintHelp();
    return;
  }
  
  if(request.indexOf("colour") >= 0){
    SetColour(request.substring((request.indexOf("colour") + String("colour ").length()), request.indexOf(";")));
    request.remove(0, request.indexOf(";") + 2);
  }
  else{
    Serial.println("You need to choose a colour. \nType \"-help\" if you need help.\n");
    return;
  }
    
  if(request.indexOf("rate") >= 0)
    SetFadeRate(request.substring((request.indexOf("rate") + String("rate ").length()), request.indexOf(";")));
  else
    SetFadeRate("5");
  Serial.println();
}
void SerialHandler::PrintWelcome(void){
  Serial.println("***Welcome to Labb4 demo***");
  Serial.println("Press interrupt button to change mode.\n");
  Serial.println(" * Mode #1:  NONE\t(You can't do anything)  <- DEFAULT");
  Serial.println(" * Mode #2:  BUTTON\t(Only shield buttons)");
  Serial.println("\tPOT:  Change speed");
  Serial.println("\tKEY1: GREEN");
  Serial.println("\tKEY2: BLUE");
  Serial.println("\tBOTH: RED");
  Serial.println(" * Mode #3:  SERIAL\t(Only serial inputs)");
  Serial.println("\tSerial inputs");
  Serial.println(" * Mode #4:  BOTH\t(Both buttons & serial)\n");
  Serial.println("For serial help type -help in SERIAL mode");
  Serial.println();
}
void SerialHandler::PrintHelp(void){
  Serial.println("***Serial input Help***");
  Serial.println("-help : This menu");
  
  Serial.println("-colour (parameter); : Select fading colour (REQ)");
  Serial.println("\t(parameter:string)");
  Serial.println("\t\tred     : red color fade");
  Serial.println("\t\tgreen   : green color fade");
  Serial.println("\t\tblue    : blue color fade");
  Serial.println("\t\tpurple  : purple color fade");
  Serial.println("\t\tyellow  : yellow color fade");
  Serial.println("\t\torange  : orange color fade");
  Serial.println("\t\tcyan    : blue color fade");
  Serial.println("\t\trainbow : rainbow color fade <- DEFAULT");
  
  Serial.println("-rate (parameter); : Select fading speed in ms(OPT)");
  Serial.println("\t(parameter:uint)");
  Serial.println("\t\t5 : 5 ms  <- DEFAULT");
  Serial.println("\t\tuint : (your choice ms)");
  Serial.println();
  Serial.println("Example: -colour red -rate 10");
  Serial.println("\t\t->Fading red with faderate 10 ms.");
  Serial.println();
}
