#include <TouchScreen.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_HX8357.h>
#include <SPI.h>
#include <SD.h>
#include <DueTimer.h>
#include "Switches.h"
#include "LCD.h"

#include "Fonts/JosefinSans_Bold40pt7b.h"
#include "Fonts/JosefinSans_Bold20pt7b.h"
#include "Fonts/JosefinSans_Bold15pt7b.h"
#include "Fonts/JosefinSans_Bold12pt7b.h"
#include "Fonts/JosefinSans_Bold10pt7b.h"
#include "Fonts/JosefinSans_Bold8pt7b.h"
#include "Fonts/JosefinSans_BoldItalic40pt7b.h"
#include "Fonts/JosefinSans_BoldItalic20pt7b.h"
#include "Fonts/JosefinSans_BoldItalic15pt7b.h"
#include "Fonts/JosefinSans_BoldItalic12pt7b.h"
#include "Fonts/JosefinSans_BoldItalic10pt7b.h"
#include "Fonts/JosefinSans_BoldItalic8pt7b.h"

extern bool play; 

//creating type "State"
enum State {HOME = 0, LESSONS = 1, LEARN = 2, PLAY = 3, SETTINGS = 4, SHIFTING = 5, SUSTAIN = 6, CHORDS = 7, PLAYING_LESSON = 8, LEARNING_SONG = 9, PLAYING_SONG = 10, FINISHED_LESSON = 11, FINISHED_LEARNING = 12, FINISHED_PLAYING = 13};

//creating variable of type "State" called CurrState
enum State CurrState;

void setup() {
  Serial.begin(9600);
  Serial.print("In setup");
  bool success = LCDSetup();
  if(success){
    LEDSetup();
    analogReadResolution(12);
    MuxSetup();
    InitializeState();
  }
}

