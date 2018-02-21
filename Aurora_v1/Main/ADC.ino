/* TODO: Any Functions that utilize the "CheckADC"
 *       
 *       IMO - these will probably be called from within the LED functions
 *       since depending upon if you are in "LEARN" or "PLAY" the 
 *       CheckADC() will either prevent you from playing or
 *       it will just accrue the data to calculate perfect of notes 
 *       perfectly hit.
 *       
 */

#include <stdint.h>
 
int minValue;
int maxValue;
int sensorValue;
char* noteString = "E1gA1r";

boolean checkPlacement(char* noteString){
  boolean correctPlacement = false;

  for (int i = 0; (i+1) <= sizeof(noteString); i=i+3){
    char stringName = noteString[i];
    char fretNumber = noteString[i+1];
    switch(stringName){
      case 'E':
        switch(fretNumber){
          case 'x': //for 'nothing should be here' case
            minValue = 100;
            sensorValue = analogRead(A0);
            if (sensorValue > minValue){
              correctPlacement = false;
            }
            else{
              correctPlacement = true;
            }
            break;
          case '0': //for Open String
            minValue = 100;
            sensorValue = analogRead(A0);
            if (sensorValue > minValue){
              correctPlacement = false;
            }
            else{
              correctPlacement = true;
            }
            break;          
          case '1':
            minValue = 100;
            maxValue = 200;
            sensorValue = analogRead(A0);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '2':
            minValue = 100;
            maxValue = 200;
            sensorValue = analogRead(A0);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '3':
            minValue = 100;
            maxValue = 200;
            sensorValue = analogRead(A0);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '4':
            minValue = 100;
            maxValue = 200;
            sensorValue = analogRead(A0);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '5':
            minValue = 100;
            maxValue = 200;
            sensorValue = analogRead(A0);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '6':
            minValue = 100;
            maxValue = 200;
            sensorValue = analogRead(A0);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '7':
            minValue = 100;
            maxValue = 200;
            sensorValue = analogRead(A1);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '8':
            minValue = 100;
            maxValue = 200;
            sensorValue = analogRead(A1);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '9':
            minValue = 100;
            maxValue = 200;
            sensorValue = analogRead(A1);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case 'A':
            minValue = 100;
            maxValue = 200;
            sensorValue = analogRead(A1);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case 'B':
            minValue = 100;
            maxValue = 200;
            sensorValue = analogRead(A1);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case 'C':
            minValue = 100;
            maxValue = 200;
            sensorValue = analogRead(A1);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          //Add more cases here for more frets...
        }
        break;
      case 'A':
        //copy switch(fretNumber) after changing the min/max Value
        break;
      case 'D':
        //copy switch(fretNumber) after changing the min/max Value
        break;
      case 'G':
        //copy switch(fretNumber) after changing the min/max Value
        break; 
      case 'B':
        //copy switch(fretNumber) after changing the min/max Value 
        break;
      case 'e':
        //copy switch(fretNumber) after changing the min/max Value 
        break;
      case 'X':
        //copy switch(fretNumber) after changing the min/max Value
        break;      
    }
  }
  if (correctPlacement == true){
    return true;
  }
  else {
    return false;
  }
}
 

