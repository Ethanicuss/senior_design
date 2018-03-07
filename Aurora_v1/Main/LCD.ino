/* TODO: Any function that has "Draw" in it.
 *       
 *       This Module will just draw each screen.
 */
#include "LCD.h"
#include "Controls.h"
#define SD_CS 4
#define TFT_DC 9
#define TFT_CS 10

extern Adafruit_HX8357 tft = Adafruit_HX8357(TFT_CS, TFT_DC);

// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
bool LCDSetup(void) {
  Serial.print("Initializing LCD... ");
  tft.begin(HX8357D);
  tft.setRotation(3);
  tft.fillScreen(HX8357_WHITE);

  Serial.println("done.");
  Serial.print("Initializing SD card... ");
  
  if (!SD.begin(SD_CS)) {
    Serial.println("failed!");
    return false;
  }
  else{
    Serial.println("done.");
    return true;
  }
}

void UpdateScreen(){
}

 void DrawHomeScreen(){
  tft.fillRect(0, 0, 240, 360, HX8357_WHITE);
  tft.fillRect(240, 0, 240, 320/3, 0x00DF);
  tft.fillTriangle(240, 0, 240, 320/3, 255, 320/3, HX8357_WHITE);
  tft.fillRect(240, 320/3, 240, 323/3, 0xF81D);
  tft.fillTriangle(240, 320/3, 240, 320/3+323/3, 255, 320/3+323/3, HX8357_WHITE);
  tft.fillRect(240, 640/3, 240, 326/3, 0x07EE);  
  tft.fillTriangle(240, 640/3, 240, 320/3+323/3+326/3, 255, 320/3+323/3+326/3, HX8357_WHITE);

  tft.setFont(&JosefinSans_BoldItalic20pt7b);
  tft.setTextColor(0x981F);
  tft.setCursor(35, 155);
  tft.print("AURORA");
  tft.setFont(&JosefinSans_Bold8pt7b);
  tft.setCursor(41, 180);
  tft.setTextColor(0x9CF3);
  tft.print("LET'S PLAY GUITAR!");

  tft.setFont(&JosefinSans_Bold20pt7b);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(273, 70);
  tft.print("LESSONS");

  tft.setCursor(300, 170);
  tft.print("LEARN");

  tft.setCursor(315, 283);
  tft.print("PLAY");
 }

 /*********** HOME MENU SCREENS **********/
 void DrawLessonsScreen(){
  tft.fillRect(0, 0, 240, 360, HX8357_WHITE);
  tft.fillRect(240, 0, 240, 320, 0xF81D);
  tft.drawLine(260, 320/3, 460, 320/3, 0xFE5F);
  tft.drawLine(260, 640/3, 460, 640/3, 0xFE5F);

  tft.setFont(&JosefinSans_BoldItalic20pt7b);
  tft.setTextColor(0xF81D);
  tft.setCursor(26, 155);
  tft.print("LESSONS");

  tft.setTextColor(0x9CF3);
  tft.setFont(&JosefinSans_Bold8pt7b);
  tft.setCursor(35, 180);
  tft.print("LEARN BASIC GUITAR");
  tft.setCursor(68, 198);
  tft.print("TECHNIQUES");

  tft.setFont(&JosefinSans_Bold20pt7b);
  tft.setCursor(11, 33);
  tft.print("<");

  tft.setFont(&JosefinSans_Bold15pt7b);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(290, 65);
  tft.print("SHIFTING");

  tft.setCursor(288, 170);
  tft.print("SUSTAINS");

  tft.setCursor(295, 278);
  tft.print("CHORDS");
 }

 void DrawLearnScreen(){
  tft.fillRect(0, 0, 240, 360, HX8357_WHITE);
  tft.fillRect(240, 0, 240, 320, 0xF81D);
  tft.drawLine(260, 80, 465, 80, 0xFE5F);
  tft.drawLine(260, 160, 465, 160, 0xFE5F);
  tft.drawLine(260, 240, 465, 240, 0xFE5F);

  tft.setFont(&JosefinSans_BoldItalic20pt7b);
  tft.setTextColor(0xF81D);
  tft.setCursor(49, 155);
  tft.print("LEARN");

  tft.setTextColor(0x9CF3);
  tft.setFont(&JosefinSans_Bold8pt7b);
  tft.setCursor(28, 180);
  tft.print("SELECT A SONG FOR A");
  tft.setCursor(52, 198);
  tft.print("GUIDED LESSON");

  tft.setFont(&JosefinSans_Bold20pt7b);
  tft.setCursor(11, 33);
  tft.print("<");

  tft.setFont(&JosefinSans_Bold12pt7b);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(275, 40);
  tft.print("WONDERWALL");

  tft.setCursor(280, 120);
  tft.print("FREE FALLIN'");

  tft.setCursor(318, 200);
  tft.print("AFRICA");

  tft.setCursor(300, 280);
  tft.print("I'M YOURS");


  tft.setTextColor(0xFE5F);
  tft.setFont(&JosefinSans_Bold8pt7b);
  tft.setCursor(335, 60);
  tft.print("OASIS");

  tft.setCursor(318, 140);
  tft.print("TOM PETTY");

  tft.setCursor(340, 220);
  tft.print("TOTO");

  tft.setCursor(310, 300);
  tft.print("JASON MRAZ");
 }

 void DrawPlayScreen(){
  tft.fillRect(0, 0, 240, 360, HX8357_WHITE);
  tft.fillRect(240, 0, 240, 320, 0xF81D);
  tft.drawLine(260, 80, 460, 80, 0xFE5F);
  tft.drawLine(260, 160, 460, 160, 0xFE5F);
  tft.drawLine(260, 240, 460, 240, 0xFE5F);

  tft.setFont(&JosefinSans_BoldItalic20pt7b);
  tft.setTextColor(0xF81D);
  tft.setCursor(70, 155);
  tft.print("PLAY");

  tft.setTextColor(0x9CF3);
  tft.setFont(&JosefinSans_Bold8pt7b);
  tft.setCursor(20, 180);
  tft.print("SELECT A SONG TO PLAY");
  tft.setCursor(60, 198);
  tft.print("ON YOUR OWN");

  tft.setFont(&JosefinSans_Bold20pt7b);
  tft.setCursor(11, 33);
  tft.print("<");

  tft.setFont(&JosefinSans_Bold12pt7b);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(275, 40);
  tft.print("WONDERWALL");

  tft.setCursor(280, 120);
  tft.print("FREE FALLIN'");

  tft.setCursor(318, 200);
  tft.print("AFRICA");

  tft.setCursor(300, 280);
  tft.print("I'M YOURS");


  tft.setTextColor(0xFE5F);
  tft.setFont(&JosefinSans_Bold8pt7b);
  tft.setCursor(335, 60);
  tft.print("OASIS");

  tft.setCursor(318, 140);
  tft.print("TOM PETTY");

  tft.setCursor(340, 220);
  tft.print("TOTO");

  tft.setCursor(310, 300);
  tft.print("JASON MRAZ");
 }

 /*********** LESSONS SCREENS ***********/

 void DrawShiftingScreen(){
  tft.fillRect(0, 50, 220, 200, HX8357_WHITE);
  tft.fillRect(240, 0, 240, 320, 0x00DF);
  tft.drawLine(260, 320/3, 460, 320/3, 0xFE5F);
  tft.drawLine(260, 640/3, 460, 640/3, 0xFE5F);

  tft.setFont(&JosefinSans_BoldItalic20pt7b);
  tft.setTextColor(0x00DF);
  tft.setCursor(26, 155);
  tft.print("SHIFTING");

  tft.setTextColor(0x9CF3);
  tft.setFont(&JosefinSans_Bold8pt7b);
  tft.setCursor(32, 180);
  tft.print("LEARN PROPER HAND");
  tft.setCursor(70, 198);
  tft.print("MOVEMENT");

  tft.setFont(&JosefinSans_Bold20pt7b);
  tft.setCursor(11, 33);
  tft.print("<");

  tft.setFont(&JosefinSans_Bold12pt7b);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(283, 65);
  tft.print("SHIFTING 101");

  tft.setCursor(283, 170);
  tft.print("SHIFTING 102");

  tft.setCursor(283, 278);
  tft.print("SHIFTING 103");
 }

 void DrawSustainScreen(){
  tft.fillRect(0, 50, 220, 200, HX8357_WHITE);
  tft.fillRect(240, 0, 240, 320, 0x00DF);
  tft.drawLine(260, 320/3, 460, 320/3, 0xFE5F);
  tft.drawLine(260, 640/3, 460, 640/3, 0xFE5F);

  tft.setFont(&JosefinSans_BoldItalic20pt7b);
  tft.setTextColor(0x00DF);
  tft.setCursor(23, 155);
  tft.print("SUSTAINS");

  tft.setTextColor(0x9CF3);
  tft.setFont(&JosefinSans_Bold8pt7b);
  tft.setCursor(32, 180);
  tft.print("LEARN HOW TO HOLD");
  tft.setCursor(92, 198);
  tft.print("NOTES");

  tft.setFont(&JosefinSans_Bold20pt7b);
  tft.setCursor(11, 33);
  tft.print("<");

  tft.setFont(&JosefinSans_Bold12pt7b);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(283, 65);
  tft.print("SUSTAINS 101");

  tft.setCursor(283, 170);
  tft.print("SUSTAINS 102");

  tft.setCursor(283, 278);
  tft.print("SUSTAINS 103");
 }

 void DrawChordsScreen(){
  tft.fillRect(0, 50, 220, 200, HX8357_WHITE);
  tft.fillRect(240, 0, 240, 320, 0x00DF);
  tft.drawLine(260, 320/3, 460, 320/3, 0xFE5F);
  tft.drawLine(260, 640/3, 460, 640/3, 0xFE5F);

  tft.setFont(&JosefinSans_BoldItalic20pt7b);
  tft.setTextColor(0x00DF);
  tft.setCursor(35, 155);
  tft.print("CHORDS");

  tft.setTextColor(0x9CF3);
  tft.setFont(&JosefinSans_Bold8pt7b);
  tft.setCursor(32, 180);
  tft.print("LEARN HOW TO PLAY");
  tft.setCursor(50, 198);
  tft.print("MULTIPLE NOTES");

  tft.setFont(&JosefinSans_Bold20pt7b);
  tft.setCursor(11, 33);
  tft.print("<");

  tft.setFont(&JosefinSans_Bold12pt7b);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(290, 65);
  tft.print("CHORDS 101");

  tft.setCursor(290, 170);
  tft.print("CHORDS 102");

  tft.setCursor(290, 278);
  tft.print("CHORDS 103");
 }

 /*********** SHIFTING LESSON ***********/
 void DrawShiftingLesson(){
  tft.fillRect(0, 0, 480, 260, HX8357_WHITE);
  tft.fillRect(0, 260, 480, 60, 0x9CF3);
  tft.drawLine(241, 268, 241, 312, HX8357_WHITE);

  tft.setFont(&JosefinSans_BoldItalic15pt7b);
  tft.setTextColor(0x07EE);
  tft.setCursor(330,40);
  tft.print("LESSONS");

  tft.setFont(&JosefinSans_Bold20pt7b);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(55, 304);
  tft.print("PLAY");
  tft.setCursor(310, 304);
  tft.print("QUIT");

  tft.setFont(&JosefinSans_Bold15pt7b);
  switch(currentLesson) {
    case 1:
      tft.setTextColor(0x07EE);
      tft.setCursor(148, 120);
      tft.print("SHIFTING 101");
      break;
      
    case 2:
      tft.setTextColor(0x07EE);
      tft.setCursor(148, 120);
      tft.print("SHIFTING 102");
      break;

    case 3:
      tft.setTextColor(0x07EE);
      tft.setCursor(148, 120);
      tft.print("SHIFTING 103");
      break;
  }
 }

 /*********** SUSTAIN LESSON ***********/
 void DrawSustainLesson(){
  tft.fillRect(0, 0, 480, 260, HX8357_WHITE);
  tft.fillRect(0, 260, 480, 60, 0x9CF3);
  tft.drawLine(241, 268, 241, 312, HX8357_WHITE);

  tft.setFont(&JosefinSans_BoldItalic15pt7b);
  tft.setTextColor(0x07EE);
  tft.setCursor(330,40);
  tft.print("LESSONS");

  tft.setFont(&JosefinSans_Bold20pt7b);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(55, 304);
  tft.print("PLAY");
  tft.setCursor(310, 304);
  tft.print("QUIT");

  tft.setFont(&JosefinSans_Bold15pt7b);
  switch(currentLesson) {
    case 1:
      tft.setTextColor(0x07EE);
      tft.setCursor(148, 120);
      tft.print("SUSTAINS 101");
      break;
      
    case 2:
      tft.setTextColor(0x07EE);
      tft.setCursor(148, 120);
      tft.print("SUSTAINS 102");
      break;

    case 3:
      tft.setTextColor(0x07EE);
      tft.setCursor(148, 120);
      tft.print("SUSTAINS 103");
      break;
  }
 }

 /*********** CHORDS LESSON ***********/
 void DrawChordsLesson(){
  tft.fillRect(0, 0, 480, 260, HX8357_WHITE);
  tft.fillRect(0, 260, 480, 60, 0x9CF3);
  tft.drawLine(241, 268, 241, 312, HX8357_WHITE);

  tft.setFont(&JosefinSans_BoldItalic15pt7b);
  tft.setTextColor(0x07EE);
  tft.setCursor(330,40);
  tft.print("LESSONS");

  tft.setFont(&JosefinSans_Bold20pt7b);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(55, 304);
  tft.print("PLAY");
  tft.setCursor(310, 304);
  tft.print("QUIT");

  tft.setFont(&JosefinSans_Bold15pt7b);
  switch(currentLesson) {
    case 1:
      tft.setTextColor(0x07EE);
      tft.setCursor(155, 120);
      tft.print("CHORDS 101");
      break;
      
    case 2:
      tft.setTextColor(0x07EE);
      tft.setCursor(155, 120);
      tft.print("CHORDS 102");
      break;

    case 3:
      tft.setTextColor(0x07EE);
      tft.setCursor(155, 120);
      tft.print("CHORDS 103");
      break;
  }
 }

 /*********** WHILE PLAYING SCREENS******/
 void DrawLearnSong(){
  tft.fillRect(0, 0, 480, 260, HX8357_WHITE);
  tft.fillRect(0, 260, 480, 60, 0x9CF3);
  tft.drawLine(241, 268, 241, 312, HX8357_WHITE);

  tft.setFont(&JosefinSans_BoldItalic15pt7b);
  tft.setTextColor(0x07EE);
  tft.setCursor(363,40);
  tft.print("LEARN");

  tft.setFont(&JosefinSans_Bold20pt7b);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(55, 304);
  tft.print("PLAY");
  tft.setCursor(310, 304);
  tft.print("QUIT");

  tft.setFont(&JosefinSans_Bold15pt7b);
  switch(currentLearn) {
    case 1:
      tft.setTextColor(0x07EE);
      tft.setCursor(125, 120);
      tft.print("WONDERWALL");
    
      tft.setFont(&JosefinSans_Bold12pt7b);
      tft.setTextColor(0x9CF3);
      tft.setCursor(205, 152);
      tft.print("OASIS");
      break;
      
    case 2:
      tft.setTextColor(0x07EE);
      tft.setCursor(140, 120);
      tft.print("FREE FALLIN'");
    
      tft.setFont(&JosefinSans_Bold12pt7b);
      tft.setTextColor(0x9CF3);
      tft.setCursor(173, 152);
      tft.print("TOM PETTY");
      break;

    case 3:
      tft.setTextColor(0x07EE);
      tft.setCursor(185, 120);
      tft.print("AFRICA");
    
      tft.setFont(&JosefinSans_Bold12pt7b);
      tft.setTextColor(0x9CF3);
      tft.setCursor(208, 152);
      tft.print("TOTO");
      break;

    case 4:
      tft.setTextColor(0x07EE);
      tft.setCursor(165, 120);
      tft.print("I'M YOURS");
    
      tft.setFont(&JosefinSans_Bold12pt7b);
      tft.setTextColor(0x9CF3);
      tft.setCursor(165, 152);
      tft.print("JASON MRAZ");
      break;
  }
 }

 void DrawPlaySong(){
  tft.fillRect(0, 0, 480, 260, HX8357_WHITE);
  tft.fillRect(0, 260, 480, 60, 0x9CF3);
  tft.drawLine(241, 268, 241, 312, HX8357_WHITE);

  tft.setFont(&JosefinSans_BoldItalic15pt7b);
  tft.setTextColor(0x07EE);
  tft.setCursor(385,40);
  tft.print("PLAY");

  tft.setFont(&JosefinSans_Bold20pt7b);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(65, 304);
  tft.print("PLAY");
  tft.setCursor(310, 304);
  tft.print("QUIT");

  tft.setFont(&JosefinSans_Bold15pt7b);
  switch(currentPlay) {
    case 1:
      tft.setTextColor(0x07EE);
      tft.setCursor(125, 120);
      tft.print("WONDERWALL");
    
      tft.setFont(&JosefinSans_Bold12pt7b);
      tft.setTextColor(0x9CF3);
      tft.setCursor(205, 152);
      tft.print("OASIS");
      break;
      
    case 2:
      tft.setTextColor(0x07EE);
      tft.setCursor(140, 120);
      tft.print("FREE FALLIN'");
    
      tft.setFont(&JosefinSans_Bold12pt7b);
      tft.setTextColor(0x9CF3);
      tft.setCursor(173, 152);
      tft.print("TOM PETTY");
      break;

    case 3:
      tft.setTextColor(0x07EE);
      tft.setCursor(185, 120);
      tft.print("AFRICA");
    
      tft.setFont(&JosefinSans_Bold12pt7b);
      tft.setTextColor(0x9CF3);
      tft.setCursor(208, 152);
      tft.print("TOTO");
      break;

    case 4:
      tft.setTextColor(0x07EE);
      tft.setCursor(165, 120);
      tft.print("I'M YOURS");
    
      tft.setFont(&JosefinSans_Bold12pt7b);
      tft.setTextColor(0x9CF3);
      tft.setCursor(165, 152);
      tft.print("JASON MRAZ");
      break;
  }
 }

