#include <SPI.h>
#include <SD.h>

File f;
int len;

int GetSongLength(){
  if(f){
    return len;
  }
  else{
    return 0;
  }
}

void OpenFile(String fname){
  char line[3];
  char newline[1];
  int bpm = 0;
  // open the file for reading:
  f = SD.open(fname);
  // read song bpm from first line of file
  if (f) {
    // read number of chords in the song
    f.read(line, 3);
    // read newline character in to dummy buffer
    f.read(newline, 1);
    // find the number of lines in the song (basically convert from chars to an integer using the minus '0' trick)
    len = (line[0] - '0') * 100 + (line[1] - '0') * 10 + (line[2] - '0');
  } 
  else {
    // if the file didn't open, print an error:
    Serial.println("Error opening song file!");
  }
}

String ReadFile(){
  char line[18];
  char newline[1];
  if(f.available()){
    // read chord from song in to buffer
    f.read(line, 18);
    // read newline character in to dummy buffer
    f.read(newline, 1);
    return line;
  }
  else{
    return "X";
  }
}




