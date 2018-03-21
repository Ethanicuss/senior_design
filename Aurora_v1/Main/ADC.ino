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
#include "Switches.h"
 
int minValue;
int maxValue;
int sensorValue;
int sensorValueBeta;
char* noteString = "E1gA1r";

int fret1min = 0;
int fret1max = 0;
int fret2min = 0;
int fret2max = 0;
int fret3min = 0;
int fret3max = 0;
int fret4min = 0;
int fret4max = 0;
int fret5min = 0;
int fret5max = 0;
int fret6min = 0;
int fret6max = 0;


//String recordedString = "xxxxxxxxxxxxxxxxxx"; //18chars

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
 
String recordPlacement(){
  /*** String E Fret 1-6 ***/
  if (analogRead(A0) >= fret1min && analogRead(A0) <= fret1max){
    recordedString[i] = 'E';
    recordedString[i+1] = '1';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A0) >= fret2min && analogRead(A0) <= fret2max){
    recordedString[i] = 'E';
    recordedString[i+1] = '2';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A0) >= fret3min && analogRead(A0) <= fret3max){
    recordedString[i] = 'E';
    recordedString[i+1] = '3';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A0) >= fret4min && analogRead(A0) <= fret4max){
    recordedString[i] = 'E';
    recordedString[i+1] = '4';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A0) >= fret5min && analogRead(A0) <= fret5max){
    recordedString[i] = 'E';
    recordedString[i+1] = '5';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A0) >= fret6min && analogRead(A0) <= fret6max){
    recordedString[i] = 'E';
    recordedString[i+1] = '6';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  /*** String E Frets 7-12 ***/
  if (analogRead(A1) >= fret1min && analogRead(A1) <= fret1max){
    recordedString[i] = 'E';
    recordedString[i+1] = '7';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A1) >= fret2min && analogRead(A1) <= fret2max){
    recordedString[i] = 'E';
    recordedString[i+1] = '8';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A1) >= fret3min && analogRead(A1) <= fret3max){
    recordedString[i] = 'E';
    recordedString[i+1] = '9';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A1) >= fret4min && analogRead(A1) <= fret4max){
    recordedString[i] = 'E';
    recordedString[i+1] = 'A';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A1) >= fret5min && analogRead(A1) <= fret5max){
    recordedString[i] = 'E';
    recordedString[i+1] = 'B';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A1) >= fret6min && analogRead(A1) <= fret6max){
    recordedString[i] = 'E';
    recordedString[i+1] = 'C';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  /***** String A Fret 1-6 *******/
  if (analogRead(A2) >= fret1min && analogRead(A2) <= fret1max){
    recordedString[i] = 'A';
    recordedString[i+1] = '1';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A2) >= fret2min && analogRead(A2) <= fret2max){
    recordedString[i] = 'A';
    recordedString[i+1] = '2';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A2) >= fret3min && analogRead(A2) <= fret3max){
    recordedString[i] = 'A';
    recordedString[i+1] = '3';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A2) >= fret4min && analogRead(A2) <= fret4max){
    recordedString[i] = 'A';
    recordedString[i+1] = '4';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A2) >= fret5min && analogRead(A2) <= fret5max){
    recordedString[i] = 'A';
    recordedString[i+1] = '5';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A2) >= fret6min && analogRead(A2) <= fret6max){
    recordedString[i] = 'A';
    recordedString[i+1] = '6';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  /***** String A Frets 7-12 ****/
  if (analogRead(A3) >= fret1min && analogRead(A3) <= fret1max){
    recordedString[i] = 'A';
    recordedString[i+1] = '7';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A3) >= fret2min && analogRead(A3) <= fret2max){
    recordedString[i] = 'A';
    recordedString[i+1] = '8';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A3) >= fret3min && analogRead(A3) <= fret3max){
    recordedString[i] = 'A';
    recordedString[i+1] = '9';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A3) >= fret4min && analogRead(A3) <= fret4max){
    recordedString[i] = 'A';
    recordedString[i+1] = 'A';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A3) >= fret5min && analogRead(A3) <= fret5max){
    recordedString[i] = 'A';
    recordedString[i+1] = 'B';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A3) >= fret6min && analogRead(A3) <= fret6max){
    recordedString[i] = 'A';
    recordedString[i+1] = 'C';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  /*** String D Fret 1-6 ***/
  if (analogRead(A4) >= fret1min && analogRead(A4) <= fret1max){
    recordedString[i] = 'D';
    recordedString[i+1] = '1';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A4) >= fret2min && analogRead(A4) <= fret2max){
    recordedString[i] = 'D';
    recordedString[i+1] = '2';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A4) >= fret3min && analogRead(A4) <= fret3max){
    recordedString[i] = 'D';
    recordedString[i+1] = '3';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A4) >= fret4min && analogRead(A4) <= fret4max){
    recordedString[i] = 'D';
    recordedString[i+1] = '4';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A4) >= fret5min && analogRead(A4) <= fret5max){
    recordedString[i] = 'D';
    recordedString[i+1] = '5';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A4) >= fret6min && analogRead(A4) <= fret6max){
    recordedString[i] = 'D';
    recordedString[i+1] = '6';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  /****** String D Fret 7-12******/
  if (analogRead(A5) >= fret1min && analogRead(A5) <= fret1max){
    recordedString[i] = 'D';
    recordedString[i+1] = '7';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A5) >= fret2min && analogRead(A5) <= fret2max){
    recordedString[i] = 'D';
    recordedString[i+1] = '8';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A5) >= fret3min && analogRead(A5) <= fret3max){
    recordedString[i] = 'D';
    recordedString[i+1] = '9';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A5) >= fret4min && analogRead(A5) <= fret4max){
    recordedString[i] = 'D';
    recordedString[i+1] = 'A';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A5) >= fret5min && analogRead(A5) <= fret5max){
    recordedString[i] = 'D';
    recordedString[i+1] = 'B';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A5) >= fret6min && analogRead(A5) <= fret6max){
    recordedString[i] = 'D';
    recordedString[i+1] = 'C';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  /****** String G Fret 1-6****/
  if (analogRead(A6) >= fret1min && analogRead(A6) <= fret1max){
    recordedString[i] = 'G';
    recordedString[i+1] = '1';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A6) >= fret2min && analogRead(A6) <= fret2max){
    recordedString[i] = 'G';
    recordedString[i+1] = '2';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A6) >= fret3min && analogRead(A6) <= fret3max){
    recordedString[i] = 'G';
    recordedString[i+1] = '3';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A6) >= fret4min && analogRead(A6) <= fret4max){
    recordedString[i] = 'G';
    recordedString[i+1] = '4';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A6) >= fret5min && analogRead(A6) <= fret5max){
    recordedString[i] = 'G';
    recordedString[i+1] = '5';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A6) >= fret6min && analogRead(A6) <= fret6max){
    recordedString[i] = 'G';
    recordedString[i+1] = '6';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  /***** String G Fret 7-12*******/
  if (analogRead(A7) >= fret1min && analogRead(A7) <= fret1max){
    recordedString[i] = 'G';
    recordedString[i+1] = '7';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A7) >= fret2min && analogRead(A7) <= fret2max){
    recordedString[i] = 'G';
    recordedString[i+1] = '8';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A7) >= fret3min && analogRead(A7) <= fret3max){
    recordedString[i] = 'G';
    recordedString[i+1] = '9';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A7) >= fret4min && analogRead(A7) <= fret4max){
    recordedString[i] = 'G';
    recordedString[i+1] = 'A';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A7) >= fret5min && analogRead(A7) <= fret5max){
    recordedString[i] = 'G';
    recordedString[i+1] = 'B';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A7) >= fret6min && analogRead(A7) <= fret6max){
    recordedString[i] = 'G';
    recordedString[i+1] = 'C';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  /***** String B Fret 1-6****/
  if (analogRead(A8) >= fret1min && analogRead(A8) <= fret1max){
    recordedString[i] = 'B';
    recordedString[i+1] = '1';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A8) >= fret2min && analogRead(A8) <= fret2max){
    recordedString[i] = 'B';
    recordedString[i+1] = '2';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A8) >= fret3min && analogRead(A8) <= fret3max){
    recordedString[i] = 'B';
    recordedString[i+1] = '3';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A8) >= fret4min && analogRead(A8) <= fret4max){
    recordedString[i] = 'B';
    recordedString[i+1] = '4';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A8) >= fret5min && analogRead(A8) <= fret5max){
    recordedString[i] = 'B';
    recordedString[i+1] = '5';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (analogRead(A8) >= fret6min && analogRead(A8) <= fret6max){
    recordedString[i] = 'B';
    recordedString[i+1] = '6';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  /***** String B Fret 7-12****/
  if (readSensor(0) >= fret1min && readSensor(0) <= fret1max){
    recordedString[i] = 'B';
    recordedString[i+1] = '7';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (readSensor(0) >= fret2min && readSensor(0) <= fret2max){
    recordedString[i] = 'B';
    recordedString[i+1] = '8';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (readSensor(0) >= fret3min && readSensor(0) <= fret3max){
    recordedString[i] = 'B';
    recordedString[i+1] = '9';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (readSensor(0) >= fret4min && readSensor(0) <= fret4max){
    recordedString[i] = 'B';
    recordedString[i+1] = 'A';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (readSensor(0) >= fret5min && readSensor(0) <= fret5max){
    recordedString[i] = 'B';
    recordedString[i+1] = 'B';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (readSensor(0) >= fret6min && readSensor(0) <= fret6max){
    recordedString[i] = 'B';
    recordedString[i+1] = 'C';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  /*** String e Fret 1-6 ****/
  if (readSensor(1) >= fret1min && readSensor(1) <= fret1max){
    recordedString[i] = 'e';
    recordedString[i+1] = '1';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (readSensor(1) >= fret2min && readSensor(1) <= fret2max){
    recordedString[i] = 'e';
    recordedString[i+1] = '2';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (readSensor(1) >= fret3min && readSensor(1) <= fret3max){
    recordedString[i] = 'e';
    recordedString[i+1] = '3';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (readSensor(1) >= fret4min && readSensor(1) <= fret4max){
    recordedString[i] = 'e';
    recordedString[i+1] = '4';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (readSensor(1) >= fret5min && readSensor(1) <= fret5max){
    recordedString[i] = 'e';
    recordedString[i+1] = '5';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (readSensor(1) >= fret6min && readSensor(1) <= fret6max){
    recordedString[i] = 'e';
    recordedString[i+1] = '6';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  /**** String e Fret 7-12****/
  if (readSensor(2) >= fret1min && readSensor(2) <= fret1max){
    recordedString[i] = 'e';
    recordedString[i+1] = '7';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (readSensor(2) >= fret2min && readSensor(2) <= fret2max){
    recordedString[i] = 'e';
    recordedString[i+1] = '8';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (readSensor(2) >= fret3min && readSensor(2) <= fret3max){
    recordedString[i] = 'e';
    recordedString[i+1] = '9';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (readSensor(2) >= fret4min && readSensor(2) <= fret4max){
    recordedString[i] = 'e';
    recordedString[i+1] = 'A';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (readSensor(2) >= fret5min && readSensor(2) <= fret5max){
    recordedString[i] = 'e';
    recordedString[i+1] = 'B';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
  if (readSensor(2) >= fret6min && readSensor(2) <= fret6max){
    recordedString[i] = 'e';
    recordedString[i+1] = 'C';
    recordedString[i+2] = color;
    LightLED(recordedString, false);
  }
}

void addOpenStrings(char buffer[]){
  for (int j=0; j < 6; j++){
    if (buffer[j] != 'x'){
      noteString[i] = buffer[j];
      noteString[i+1] = '0';
      noteString[i+2] = 'w';
    }
  }
}