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

  tft.setFont(&JosefinSans_BoldItalic20pt7b);
  tft.setTextColor(0x981F);
  tft.setCursor(35, 155);
  tft.print("AURORA");
  tft.setFont(&JosefinSans_Bold8pt7b);
  tft.setCursor(41, 180);
  tft.setTextColor(0x9CF3);
  tft.print("LET'S PLAY GUITAR!");

  DrawHomeScreenButtons();
 }

 void DrawHomeScreenButtons(){
  if(currentPage == 0) {
    tft.fillRect(240, 0, 240, 95, 0x00DF);
    tft.fillTriangle(240, 0, 240, 95, 255, 95, HX8357_WHITE);
    tft.setFont(&JosefinSans_Bold20pt7b);
    tft.setTextColor(HX8357_WHITE);
    tft.setCursor(273, 60);
    tft.print("LESSONS");
  
    tft.fillRect(240, 95, 240, 95, 0xF81D);
    tft.fillTriangle(240, 95, 240, 95+95, 255, 95+95, HX8357_WHITE);
    tft.setCursor(300, 155);
    tft.print("LEARN");
  
    tft.fillRect(240, 190, 240, 95, 0x07EE);  
    tft.fillTriangle(240, 95+95, 240, 95+95+95, 255, 95+95+95, HX8357_WHITE);
    tft.setCursor(315, 255);
    tft.print("PLAY");
  
    tft.fillRect(240, 285, 240, 35, 0x9CF3);  
    tft.fillTriangle(240, 95+95+95, 240, 360, 253, 360, HX8357_WHITE);
    tft.setFont(&JosefinSans_Bold8pt7b);
    tft.setCursor(320, 310);
    tft.print("NEXT PAGE");
  }
  else {
    tft.fillRect(240, 0, 240, 95, 0xF81D);
    tft.fillTriangle(240, 0, 240, 95, 255, 95, HX8357_WHITE);
    tft.setFont(&JosefinSans_Bold20pt7b);
    tft.setTextColor(HX8357_WHITE);
    tft.setCursor(284, 60);
    tft.print("RECORD");
  
    tft.fillRect(240, 95, 240, 95, 0x07EE);
    tft.fillTriangle(240, 95, 240, 95+95, 255, 95+95, HX8357_WHITE);
    tft.setCursor(283, 155);
    tft.print("UPLOAD");

    tft.setFont(&JosefinSans_Bold15pt7b);
    tft.fillRect(240, 190, 240, 95, 0x00DF);  
    tft.fillTriangle(240, 95+95, 240, 95+95+95, 255, 95+95+95, HX8357_WHITE);
    tft.setCursor(265, 255);
    tft.print("DOWNLOADS");
  
    tft.fillRect(240, 285, 240, 35, 0x9CF3);  
    tft.fillTriangle(240, 95+95+95, 240, 360, 253, 360, HX8357_WHITE);
    tft.setFont(&JosefinSans_Bold8pt7b);
    tft.setCursor(302, 310);
    tft.print("PREVIOUS PAGE");
  }
  
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

  tft.setFont(&JosefinSans_Bold8pt7b);
  tft.setCursor(285, 200);
  tft.print("UNDER THE BRIDGE");

  tft.setFont(&JosefinSans_Bold12pt7b);
  tft.setCursor(270, 290);
  tft.print("COMING SOON");


  tft.setTextColor(0xFE5F);
  tft.setFont(&JosefinSans_Bold8pt7b);
  tft.setCursor(335, 60);
  tft.print("OASIS");

  tft.setCursor(318, 140);
  tft.print("TOM PETTY");

  tft.setCursor(265, 220);
  tft.print("RED HOT CHILI PEPPERS");
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

  tft.setFont(&JosefinSans_Bold8pt7b);
  tft.setCursor(285, 200);
  tft.print("UNDER THE BRIDGE");

  tft.setFont(&JosefinSans_Bold12pt7b);
  tft.setCursor(270, 290);
  tft.print("COMING SOON");


  tft.setTextColor(0xFE5F);
  tft.setFont(&JosefinSans_Bold8pt7b);
  tft.setCursor(335, 60);
  tft.print("OASIS");

  tft.setCursor(318, 140);
  tft.print("TOM PETTY");

  tft.setCursor(265, 220);
  tft.print("RED HOT CHILI PEPPERS");
 }

 void DrawRecordScreen(){
  tft.fillRect(0, 0, 240, 360, HX8357_WHITE);
  tft.fillRect(240, 0, 240, 320, 0xF81D);
  tft.drawLine(260, 320/3, 460, 320/3, 0xFE5F);
  tft.drawLine(260, 640/3, 460, 640/3, 0xFE5F);

  tft.setFont(&JosefinSans_BoldItalic20pt7b);
  tft.setTextColor(0xF81D);
  tft.setCursor(35, 155);
  tft.print("RECORD");

  tft.setTextColor(0x9CF3);
  tft.setFont(&JosefinSans_Bold8pt7b);
  tft.setCursor(39, 180);
  tft.print("RECORD A SONG TO");
  tft.setCursor(50, 198);
  tft.print("LEARN AND PLAY");

  tft.setFont(&JosefinSans_Bold20pt7b);
  tft.setCursor(11, 33);
  tft.print("<");

  tft.setFont(&JosefinSans_Bold12pt7b);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(272, 65);
  tft.print("RECORD SONG");

  tft.setCursor(320, 155);
  tft.print("LEARN");
  tft.setCursor(290, 182);
  tft.print("RECORDING");

  tft.setCursor(330, 263);
  tft.print("PLAY");
  tft.setCursor(290, 290);
  tft.print("RECORDING");
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
      tft.setCursor(100, 120);
      tft.print("UNDER THE BRIDGE");
    
      tft.setFont(&JosefinSans_Bold10pt7b);
      tft.setTextColor(0x9CF3);
      tft.setCursor(130, 152);
      tft.print("RED HOT CHILI PEPPERS");
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

    case 5:
      tft.setTextColor(0x07EE);
      tft.setCursor(155, 120);
      tft.print("RECORDING");
      break;

    case 6:
      tft.setTextColor(0x07EE);
      tft.setCursor(150, 120);
      tft.print("DOWNLOAD 1");
      break;

    case 7:
      tft.setTextColor(0x07EE);
      tft.setCursor(150, 120);
      tft.print("DOWNLOAD 2");
      break;

    case 8:
      tft.setTextColor(0x07EE);
      tft.setCursor(150, 120);
      tft.print("DOWNLOAD 3");
      break;

    case 9:
      tft.setTextColor(0x07EE);
      tft.setCursor(150, 120);
      tft.print("DOWNLOAD 4");
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
      tft.setCursor(100, 120);
      tft.print("UNDER THE BRIDGE");
    
      tft.setFont(&JosefinSans_Bold10pt7b);
      tft.setTextColor(0x9CF3);
      tft.setCursor(130, 152);
      tft.print("RED HOT CHILI PEPPERS");
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

    case 5:
      tft.setTextColor(0x07EE);
      tft.setCursor(155, 120);
      tft.print("RECORDING");
      break;

    case 6:
      tft.setTextColor(0x07EE);
      tft.setCursor(150, 120);
      tft.print("DOWNLOAD 1");
      break;

    case 7:
      tft.setTextColor(0x07EE);
      tft.setCursor(150, 120);
      tft.print("DOWNLOAD 2");
      break;

    case 8:
      tft.setTextColor(0x07EE);
      tft.setCursor(150, 120);
      tft.print("DOWNLOAD 3");
      break;

    case 9:
      tft.setTextColor(0x07EE);
      tft.setCursor(150, 120);
      tft.print("DOWNLOAD 4");
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
  tft.fillRect(0, 0, 480, 260, HX8357_WHITE);
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
    tft.fillRect(75, 130, 330, 94, 0x073F);
    tft.setFont(&JosefinSans_Bold20pt7b);
    tft.setTextColor(HX8357_WHITE);
    tft.setCursor(130, 190);
    tft.print("GOOD JOB!");
 }

 void DrawFinishedLearning(){
  tft.fillRect(0, 0, 480, 260, HX8357_WHITE);
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
      tft.setCursor(100, 50);
      tft.print("FREE FALLIN'");
      
      tft.setFont(&JosefinSans_Bold12pt7b);
      tft.setCursor(170, 78);
      tft.print("TOM PETTY");
      break;
    case 3:
      tft.setTextColor(0x9CF3);
      tft.setCursor(35, 50);
      tft.print("UNDER THE BRIDGE");
      
      tft.setFont(&JosefinSans_Bold12pt7b);
      tft.setCursor(90, 78);
      tft.print("RED HOT CHILI PEPPERS");
      break;
    case 4:
      tft.setTextColor(0x9CF3);
      tft.setCursor(87, 50);
      tft.print("I'M YOURS");
      
      tft.setFont(&JosefinSans_Bold12pt7b);
      tft.setCursor(205, 78);
      tft.print("JASON MRAZ");
      break;
    case 5:
      tft.setTextColor(0x9CF3);
      tft.setCursor(77, 50);
      tft.print("RECORDING");
      break;
    case 6:
      tft.setTextColor(0x9CF3);
      tft.setCursor(72, 50);
      tft.print("DOWNLOAD 1");
      break;
    case 7:
      tft.setTextColor(0x9CF3);
      tft.setCursor(72, 50);
      tft.print("DOWNLOAD 2");
      break;
    case 8:
      tft.setTextColor(0x9CF3);
      tft.setCursor(72, 50);
      tft.print("DOWNLOAD 3");
      break;
    case 9:
      tft.setTextColor(0x9CF3);
      tft.setCursor(72, 50);
      tft.print("DOWNLOAD 4");
      break;
  }

  tft.fillRect(75, 130, 330, 94, 0x073F);
  tft.setFont(&JosefinSans_Bold20pt7b);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(130, 190);
  tft.print("GOOD JOB!");
 }

 void DrawFinishedPlaying(){
  tft.fillRect(0, 0, 480, 260, HX8357_WHITE);
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
      tft.setCursor(100, 50);
      tft.print("FREE FALLIN'");
      
      tft.setFont(&JosefinSans_Bold12pt7b);
      tft.setCursor(170, 78);
      tft.print("TOM PETTY");
      break;
    case 3:
      tft.setTextColor(0x9CF3);
      tft.setCursor(35, 50);
      tft.print("UNDER THE BRIDGE");
      
      tft.setFont(&JosefinSans_Bold12pt7b);
      tft.setCursor(90, 78);
      tft.print("RED HOT CHILI PEPPERS");
      break;
    case 4:
      tft.setTextColor(0x9CF3);
      tft.setCursor(87, 50);
      tft.print("I'M YOURS");
      
      tft.setFont(&JosefinSans_Bold12pt7b);
      tft.setCursor(205, 78);
      tft.print("JASON MRAZ");
      break;
    case 5:
      tft.setTextColor(0x9CF3);
      tft.setCursor(77, 50);
      tft.print("RECORDING");
      break;
    case 6:
      tft.setTextColor(0x9CF3);
      tft.setCursor(72, 50);
      tft.print("DOWNLOAD 1");
      break;
    case 7:
      tft.setTextColor(0x9CF3);
      tft.setCursor(72, 50);
      tft.print("DOWNLOAD 2");
      break;
    case 8:
      tft.setTextColor(0x9CF3);
      tft.setCursor(72, 50);
      tft.print("DOWNLOAD 3");
      break;
    case 9:
      tft.setTextColor(0x9CF3);
      tft.setCursor(72, 50);
      tft.print("DOWNLOAD 4");
      break;
  }

    int percent = 49;

  // INSERT PLAY CORRECT PERCENT HERE

    tft.setFont(&JosefinSans_Bold40pt7b);
    tft.setTextColor(0x073F);
    tft.setCursor(160, 200);
    tft.print(percent);
    tft.setCursor(250, 200);
    tft.print(" %");
 }

  /********** RECORD SCREENS *******/