// This stuff needs to go in while(playing)
//  tft.setCursor(165, 290);
//  tft.print("PROGRESS");
//
//  tft.setFont(&JosefinSans_Bold40pt7b);
//  tft.setTextColor(0x07EE);
//  tft.setCursor(80, 270);
//  int testInt = 87;
//  tft.print(testInt);
//  tft.setCursor(120, 270);
//  tft.print("%");
  
 

 void DrawPercent(){
  tft.setFont(&JosefinSans_Bold40pt7b);
  tft.setTextColor(0x07EE);
  tft.setCursor(145, 230);
  int testInt = 100;
  int pcent= GetPlayPercent();
  tft.print(testInt);
  tft.setCursor(280, 230);
  tft.print("%");
 }

 /********** PLAY/PAUSED ************/
 void DrawCountdown(){
  tft.fillRect(0, 160, 480, 95, HX8357_WHITE);
  tft.setFont(&JosefinSans_Bold40pt7b);
  tft.setTextColor(0x07EE);
  tft.setCursor(145, 230);
  tft.fillRect(0, 250, 480/4, 10, 0x0x07EE);
  tft.print(3);
  tft.fillRect(0, 160, 480, 85, HX8357_WHITE);
  tft.fillRect(480/4, 250, 480/4, 10, 0x0x07EE);
  tft.print(2);
  tft.fillRect(0, 160, 480, 85, HX8357_WHITE);
  tft.fillRect(480*2/4, 250, 480/4, 10, 0x0x07EE);
  tft.print(1);
  tft.fillRect(0, 160, 480, 85, HX8357_WHITE);
  tft.fillRect(480*3/4, 250, 480/4, 10, 0x0x07EE);
  tft.setCursor(130, 230);
  tft.print(START!);
  tft.fillRect(0, 160, 480, 95, HX8357_WHITE);
 }
 
 void DrawPause(){
  tft.fillRect(0, 260, 240, 60, 0x9CF3);
  tft.setFont(&JosefinSans_Bold20pt7b);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(65, 304);
  tft.print("PLAY");
  
  tft.fillRect(0, 160, 480, 95, HX8357_WHITE);
  tft.fillRect(205, 165, 24, 82, 0x07EE);
  tft.fillRect(252, 165, 24, 82, 0x07EE);
 }

 void DrawPlay(){
  tft.fillRect(0, 260, 240, 60, 0x9CF3);
  tft.setFont(&JosefinSans_Bold20pt7b);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(55, 304);
  tft.print("PAUSE");
  
  tft.fillRect(0, 160, 480, 95, HX8357_WHITE);
 }
 

 /********** FINSIHED SCREENS *******/
 void DrawFinishedLessons(){
  tft.fillRect(0, 0, 480, 80, HX8357_WHITE);
  tft.fillRect(0, 260, 480, 60, 0x9CF3);
  tft.drawLine(241, 268, 241, 312, HX8357_WHITE);
  
  tft.setFont(&JosefinSans_Bold20pt7b);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(33, 304);
  tft.print("LESSONS");
  tft.setCursor(300, 304);
  tft.print("HOME");

  switch(currentLessonType) {
    case 1:
      switch(currentLesson) {
        case 1:
          tft.setTextColor(0x9CF3);
          tft.setCursor(114, 50);
          tft.print("SHIFTING 101");
          break;
        case 2:
          tft.setTextColor(0x9CF3);
          tft.setCursor(114, 50);
          tft.print("SHIFTING 102");
          break;
        case 3:
          tft.setTextColor(0x9CF3);
          tft.setCursor(114, 50);
          tft.print("SHIFTING 103");
          break;
      }
      break;
    case 2:
      switch(currentLesson) {
        case 1:
          tft.setTextColor(0x9CF3);
          tft.setCursor(87, 50);
          tft.print("SUSTAINS 101");
          break;
        case 2:
          tft.setTextColor(0x9CF3);
          tft.setCursor(87, 50);
          tft.print("SUSTAINS 102");
          break;
        case 3:
          tft.setTextColor(0x9CF3);
          tft.setCursor(87, 50);
          tft.print("SUSTAINS 103");
          break;
      }
      break;
    case 3:
      switch(currentLesson) {
        case 1:
          tft.setTextColor(0x9CF3);
          tft.setCursor(87, 50);
          tft.print("CHORDS 101");
          break;
        case 2:
          tft.setTextColor(0x9CF3);
          tft.setCursor(87, 50);
          tft.print("CHORDS 102");
          break;
        case 3:
          tft.setTextColor(0x9CF3);
          tft.setCursor(87, 50);
          tft.print("CHORDS 103");
          break;
      }
      break;
  }

  tft.fillRect(75, 90, 330, 94, 0x073F);  
 }

 void DrawFinishedLearning(){
  tft.fillRect(0, 0, 480, 80, HX8357_WHITE);
  tft.fillRect(0, 260, 480, 60, 0x9CF3);
  tft.drawLine(241, 268, 241, 312, HX8357_WHITE);
  
  tft.setFont(&JosefinSans_Bold20pt7b);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(50, 304);
  tft.print("SONGS");
  tft.setCursor(300, 304);
  tft.print("HOME");

  switch(currentLearn) {
    case 1:
      tft.setTextColor(0x9CF3);
      tft.setCursor(87, 50);
      tft.print("WONDERWALL");
      
      tft.setFont(&JosefinSans_Bold12pt7b);
      tft.setCursor(205, 78);
      tft.print("OASIS");
      break;
    case 2:
      tft.setTextColor(0x9CF3);
      tft.setCursor(87, 50);
      tft.print("FREE FALLIN'");
      
      tft.setFont(&JosefinSans_Bold12pt7b);
      tft.setCursor(205, 78);
      tft.print("TOM PETTY");
      break;
    case 3:
      tft.setTextColor(0x9CF3);
      tft.setCursor(87, 50);
      tft.print("AFRICA");
      
      tft.setFont(&JosefinSans_Bold12pt7b);
      tft.setCursor(205, 78);
      tft.print("TOTO");
      break;
    case 4:
      tft.setTextColor(0x9CF3);
      tft.setCursor(87, 50);
      tft.print("I'M YOURS");
      
      tft.setFont(&JosefinSans_Bold12pt7b);
      tft.setCursor(205, 78);
      tft.print("JASON MRAZ");
      break;
  }

  tft.fillRect(75, 90, 330, 94, 0x073F);
 }

 void DrawFinishedPlaying(){
  tft.fillRect(0, 0, 480, 80, HX8357_WHITE);
  tft.fillRect(0, 260, 480, 60, 0x9CF3);
  tft.drawLine(241, 268, 241, 312, HX8357_WHITE);
  
  tft.setFont(&JosefinSans_Bold20pt7b);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(50, 304);
  tft.print("SONGS");
  tft.setCursor(300, 304);
  tft.print("HOME");

  switch(currentPlay) {
    case 1:
      tft.setTextColor(0x9CF3);
      tft.setCursor(87, 50);
      tft.print("WONDERWALL");
      
      tft.setFont(&JosefinSans_Bold12pt7b);
      tft.setCursor(205, 78);
      tft.print("OASIS");
      break;
    case 2:
      tft.setTextColor(0x9CF3);
      tft.setCursor(87, 50);
      tft.print("FREE FALLIN'");
      
      tft.setFont(&JosefinSans_Bold12pt7b);
      tft.setCursor(205, 78);
      tft.print("TOM PETTY");
      break;
    case 3:
      tft.setTextColor(0x9CF3);
      tft.setCursor(87, 50);
      tft.print("AFRICA");
      
      tft.setFont(&JosefinSans_Bold12pt7b);
      tft.setCursor(205, 78);
      tft.print("TOTO");
      break;
    case 4:
      tft.setTextColor(0x9CF3);
      tft.setCursor(87, 50);
      tft.print("I'M YOURS");
      
      tft.setFont(&JosefinSans_Bold12pt7b);
      tft.setCursor(205, 78);
      tft.print("JASON MRAZ");
      break;
  }

  tft.fillRect(75, 90, 330, 94, 0x073F);  
 }

