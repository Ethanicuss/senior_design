#include "Controls.h"
#include "SD.h"
#include "LED.h"

// Functions that control song play and can be called from any screen
bool fileOpened;
int bpm;
void playPause(String songName){
  // load song from SD card (DOMINO)
  if(!fileOpened){
    bpm = openFile(songName);
    fileOpened = true;
  }
  // ex: "ExxA0wD2rG2gB2be0w";
  String chord = readFile();
  lightLED(chord); 
  // TODO: TARANG
  // CheckADC(song); 
  // This will update the percentage of notes the user has hit perfectly
  // TODO: DON
  UpdateScreen(); 
  // Goto Next Note AKA close "for loop".
}

void quit(){
  darkLED(); // TODO: Turns off all the LEDS
}