void DrawChooseBMP(){
  tft.fillRect(0, 0, 480, 260, HX8357_WHITE);
  tft.fillRect(0, 260, 480, 60, 0x9CF3);
  tft.drawLine(241, 268, 241, 312, HX8357_WHITE);
  // arrow buttons rectangles
  tft.fillRect(73, 184, 80, 55, 0x07EE);
  tft.fillRect(177, 184, 51, 55, 0x07EE);
  tft.fillRect(251, 184, 51, 55, 0x07EE);
  tft.fillRect(327, 184, 80, 55, 0x07EE);

  tft.setTextColor(HX8357_WHITE);
  tft.setFont(&JosefinSans_Bold40pt7b);
  tft.setCursor(75, 230);
  tft.print("<");
  tft.setCursor(110, 230);
  tft.print("<");

  tft.setCursor(184, 230);
  tft.print("<");

  tft.setCursor(253, 230);
  tft.print(">");

  tft.setCursor(327, 230);
  tft.print(">");
  tft.setCursor(360, 230);
  tft.print(">");

  tft.setFont(&JosefinSans_BoldItalic15pt7b);
  tft.setTextColor(0x07EE);
  tft.setCursor(340,40);
  tft.print("RECORD");

  tft.setFont(&JosefinSans_Bold15pt7b);
  tft.setTextColor(0x9CF3);
  tft.setCursor(120, 90);
  tft.print("CHOOSE A BPM");

  tft.setFont(&JosefinSans_Bold40pt7b);
  tft.setTextColor(0x07EE);
  tft.setCursor(180,165);
  tft.print(BPM);

  tft.setFont(&JosefinSans_Bold15pt7b);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(37, 300);
  tft.print("CONTINUE");
  tft.setCursor(320, 300);
  tft.print("QUIT");
}

