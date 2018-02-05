#include "Switches.h"
#include "SD.h"
#include "Controls.h"

extern bool play; 

//creating type "State"
enum State {HOME = 0, LESSONS = 1, LEARN = 2, PLAY = 3, SETTINGS = 4, SHIFTING = 5, SUSTAIN = 6, CHORDS = 7, PLAYING_LESSON = 8, LEARNING_SONG = 9, PLAYING_SONG = 10, FINISHED_LESSON = 11, FINISHED_LEARNING = 12, FINISHED_PLAYING = 13};

//creating variable of type "State" called CurrState
enum State CurrState;

void setup() {
  // put your setup code here, to run once:
  InitializeVars();
  play = true;
  setupLED();
  setupSD();
  int bpm = openFile("freefall.txt");
  String song = readFile();
  lightLED(song);
}

void loop() {
  
  //SWITCH STATEMENT THAT HANDLES EVERY SCREEN STATE
  // -- See UI Diagram for Control Flow Graph
/****************** HOME SCREEN OPTIONS *****************/
  switch(CurrState){
    case HOME:
      //TODO; HOME
      //TODO: DrawHomeScreen();
      switch (BtnPressed){
        case LESSONS:
          //TODO: DrawLessonsScreen() DON
          CurrState = LESSONS;
          break;
        case LEARN:
          //TODO: DrawLearnScreen() DON
          CurrState = LEARN;
          break;
        case PLAY:
          //TODO: DrawPlayScreen() DON
          CurrState = PLAY;
          break;
        case SETTINGS:
          //TODO: DrawSettingsScreen()
          CurrState = SETTINGS;
          break;
      }
/*********************** LESSONS MODE **********************/
    case LESSONS:
      //TODO - LESSONS
      switch (BtnPressed){
        case SHIFTING:
          //TODO: DrawShiftingScreen()
          CurrState = SHIFTING;
          break;
        case SUSTAIN:
          //TODO: DrawSustainScreen()
          CurrState = SUSTAIN;
          break;
        case CHORDS:
         //TODO: DrawChordsScreen()
         CurrState = CHORDS;
         break;
      }
    case SHIFTING:
      switch (BtnPressed){
        case Btn1: //Shifting101:
          //TODO: DrawShiftingLesson(101);
            // -- Make Changes for each Difficulty withing the draw
            // -- ex. print("101")
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
      }
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
      }
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
      }
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
    case FINISHED_LESSON:
      switch (BtnPressed){
        case Btn1: //Lessons:
          //TODO: CurrState = DrawLessonsScreen();
          break;
      }
/****************************** LEARN MODE *************************************/ 
    case LEARN:
      switch (BtnPressed){
        case Btn1: //UP:
          //TODO: UPsongList() keep track of how many times, possible loop around?
          //TODO: DrawLearnScreen(); //to refresh the screen with the new songs.
          break;
        case Btn2: //DOWN:
          //TODO: DOWNsongList() same as UPsongList
          //TODO: DrawLearnScreen();
          break;
        case Btn3: //SONG1:
          //TODO: DrawLearnSong(); draws the learning song screen
          CurrState = LEARNING_SONG;
          break;
        case Btn4: //SONG2:
          //TODO: DrawLearnSong();
          CurrState = LEARNING_SONG;
          break;
        case Btn5: //SONG3:
          //TODO: DrawLearnSong();
          CurrState = LEARNING_SONG;
          break;      
      }
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
   case FINISHED_LEARNING:
      switch (BtnPressed){
        case Btn1: //PlayCurrentSong:
          //TODO: PlaySong();  
          break;
        case BackBtn:
          CurrState = LEARN;
          break;
      }
/******************************** PLAY MODE **********************************/
   case PLAY:
      switch (BtnPressed){
        case Btn1: //UP:
          //TODO: UPsongList()
          //TODO: DrawPlayScreen(); //to refresh the songlist
          break;
        case Btn2: //DOWN:
          //TODO: DOWNsongList() //same as UPsongList
          //TODO: DrawPlayScreen();
          break;
        case Btn3: //SONG1:
          //TODO: DrawPlaySong(); draws the learning song screen
          CurrState = PLAYING_SONG;
          break;
        case Btn4: //SONG2:
          //TODO: DrawPlaySong();
          CurrState = PLAYING_SONG;
          break;
        case Btn5: //SONG3:
          //TODO: DrawPlaySong();
          CurrState = PLAYING_SONG;
          break;      
      }
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
   case FINISHED_PLAYING:
      switch (BtnPressed){
        case Btn1: //SongSelect:
          CurrState = PLAY;  
          break;
      }
/********************************* SETTINGS ***********************************/
  case SETTINGS:
    switch (BtnPressed){
      //TODO: ALL SETTINGS OPTIONS AND FUNCTIONALITY
    }
  } //State Switch Closing Brace
}

void InitializeVars(){
 CurrState = HOME;
 BtnPressed = NONE;
  
}


