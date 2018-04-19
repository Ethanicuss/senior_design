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


int hasHappened = 0;
int songLen = 0;
int ESPstate = 0;
String received;


void setup() {
  Serial.begin(9600);
  Serial.println("In setup");
  //Serial.end();
  
  bool success = LCDSetup();
  if(success){
    LEDSetup();
    analogReadResolution(12);
    MuxSetup();
  }

  //ESP
  Serial1.begin(115200);
  while (received != "connected"){
    if (Serial1.available() > 0){
     received = Serial1.readString(); 
    }
    Serial.print("Connecting");
    Serial.print(received);
  }
  Serial.println("Connected!");
  wifiCase = 2;
  Serial1.print(wifiCase);
}


void loop() {
  
  // SWITCH STATEMENT THAT HANDLES EVERY SCREEN STATE
  // -- See UI Diagram for Control Flow Graph
/****************** HOME SCREEN OPTIONS *****************/

  //DisplayXYZ();
  //CheckTouch();
  while(ESPstate == 0){
   if (Serial1.available() > 0){
    ESPstate = Serial1.readString().toInt();
   }
   Serial.println("ESP: " + ESPstate);
  }
  if (ESPstate == 2){ //UPLOAD
    //TEST - SETUP
    String songThing = "freefall.txt";
    int complete = 0;
    OpenFile(songThing);
    songLen = GetSongLength();
    Serial1.print(songLen);
    delay(500);
    Serial.println("songLen = " + songLen);
    delay(500);
    //^^^^^^^^^^^^
    //Waiting until songLen has been received by ESP
    while(received != "passed"){
      if(Serial1.available() > 0){
        received = Serial.readString();
      }
      Serial.println("passed? : " + received);
    }
    //Send First Note
    for (int x = 0; x <= songLen; x++){ //for each note in the song
      String line = ReadFile(); 
      Serial.println("line: " + line);
      delay(100);
      Serial1.print(line);
      //wait until that line is "added" to FB
      while(received != "added"){
        if(Serial1.available() > 0){
          received = Serial.readString();
        }
        Serial.println("added? : " + received);
        received = "empty"; //reset received
      }
    }
    while(received != "done"){
      if (Serial1.available() > 0){
        received = Serial.readString();
      }
      Serial.println("done? : " + received);
    }
  }
}