void DrawBPMNumber(){
  tft.fillRect(135, 99, 200, 80, HX8357_WHITE);
  tft.setFont(&JosefinSans_Bold40pt7b);
  tft.setTextColor(0x07EE);

  if(BPM > 99) {
    tft.setCursor(180,165);
    tft.print(BPM);
  }
  else if (BPM < 10) {
    tft.setCursor(220,165);
    tft.print(BPM);
  }
  else {
    tft.setCursor(200,165);
    tft.print(BPM);
  }
}

void Draw_REC_RED(){
  tft.fillRect(0, 0, 480, 260, HX8357_WHITE);
  tft.fillRect(0, 260, 480, 60, 0x9CF3);
  tft.drawLine(240, 268, 240, 312, HX8357_WHITE);
  
  tft.setFont(&JosefinSans_BoldItalic15pt7b);
  tft.setTextColor(0x07EE);
  tft.setCursor(340,40);
  tft.print("RECORD");

  tft.setTextColor(0x9CF3);
  tft.setFont(&JosefinSans_Bold20pt7b);
  tft.setCursor(11, 33);
  tft.print("<");
    
  tft.setFont(&JosefinSans_Bold15pt7b);
  tft.setCursor(77, 95);
  tft.print("PLACE INDEX FINGER");
  tft.setCursor(150, 134);
  tft.print("FOR CHORD");

  tft.fillCircle(240, 198, 45, HX8357_RED);
  tft.setFont(&JosefinSans_Bold10pt7b);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(221, 205);
  tft.print("RED");

  tft.setFont(&JosefinSans_Bold15pt7b);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(37, 300);
  tft.print("CONTINUE");
  tft.setCursor(325, 300);
  tft.print("END");
}

