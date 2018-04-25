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
String error;
int downloadNum = 0;
File d;

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
  wifiCase = 2; //for upload
  //wifiCase = 3; //for download
  Serial1.print(wifiCase);
  Serial1.flush();
}


void loop() {
  
  // SWITCH STATEMENT THAT HANDLES EVERY SCREEN STATE
  // -- See UI Diagram for Control Flow Graph
/****************** HOME SCREEN OPTIONS *****************/

  //DisplayXYZ();
  //CheckTouch();
  
  //checks the state of the ESP
  while(ESPstate == 0){
   if (Serial1.available() > 0){
    ESPstate = Serial1.readString().toInt();
   }
   Serial.print("ESP: ");
   Serial.println(ESPstate);
   delay(500);
  }
  delay(500);
  //^^^^^^^^^^^^^^^^^^^^^^^^^^
  if (ESPstate == 2){ //UPLOAD
    //TEST - SETUP
    String songThing = "wonderwall.txt";
    int complete = 0;
    OpenFile(songThing);
    songLen = GetSongLength();
    //FOR TESTING
    songLen = 10;
    //^^^^^^^^^^
    Serial.print("songLen = ");
    Serial.println(songLen);
    delay(500);
    Serial1.print(songLen);
    Serial1.flush();
    //^^^^^^^^^^^^
    //Waiting until songLen has been received by ESP
    while(received != "passed"){
      if(Serial1.available() > 0){
        received = Serial1.readString();
      }
      Serial.print("passed? : ");
      Serial.println(received);
      delay(500);
    }
    //Send First Note
    for (int x = 0; x < songLen; x++){ //for each note in the song
      String line = ReadFile(); 
      Serial.print("line: ");
      Serial.println(line);
      delay(500);
      Serial1.print(line);
      Serial1.flush();
      //wait until that line is "added" to FB
      while(received != "added"){
        if(Serial1.available() > 0){
          received = Serial1.readString();
        }
        Serial.print("added? : ");
        Serial.println(received);
        delay(500);
        if (x == (songLen - 1)){
          break;
        }
      }
      received = "empty"; //reset received
    }
    /*
    Serial1.print("1");
    Serial1.flush();
    */
    while(received != "done"){
      if (Serial1.available() > 0){
        received = Serial1.readString();
      }
      Serial.print("done? : ");
      Serial.println(received);
      delay(500);
    }
    Serial.println("completed!");
  }
  if (ESPstate == 3){ //DOWNLOAD
    //download the file
    //1. check to make sure that this device has a download queued
    while (received != "queued"){
      if(Serial1.available() > 0){
        received = Serial1.readString();
        Serial.print("device queued? : ");
        Serial.println(received);
      }
      else{
        Serial.println("No Match");
        error = "nothing queued";
      }
      delay(500);
    }
    Serial1.flush();
    received = "empty";

    //2. get the NumNotes and make a for loop for that
    int songNotes = 0;
    while (songNotes == 0){
      if(Serial1.available() > 0){
        songNotes = Serial1.readString().toInt();
        Serial.print("SongNotes = ");
        Serial.println(songNotes);
      }
      else{
        Serial.println("No Notess");
      }
      delay(500);
    }
    Serial1.flush();
    //3. open a file
    String DLsong = "downL";
    DLsong = DLsong + downloadNum;
    DLsong = DLsong + ".txt";
    downloadNum++;
    if (downloadNum > 3){
      error = "Max Downloads Reached";
    }
    d = SD.open(DLsong);
    //d.write("    \n");

    for(int n = 0; n < songNotes; n++){
      //4. write lines to the new file
      if (Serial1.available()){
        received = Serial1.readString();
        char DLarray[50];
        received.toCharArray(DLarray, received.length());
        d.write(DLarray);
        d.write("\n");
        Serial1.print("1");
      }
      while (received != "added"){
        if (Serial1.available()){
          received = Serial1.readString();
        }
        Serial.print("added? : ");
        Serial.println(received);
      }
      received = "empty"; 
    }
  }
  ESPstate = 0;
}


