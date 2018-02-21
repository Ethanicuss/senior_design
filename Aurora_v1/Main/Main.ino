#include <TouchScreen.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_HX8357.h>
#include <TouchScreen.h>
#include <SPI.h>
#include <SD.h>
#include "Switches.h"
#include "SD.h"
#include "Controls.h"

#include <Fonts/JosefinSans_Bold20pt7b.h>
#include <Fonts/JosefinSans_Bold12pt7b.h>
#include <Fonts/JosefinSans_Bold10pt7b.h>
#include <Fonts/JosefinSans_Bold8pt7b.h>
#include <Fonts/JosefinSans_BoldItalic20pt7b.h>
#include <Fonts/JosefinSans_BoldItalic12pt7b.h>
#include <Fonts/JosefinSans_BoldItalic10pt7b.h>
#include <Fonts/JosefinSans_BoldItalic8pt7b.h>

extern bool play; 

//creating type "State"
enum State {HOME = 0, LESSONS = 1, LEARN = 2, PLAY = 3, SETTINGS = 4, SHIFTING = 5, SUSTAIN = 6, CHORDS = 7, PLAYING_LESSON = 8, LEARNING_SONG = 9, PLAYING_SONG = 10, FINISHED_LESSON = 11, FINISHED_LEARNING = 12, FINISHED_PLAYING = 13};

//creating variable of type "State" called CurrState
enum State CurrState;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("In setup");
  play = true;
  setupLED();
  setupSD();
  LCDSetup();
  TouchscreenSetup();
  int bpm = openFile("freefall.txt");
  String song = readFile();
  lightLED(song);
  InitializeVars(); 
  analogReadResolution(12);
}

void loop() {
  
  //SWITCH STATEMENT THAT HANDLES EVERY SCREEN STATE
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
          //TODO: DrawLessonsScreen() DON
          DrawLessonsScreen();
          CurrState = LESSONS;
          break;
        case Btn2: //LEARN:
          Serial.println("Button 2 Hit");
          //TODO: DrawLearnScreen() DON
          DrawLearnScreen();
          CurrState = LEARN;
          break;
        case Btn3: //PLAY:
          Serial.println("Button 3 Hit");
          //TODO: DrawPlayScreen() DON
          DrawPlayScreen();
          CurrState = PLAY;
          break;
        case Btn4: //SETTINGS:
          Serial.println("Button 4 Hit");
          //TODO: DrawSettingsScreen()
          DrawSettingsScreen();
          CurrState = SETTINGS;
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
          CurrState = SUSTAIN;
          break;
        case Btn3: //CHORDS:
          Serial.println("Button 3.1 Hit");
          //TODO: DrawChordsScreen()
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
        case Btn1: //Shifting101:
          //TODO: DrawShiftingLesson(101);
            // -- Make Changes for each Difficulty withing the draw
            // -- ex. print("101")
          DrawShiftingLesson();
          CurrState = PLAYING_LESSON;
          break;
        case Btn2: //Shifting102:
          //TODO: DrawShiftingLesson(102);
              // -- Make Changes for each Difficulty within the draw
              // -- ex. print("102")
          CurrState = PLAYING_LESSON;
          break;
        case Btn3: //Shifting103:
          //TODO: DrawShiftingLesson(103);
            // -- Make Changes for each Difficulty within the draw
            // -- ex. print("101")
          CurrState = PLAYING_LESSON;
          break;
        case BackBtn: //Back:
          //TODO: DrawLessonsScreen()
          CurrState = LESSONS;
          break;
      }
      break;
    case SUSTAIN:
      switch (BtnPressed){
        case Btn1: //Sustain101:
          //TODO: DrawSustainLesson();
            // -- Make Changes for each Difficulty within the draw
            // -- ex. print("101")
          CurrState = PLAYING_LESSON;
          break;
        case Btn2: //Sustain102:
          //TODO: DrawSustainLesson();
              // -- Make Changes for each Difficulty within the draw
              // -- ex. print("102")
          CurrState = PLAYING_LESSON;
          break;
        case Btn3: //Sustain103:
          //TODO: DrawSustainLesson();
            // -- Make Changes for each Difficulty within the draw
            // -- ex. print("101")
          CurrState = PLAYING_LESSON;
          break;
        case BackBtn: //Back:
          //TODO: DrawLessonsScreen()
          CurrState = LESSONS;
          break;
      }
      break;
    case CHORDS:
      switch (BtnPressed){
        case Btn1: //Chords101:
          //TODO: DrawChordsLesson();
            // -- Make Changes for each Difficulty within the draw
            // -- ex. print("101")
          CurrState = PLAYING_LESSON;
          break;
        case Btn2: //Chords102:
          //TODO: DrawChordsLesson();
              // -- Make Changes for each Difficulty within the draw
              // -- ex. print("102")
          CurrState = PLAYING_LESSON;
          break;
        case Btn3: //Chords103:
          //TODO: DrawChordsLesson();
            // -- Make Changes for each Difficulty within the draw
            // -- ex. print("101")
          CurrState = PLAYING_LESSON;
          break;
        case BackBtn: //Back:
          //TODO: DrawLessonsScreen()
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
          //TODO: DrawFinishedLesson();
          //TODO: Quit(); //within this function should be a "CurrState = FINISHED_LESSON"
        
        //TODO: At 100% in this screen it should change State. Ex. "CurrState = FINISHED_LESSON"
        //TODO: 
          break;
      }
      break;
    case FINISHED_LESSON:
      switch (BtnPressed){
        case Btn1: //Lessons:
          //TODO: CurrState = DrawLessonsScreen();
          break;
      }
      break;