void Draw_REC_BLUE(){
  tft.fillRect(0, 0, 480, 260, HX8357_WHITE);
  tft.fillRect(0, 260, 480, 60, 0x9CF3);
  tft.drawLine(240, 268, 240, 312, HX8357_WHITE);
  
  tft.setFont(&JosefinSans_BoldItalic15pt7b);
  tft.setTextColor(0x07EE);
  tft.setCursor(340,40);
  tft.print("RECORD");

  tft.setTextColor(0x9CF3);
  tft.setFont(&JosefinSans_Bold20pt7b);
  tft.setCursor(11, 33);
  tft.print("<");
    
  tft.setFont(&JosefinSans_Bold15pt7b);
  tft.setCursor(65, 95);
  tft.print("PLACE MIDDLE FINGER");
  tft.setCursor(150, 134);
  tft.print("FOR CHORD");

  tft.fillCircle(240, 198, 45, HX8357_BLUE);
  tft.setFont(&JosefinSans_Bold10pt7b);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(213, 205);
  tft.print("BLUE");

  tft.setFont(&JosefinSans_Bold15pt7b);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(37, 300);
  tft.print("CONTINUE");
  tft.setCursor(325, 300);
  tft.print("END");
}

void Draw_REC_GREEN(){
  tft.fillRect(0, 0, 480, 260, HX8357_WHITE);
  tft.fillRect(0, 260, 480, 60, 0x9CF3);
  tft.drawLine(240, 268, 240, 312, HX8357_WHITE);
  
  tft.setFont(&JosefinSans_BoldItalic15pt7b);
  tft.setTextColor(0x07EE);
  tft.setCursor(340,40);
  tft.print("RECORD");

  tft.setTextColor(0x9CF3);
  tft.setFont(&JosefinSans_Bold20pt7b);
  tft.setCursor(11, 33);
  tft.print("<");
    
  tft.setFont(&JosefinSans_Bold15pt7b);
  tft.setCursor(90, 95);
  tft.print("PLACE RING FINGER");
  tft.setCursor(150, 134);
  tft.print("FOR CHORD");

  tft.fillCircle(240, 198, 45, 0x1703);
  tft.setFont(&JosefinSans_Bold10pt7b);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(205, 205);
  tft.print("GREEN");

  tft.setFont(&JosefinSans_Bold15pt7b);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(37, 300);
  tft.print("CONTINUE");
  tft.setCursor(325, 300);
  tft.print("END");
}

