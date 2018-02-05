#include <SPI.h>
#include <SD.h>

File f;

void setupSD(){
   // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  if (!SD.begin(4)) {
    Serial.println("SD initialization failed!");
  }
  
}

int openFile(String fname){
  char line[2];
  char newline[1];
  int bpm = 0;
  // open the file for reading:
  f = SD.open(fname);
  // read song bpm from first line of file
  if (f) {
    // read song bpm
    f.read(line, 2);
    // read newline character in to dummy buffer
    f.read(newline, 1);
    // calculate bpm (basically convert from chars to an integer using the minus '0' trick)
    bpm = (line[0] - '0') * 10 + (line[1] - '0');
  } 
  else {
    // if the file didn't open, print an error:
    Serial.println("error opening song file");
  }
  return bpm;
}

String readFile(){
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




