#include "State.h"

void InitializeState(){
  BtnPressed = NONE;
  CurrState = HOME;
  PreState = HOME;
  Xcoor = 0;
  Ycoor = 0;
  DrawHomeScreen();
  currentLesson = 0;
  currentLearn = 0;
  currentPlay = 0;
}

void CheckTouch(){
  switch (CurrState){
    case HOME:
      if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < -1500 && Xcoor > -2500)){
        //Serial.println("Should go Lessons ");
        BtnPressed = Btn1;
      }
      else if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < -600 && Xcoor > -1500 )){
        //Serial.println("Should go to Learn ");
        BtnPressed = Btn2;
      }
      else if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < 500 && Xcoor > -600 )){
        Serial.println("Should go to Play ");
        BtnPressed = Btn3;
      }
      break;
    case LESSONS:
      if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < -1500 && Xcoor > -2500)){
        //Serial.println("Should go Shifting ");
        BtnPressed = Btn1;
      }
      else if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < -600 && Xcoor > -1500 )){
        //Serial.println("Should go to Sustains ");
        BtnPressed = Btn2;
      }
      else if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < 500 && Xcoor > -600 )){
        Serial.println("Should go to Chords ");
        BtnPressed = Btn3;
      }
      else if ((Ycoor < 500 && Ycoor > 150) && (Xcoor < -2000 && Xcoor > -2500)){
        //Serial.println("Should go back to HOME");
        BtnPressed = BackBtn;
      }
      break;
    case LEARN:
      if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < -1750 && Xcoor > -2500)){  //TODO: CHECK X&Y
        Serial.println("Should go Wonderwall ");
        BtnPressed = Btn1;
      }
      else if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < -1065 && Xcoor > -1750 )){  //TODO: CHECK X&Y
        Serial.println("Should go to Free Fallin ");
        BtnPressed = Btn2;
      }
      else if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < -360 && Xcoor > -1065 )){  //TODO: CHECK X&Y
        Serial.println("Should go to Africa ");
        BtnPressed = Btn3;
      }
      else if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < 400 && Xcoor > -360 )){  //TODO: CHECK X&Y
        Serial.println("Should go to I'm Yours ");
        BtnPressed = Btn4;
      }
      else if ((Ycoor < 500 && Ycoor > 150) && (Xcoor < -2000 && Xcoor > -2500)){
        //Serial.println("Should go back to HOME");
        BtnPressed = BackBtn;
      }
      break;
    case PLAY:
      if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < -1750 && Xcoor > -2500)){  //TODO: CHECK X&Y
        Serial.println("Should go Wonderwall ");
        BtnPressed = Btn1;
      }
      else if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < -1065 && Xcoor > -1750 )){  //TODO: CHECK X&Y
        Serial.println("Should go to Free Fallin ");
        BtnPressed = Btn2;
      }
      else if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < -360 && Xcoor > -1065 )){  //TODO: CHECK X&Y
        Serial.println("Should go to Africa ");
        BtnPressed = Btn3;
      }
      else if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < 400 && Xcoor > -360 )){  //TODO: CHECK X&Y
        Serial.println("Should go to I'm Yours ");
        BtnPressed = Btn4;
      }
      else if ((Ycoor < 500 && Ycoor > 150) && (Xcoor < -2000 && Xcoor > -2500)){
        //Serial.println("Should go back to HOME");
        BtnPressed = BackBtn;
      }
      break;

    case SHIFTING:
      if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < -1500 && Xcoor > -2500)){
        Serial.println("Should go Lessons 101 ");
        BtnPressed = Btn1;
      }
      else if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < -600 && Xcoor > -1500 )){
        Serial.println("Should go Lessons 102 ");
        BtnPressed = Btn2;
      }
      else if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < 500 && Xcoor > -600 )){
        Serial.println("Should go Lessons 103 ");
        BtnPressed = Btn3;
      }
      else if ((Ycoor < 500 && Ycoor > 150) && (Xcoor < -2000 && Xcoor > -2500)){
        Serial.println("Should go back to LESSONS");
        BtnPressed = BackBtn;
      }
      break;

    case SUSTAIN:
      if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < -1500 && Xcoor > -2500)){
        Serial.println("Should go Lessons 101 ");
        BtnPressed = Btn1;
      }
      else if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < -600 && Xcoor > -1500 )){
        Serial.println("Should go Lessons 102 ");
        BtnPressed = Btn2;
      }
      else if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < 500 && Xcoor > -600 )){
        Serial.println("Should go Lessons 103 ");
        BtnPressed = Btn3;
      }
      else if ((Ycoor < 500 && Ycoor > 150) && (Xcoor < -2000 && Xcoor > -2500)){
        Serial.println("Should go back to LESSONS");
        BtnPressed = BackBtn;
      }
      break;

    case CHORDS:
      if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < -1500 && Xcoor > -2500)){
        Serial.println("Should go Lessons 101 ");
        BtnPressed = Btn1;
      }
      else if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < -600 && Xcoor > -1500 )){
        Serial.println("Should go Lessons 102 ");
        BtnPressed = Btn2;
      }
      else if ((Ycoor < -1060 && Ycoor > -3000) && (Xcoor < 500 && Xcoor > -600 )){
        Serial.println("Should go Lessons 103 ");
        BtnPressed = Btn3;
      }
      else if ((Ycoor < 500 && Ycoor > 150) && (Xcoor < -2000 && Xcoor > -2500)){
        Serial.println("Should go back to LESSONS");
        BtnPressed = BackBtn;
      }
      break;

    case PLAYING_LESSON:
      if ((Ycoor < 350 && Ycoor > -1050) && (Xcoor < 300 && Xcoor > -300)){
        Serial.println("Should pause/play ");
        BtnPressed = Btn1;
      }
      else if ((Ycoor < -1050 && Ycoor > -3000) && (Xcoor < 300 && Xcoor > -300 )){
        Serial.println("Should quit ");
        BtnPressed = Btn2;
      }
      break;
    case LEARNING_SONG:
      if ((Ycoor < 350 && Ycoor > -1050) && (Xcoor < 300 && Xcoor > -300)){
        Serial.println("Should pause/play ");
        BtnPressed = Btn1;
      }
      else if ((Ycoor < -1050 && Ycoor > -3000) && (Xcoor < 300 && Xcoor > -300 )){
        Serial.println("Should quit ");
        BtnPressed = Btn2;
      }
      break;
    case PLAYING_SONG:
      if ((Ycoor < 350 && Ycoor > -1050) && (Xcoor < 300 && Xcoor > -300)){
        Serial.println("Should pause/play ");
        BtnPressed = Btn1;
      }
      else if ((Ycoor < -1050 && Ycoor > -3000) && (Xcoor < 300 && Xcoor > -300 )){
        Serial.println("Should quit ");
        BtnPressed = Btn2;
      }
      break;
    case FINISHED_LESSON:
      if ((Ycoor < 350 && Ycoor > -1050) && (Xcoor < 300 && Xcoor > -300)){
        Serial.println("Should go to lessons ");
        BtnPressed = Btn1;
      }
      else if ((Ycoor < -1050 && Ycoor > -3000) && (Xcoor < 300 && Xcoor > -300 )){
        Serial.println("Should go home ");
        BtnPressed = Btn2;
      }
      break;
     case FINISHED_LEARNING:
      if ((Ycoor < 350 && Ycoor > -1050) && (Xcoor < 300 && Xcoor > -300)){
        Serial.println("Should go to lessons ");
        BtnPressed = Btn1;
      }
      else if ((Ycoor < -1050 && Ycoor > -3000) && (Xcoor < 300 && Xcoor > -300 )){
        Serial.println("Should go home ");
        BtnPressed = Btn2;
      }
      break;
    case FINISHED_PLAYING:
      if ((Ycoor < 350 && Ycoor > -1050) && (Xcoor < 300 && Xcoor > -300)){
        Serial.println("Should go to lessons ");
        BtnPressed = Btn1;
      }
      else if ((Ycoor < -1050 && Ycoor > -3000) && (Xcoor < 300 && Xcoor > -300 )){
        Serial.println("Should go home ");
        BtnPressed = Btn2;
      }
      break;
    case SETTINGS:
      if (Ycoor < 1000 && Ycoor > 712 ){
        BtnPressed = BackBtn;
      }
      break;
    case PAUSED:
      if ((Ycoor < 350 && Ycoor > -1050) && (Xcoor < 300 && Xcoor > -300)){
        Serial.println("Should pause/play ");
        BtnPressed = Btn1;
      }
      else if ((Ycoor < -1050 && Ycoor > -3000) && (Xcoor < 300 && Xcoor > -300 )){
        Serial.println("Should quit ");
        BtnPressed = Btn2;
      }
      break;  
  }
}