void Draw_REC_PURPLE(){
  tft.fillRect(0, 0, 480, 260, HX8357_WHITE);
  tft.fillRect(0, 260, 480, 60, 0x9CF3);
  tft.drawLine(240, 268, 240, 312, HX8357_WHITE);
  
  tft.setFont(&JosefinSans_BoldItalic15pt7b);
  tft.setTextColor(0x07EE);
  tft.setCursor(340,40);
  tft.print("RECORD");

  tft.setTextColor(0x9CF3);
  tft.setFont(&JosefinSans_Bold20pt7b);
  tft.setCursor(11, 33);
  tft.print("<");
    
  tft.setFont(&JosefinSans_Bold15pt7b);
  tft.setCursor(77, 95);
  tft.print("PLACE PINKY FINGER");
  tft.setCursor(150, 134);
  tft.print("FOR CHORD");

  tft.fillCircle(240, 198, 45, 0xB89C);
  tft.setFont(&JosefinSans_Bold10pt7b);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(201, 205);
  tft.print("PURPLE");

  tft.setFont(&JosefinSans_Bold15pt7b);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(37, 300);
  tft.print("CONTINUE");
  tft.setCursor(325, 300);
  tft.print("END");
}

void Draw_REC_OPEN(){
  tft.fillRect(0, 0, 480, 260, HX8357_WHITE);
  tft.fillRect(0, 260, 480, 60, 0x9CF3);
  
  tft.setFont(&JosefinSans_BoldItalic15pt7b);
  tft.setTextColor(0x07EE);
  tft.setCursor(340,40);
  tft.print("RECORD");

  tft.setTextColor(0x9CF3);
  tft.setFont(&JosefinSans_Bold20pt7b);
  tft.setCursor(11, 33);
  tft.print("<");
    
  tft.setFont(&JosefinSans_Bold15pt7b);
  tft.setCursor(125, 95);
  tft.print("CHOOSE WHICH");
  tft.setCursor(98, 134);
  tft.print("STRINGS ARE OPEN");

  tft.setTextColor(0x07EE);
  tft.setFont(&JosefinSans_Bold20pt7b);  
  tft.setCursor(28, 225);
  tft.print("E");
  tft.setCursor(106, 225);
  tft.print("A");
  tft.setCursor(186, 225);
  tft.print("D");
  tft.setCursor(264, 225);
  tft.print("G");
  tft.setCursor(348, 225);
  tft.print("B");
  tft.setCursor(426, 225);
  tft.print("E");

  tft.setFont(&JosefinSans_Bold15pt7b);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(160, 300);
  tft.print("CONTINUE");
}

