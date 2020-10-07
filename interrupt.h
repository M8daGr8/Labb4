enum Mode {
  none = 0, 
  button = 1, 
  serial = 2,
  both = 3
};

Mode mode = none;

void PrintMode(){
  Serial.print(F("Current mode: "));
  switch(mode){
    case none:
      Serial.println(F("NONE"));
      break;
    case button:
      Serial.println(F("BUTTON"));
      break;
    case serial:
      Serial.println(F("SERIAL"));
      break;
    default:
      Serial.println(F("BUTTON & SERIAL"));
      break;
  }
  Serial.println();
}

void ChangeMode(){
  switch(mode){
    case none:
      mode = button;
      break;
    case button:
      mode = serial;
      break;
    case serial:
      mode = both;
      break;
    default:
      mode = none;
      break;
  }
  PrintMode();
}

unsigned long hToLMillis = 0;
unsigned long prevMillis = 0;

void SetInterruptTime(void){
  hToLMillis = millis();
}
void CheckInterruptTime(void){
  if(hToLMillis - prevMillis >= 20){
    if(!digitalRead(BUTTON_THREE)){
      ChangeMode();
      prevMillis = hToLMillis;
    } 
  }
}
