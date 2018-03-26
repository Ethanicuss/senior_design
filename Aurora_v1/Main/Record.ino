#include "Record.h"
#include <SPI.h>
#include <SD.h>

/*TODO: Within an interrupt Handler for switch inputs
        we have to assign "BtnPressed = _______"

        This is my code from 445L - TK \/\/\/\/
        
        enum Button {NONE = 0, UP = 1, DOWN = 2, BACK = 3, SET = 4, OFF = 5};
        extern enum Button BtnPressed;

        we have to change the "NONE", "DOWN", etc...
        to all of the options I added in Main....
            "LESSONS", "PLAY", "LEARN", etc...
            ^^ all of the options are listed under all the
            places I wrote "switch(BtnPressed)"

            This is harder here, because unlike in 445L where I had
            5 physical buttons that would never change and always be on
            a certain Port.

            We have a touch screen where the areas for the buttons are variable
            and the each button has to be different because the functionality
            is completely different depending on the screen.

            ^ Possible ALT Solution - Change the BtnPressed cases in Main
                                      to instead account for just one button
                                      "Select" that has different areas depending
                                      on the CurrStateScreen you are on.
*/


File g;

//*** FOR Record Mode I/O ***//
void mkRecording(){
  // reset buffer for new recording
  String fileName = "rec.txt";
  g = SD.open(fileName);
  g.write("    \n");
}

void writeToFile(String line){
  // write string to file with f.write()
  char asarray[50];
  line.toCharArray(asarray, line.length());
  g.write(asarray);
  g.write("\n");
}

int BPMtoTiming(double BPM, double note){
  return (int)((1000*(BPM/60))*note);
}

void resetPointer(void){
  g.seek(0);
}

