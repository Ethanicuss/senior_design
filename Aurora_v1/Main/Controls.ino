#include <stdint.h>
#include "TouchScreen.h"
#include <TouchScreen.h>
#include "Switches.h"


//Functions that Control functionality and can be called from any screen

void PlayPause(){ //DOMINO's structure
//while (play){
  //For loop for entire Song
  //TODO: LED_ON(NoteString *see Song Module*) DOMINO
      //Light NextLEDs within LightLEDs 
  //TODO: CheckADC(NoteString) TARANG
  //TODO: UpdateScreen() "This will update the percentage of notes the user has hit perfectly"
  //Goto Next Note AKA close "for loop".
//} close while. "play variable changes on input"
}

void Quit(){
  //TODO: LED_OFF "Turns off all the LEDS
}

void CheckTouch(){

  //Touchscreen ts = getTS();
  //TSPoint p = ts.getPoint();
  switch (CurrState){
    case HOME:
      if (Ycoor < 1000 && Ycoor > 712 ){
        Serial.println("Should go Lessons ");
        BtnPressed = Btn1;
      }
      else if (Ycoor < 712 && Ycoor > 513 ){
        Serial.println("Should go to Learn ");
        BtnPressed = Btn2;
      }
      else if (Ycoor < 513 && Ycoor > 314 ){
        Serial.println("Should go to Play ");
        BtnPressed = Btn3;
      }
      else if (Ycoor < 314 && Ycoor> 100 ){
        Serial.println("Should go to Settings ");
        BtnPressed = Btn4;
      }
      break;
    case LESSONS:
      if (Ycoor < 1000 && Ycoor> 712 ){
        BtnPressed = BackBtn;
      }
      break;
    case LEARN:
      if (Ycoor < 1000 &&Ycoor> 712 ){
        BtnPressed = BackBtn;
      }
      break;
    case PLAY:
      if (Ycoor < 1000 && Ycoor > 712 ){
        BtnPressed = BackBtn;
      }
      break;
    case SETTINGS:
      if (Ycoor < 1000 && Ycoor > 712 ){
        BtnPressed = BackBtn;
      }
      break;
  }
}

