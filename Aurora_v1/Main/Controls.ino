//Functions that control song play and can be called from any screen
bool fileOpened;
String song;
int noteNumber;
extern bool play;
void PlayPause(String songName){
  if (play){
    // load song from SD card (DOMINO)
    if(!fileOpened){
      song = openFile(songName);
      fileOpened = true;
      noteNumber = 0;
    }
    lightLED(song, noteNumber); 
    noteNumber++;
    // TODO: TARANG
    CheckADC(song); 
    // This will update the percentage of notes the user has hit perfectly
    // TODO: DON
    UpdateScreen(); 
    // Goto Next Note AKA close "for loop".
  }
  else{
    // song is paused
  }
}

void Quit(){
  darkLED(); // TODO: Turns off all the LEDS
}

