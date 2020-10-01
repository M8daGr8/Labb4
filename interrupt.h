uint8_t mode = 0;

void ChangeState(void){
  static unsigned long prevMillis = 0;
  unsigned long timeNow = millis();
  
  if(timeNow - prevMillis >= 25){
    mode++;
    if(mode == 4)
      mode = 0;
  }
  prevMillis = timeNow;
}
