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
  // cast everything to doubles
  double pos = GetSongPosition();
  double len = GetSongLength();
  return (int) ((pos/len)*100.0);
}

// Interrupt is called once per millisecond
void InterruptHandler(){
  endOfNote = true;
}

/*
void ChangeInterruptPeriod(int newPeriod){
  Timer3.setPeriod(newPeriod);
}
*/

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

  Serial.println(currentChord);
  Serial.println(currentDuration);

  nextChord = ReadFile();
  nextDuration = ReadFile().toInt();

  LightLED(currentChord, true);
  LightLED(nextChord, false);

  songPosition++;
}

/*
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
*/

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

    //TESTING
    Serial.println(nextChord);
    Serial.println(nextDuration);
    
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
