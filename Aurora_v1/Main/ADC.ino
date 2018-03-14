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
int sensorValueBeta;
char* noteString = "E1gA1r";

//Use this line to check sensor for ADC 9, 10 , 11
//sensorValue = readSensor(0); //for A9
//sensorValue = readSensor(1); //for A10
//sensorValue = readSensor(1); //for A11

boolean checkPlacement(String noteString){
  boolean correctPlacement = false;
  for (int i = 0; (i+1) <= 18; i=i+3){
    char stringName = noteString[i];
    char fretNumber = noteString[i+1];
    switch(stringName){
      case 'E':
        switch(fretNumber){
          case 'x': //for 'nothing should be here' case
            minValue = 4000;   //make this a tighter value after testing
            sensorValue = analogRead(A0);
            if (sensorValue > minValue){
              correctPlacement = false;
            }
            else{
              correctPlacement = true;
            }
            break;
          case '0': //for Open String
            minValue = 50; //make this a tighter value after testing
            sensorValue = analogRead(A0);
            sensorValueBeta = analogRead(A1);
            if (sensorValue > minValue || sensorValueBeta > minValue){
              correctPlacement = false;
            }
            else{
              correctPlacement = true;
            }
            break;          
          case '1':
            minValue = 0; //TODO: change these when we get 50k Res
            maxValue = 10; //TODO: change these when we get 50k Res
            sensorValue = analogRead(A0);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '2':
            minValue = 11; //TODO: change these when we get 50k Res
            maxValue = 100; //TODO: change these when we get 50k Res
            sensorValue = analogRead(A0);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '3':
            minValue = 200; //TODO: change these when we get 50k Res
            maxValue = 500; //TODO: change these when we get 50k Res
            sensorValue = analogRead(A0);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '4':
            minValue = 1500; //TODO: change these when we get 50k Res
            maxValue = 2900; //TODO: change these when we get 50k Res
            sensorValue = analogRead(A0);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '5':
            minValue = 3000; //TODO: change these when we get 50k Res
            maxValue = 3800; //TODO: change these when we get 50k Res
            sensorValue = analogRead(A0);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '6':
            minValue = 3801; //TODO: change these when we get 50k Res
            maxValue = 4100; //TODO: change these when we get 50k Res
            sensorValue = analogRead(A0);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '7':
            minValue = 0; //
            maxValue = 10;
            sensorValue = analogRead(A1);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '8':
            minValue = 11;
            maxValue = 100;
            sensorValue = analogRead(A1);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '9':
            minValue = 200;
            maxValue = 500;
            sensorValue = analogRead(A1);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case 'A':
            minValue = 1500;
            maxValue = 2900;
            sensorValue = analogRead(A1);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case 'B':
            minValue = 3000;
            maxValue = 3800;
            sensorValue = analogRead(A1);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case 'C':
            minValue = 3801;
            maxValue = 4100;
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
        switch(fretNumber){
          case 'x': //for 'nothing should be here' case
            minValue = 4000;   //make this a tighter value after testing
            sensorValue = analogRead(A2);
            if (sensorValue > minValue){
              correctPlacement = false;
            }
            else{
              correctPlacement = true;
            }
            break;
          case '0': //for Open String
            minValue = 4000; //make this a tighter value after testing
            sensorValue = analogRead(A2);
            sensorValueBeta = analogRead(A3);
            if (sensorValue > minValue || sensorValueBeta > minValue){
              correctPlacement = false;
            }
            else{
              correctPlacement = true;
            }
            break;          
          case '1':
            minValue = 0; //TODO: change these when we get 50k Res
            maxValue = 10; //TODO: change these when we get 50k Res
            sensorValue = analogRead(A2);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '2':
            minValue = 11; //TODO: change these when we get 50k Res
            maxValue = 100; //TODO: change these when we get 50k Res
            sensorValue = analogRead(A2);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '3':
            minValue = 200; //TODO: change these when we get 50k Res
            maxValue = 500; //TODO: change these when we get 50k Res
            sensorValue = analogRead(A2);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '4':
            minValue = 1500; //TODO: change these when we get 50k Res
            maxValue = 2900; //TODO: change these when we get 50k Res
            sensorValue = analogRead(A2);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '5':
            minValue = 3000; //TODO: change these when we get 50k Res
            maxValue = 3800; //TODO: change these when we get 50k Res
            sensorValue = analogRead(A2);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '6':
            minValue = 3801; //TODO: change these when we get 50k Res
            maxValue = 4100; //TODO: change these when we get 50k Res
            sensorValue = analogRead(A2);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '7':
            minValue = 0; //
            maxValue = 10;
            sensorValue = analogRead(A3);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '8':
            minValue = 11;
            maxValue = 100;
            sensorValue = analogRead(A3);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '9':
            minValue = 200;
            maxValue = 500;
            sensorValue = analogRead(A3);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case 'A':
            minValue = 1500;
            maxValue = 2900;
            sensorValue = analogRead(A3);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case 'B':
            minValue = 3000;
            maxValue = 3800;
            sensorValue = analogRead(A3);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case 'C':
            minValue = 3801;
            maxValue = 4100;
            sensorValue = analogRead(A3);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          //Add more cases here for more frets...
        }
        //copy switch(fretNumber) after changing the min/max Value
        break;
      case 'D':
        //copy switch(fretNumber) after changing the min/max Value
        switch(fretNumber){
          case 'x': //for 'nothing should be here' case
            minValue = 4000;   //make this a tighter value after testing
            sensorValue = analogRead(A4);
            if (sensorValue > minValue){
              correctPlacement = false;
            }
            else{
              correctPlacement = true;
            }
            break;
          case '0': //for Open String
            minValue = 4000; //make this a tighter value after testing
            sensorValue = analogRead(A4);
            sensorValueBeta = analogRead(A5);
            if (sensorValue > minValue || sensorValueBeta > minValue){
              correctPlacement = false;
            }
            else{
              correctPlacement = true;
            }
            break;          
          case '1':
            minValue = 0; //TODO: change these when we get 50k Res
            maxValue = 10; //TODO: change these when we get 50k Res
            sensorValue = analogRead(A4);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '2':
            minValue = 11; //TODO: change these when we get 50k Res
            maxValue = 100; //TODO: change these when we get 50k Res
            sensorValue = analogRead(A4);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '3':
            minValue = 200; //TODO: change these when we get 50k Res
            maxValue = 500; //TODO: change these when we get 50k Res
            sensorValue = analogRead(A4);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '4':
            minValue = 1500; //TODO: change these when we get 50k Res
            maxValue = 2900; //TODO: change these when we get 50k Res
            sensorValue = analogRead(A4);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '5':
            minValue = 3000; //TODO: change these when we get 50k Res
            maxValue = 3800; //TODO: change these when we get 50k Res
            sensorValue = analogRead(A4);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '6':
            minValue = 3801; //TODO: change these when we get 50k Res
            maxValue = 4100; //TODO: change these when we get 50k Res
            sensorValue = analogRead(A4);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '7':
            minValue = 0; //
            maxValue = 10;
            sensorValue = analogRead(A5);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '8':
            minValue = 11;
            maxValue = 100;
            sensorValue = analogRead(A5);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '9':
            minValue = 200;
            maxValue = 500;
            sensorValue = analogRead(A5);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case 'A':
            minValue = 1500;
            maxValue = 2900;
            sensorValue = analogRead(A5);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case 'B':
            minValue = 3000;
            maxValue = 3800;
            sensorValue = analogRead(A5);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case 'C':
            minValue = 3801;
            maxValue = 4100;
            sensorValue = analogRead(A5);
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
      case 'G':
        //copy switch(fretNumber) after changing the min/max Value
        switch(fretNumber){
          case 'x': //for 'nothing should be here' case
            minValue = 4000;   //make this a tighter value after testing
            sensorValue = analogRead(A6);
            if (sensorValue > minValue){
              correctPlacement = false;
            }
            else{
              correctPlacement = true;
            }
            break;
          case '0': //for Open String
            minValue = 4000; //make this a tighter value after testing
            sensorValue = analogRead(A6);
            sensorValueBeta = analogRead(A7);
            if (sensorValue > minValue || sensorValueBeta > minValue){
              correctPlacement = false;
            }
            else{
              correctPlacement = true;
            }
            break;          
          case '1':
            minValue = 0; //TODO: change these when we get 50k Res
            maxValue = 10; //TODO: change these when we get 50k Res
            sensorValue = analogRead(A6);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '2':
            minValue = 11; //TODO: change these when we get 50k Res
            maxValue = 100; //TODO: change these when we get 50k Res
            sensorValue = analogRead(A6);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '3':
            minValue = 200; //TODO: change these when we get 50k Res
            maxValue = 500; //TODO: change these when we get 50k Res
            sensorValue = analogRead(A6);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '4':
            minValue = 1500; //TODO: change these when we get 50k Res
            maxValue = 2900; //TODO: change these when we get 50k Res
            sensorValue = analogRead(A6);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '5':
            minValue = 3000; //TODO: change these when we get 50k Res
            maxValue = 3800; //TODO: change these when we get 50k Res
            sensorValue = analogRead(A6);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '6':
            minValue = 3801; //TODO: change these when we get 50k Res
            maxValue = 4100; //TODO: change these when we get 50k Res
            sensorValue = analogRead(A6);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '7':
            minValue = 0; //
            maxValue = 10;
            sensorValue = analogRead(A7);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '8':
            minValue = 11;
            maxValue = 100;
            sensorValue = analogRead(A7);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '9':
            minValue = 200;
            maxValue = 500;
            sensorValue = analogRead(A7);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case 'A':
            minValue = 1500;
            maxValue = 2900;
            sensorValue = analogRead(A7);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case 'B':
            minValue = 3000;
            maxValue = 3800;
            sensorValue = analogRead(A7);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case 'C':
            minValue = 3801;
            maxValue = 4100;
            sensorValue = analogRead(A7);
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
      case 'B':
        //copy switch(fretNumber) after changing the min/max Value
        switch(fretNumber){
          case 'x': //for 'nothing should be here' case
            minValue = 4000;   //make this a tighter value after testing
            sensorValue = analogRead(A8);
            if (sensorValue > minValue){
              correctPlacement = false;
            }
            else{
              correctPlacement = true;
            }
            break;
          case '0': //for Open String
            minValue = 4000; //make this a tighter value after testing
            sensorValue = analogRead(A8);
            sensorValueBeta = analogRead(A9);
            if (sensorValue > minValue || sensorValueBeta > minValue){
              correctPlacement = false;
            }
            else{
              correctPlacement = true;
            }
            break;          
          case '1':
            minValue = 0; //TODO: change these when we get 50k Res
            maxValue = 10; //TODO: change these when we get 50k Res
            sensorValue = analogRead(A8);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '2':
            minValue = 11; //TODO: change these when we get 50k Res
            maxValue = 100; //TODO: change these when we get 50k Res
            sensorValue = analogRead(A8);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '3':
            minValue = 200; //TODO: change these when we get 50k Res
            maxValue = 500; //TODO: change these when we get 50k Res
            sensorValue = analogRead(A8);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '4':
            minValue = 1500; //TODO: change these when we get 50k Res
            maxValue = 2900; //TODO: change these when we get 50k Res
            sensorValue = analogRead(A8);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '5':
            minValue = 3000; //TODO: change these when we get 50k Res
            maxValue = 3800; //TODO: change these when we get 50k Res
            sensorValue = analogRead(A8);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '6':
            minValue = 3801; //TODO: change these when we get 50k Res
            maxValue = 4100; //TODO: change these when we get 50k Res
            sensorValue = analogRead(A8);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '7':
            minValue = 0; //
            maxValue = 10;
            sensorValue = readSensor(0);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '8':
            minValue = 11;
            maxValue = 100;
            sensorValue = readSensor(0);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '9':
            minValue = 200;
            maxValue = 500;
            sensorValue = readSensor(0);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case 'A':
            minValue = 1500;
            maxValue = 2900;
            sensorValue = readSensor(0);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case 'B':
            minValue = 3000;
            maxValue = 3800;
            sensorValue = readSensor(0);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case 'C':
            minValue = 3801;
            maxValue = 4100;
            sensorValue = readSensor(0);
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
      case 'e':
        //copy switch(fretNumber) after changing the min/max Value
        switch(fretNumber){
          case 'x': //for 'nothing should be here' case
            minValue = 4000;   //make this a tighter value after testing
            sensorValue = readSensor(1);
            if (sensorValue > minValue){
              correctPlacement = false;
            }
            else{
              correctPlacement = true;
            }
            break;
          case '0': //for Open String
            minValue = 4000; //make this a tighter value after testing
            sensorValue = readSensor(1);
            sensorValueBeta = readSensor(2);
            if (sensorValue > minValue || sensorValueBeta > minValue){
              correctPlacement = false;
            }
            else{
              correctPlacement = true;
            }
            break;          
          case '1':
            minValue = 0; //TODO: change these when we get 50k Res
            maxValue = 10; //TODO: change these when we get 50k Res
            sensorValue = readSensor(1);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '2':
            minValue = 11; //TODO: change these when we get 50k Res
            maxValue = 100; //TODO: change these when we get 50k Res
            sensorValue = readSensor(1);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '3':
            minValue = 200; //TODO: change these when we get 50k Res
            maxValue = 500; //TODO: change these when we get 50k Res
            sensorValue = readSensor(1);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '4':
            minValue = 1500; //TODO: change these when we get 50k Res
            maxValue = 2900; //TODO: change these when we get 50k Res
            sensorValue = analogRead(A0);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '5':
            minValue = 3000; //TODO: change these when we get 50k Res
            maxValue = 3800; //TODO: change these when we get 50k Res
            sensorValue = readSensor(1);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '6':
            minValue = 3801; //TODO: change these when we get 50k Res
            maxValue = 4100; //TODO: change these when we get 50k Res
            sensorValue = readSensor(1);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '7':
            minValue = 0; //
            maxValue = 10;
            sensorValue = readSensor(2);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '8':
            minValue = 11;
            maxValue = 100;
            sensorValue = readSensor(2);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case '9':
            minValue = 200;
            maxValue = 500;
            sensorValue = readSensor(2);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case 'A':
            minValue = 1500;
            maxValue = 2900;
            sensorValue = readSensor(2);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case 'B':
            minValue = 3000;
            maxValue = 3800;
            sensorValue = readSensor(2);
            if (sensorValue > minValue && sensorValue < maxValue){
              correctPlacement = true;
            }
            else{
              correctPlacement = false;
            }
            break;
          case 'C':
            minValue = 3801;
            maxValue = 4100;
            sensorValue = readSensor(2);
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
      case 'X':
        //copy switch(fretNumber) after changing the min/max Value
        break;      
    }
    if (correctPlacement == false){
      Serial.println("FAIL");
      break; //breaks for loop     
    }
  }
  if (correctPlacement == true){
    return true;
  }
  else {
    return false;
  }
}

void adcOUT(void){
  // show all sensor readings
    Serial.print("Sensor A0: ");
    Serial.println(analogRead(A0));
    Serial.print("Sensor A1: ");
    Serial.println(analogRead(A1));
    Serial.print("Sensor A2: ");
    Serial.println(analogRead(A2));
    Serial.print("Sensor A3: ");
    Serial.println(analogRead(A3));
    Serial.print("Sensor A4: ");
    Serial.println(analogRead(A4));
    Serial.print("Sensor A5: ");
    Serial.println(analogRead(A5));
    Serial.print("Sensor A6: ");
    Serial.println(analogRead(A6));
    Serial.print("Sensor A7: ");
    Serial.println(analogRead(A7));
    Serial.print("Sensor A8: ");
    Serial.println(analogRead(A8));
    Serial.print("Sensor A9: ");
    Serial.println(readSensor(0));
    Serial.print("Sensor A10: ");
    Serial.println(readSensor(1));
    Serial.print("Sensor A11: ");
    Serial.println(readSensor(2));

    /*
    Serial.println("Sensor A1: " + analogRead(A1));
    Serial.println("Sensor A2: " + analogRead(A2));
    Serial.println("Sensor A3: " + analogRead(A3));
    Serial.println("Sensor A4: " + analogRead(A4));
    Serial.println("Sensor A5: " + analogRead(A5));
    Serial.println("Sensor A6: " + analogRead(A6));
    Serial.println("Sensor A7: " + analogRead(A7));
    Serial.println("Sensor A8: " + analogRead(A8));
    Serial.println("Sensor A9: " + readSensor(0));
    Serial.println("Sensor A10: " + readSensor(1));
    Serial.println("Sensor A11: " + readSensor(2));
    */
}  // end of loop
 

