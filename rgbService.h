
const byte colours[][3] = { 
  { 255, 0, 255 },  // <-- PURPLE
  { 0, 255, 0 },    // <-- BLUE
  { 0, 255, 255 },  // <-- CYAN
  { 0, 0, 255 },    // <-- GREEN
  { 255, 255, 0 },  // <-- YELLOW
  { 255, 165, 0 },  // <-- ORANGE
  { 255, 0, 0 }     // <-- RED
};

byte values[] = { 0, 0, 0 };

byte colour = 0;

void UpdateValues(uint8_t led){
  uint8_t fadeRate = pot.GetValue();

}

void RainbowCycle(void){
  while(true){
    if(colour >= sizeof(colours) / sizeof(colours[0]))
      colour = 0;
        
    while(values[0] != colours[colour][0] || values[1] != colours[colour][1] || values[2] != colours[colour][2]){
      if(millis() - prevMillis >= fadeRate){
        for(int i = 0; i < sizeof(values) / sizeof(values[0]); i++){
          if(values[i] < colours[colour][i])
            values[i] += 1;
          else if(values[i] > colours[colour][i])
            values[i] -=1;
        }
        for(int i = 0; i < sizeof(leds) / sizeof(leds[0]); i++){
          analogWrite(leds[i], 0);
          analogWrite(leds[i], values[i]);
        }
        ReadInputPins();
        prevMillis = millis();
      }
      
      if(digitalRead(btnOne) || digitalRead(btnTwo)){
        for(int i = 0; i < sizeof(leds) / sizeof(leds[0]); i++)
          analogWrite(leds[i], 0); 
        return;
      }
    }
    colour++;
  }
}
