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
  // open the file for reading:
  f = SD.open(fname);
  // read song bpm from first line of file
  if (f) {
    // find the number of lines in the song (basically convert from chars to an integer using the minus '0' trick)
    len = ReadFile().toInt();
  } 
  else {
    // if the file didn't open, print an error:
    Serial.println("Error opening song file!");
  }
}

String ReadFile(){
  String line = "";
  if(f.available()){
    char c = f.read();
    while(f.available()){
      if(c < 48 || c > 122){
        return line;
      }
      line.concat(c);
      c = f.read();
    }
  }
  else{
    Serial.println("File not available.");
    return "X";
  }
}




