#include "Controls.h"
#include "SD.h"
#include "LED.h"
#include "Switches.h"
#include <stdint.h>
#include <TouchScreen.h>
#include <DueTimer.h>

// Functions that control song play and can be called from any screen
bool playing;

// Interrupt is called once per millisecond
void InterruptHandler(){
  Serial.println("interrupting!");
  if(playing){
    unsigned long currentMillis = millis();
    playing = UpdateNote();
    if(!playing){
      Quit();
    }
  }
}

void InterruptSetup(){
  Serial.print("Initializing interrupts... ");
  Timer3.attachInterrupt(InterruptHandler).setPeriod(1000).start();
  Serial.println("done.");
}

bool UpdateNote(){
  // ex: "ExxA0wD2rG2gB2be0w";
  String chord = ReadFile();
  Serial.println(chord);
  // exit from playing loop if we reach the end of the song 
  if(chord == "X"){
    return false;
  }
  // actually light up LEDs
  LightLED(chord); 
  // TODO: TARANG
  // CheckADC(song); 
  // This will update the percentage of notes the user has hit perfectly
  // TODO: DON
  // UpdateScreen(); 
  return true;
}

void StartSong(String songName){
  // load song from SD card
  OpenFile(songName);
  // "play" first note in the song
  playing = UpdateNote();
}

void Quit(){
  // turns off all the LEDS
  DarkLED();
}

void CheckTouch(){

  //Touchscreen ts = getTS();
  //TSPoint p = ts.getPoint();
  Serial.println("in checktouch");
  switch (CurrState){
    case HOME:
      if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < -1500 && Xcoor > -2500)){
        Serial.println("Should go Lessons ");
        BtnPressed = Btn1;
      }
      else if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < -600 && Xcoor > -1500 )){
        Serial.println("Should go to Learn ");
        BtnPressed = Btn2;
      }
      else if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < -250 && Xcoor > -600 )){
        Serial.println("Should go to Play ");
        BtnPressed = Btn3;
      }
//      else if (Ycoor < 314 && Ycoor> 100 ){
//        Serial.println("Should go to Settings ");
//        BtnPressed = Btn4;
//      }
      break;
    case LESSONS:
      if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < -1500 && Xcoor > -2500)){
        Serial.println("Should go Shifting ");
        BtnPressed = Btn1;
      }
      else if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < -600 && Xcoor > -1500 )){
        Serial.println("Should go to Sustains ");
        BtnPressed = Btn2;
      }
      else if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < -250 && Xcoor > -600 )){
        Serial.println("Should go to Chords ");
        BtnPressed = Btn3;
      }
      else if ((Ycoor < 500 && Ycoor > 150) && (Xcoor < -2000 && Xcoor > -2500)){
        Serial.println("Should go back to HOME");
        BtnPressed = BackBtn;
      }
      break;
    case LEARN:
      if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < -1500 && Xcoor > -2500)){  //TODO: CHECK X&Y
        Serial.println("Should go Wonderwall ");
        BtnPressed = Btn1;
      }
      else if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < -600 && Xcoor > -1500 )){  //TODO: CHECK X&Y
        Serial.println("Should go to Free Fallin ");
        BtnPressed = Btn2;
      }
      else if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < -250 && Xcoor > -600 )){  //TODO: CHECK X&Y
        Serial.println("Should go to Africa ");
        BtnPressed = Btn3;
      }
      else if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < -250 && Xcoor > -600 )){  //TODO: CHECK X&Y
        Serial.println("Should go to I'm Yours ");
        BtnPressed = Btn3;
      } 
      else if ((Ycoor < 500 && Ycoor > 150) && (Xcoor < -2000 && Xcoor > -2500)){
        Serial.println("Should go back to HOME");
        BtnPressed = BackBtn;
      }
      break;
    case PLAY:
      if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < -1500 && Xcoor > -2500)){  //TODO: CHECK X&Y
        Serial.println("Should go Wonderwall ");
        BtnPressed = Btn1;
      }
      else if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < -600 && Xcoor > -1500 )){  //TODO: CHECK X&Y
        Serial.println("Should go to Free Fallin ");
        BtnPressed = Btn2;
      }
      else if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < -250 && Xcoor > -600 )){  //TODO: CHECK X&Y
        Serial.println("Should go to Africa ");
        BtnPressed = Btn3;
      }
      else if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < -250 && Xcoor > -600 )){  //TODO: CHECK X&Y
        Serial.println("Should go to I'm Yours ");
        BtnPressed = Btn3;
      } 
      else if ((Ycoor < 500 && Ycoor > 150) && (Xcoor < -2000 && Xcoor > -2500)){
        Serial.println("Should go back to HOME");
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

