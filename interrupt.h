enum Mode {
  none = 0, 
  button = 1, 
  serial = 2,
  both = 3
};

Mode mode = none;

void ChangeState(void){
  static unsigned long prevMillis = 0;
  unsigned long timeNow = millis();
  
  if(timeNow - prevMillis >= 500){
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
  }
  prevMillis = timeNow;
}
