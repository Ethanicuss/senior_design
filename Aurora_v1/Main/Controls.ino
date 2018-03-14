#include <stdint.h>
#include <TouchScreen.h>
#include <DueTimer.h>
#include "Controls.h"

// Functions that control song play and can be called from any screen
bool playMode = false;
bool playing;
bool changeNote = false;
String currentChord;
String nextChord;
int currentDuration;
int nextDuration;
int songPosition;

String songTitle = "";
bool endOfNote = false;

int GetSongPosition(){
  return songPosition;
}

int GetPlayPercent(){
  double fraction = GetSongPosition()/GetSongLength();
  return (int) fraction*100;
}

// Interrupt is called once per millisecond
void InterruptHandler(){
  endOfNote = true;
  /*if(playing){
    playing = UpdateNote(false);
  }
  */
}

void ChangeInterruptPeriod(int newPeriod){
  Timer3.setPeriod(newPeriod);
}

void InterruptSetup(int firstPeriod){
  // interrupts every X microseconds
  Timer3.attachInterrupt(InterruptHandler).start(firstPeriod);
}

void FirstNote(void){
  currentChord = ReadFile();
  currentDuration = ReadFile().toInt();

  nextChord = ReadFile();
  nextDuration = ReadFile().toInt();

  LightLED(currentChord, true);
  LightLED(nextChord, false);

  songPosition++;

  InterruptSetup(currentDuration);
}


void FirstNote_Learn(void){
  currentChord = ReadFile();
  currentDuration = ReadFile().toInt();

  nextChord = ReadFile();
  nextDuration = ReadFile().toInt();

  LightLED(currentChord, true);
  LightLED(nextChord, false);

  songPosition++;
}

bool UpdateNote(bool firstNote){

  // update current note
  if(firstNote){
    currentChord = ReadFile();
    currentDuration = ReadFile().toInt();
  }
  else{
    currentChord = nextChord;
    currentDuration = nextDuration;
  }
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

  // only do interrupt stuff if you're in play mode, NOT in learn mode
  if(playMode){
    // set duration of interrupt
    if(firstNote){
      InterruptSetup(currentDuration);
    }
    else{
      ChangeInterruptPeriod(currentDuration);
    }
  }
  // for keeping track of how far through the song you are
  songPosition++;
  // true = still playing, false = paused/not playing
  return true;
}

void songSetup(String songName){
  OpenFile(songName);
  songPosition = 0;
  songTitle = songName;
}

void PlaySong_TK(String songTitle){
  if(currentChord == "X"){ //is this a problem???
    Serial.println("Song is finished");
    Quit();
    CurrState = FINISHED_PLAYING;
  }
  else {
    if (songPosition == 0){
      FirstNote();
    }
  }
  if (endOfNote == true){
    //Serial.println("Should go to Next Note");
    endOfNote = false;
    songPosition++;
    // clear lit LEDs from last current chord
    DarkLED(currentChord);
    //1. go to next note
    currentChord = nextChord;  
    currentDuration = nextDuration;  
    nextChord = ReadFile();
    nextDuration = ReadFile().toInt();
    
    //2. actually light up LEDs
    LightLED(currentChord, true);
    LightLED(nextChord, false);

    //3. set up interrupts
    InterruptSetup(currentDuration);
  }
}

/*
void PlaySong(String songName){
  playMode = true;
  // load song from SD card
  OpenFile(songName);
  songPosition = 0;
  // "play" first note in the song
  playing = UpdateNote(true);
  while(playing){
    CheckTouch();
    checkPlayPause();
    //interrrupts move the sequence of notes
    playing = UpdateNote(false);
  }
  // once you're done playing, dark all LEDs
  Quit();
  playMode = false;
}
*/

/*
void LearnSong(String songName){
  // load song from SD card
  OpenFile(songName);
  songPosition = 0;
  // "play" first note in the song
  playing = UpdateNote(true);
  //TESTING 
  Serial.println("in LearnSong");
  //TESTING
  while(playing){
    //TESTING
    Serial.println("in playing");
    //TESTING
    CheckTouch();
    checkPlayPause();
    playing = UpdateNote(false);
    while(!checkPlacement(currentChord)){
      checkPlayPause();
      //TESTING
       Serial.println("checking Placement");
      //TESTING
      adcOUT();
    }
  }
  // once you're done playing, dark all LEDs
  Quit();
}
*/

void LearnSong_TK(String songName){
  Serial.println("in learnsong");
  if(currentChord == "X"){ //is this a problem???
    Serial.println("Song is finished");
    Quit();
    CurrState = FINISHED_LEARNING;
  }
  else {
    if (songPosition == 0){
      FirstNote_Learn();
    }
  }
  if (checkPlacement(currentChord)){
    //Serial.println("Should go to Next Note");
    endOfNote = false;
    songPosition++;
    // clear lit LEDs from last current chord
    DarkLED(currentChord);
    //1. go to next note
    currentChord = nextChord;  
    currentDuration = nextDuration;  
    nextChord = ReadFile();
    nextDuration = ReadFile().toInt();
    
    //2. actually light up LEDs
    LightLED(currentChord, true);
    LightLED(nextChord, false);
    return;
  }
  else{
    Serial.println("adc values: ");
    adcOUT();
  }
}
void checkPlayPause(){
  if(BtnPressed == Btn1){ //they hit Pause for the first time
      BtnPressed = NONE;
      //TESTING
      Serial.println("Paused");
      //TESTING
      playing = false;
      //draw pause screen (outside of the while loop so it only gets drawn once)
      while (!playing){
        //Paused
        CheckTouch();
        if (BtnPressed == Btn1){
          BtnPressed = NONE;
          //TESTING
          Serial.println("un-Paused");
          //TESTING
          playing = true;
          //draw learn screen again
        }
      }
    }
    if(CurrState == LEARNING_SONG){
      if (BtnPressed == Btn2){
        BtnPressed = NONE;
        Quit();
        DrawFinishedLearning();
        CurrState = FINISHED_LEARNING;
      }
    }
    else if (CurrState == PLAYING_SONG){
      if (BtnPressed == Btn2){
        BtnPressed = NONE;
        Quit();
        DrawFinishedPlaying();
        CurrState = FINISHED_PLAYING;
      }
    }
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