// This function opens a Windows Bitmap (BMP) file and
// displays it at the given coordinates.  It's sped up
// by reading many pixels worth of data at a time
// (rather than pixel by pixel).  Increasing the buffer
// size takes more of the Arduino's precious RAM but
// makes loading a little faster.  20 pixels seems a
// good balance.

#define BUFFPIXEL 20

void bmpDraw(char *filename, uint8_t x, uint16_t y) {

  File     bmpFile;
  int      bmpWidth, bmpHeight;   // W+H in pixels
  uint8_t  bmpDepth;              // Bit depth (currently must be 24)
  uint32_t bmpImageoffset;        // Start of image data in file
  uint32_t rowSize;               // Not always = bmpWidth; may have padding
  uint8_t  sdbuffer[3*BUFFPIXEL]; // pixel buffer (R+G+B per pixel)
  uint8_t  buffidx = sizeof(sdbuffer); // Current position in sdbuffer
  boolean  goodBmp = false;       // Set to true on valid header parse
  boolean  flip    = true;        // BMP is stored bottom-to-top
  int      w, h, row, col;
  uint8_t  r, g, b;
  uint32_t pos = 0, startTime = millis();

  if((x >= tft.width()) || (y >= tft.height())) return;

  Serial.println();
  Serial.print(F("Loading image '"));
  Serial.print(filename);
  Serial.println('\'');

  // Open requested file on SD card
  if ((bmpFile = SD.open(filename)) == NULL) {
    Serial.println(F("File not found"));
    return;
  }

  // Parse BMP header
  if(read16(bmpFile) == 0x4D42) { // BMP signature
    Serial.print(F("File size: ")); Serial.println(read32(bmpFile));
    (void)read32(bmpFile); // Read & ignore creator bytes
    bmpImageoffset = read32(bmpFile); // Start of image data
    Serial.print(F("Image Offset: ")); Serial.println(bmpImageoffset, DEC);
    // Read DIB header
    Serial.print(F("Header size: ")); Serial.println(read32(bmpFile));
    bmpWidth  = read32(bmpFile);
    bmpHeight = read32(bmpFile);
    if(read16(bmpFile) == 1) { // # planes -- must be '1'
      bmpDepth = read16(bmpFile); // bits per pixel
      Serial.print(F("Bit Depth: ")); Serial.println(bmpDepth);
      if((bmpDepth == 24) && (read32(bmpFile) == 0)) { // 0 = uncompressed

        goodBmp = true; // Supported BMP format -- proceed!
        Serial.print(F("Image size: "));
        Serial.print(bmpWidth);
        Serial.print('x');
        Serial.println(bmpHeight);

        // BMP rows are padded (if needed) to 4-byte boundary
        rowSize = (bmpWidth * 3 + 3) & ~3;

        // If bmpHeight is negative, image is in top-down order.
        // This is not canon but has been observed in the wild.
        if(bmpHeight < 0) {
          bmpHeight = -bmpHeight;
          flip      = false;
        }

        // Crop area to be loaded
        w = bmpWidth;
        h = bmpHeight;
        if((x+w-1) >= tft.width())  w = tft.width()  - x;
        if((y+h-1) >= tft.height()) h = tft.height() - y;

        // Set TFT address window to clipped image bounds
        tft.setAddrWindow(x, y, x+w-1, y+h-1);

        for (row=0; row<h; row++) { // For each scanline...

          // Seek to start of scan line.  It might seem labor-
          // intensive to be doing this on every line, but this
          // method covers a lot of gritty details like cropping
          // and scanline padding.  Also, the seek only takes
          // place if the file position actually needs to change
          // (avoids a lot of cluster math in SD library).
          if(flip) // Bitmap is stored bottom-to-top order (normal BMP)
            pos = bmpImageoffset + (bmpHeight - 1 - row) * rowSize;
          else     // Bitmap is stored top-to-bottom
            pos = bmpImageoffset + row * rowSize;
          if(bmpFile.position() != pos) { // Need seek?
            bmpFile.seek(pos);
            buffidx = sizeof(sdbuffer); // Force buffer reload
          }

          for (col=0; col<w; col++) { // For each pixel...
            // Time to read more pixel data?
            if (buffidx >= sizeof(sdbuffer)) { // Indeed
              bmpFile.read(sdbuffer, sizeof(sdbuffer));
              buffidx = 0; // Set index to beginning
            }

            // Convert pixel from BMP to TFT format, push to display
            b = sdbuffer[buffidx++];
            g = sdbuffer[buffidx++];
            r = sdbuffer[buffidx++];
            tft.pushColor(tft.color565(r,g,b));
          } // end pixel
        } // end scanline
        Serial.print(F("Loaded in "));
        Serial.print(millis() - startTime);
        Serial.println(" ms");
      } // end goodBmp
    }
  }

  bmpFile.close();
  if(!goodBmp) Serial.println(F("BMP format not recognized."));
}

// These read 16- and 32-bit types from the SD card file.
// BMP data is stored little-endian, Arduino is little-endian too.
// May need to reverse subscript order if porting elsewhere.

uint16_t read16(File &f) {
  uint16_t result;
  ((uint8_t *)&result)[0] = f.read(); // LSB
  ((uint8_t *)&result)[1] = f.read(); // MSB
  return result;
}

uint32_t read32(File &f) {
  uint32_t result;
  ((uint8_t *)&result)[0] = f.read(); // LSB
  ((uint8_t *)&result)[1] = f.read();
  ((uint8_t *)&result)[2] = f.read();
  ((uint8_t *)&result)[3] = f.read(); // MSB
  return result;
}
