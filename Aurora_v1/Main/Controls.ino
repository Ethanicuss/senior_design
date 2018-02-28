#include <stdint.h>
#include <TouchScreen.h>
#include <DueTimer.h>

// Functions that control song play and can be called from any screen
bool playing;
String currentChord;
String nextChord;
int currentDuration;
int nextDuration;
int songPosition;

int GetSongPosition(){
  return songPosition;
}

// Interrupt is called once per millisecond
void InterruptHandler(){
  playing = UpdateNote(false);
}

void ChangeInterruptPeriod(int newPeriod){
  Timer3.setPeriod(newPeriod);
}

void InterruptSetup(int firstPeriod){
  // interrupts every X microseconds
  Timer3.attachInterrupt(InterruptHandler).start(firstPeriod);
}

bool UpdateNote(bool firstNote){
  if(firstNote){
    currentChord = ReadFile();
    currentDuration = ReadFile().toInt();
  }
  else{
    currentChord = nextChord;
    currentDuration = nextDuration;
  }

  Serial.println(currentChord);
  Serial.println(currentDuration);

  // exit from playing loop if we reach the end of the song 
  if(currentChord == "X"){
    return false;
  }

  // read next chord/duration from file
  nextChord = ReadFile();
  nextDuration = ReadFile().toInt();
  
  // actually light up LEDs
  LightLED(currentChord, true); 
  LightLED(nextChord, false);

  // set duration of interrupt
  if(firstNote){
    InterruptSetup(currentDuration);
  }
  else{
    ChangeInterruptPeriod(currentDuration);
  }

  songPosition++;

  return true;
}

void PlaySong(String songName){
  // load song from SD card
  OpenFile(songName);
  songPosition = 0;
  // "play" first note in the song
  playing = UpdateNote(true);
  while(playing){
  }
  // once you're done playing, dark all LEDs
  Quit();
}

void Quit(){
  // turns off all the LEDS
  DarkLED();
}

void CheckTouch(){
  //Touchscreen ts = getTS();
  //TSPoint p = ts.getPoint();
  //Serial.println("in checktouch");
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
  }
}

