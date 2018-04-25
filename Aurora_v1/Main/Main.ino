#include <TouchScreen.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_HX8357.h>
#include <DueTimer.h>
#include <SPI.h>
#include <SD.h>
#include "LCD.h"
#include "Controls.h"
#include "State.h"
#include "Record.h"

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

void setup() {
  Serial.begin(9600);
  Serial.println("In setup");
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
          if(currentPage == 0) {
            DrawLessonsScreen();
            CurrState = LESSONS;
          }
          else {
            DrawRecordScreen();
            CurrState = REC_MODE;
          }
          break;
        case Btn2: //LEARN:
          Serial.println("Button 2 Hit");
          if(currentPage == 0) {
            DrawLearnScreen();
            CurrState = LEARN;
          }
          else {
            DrawUploadScreen();
            CurrState = HOME;
          }
          break;
        case Btn3: //PLAY:
          Serial.println("Button 3 Hit");
          if(currentPage == 0) {
            DrawPlayScreen();
            CurrState = PLAY;
          }
          else {
            DrawDownloadsScreen();
            CurrState = DOWNLOADS;
          }
          
          break;
        case Btn4: //NEXT PAGE:
          Serial.println("Button 4 Hit");
          if(currentPage == 0) {
            currentPage = 1;
          }
          else {
            currentPage = 0;
          }
          DrawHomeScreenButtons();
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
          songSetup("shift1.txt");
          DrawShiftingLesson();
          DrawCountdown();
          CurrState = PLAYING_LESSON;
          break;
        case Btn2:
          currentLesson = 2;
          currentLessonType = 1;
          songSetup("shift2.txt");
          DrawShiftingLesson();
          DrawCountdown();
          CurrState = PLAYING_LESSON;
          break;
        case Btn3: 
          currentLesson = 3;
          currentLessonType = 1;
          songSetup("shift3.txt");
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
          songSetup("sustain1.txt");
          DrawSustainLesson();
          DrawCountdown();
          CurrState = PLAYING_LESSON;
          break;
        case Btn2:
          currentLesson = 2;
          currentLessonType = 2;
          songSetup("sustain2.txt");
          DrawSustainLesson();
          CurrState = PLAYING_LESSON;
          break;
        case Btn3:
          currentLesson = 3;
          currentLessonType = 2;
          songSetup("sustain3.txt");
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
          songSetup("chord1.txt");
          DrawChordsLesson();
          DrawCountdown();
          CurrState = PLAYING_LESSON;
          break;
        case Btn2:
          currentLesson = 2;
          currentLessonType = 3;
          songSetup("chord2.txt");
          DrawChordsLesson();
          CurrState = PLAYING_LESSON;
          break;
        case Btn3:
          currentLesson = 3;
          currentLessonType = 3;
          songSetup("chord3.txt");
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
      //PlaySong_TK(songTitle); // IS THIS SUPPOSED TO BE HERE???

      Serial.println("IN PLAYING_LESSON");
      
      switch (BtnPressed){
        case Btn1: //PlayPause:
          //TODO: PlayPause() DOMINO //Use a change of flag in the interrupt for this
                                     //  -- to know if it is on Play or Pause.
                                     // within PlayPause() will be LED functionality.
          
          Serial.println("SHOULD PAUSE");
          DrawPause();
          PreState = PLAYING_LESSON;
          CurrState = PAUSED;                           
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
          songSetup("wonderwa.txt");
          DrawCountdown();
          CurrState = LEARNING_SONG;
          break;
        case Btn2: 
          currentLearn = 2;
          DrawLearnSong();
          songSetup("freefall.txt");
          DrawCountdown();
          CurrState = LEARNING_SONG;
          break;
        case Btn3: 
          currentLearn = 3;
          DrawLearnSong();
          songSetup("bridge.txt");
          DrawCountdown();
          CurrState = LEARNING_SONG;
          break;
//        case Btn4: 
//          currentLearn = 4;
//          DrawLearnSong();
//          songSetup("imyours.txt");
//          for (int i = 0; i < 3; i++){
//            //TODO: DrawCountDown()
//            Serial.print("Song Starts in: ");
//            Serial.println(i);
//          }
//          CurrState = LEARNING_SONG;
//          break;
        case BackBtn: //Back:
          DrawHomeScreen();
          CurrState = HOME;
          break;       
      }
      break;
    case LEARNING_SONG:
        LearnSong_TK(songTitle);
        Serial.println("Learning Song");
        DrawPlayPercent();
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
          DrawPause();
          PreState = LEARNING_SONG;
          CurrState = PAUSED;
          break;
        case Btn2: //Quit:
          DrawFinishedLearning();
          Quit();
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
          Quit();
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
          songSetup("wonderwa.txt");
          //playMode = true;
          DrawCountdown();
          //FirstNote();
          CurrState = PLAYING_SONG;
          break;
        case Btn2: 
          currentPlay = 2;
          DrawPlaySong();
          songSetup("freefall.txt");
          //playMode = true;
          FirstNote();
          DrawCountdown();
          CurrState = PLAYING_SONG;
          break;
        case Btn3: 
          currentPlay = 3;
          DrawPlaySong();
          songSetup("bridge.txt");
          //playMode = true;
          FirstNote();
          DrawCountdown();
          CurrState = PLAYING_SONG;
          break;
//        case Btn4: 
//          currentPlay = 4;
//          DrawPlaySong();
//          songSetup("imyours.txt");
//          //playMode = true;
//          FirstNote();
//          DrawCountdown();
//          CurrState = PLAYING_SONG;
          break;
        case BackBtn: //Back:
          DrawHomeScreen();
          CurrState = HOME;
          break;       
      }
      break;
   case PLAYING_SONG:
        PlaySong_TK(songTitle);
        DrawPlayPercent(); // GET LEARN PERCENT IF IT'S DIFFERENT THAN PLAY PERCENT
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
          DrawPause();
          PreState = PLAYING_SONG;
          CurrState = PAUSED;
          break;
        case Btn2: //Quit:
          DrawFinishedPlaying();
          Quit();
          CurrState = FINISHED_PLAYING;
          break;
      }
      break;
   case FINISHED_PLAYING:
      //playMode = false;
      Serial.println("Song fin");
      songEnd = 0;
      switch (BtnPressed){
        case Btn1: //SongSelect:
          DrawPlayScreen();
          CurrState = PLAY;  
          break;
        case Btn2: //SongSelect:
          DrawHomeScreen();
          // Quit(); possibly extraneous
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
/********************************** PAUSED **************************************/
  case PAUSED:
    Serial.println("Paused");
    //Serial.println(PreState);
    //Serial.println(BtnPressed);
    switch (BtnPressed){
      case Btn1: //Play - resume
        if (PreState == PLAYING_SONG){
          DrawPlay();
          PreState = PAUSED;
          CurrState = PLAYING_SONG; 
        }
        else if (PreState == LEARNING_SONG){
          //Draw
          DrawPlay();
          PreState = PAUSED;
          CurrState = LEARNING_SONG;
        }
        else if (PreState == PLAYING_LESSON){
          //Draw
          DrawPlay();
          PreState = PAUSED;
          CurrState = PLAYING_LESSON;
        }
        break;
      case Btn2: //Quit
        if (PreState == PLAYING_SONG){
          DrawFinishedPlaying();
          PreState = PAUSED;
          Quit();
          CurrState = FINISHED_PLAYING; 
        }
        else if (PreState == LEARNING_SONG){
          DrawFinishedLearning();
          PreState = PAUSED;
          Quit();
          CurrState = FINISHED_LEARNING;
        }
        else if (PreState == PLAYING_LESSON){
          DrawFinishedLessons();
          PreState = PAUSED;
          Quit();
          CurrState = FINISHED_LESSON;
        }
        //STAY HERE IF PAUSED & no button is being hit.
        //TESTING
        break;
    }
    break;
/****************************** RECORD *****************************/
/************ REC_MODE ****************/
  case REC_MODE:
    switch(BtnPressed){
      case Btn1: //Record a song
        DrawChooseBMP();
        CurrState = CHOOSE_BPM;
        break;
      case Btn2: //Learn a recording
        currentLearn = 5;
        DrawLearnSong();
        songSetup("record1.txt");
        DrawCountdown();
        CurrState = LEARNING_SONG;
        break;
      case Btn3:
        currentPlay = 5;
        DrawPlaySong();
        songSetup("record1.txt");
        FirstNote();
        DrawCountdown();
        CurrState = PLAYING_SONG;
        break;
      case BackBtn:
        DrawHomeScreen();
        CurrState = HOME;
        break;
    }
    break;
/********* CHOOSE_BPM *****************/
  case CHOOSE_BPM:
    switch (BtnPressed){
      case Btn1: //increase BPM
        BPM -= 10;
        if (BPM <= 0) BPM = 0;
        DrawBPMNumber();
        break;
      case Btn2: //decrease BPM
        BPM--;
        if (BPM <= 0) BPM = 0;
        DrawBPMNumber();
        break;
      case Btn3: //increase BPM by 10
        BPM++;
        DrawBPMNumber();
        break;
      case Btn4: //decrease BPM by 10
        BPM += 10;
        DrawBPMNumber();
        break;
      case Btn5: //continue
        //TODO: Create File for Recording
        mkRecording();
        n++;
        i = 0;
        color = 'r';
        Draw_REC_RED();
        CurrState = REC_RED;
        break;
      case Btn6: //quit
        DrawHomeScreen();
        CurrState = HOME;
        break;
    }
    break;
/*********** Record-Red*************/
  case REC_RED:
 //   recordedString = recordPlacement();
    switch (BtnPressed){
      case Btn1: //next color
        color = 'b';
        i = i+3;
        Draw_REC_BLUE();
        CurrState = REC_BLUE;
        break;
      case Btn2: //FINISHED
        LightLED(recordedString, true);
        Draw_REC_TEMPO();
        CurrState = REC_TEMPO;
        PreState = REC_RED;
        break;
      case Btn3: //Back
        DarkLED(recordedString);
        DrawHomeScreen();
        CurrState = HOME;
        break;
    }
    break;
//************ Record-Blue ********/
  case REC_BLUE:
  //  recordedString = recordPlacement();
    switch (BtnPressed){
      case Btn1: //next color
        color = 'g';
        i = i+3;
        Draw_REC_GREEN();
        CurrState = REC_GREEN;
        break;
      case Btn2: //FINISHED
        LightLED(recordedString, true);
        Draw_REC_TEMPO();
        CurrState = REC_TEMPO;
        PreState = REC_BLUE;
        break;
      case Btn3: //Back
        recordedString[i-1] = 'x';
        recordedString[i-2] = 'x';
        recordedString[i-3] = 'x';
        LightLED(recordedString, false);
        i = i-3;
        if (i < 0){
          Serial.print("null exception");
        }
        Draw_REC_RED();
        CurrState = REC_RED;
        break;
    }
    break;
//************ Record-Green ********/
  case REC_GREEN:
 //   recordedString = recordPlacement();
    switch (BtnPressed){
      case Btn1: //next color
        color = 'p';
        i = i+3;
        Draw_REC_PURPLE();
        CurrState = REC_PURPLE;
        break;
      case Btn2: //FINISHED
        LightLED(recordedString, true);
        Draw_REC_TEMPO();
        CurrState = REC_TEMPO;
        PreState = REC_GREEN;
        break;
      case Btn3: //Back
        recordedString[i-1] = 'x';
        recordedString[i-2] = 'x';
        recordedString[i-3] = 'x';
        LightLED(recordedString, false);
        i = i-3;
        if (i < 0){
          Serial.print("null exception");
        }
        Draw_REC_BLUE();
        CurrState = REC_BLUE;
        break;
    }
    break;
//************ Record-Purple ********/
  case REC_PURPLE:
 //   recordedString = recordPlacement();
    switch (BtnPressed){
      case Btn1: //are there open strings
        color = 'w';
        i = i+3;
        Draw_REC_OPEN();
        CurrState = REC_OPEN;
        break;
      case Btn2: //FINISHED
        LightLED(recordedString, true);
        Draw_REC_TEMPO();
        CurrState = REC_TEMPO;
        PreState = REC_PURPLE;
        break;
      case Btn3: //Back
        recordedString[i-1] = 'x';
        recordedString[i-2] = 'x';
        recordedString[i-3] = 'x';
        LightLED(recordedString, false);
        i = i-3;
        if (i < 0){
          Serial.print("null exception");
        }
        Draw_REC_GREEN();
        CurrState = REC_GREEN;
        break;
    }
    break;
//************* Record-Open*******/
  case REC_OPEN:
    switch (BtnPressed){
      case Btn1: //String E
        if (buffer[0] == 'E'){
          buffer[0] = 'x';
          openStrings[0] = false;
        }
        else {
          buffer[0] = 'E';
          openStrings[0] = true;
          //if present, remove from buffer (dehighlight box)
        }
        DrawOpenHighlight(0, openStrings[0]);
        break;
      case Btn2: //String A
        if (buffer[1] == 'A'){
          buffer[1] = 'x';
          openStrings[1] = false;
        }
        else {
          buffer[1] = 'A';
          openStrings[1] = true;
          //add to buffer (highlight box)
          //if present remove from buffer (dehighlight box)
        }
        DrawOpenHighlight(1, openStrings[1]);
        break;
      case Btn3: //String D
        if (buffer[2] == 'D'){
          buffer[2] = 'x';
          openStrings[2] = false;
        }
        else {
          buffer[2] = 'D';
          openStrings[2] = true;
          //add to buffer (highlight box)
          //if present remove from buffer (dehighlight box)
        }
        DrawOpenHighlight(2, openStrings[2]);
        break;
      case Btn4: //String G
        if (buffer[3] == 'G'){
          buffer[3] = 'x';
          openStrings[3] = false;
        }
        else {
          buffer[3] = 'G';
          openStrings[3] = true;
          //add to buffer (highlight box)
          //if present remove from buffer (dehighlight box)
        }
        DrawOpenHighlight(3, openStrings[3]);
        break;
      case Btn5: //String b
        if (buffer[4] == 'B'){
          buffer[4] = 'x';
          openStrings[4] = false;
        }
        else {
          buffer[4] = 'B';
          openStrings[4] = true;
          //add to buffer (highlight box)
          //if present remove from buffer (dehighlight box)
        }
        DrawOpenHighlight(4, openStrings[4]);
        break;
      case Btn6: //String e
        if (buffer[5] == 'e'){
          buffer[5] = 'x';
          openStrings[5] = false;
        }
        else {
          buffer[5] = 'e';
          openStrings[5] = true;
          //add to buffer (highlight box)
          //if present remove from buffer (dehighlight box)
        }
        DrawOpenHighlight(5, openStrings[5]);
        break;
      case Btn7: //Confirm
        //write all open strings to "recordedString"
        Draw_REC_TEMPO();
        CurrState = REC_TEMPO;
        PreState = REC_OPEN;
        break;
      case Btn8: //Back
        //TODO: empty buffer
        recordedString[i-1] = 'x';
        recordedString[i-2] = 'x';
        recordedString[i-3] = 'x';
        LightLED(recordedString, false);
        i = i-3;
        if (i < 0){
          Serial.print("null exception");
        }
        Draw_REC_PURPLE();
        CurrState = REC_PURPLE;
        CurrState = PreState;
        break;
    }
    break;
//******Record-Tempo******/
  case REC_TEMPO:
  Serial.print("In REC TEMPO");
    switch(BtnPressed){
      case Btn1: //Half note
        //write recordedString to File
        writeToFile(recordedString);
        //write timing value to File
        writeToFile(String(BPMtoTiming(BPM, 2)));
        Draw_REC_NEXT();
        CurrState = REC_NEXT;
        break;
      case Btn2: //Quarter note
        //write recordedString to File
        writeToFile(recordedString);
        //write timing value to File
        writeToFile(String(BPMtoTiming(BPM, 1)));
        Draw_REC_NEXT();
        CurrState = REC_NEXT;
        break;
      case Btn3: //Eigth note
        //write recordedString to File
        writeToFile(recordedString);
        //write timing value to File
        writeToFile(String(BPMtoTiming(BPM, (1/2))));
        Draw_REC_NEXT();
        CurrState = REC_NEXT;
        break;
      case Btn4: //sixteenth note
        //write recordedString to File
        writeToFile(recordedString);
        //write timing value to File
        writeToFile(String(BPMtoTiming(BPM, (1/4))));
        Draw_REC_NEXT();
        CurrState = REC_NEXT;
        break;
    }
    break;
  //********* Record-Next*******/
  case REC_NEXT:
    switch(BtnPressed){
      case Btn1: //go to next note
        //if needed move to nextline in File.
        Draw_REC_RED();
        //increment numNotes
        numNotes++;
        CurrState = REC_RED;
        break;
      case Btn2: //Finished Song
        //DrawPopUp - saying that song has been saved in ____
        //overwrite the numNotes in the song
        void resetPointer();
        writeToFile(String(numNotes));
        DrawHomeScreen();
        CurrState = HOME;
        break;
    }
    break;
  

//**************************DOWNLOADS*****************************//

  case DOWNLOADS:
    switch(BtnPressed){
      case Btn1:
          DrawDownloadsLearnScreen();
          CurrState = DOWNLOADS_LEARN;
        break;
      case Btn2:
          DrawDownloadsPlayScreen();
          CurrState = DOWNLOADS_PLAY;
        break;
      case BackBtn:
        DrawHomeScreen();
        CurrState = HOME;
        break;
    }
    break;

  case DOWNLOADS_LEARN:
    switch(BtnPressed){
        case Btn1: 
          currentLearn = 6;
          DrawLearnSong();
        //  songSetup("wonderwa.txt");
          DrawCountdown();
          CurrState = LEARNING_SONG;
          break;
        case Btn2: 
          currentLearn = 7;
          DrawLearnSong();
       //   songSetup("freefall.txt");
          DrawCountdown();
          CurrState = LEARNING_SONG;
          break;
        case Btn3: 
          currentLearn = 8;
          DrawLearnSong();
        //  songSetup("bridge.txt");
          DrawCountdown();
          CurrState = LEARNING_SONG;
          break;
        case Btn4: 
          currentLearn = 9;
          DrawLearnSong();
        //  songSetup("imyours.txt");
          DrawCountdown();
          CurrState = LEARNING_SONG;
          break;
        case BackBtn:
          DrawDownloadsScreen();
          CurrState = DOWNLOADS;
          break;
      }
    break;


  case DOWNLOADS_PLAY:
    switch(BtnPressed) {
      case Btn1: 
          currentPlay = 6;
          DrawPlaySong();
          //songSetup("wonderwa.txt");
          DrawCountdown();
          //FirstNote();
          CurrState = PLAYING_SONG;
          break;
        case Btn2: 
          currentPlay = 7;
          DrawPlaySong();
         // songSetup("freefall.txt");
          FirstNote();
          DrawCountdown();
          CurrState = PLAYING_SONG;
          break;
        case Btn3: 
          currentPlay = 8;
          DrawPlaySong();
        //  songSetup("bridge.txt");
          FirstNote();
          DrawCountdown();
          CurrState = PLAYING_SONG;
          break;
        case Btn4: 
          currentPlay = 9;
          DrawPlaySong();
        //  songSetup("imyours.txt");
          FirstNote();
          DrawCountdown();
          CurrState = PLAYING_SONG;
          break;
        case BackBtn: //Back:
          DrawDownloadsScreen();
          CurrState = DOWNLOADS;
          break;       
    }
  } //State Switch Closing Brace
  BtnPressed = NONE;
}


