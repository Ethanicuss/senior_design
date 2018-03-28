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
  
  tft.fillRect(240, 0, 240, 95, 0x00DF);
  tft.fillTriangle(240, 0, 240, 95, 255, 95, HX8357_WHITE);
  
  tft.fillRect(240, 95, 240, 95, 0xF81D);
  tft.fillTriangle(240, 95, 240, 95+95, 255, 95+95, HX8357_WHITE);
  
  tft.fillRect(240, 190, 240, 95, 0x07EE);  
  tft.fillTriangle(240, 95+95, 240, 95+95+95, 255, 95+95+95, HX8357_WHITE);

  tft.fillRect(240, 285, 240, 35, 0x9CF3);  
  tft.fillTriangle(240, 95+95+95, 240, 360, 253, 360, HX8357_WHITE);

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
  tft.setCursor(273, 60);
  tft.print("LESSONS");

  tft.setCursor(300, 155);
  tft.print("LEARN");

  tft.setCursor(315, 255);
  tft.print("PLAY");

  tft.setFont(&JosefinSans_Bold8pt7b);
  tft.setCursor(320, 310);
  tft.print("NEXT PAGE");
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

 void DrawRecordScreen(){
  tft.fillRect(0, 0, 240, 360, HX8357_WHITE);
  tft.fillRect(240, 0, 240, 320, 0xF81D);
  tft.drawLine(260, 320/3, 460, 320/3, 0xFE5F);
  tft.drawLine(260, 640/3, 460, 640/3, 0xFE5F);

  tft.setFont(&JosefinSans_BoldItalic20pt7b);
  tft.setTextColor(0xF81D);
  tft.setCursor(26, 155);
  tft.print("RECORD");

  tft.setTextColor(0x9CF3);
  tft.setFont(&JosefinSans_Bold8pt7b);
  tft.setCursor(35, 180);
  tft.print("RECORD A SONG TO");
  tft.setCursor(40, 198);
  tft.print("LEARN AND PLAY");

  tft.setFont(&JosefinSans_Bold20pt7b);
  tft.setCursor(11, 33);
  tft.print("<");

  tft.setFont(&JosefinSans_Bold12pt7b);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(283, 65);
  tft.print("RECORD SONG");

  tft.setCursor(270, 170);
  tft.print("LEARN RECORDING");

  tft.setCursor(270, 278);
  tft.print("PLAY RECORDING");
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
  tft.print("PAUSE");
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
  tft.print("PAUSE");
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
  tft.print("PAUSE");
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
  tft.print("PAUSE");
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
  tft.setCursor(55, 304);
  tft.print("PAUSE");
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
  
 

 void DrawPlayPercent(){
  tft.setFont(&JosefinSans_Bold40pt7b);
  tft.setTextColor(0x07EE);
  int pcent= GetPlayPercent();
  if (pcent != currentPcent) {
    tft.fillRect(0, 160, 280, 95, HX8357_WHITE);
    if (pcent < 10) {
      tft.setCursor(220, 230);
      tft.print(pcent);
    }
    else if (pcent < 100) {
      tft.setCursor(180, 230);
      tft.print(pcent);
    }
    else {
      tft.setCursor(155, 230);
      tft.print(pcent);
    }
    tft.setCursor(280, 230);
    tft.print("%");
  }
  currentPcent = pcent;
 }

 /********** PLAY/PAUSED ************/
 void DrawCountdown(){
  tft.fillRect(0, 160, 480, 95, HX8357_WHITE);
  tft.setFont(&JosefinSans_Bold40pt7b);
  tft.setTextColor(0x07EE);
  tft.setCursor(220, 230);
  CountdownDelay();
  tft.fillRect(0, 250, 480/4, 10, 0x07EE);
  tft.print("3");
  CountdownDelay();
  tft.fillRect(0, 160, 480, 85, HX8357_WHITE);
  tft.fillRect(480/4, 250, 480/4, 10, 0x07EE);
  tft.setCursor(220, 230);
  tft.print("2");
  CountdownDelay();
  tft.fillRect(0, 160, 480, 85, HX8357_WHITE);
  tft.fillRect(480*2/4, 250, 480/4, 10, 0x07EE);
  tft.setCursor(230, 230);
  tft.print("1");
  CountdownDelay();
  tft.fillRect(0, 160, 480, 85, HX8357_WHITE);
  tft.fillRect(480*3/4, 250, 480/4, 10, 0x07EE);
  tft.setCursor(110, 230);
  tft.print("START!");
  CountdownDelay();
  tft.fillRect(0, 160, 480, 100, HX8357_WHITE);
 }

 void CountdownDelay(){
   for (int i = 0; i < 400; i++) {
    tft.fillRect(470, 200, 10, 40, HX8357_WHITE);
   }
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

  /********** RECORD SCREENS *******/
void DrawChooseBMP(){
  tft.fillRect(0, 0, 480, 260, HX8357_WHITE);
  tft.fillRect(0, 260, 480, 60, 0x9CF3);
  tft.drawLine(241, 268, 241, 312, HX8357_WHITE);
  // arrow buttons rectangles
  tft.fillRect(106, 202, 60, 41, 0x07EE);
  tft.fillRect(184, 202, 38, 41, 0x07EE);
  tft.fillRect(259, 202, 38, 41, 0x07EE);
  tft.fillRect(315, 202, 60, 41, 0x07EE);

  tft.setFont(&JosefinSans_BoldItalic15pt7b);
  tft.setTextColor(0x07EE);
  tft.setCursor(355,40);
  tft.print("RECORD");

  tft.setFont(&JosefinSans_Bold15pt7b);
  tft.setTextColor(0x9CF3);
  tft.setCursor(10,40);
  tft.print("CHOOSE A BPM");

  tft.setFont(&JosefinSans_Bold20pt7b);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(50, 304);
  tft.print("CONTINUE");
  tft.setCursor(310, 304);
  tft.print("QUIT");
}

void ChooseBPMNumber(){
  tft.fillRect(124, 99, 233, 95, HX8357_WHITE);

  tft.setFont(&JosefinSans_Bold40pt7b);
  tft.setTextColor(0x07EE);
  tft.setCursor(10,40);
}