void DrawOpenHighlight(int string, bool isOpen){
  tft.setFont(&JosefinSans_Bold20pt7b);  
  if(isOpen){
    tft.setTextColor(HX8357_WHITE);
    switch(string) {
      case 0:
        tft.setCursor(28, 225);
        tft.fillRect(0, 170, 80, 90, 0x07EE);
        tft.print("E");
        break;
      case 1:
        tft.setCursor(106, 225);
        tft.fillRect(80, 170, 80, 90, 0x07EE);
        tft.print("A");
        break;
      case 2:
        tft.setCursor(186, 225);
        tft.fillRect(160, 170, 80, 90, 0x07EE);
        tft.print("D");
        break;
      case 3:
        tft.setCursor(264, 225);
        tft.fillRect(240, 170, 80, 90, 0x07EE);
        tft.print("G");
        break;
      case 4:
        tft.setCursor(348, 225);
        tft.fillRect(320, 170, 80, 90, 0x07EE);
        tft.print("B");
        break;
      case 5:
        tft.setCursor(426, 225);
        tft.fillRect(400, 170, 80, 90, 0x07EE);
        tft.print("E");
        break;
    }
  }
  else if(!isOpen){
    tft.setTextColor(0x07EE);
    switch(string) {
      case 0:
        tft.setCursor(28, 225);
        tft.fillRect(0, 170, 80, 90, HX8357_WHITE);
        tft.print("E");
        break;
      case 1:
        tft.setCursor(106, 225);
        tft.fillRect(80, 170, 80, 90, HX8357_WHITE);
        tft.print("A");
        break;
      case 2:
        tft.setCursor(186, 225);
        tft.fillRect(160, 170, 80, 90, HX8357_WHITE);
        tft.print("D");
        break;
      case 3:
        tft.setCursor(264, 225);
        tft.fillRect(240, 170, 80, 90, HX8357_WHITE);
        tft.print("G");
        break;
      case 4:
        tft.setCursor(348, 225);
        tft.fillRect(320, 170, 80, 90, HX8357_WHITE);
        tft.print("B");
        break;
      case 5:
        tft.setCursor(426, 225);
        tft.fillRect(400, 170, 80, 90, HX8357_WHITE);
        tft.print("E");
        break;
    }
  }
}

void Draw_REC_TEMPO(){
  tft.fillRect(0, 0, 480, 260, HX8357_WHITE);
  
  tft.setFont(&JosefinSans_BoldItalic15pt7b);
  tft.setTextColor(0x07EE);
  tft.setCursor(340,40);
  tft.print("RECORD");

  tft.setFont(&JosefinSans_Bold15pt7b);
  tft.setTextColor(0x9CF3);
  tft.setCursor(80, 115);
  tft.print("CHOOSE THE TEMPO");

  tft.fillRect(0, 160, 480, 160, 0x07EE);
  tft.drawLine(121.5, 180.5, 121.5, 299.5, HX8357_WHITE);
  tft.drawLine(240.5, 180.5, 240.5, 299.5, HX8357_WHITE);
  tft.drawLine(359.5, 180.5, 359.5, 299.5, HX8357_WHITE);

  tft.setTextColor(HX8357_WHITE);
  tft.setFont(&JosefinSans_Bold20pt7b);  
  tft.setCursor(31, 258);
  tft.print("1/2");
  tft.setCursor(153, 258);
  tft.print("1/4");
  tft.setCursor(274, 258);
  tft.print("1/8");
  tft.setCursor(385, 258);
  tft.print("1/16");
}

