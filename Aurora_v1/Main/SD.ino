#include <SPI.h>
#include <SD.h>

File f;

void setupSD(){
   // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
  }
  else{
    Serial.println("initialization done."); 
  }
  
}

void openFile(String fname){
  // open the file for reading:
  f = SD.open(fname);
  if (f) {
    Serial.println(fname);
    while (f.available()) {
      Serial.write(f.read());
    }
  } 
  else {
    // if the file didn't open, print an error:
    Serial.println("error opening song file");
  }
}



