struct StateValues{
  
};

void StateMachine(void){
  
  /*switch(show){
      case red:
        break;
      case green:
        break;
      case blue:
        break;
      default: // Rainbow
        return;
  }*/
}

void S(void){

  rgbHandler.SetFadeRate(pot.GetValue());
  if(btnOne.IsPressed())
    rgbHandler.ChangeColour(red);
  else if(btnTwo.IsPressed())
    rgbHandler.ChangeColour(blue);
  else
    rgbHandler.ChangeColour(purple);
  rgbHandler.Loop();

  //
}

void CheckMode(void){
  switch(mode){
    case button:
      Serial.println("btn");
      break;
    case serial:
      Serial.println("serial");
      break;
    case both:
      Serial.println("both");
      break;
    default:
      Serial.println("none");
      return;
  }
}