void Draw_REC_NEXT(){
  tft.fillRect(0, 0, 480, 260, HX8357_WHITE);
  tft.fillRect(0, 260, 480, 60, HX8357_WHITE);
  
  tft.setFont(&JosefinSans_BoldItalic15pt7b);
  tft.setTextColor(0x07EE);
  tft.setCursor(340,40);
  tft.print("RECORD");

  tft.fillRect(73, 70, 335, 80, 0x07EE);
  tft.fillRect(73, 170, 335, 80, 0x07EE);

  tft.setTextColor(HX8357_WHITE);
  tft.setFont(&JosefinSans_Bold15pt7b);  
  tft.setCursor(150, 121);
  tft.print("NEXT NOTE");
  tft.setCursor(105, 221);
  tft.print("SAVE RECORDING");
}

// UPLOAD SCREEN

void DrawUploadScreen() {
  tft.fillRect(0, 0, 480, 320, HX8357_WHITE);
  tft.setFont(&JosefinSans_BoldItalic20pt7b);
  tft.setTextColor(0x07EE);
  tft.setCursor(120,130);
  tft.print("UPLOADING");

  tft.fillCircle(203, 198, 10, 0x07EE);
  tft.fillCircle(240, 198, 10, 0x07EE);
  tft.fillCircle(277, 198, 10, 0x07EE);

  boolean stillUploading = true;

  while (stillUploading) {
    CountdownDelay();
    tft.fillCircle(203, 198, 10, 0x9CF3);
    tft.fillCircle(277, 198, 10, 0x07EE);
    CountdownDelay();
    tft.fillCircle(240, 198, 10, 0x9CF3);
    tft.fillCircle(203, 198, 10, 0x07EE);
    CountdownDelay();
    tft.fillCircle(277, 198, 10, 0x9CF3);
    tft.fillCircle(240, 198, 10, 0x07EE);
  }
  
}

void DrawDownloadsScreen() {
  tft.fillRect(0, 0, 240, 360, HX8357_WHITE);
  tft.fillRect(240, 0, 240, 320, 0xF81D);
  tft.drawLine(260, 160, 465, 160, 0xFE5F);

  tft.setFont(&JosefinSans_BoldItalic12pt7b);
  tft.setTextColor(0xF81D);
  tft.setCursor(33, 167);
  tft.print("DOWNLOADS");

  tft.setTextColor(0x9CF3);
  tft.setFont(&JosefinSans_Bold20pt7b);
  tft.setCursor(11, 33);
  tft.print("<");

  tft.setFont(&JosefinSans_Bold12pt7b);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(323, 73);
  tft.print("LEARN");

  tft.setCursor(281, 103);
  tft.print("DOWNLOADS");

  tft.setFont(&JosefinSans_Bold12pt7b);
  tft.setCursor(330, 225);
  tft.print("PLAY");

  tft.setFont(&JosefinSans_Bold12pt7b);
  tft.setCursor(281, 255);
  tft.print("DOWNLOADS");
}

void DrawDownloadsLearnScreen() {
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
  tft.setCursor(278, 43);
  tft.print("DOWNLOAD 1");

  tft.setCursor(278, 124);
  tft.print("DOWNLOAD 2");

  tft.setFont(&JosefinSans_Bold12pt7b);
  tft.setCursor(278, 205);
  tft.print("DOWNLOAD 3");

  tft.setFont(&JosefinSans_Bold12pt7b);
  tft.setCursor(278, 282);
  tft.print("DOWNLOAD 4");


//  tft.setTextColor(0xFE5F);
//  tft.setFont(&JosefinSans_Bold8pt7b);
//  tft.setCursor(335, 60);
//  tft.print("OASIS");
//
//  tft.setCursor(318, 140);
//  tft.print("TOM PETTY");
//
//  tft.setCursor(265, 220);
//  tft.print("RED HOT CHILI PEPPERS");
//
//  tft.setCursor(310, 300);
//  tft.print("COMING SOON");
}

void DrawDownloadsPlayScreen() {
}
