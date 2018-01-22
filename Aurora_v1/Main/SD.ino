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
    while (1);
  }
  Serial.println("initialization done.");
  
}

String openFile(String fname){
  String fileText;
  // open the file for reading:
  f = SD.open(fname);
  if (f) {
    Serial.println(fname);
    // read from the file until there's nothing else in it:
    while (f.available()) {
      fileText.concat(f.read());
    }
  } 
  else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
  f.close();
  return fileText;
}

