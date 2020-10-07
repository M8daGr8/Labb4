#include "serial_handler.h"

SerialHandler::SerialHandler(uint32_t bauds){
  uart.SetBauds(bauds);
  message = "";
  fadeRate = 5;
  colour = rainbow;
}
void SerialHandler::Begin(void){
  uart.Begin();
}
void SerialHandler::ReadInput(void){
  if(uart.Read())
    message = uart.GetMessage();
}
Colour SerialHandler::GetColour(void){
  return colour;
}
uint32_t SerialHandler::GetFadeRate(void){
  return fadeRate;
}
void SerialHandler::SetColour(String desiredColour){
  Serial.print(F("\tNew colour:\t"));
  
  if(desiredColour.indexOf("purple") >= 0){
    colour = purple;
    Serial.println(F("Purple")); 
  }
  else if(desiredColour.indexOf("blue") >= 0){
    colour = blue;
    Serial.println(F("Blue"));
  }
  else if(desiredColour.indexOf("cyan") >= 0){
    colour = cyan;
    Serial.println(F("Cyan"));
  }
  else if(desiredColour.indexOf("green") >= 0){
    colour = green;
    Serial.println(F("Green"));
  }
  else if(desiredColour.indexOf("yellow") >= 0){
    colour = yellow;
    Serial.println(F("Yellow"));
  }
  else if(desiredColour.indexOf("orange") >= 0){
    colour = orange;
    Serial.println(F("Orange"));
  }
  else if(desiredColour.indexOf("red") >= 0){
    colour = red;
    Serial.println(F("Red"));
  }
  else{
    colour = rainbow;
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
bool SerialHandler::HasNewValues(void){
  message.toLowerCase();
  String request = message;
  message = "";
  
  if(request == "")
    return false;

  Serial.println(">> " + request + "\n");
  
  if(request.indexOf("help") >= 0 || request[0] == 'h'){
    PrintHelp();
    return false;
  }

  if(request.indexOf("colour") >= 0){
    SetColour(request.substring((request.indexOf("colour") + String("colour ").length()), request.indexOf(";")));
    request.remove(0, request.indexOf(";") + 2);
  }
  else{
    Serial.println(F("You need to choose a colour. \nType \"-help\" if you need help.\n"));
    return false;
  }
    
  if(request.indexOf("rate") >= 0)
    SetFadeRate(request.substring((request.indexOf("rate") + String("rate ").length()), request.indexOf(";")));
  else
    SetFadeRate("5");
  Serial.println();
  return true;
}

//9280 (28%)
//1495 (72%)
void SerialHandler::PrintWelcome(void){
  Serial.println(F("***Welcome to Labb4 demo***"));
  Serial.println(F("Press interrupt button to change mode.\n"));
  Serial.println(F(" * Mode #1:  NONE\t(You can't do anything)  <- DEFAULT"));
  Serial.println(F(" * Mode #2:  BUTTON\t(Only shield buttons)"));
  Serial.println(F("\tPOT:  Change speed"));
  Serial.println(F("\tKEY1: GREEN"));
  Serial.println(F("\tKEY2: BLUE"));
  Serial.println(F("\tBOTH: RED"));
  Serial.println(F(" * Mode #3:  SERIAL\t(Only serial inputs)"));
  Serial.println(F("\tSerial inputs"));
  Serial.println(F(" * Mode #4:  BOTH\t(Both buttons & serial)\n"));
  Serial.println(F("For serial help type -help in SERIAL mode"));
  Serial.println();
}
void SerialHandler::PrintHelp(void){
  Serial.println(F("***Serial input Help***"));
  Serial.println(F("-help : This menu"));
  
  Serial.println(F("-colour (parameter); : Select fading colour (REQ)"));
  Serial.println(F("\t(parameter:string)"));
  Serial.println(F("\t\tred     : red color fade"));
  Serial.println(F("\t\tgreen   : green color fade"));
  Serial.println(F("\t\tblue    : blue color fade"));
  Serial.println(F("\t\tpurple  : purple color fade"));
  Serial.println(F("\t\tyellow  : yellow color fade"));
  Serial.println(F("\t\torange  : orange color fade"));
  Serial.println(F("\t\tcyan    : blue color fade"));
  Serial.println(F("\t\trainbow : rainbow color fade <- DEFAULT"));
  
  Serial.println(F("-rate (parameter); : Select fading speed in ms(OPT)"));
  Serial.println(F("\t(parameter:uint)"));
  Serial.println(F("\t\t5 : 5 ms  <- DEFAULT"));
  Serial.println(F("\t\tuint : (your choice ms)"));
  Serial.println();
  Serial.println(F("Example: -colour red -rate 10"));
  Serial.println(F("\t\t->Fading red with faderate 10 ms."));
  Serial.println();
}
