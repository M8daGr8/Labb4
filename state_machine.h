void StateMachine(void){
  bool btnOneIsPressed = btnOne.IsPressed();
  bool btnTwoIsPressed = btnTwo.IsPressed();

  if(btnOneIsPressed && btnTwoIsPressed)
    UpdateValues(0);
  else if(btnOneIsPressed)
    UpdateValues(1);
  else if(btnTwoIsPressed)
    UpdateValues(2);
  else{
    Serial.println("hejsan"); 
    return;
  }
}