/****************************** LEARN MODE *************************************/ 
    case LEARN:
      Serial.println("In Learn ");
      switch (BtnPressed){
        case Btn1: //SONG1:
          //TODO: DrawLearnSong(); draws the learning song screen
          CurrState = LEARNING_SONG;
          break;
        case Btn2: //SONG2:
          //TODO: DrawLearnSong();
          CurrState = LEARNING_SONG;
          break;
        case Btn3: //SONG3:
          //TODO: DrawLearnSong();
          CurrState = LEARNING_SONG;
          break;
        case Btn4: //SONG1:
          //TODO: DrawLearnSong(); draws the learning song screen
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
        case Btn2: //Quit:
          //TODO: Quit(); //within this function should be a "CurrState = FINISHED_LEARNING"
          //TODO: DrawFinishedLearning();
          break;
        
        //TODO: At 100% in this screen it should change State. Ex. "CurrState = FINSIHED_LEARNING
        //TODO: DrawFinishedLearning();
      }
      break;
   case FINISHED_LEARNING:
      switch (BtnPressed){
        case Btn1: //PlayCurrentSong:
          //TODO: PlaySong();  
          break;
        case BackBtn:
          //TODO: DrawLearnScreen();
          CurrState = LEARN;
          break;
      }
      break;
/******************************** PLAY MODE **********************************/
   case PLAY:
      Serial.println("In Play ");
      switch (BtnPressed){
        case Btn1: 
          DrawPlaySong(1);
          CurrState = PLAYING_SONG;
          break;
        case Btn2: 
          DrawPlaySong(2);
          CurrState = PLAYING_SONG;
          break;
        case Btn3: 
          DrawPlaySong(3);
          CurrState = PLAYING_SONG;
          break;
        case Btn4: 
          DrawPlaySong(4);
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
          break;
        case Btn2: //Quit:
          //TODO: Quit(); //quits the song, and takes user to the results
          //TODO: DrawFinishedPlaying();
          CurrState = FINISHED_PLAYING;
          break;
        
        //TODO: At 100% in this screen it should change State. Ex. "CurrState = FINSIHED_PlAYING"
        //TODO: DrawFinishedPlaying();
      }
      break;
   case FINISHED_PLAYING:
      switch (BtnPressed){
        case Btn1: //SongSelect:
          //TODO: DrawPlayScreen();
          CurrState = PLAY;  
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

void InitializeVars(){
 CurrState = HOME;
 BtnPressed = NONE;
 DrawHomeScreen();
}


