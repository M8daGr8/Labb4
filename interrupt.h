enum Mode {
  none = 0, 
  button = 1, 
  serial = 2,
  both = 3
};

Mode mode = none;

void PrintMode(){
  Serial.print("Current mode: ");
  switch(mode){
    case none:
      Serial.println("NONE");
      break;
    case button:
      Serial.println("BUTTON");
      break;
    case serial:
      Serial.println("SERIAL");
      break;
    default:
      Serial.println("BUTTON & SERIAL");
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
void Debounce(void){
  unsigned long timeNow = millis();
  static unsigned long prevMillis = timeNow;
  
  if(timeNow - prevMillis >= 15){
    ChangeMode();
  }
  prevMillis = timeNow;
}