void loop() {
  
  // SWITCH STATEMENT THAT HANDLES EVERY SCREEN STATE
  // -- See UI Diagram for Control Flow Graph
/****************** HOME SCREEN OPTIONS *****************/

  DisplayXYZ();
  CheckTouch();
  switch(CurrState){
    case HOME:
      Serial.println("In HOME ");
      //TODO; HOME
      switch (BtnPressed){
        case Btn1: //LESSONS:
          Serial.println("Button 1 Hit");
          DrawLessonsScreen();
          CurrState = LESSONS;
          break;
        case Btn2: //LEARN:
          Serial.println("Button 2 Hit");
          DrawLearnScreen();
          CurrState = LEARN;
          break;
        case Btn3: //PLAY:
          Serial.println("Button 3 Hit");
          DrawPlayScreen();
          CurrState = PLAY;
          break;
        case Btn4: //SETTINGS:
          Serial.println("Button 4 Hit");
          //TODO: DrawSettingsScreen()
       //   DrawSettingsScreen();
         // CurrState = SETTINGS;
          break;
      }
      break;
/*********************** LESSONS MODE **********************/
    case LESSONS:
      Serial.println("In Lessons ");
      //TODO - LESSONS
      switch (BtnPressed){
        case Btn1: //SHIFTING:
          Serial.println("Button 1.1 Hit");
          DrawShiftingScreen();
          CurrState = SHIFTING;
          break;
        case Btn2: //SUSTAIN:
          Serial.println("Button 2.1 Hit");
          //TODO: DrawSustainScreen()
          DrawSustainScreen();
          CurrState = SUSTAIN;
          break;
        case Btn3: //CHORDS:
          Serial.println("Button 3.1 Hit");
          //TODO: DrawChordsScreen()
          DrawChordsScreen();
          CurrState = CHORDS;
          break;
        case BackBtn: //Back:
          Serial.println("Button 4,1 Hit");
          CurrState = HOME;
          DrawHomeScreen();
          break;
      }
      break;
    case SHIFTING:
      switch (BtnPressed){
        case Btn1: 
          currentLesson = 1;
          currentLessonType = 1;
          DrawShiftingLesson();
          CurrState = PLAYING_LESSON;
          break;
        case Btn2:
          currentLesson = 2;
          currentLessonType = 1;
          DrawShiftingLesson();
          CurrState = PLAYING_LESSON;
          break;
        case Btn3: 
          currentLesson = 3;
          currentLessonType = 1;
          DrawShiftingLesson();
          CurrState = PLAYING_LESSON;
          break;
        case BackBtn:
          DrawLessonsScreen();
          CurrState = LESSONS;
          break;
      }
      break;
    case SUSTAIN:
      switch (BtnPressed){
        case Btn1:
          currentLesson = 1;
          currentLessonType = 2;
          DrawSustainLesson();
          CurrState = PLAYING_LESSON;
          break;
        case Btn2:
          currentLesson = 2;
          currentLessonType = 2;
          DrawSustainLesson();
          CurrState = PLAYING_LESSON;
          break;
        case Btn3:
          currentLesson = 3;
          currentLessonType = 2;
          DrawSustainLesson();
          CurrState = PLAYING_LESSON;
          break;
        case BackBtn:
          DrawLessonsScreen();
          CurrState = LESSONS;
          break;
      }
      break;
    case CHORDS:
      switch (BtnPressed){
        case Btn1:
          currentLesson = 1;
          currentLessonType = 3;
          DrawChordsLesson();
          CurrState = PLAYING_LESSON;
          break;
        case Btn2:
          currentLesson = 2;
          currentLessonType = 3;
          DrawChordsLesson();
          CurrState = PLAYING_LESSON;
          break;
        case Btn3:
          currentLesson = 3;
          currentLessonType = 3;
          DrawChordsLesson();
          CurrState = PLAYING_LESSON;
          break;
        case BackBtn:
          DrawLessonsScreen();
          CurrState = LESSONS;
          break;
      }
      break;
    case PLAYING_LESSON:
      switch (BtnPressed){
        case Btn1: //PlayPause:
          //TODO: PlayPause() DOMINO //Use a change of flag in the interrupt for this
                                     //  -- to know if it is on Play or Pause.
                                     // within PlayPause() will be LED functionality.
                                     
          break;
        case Btn2: //Quit:
          DrawFinishedLessons();
          CurrState = FINISHED_LESSON;
          break;
      }
      break;
    case FINISHED_LESSON:
      switch (BtnPressed){
        case Btn1: //Lessons:
          DrawLessonsScreen();
          CurrState = LESSONS;
          break;
        case Btn2:
          DrawHomeScreen();
          CurrState = HOME;
          break;
      }
      break;
/****************************** LEARN MODE *************************************/ 
    case LEARN:
      Serial.println("In Learn ");
      switch (BtnPressed){
        case Btn1: 
          currentLearn = 1;
          DrawLearnSong();
          CurrState = LEARNING_SONG;
          break;
        case Btn2: 
          currentLearn = 2;
          DrawLearnSong();
          CurrState = LEARNING_SONG;
          break;
        case Btn3: 
          currentLearn = 3;
          DrawLearnSong();
          CurrState = LEARNING_SONG;
          break;
        case Btn4: 
          currentLearn = 4;
          DrawLearnSong();
          CurrState = LEARNING_SONG;
          break;
        case BackBtn: //Back:
          DrawHomeScreen();
          CurrState = HOME;
          break;       
      }
      break;
    case LEARNING_SONG:
        /*TODO: LearnSong() this function should check whatever variable you have assigned
                              for each song, so that it can just do a quick, "switch(songNumber)"
                              to know which song to Learn, should also have this line at the end 
                              "CurrState = LEARNING_SONG"

                              ALTERNATIVE: Should keep track of the song in each case "SONG1/2/3"

                              This function controls the entire functionality for Learning a Song
                              ex. Control Placement LED
          */
      switch (BtnPressed){
        case Btn1: //PlayPause:
          //TODO: PlayPause() //Use a change of flag in the interrupt for this
          //                     -- to know if it is on Play or Pause.
          break;
        case Btn2:
          DrawFinishedLearning();
          CurrState = FINISHED_LEARNING;
          break;
      }
      break;
   case FINISHED_LEARNING:
      switch (BtnPressed){
        case Btn1: //PlayCurrentSong:
          DrawLearnScreen();
          CurrState = LEARN;
          break;
        case Btn2:
          DrawHomeScreen();
          CurrState = HOME;
          break;
      }
      break;
/******************************** PLAY MODE **********************************/
   case PLAY:
      Serial.println("In Play ");
      switch (BtnPressed){
        case Btn1: 
          currentPlay = 1;
          DrawPlaySong();
          CurrState = PLAYING_SONG;
          break;
        case Btn2: 
          currentPlay = 2;
          DrawPlaySong();
          CurrState = PLAYING_SONG;
          break;
        case Btn3: 
          currentPlay = 3;
          DrawPlaySong();
          CurrState = PLAYING_SONG;
          break;
        case Btn4: 
          currentPlay = 4;
          DrawPlaySong();
          CurrState = PLAYING_SONG;
          break;
        case BackBtn: //Back:
          DrawHomeScreen();
          CurrState = HOME;
          break;       
      }
      break;
   case PLAYING_SONG:
        /*TODO: PlaySong() this function should check whatever variable you have assigned
                              for each song, so that it can just do a quick, "switch(songNumber)"
                              to know which song to Learn, should also have this line at the end 
                              "CurrState = PlAYING_SONG"

                              ALTERNATIVE: Should keep track of the song in each case "SONG1/2/3"

                              This function controls the entire functionality for Playing a Song
                              ex. No Control Placement LED, instead uses the tempo.
          */
      switch (BtnPressed){
        case Btn1: //PlayPause:
          //TODO: PlayPause() //Use a change of flag in the interrupt for this
          //                     -- to know if it is on Play or Pause.
          paused = !paused;
          if (!paused) {
    //        tft.fillRect(20, 300, 480, 260, HX8357_WHITE);
          }
          else {
      //      tft.fillRect(20, 300, 480, 260, HX8357_WHITE);
          }
          break;
        case Btn2: //Quit:
          //TODO: Quit(); //quits the song, and takes user to the results
          DrawFinishedPlaying();
          CurrState = FINISHED_PLAYING;
          break;
        
        //TODO: At 100% in this screen it should change State. Ex. "CurrState = FINSIHED_PlAYING"
        //TODO: DrawFinishedPlaying();
      }
      break;
   case FINISHED_PLAYING:
      switch (BtnPressed){
        case Btn1: //SongSelect:
          DrawPlayScreen();
          CurrState = PLAY;  
          break;
        case Btn2: //SongSelect:
          DrawHomeScreen();
          CurrState = HOME;  
          break;
      }
      break;

/********************************* SETTINGS ***********************************/
  case SETTINGS:
    Serial.println("In Settings ");
    switch (BtnPressed){
      //TODO: ALL SETTINGS OPTIONS AND FUNCTIONALITY
      case BackBtn: //Back:
          DrawHomeScreen();
          CurrState = HOME;
          break; 
    }
    break;
  } //State Switch Closing Brace
  BtnPressed = NONE;
}

void InitializeState(){
 CurrState = HOME;
 BtnPressed = NONE;
 DrawHomeScreen();
 currentLesson = 0;
 currentLearn = 0;
 currentPlay = 0;
}


