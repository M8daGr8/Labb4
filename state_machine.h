void ValuesFromSerial(void);
void ValuesFromButtons(bool andSerial);

struct stateValues{
  Colour colour = rainbow;
  uint32_t rate = 5;
};

stateValues values;

void StateMachine(void){
  switch(mode){
    case button:
      ValuesFromButtons(false);
      break;
    case serial:
      ValuesFromSerial();
      break;
    case both:
      ValuesFromSerial();
      ValuesFromButtons(true);
      break;
    default:
      values.colour = rainbow;
      values.rate = 5;
  }
  rgbHandler.SetColour(values.colour);
  rgbHandler.SetFadeRate(values.rate);
}
void ValuesFromSerial(void){
  if(serialHandler.HasNewValues()){
    values.colour = serialHandler.GetColour();
    values.rate = serialHandler.GetFadeRate();
  }
}
void ValuesFromButtons(bool andSerial){
  bool buttonPressed = false;
  
  if(btnOne.IsPressed() && btnTwo.IsPressed()){
    values.colour = red; 
    buttonPressed = true;  
  }
  else if(btnOne.IsPressed()){
    values.colour = blue;
    buttonPressed = true;
  }
  else if(btnTwo.IsPressed()){
    values.colour = green;
    buttonPressed = true;
  }
  else if(!andSerial)
    values.colour = rainbow;

  if(!andSerial || buttonPressed)
    values.rate = pot.GetValue();
}
