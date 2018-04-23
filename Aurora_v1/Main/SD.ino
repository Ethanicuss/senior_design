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
  Serial.print("Opening song file... ");
  f = SD.open(fname);
  // read song bpm from first line of file
  if (f) {
    Serial.println("done.");
    // find the number of lines in the song (basically convert from chars to an integer using the minus '0' trick)
    len = ReadFile().toInt();
  } 
  else {
    // if the file didn't open, print an error:
    Serial.println("error opening file!");
  }
}

String ReadFile(){
  String line = "";
  if(f.available()){
    while(f.available()){
      char c = f.read();
      if(c < 48 || c > 122){
        return line;
      }
      line.concat(c);
    }
  }
  else{
    songEnd = 1;
    Serial.println("File not available.");
    return "X";
  }
}




