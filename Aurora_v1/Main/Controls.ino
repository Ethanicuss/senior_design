#include "Controls.h"
#include "SD.h"
#include "LED.h"

// Functions that control song play and can be called from any screen
bool fileOpened;
int noteNumber;
void PlayPause(String songName){
  if (play){
    // load song from SD card (DOMINO)
    if(!fileOpened){
      openFile(songName);
      fileOpened = true;
      noteNumber = 0;
    }
    String song = "ExxA0wD2rG2gB2be0w";
    lightLED(song); 
    noteNumber++;
    // TODO: TARANG
    // CheckADC(song); 
    // This will update the percentage of notes the user has hit perfectly
    // TODO: DON
    UpdateScreen(); 
    // Goto Next Note AKA close "for loop".
  }
  else{
    // song is paused
  }
}

void quit(){
  darkLED(); // TODO: Turns off all the LEDS
}

