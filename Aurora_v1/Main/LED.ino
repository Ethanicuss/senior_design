#include <FastLED.h>
#include "Record.h"
#define LEDS_PER_ROW 6
#define NUM_ROWS 12
#define NUM_LEDS 72
#define LED_PIN 2
#define NUM_FRETS 12
#define NUM_STRINGS 6
#define LED_CLK 3


CRGB led[NUM_LEDS];

void LEDSetup(void) {
  pinMode(LED_PIN, OUTPUT);
  FastLED.addLeds<APA102, LED_PIN, LED_CLK, GBR>(led, NUM_LEDS);
  FastLED.setBrightness(100);
  for(int i = 0; i < NUM_ROWS; i++){
    for(int j = 0; j < LEDS_PER_ROW; j++){
      led[i * LEDS_PER_ROW + j] = CRGB(0, 0, 0);
    }
  }
  FastLED.show();
}

// example string would be: ExxA0wD2rG2gB2be0w
void LightLED(String s, bool fullBrightness){
  Serial.println(s);
  if(s == "X")
    return;
  // for each string of the guitar in the chord
  for(int i = 0; i < NUM_STRINGS; i++){
    // get the string name, fret number, and LED color
    char str = s[3 * i];
    int fret = int(s[3 * i + 1]) - 48;
    if(fret < 0 || fret > 9){
      if(s[3 * i + 1] == 'A'){
        fret = 10;
      }
      else if(s[3 * i + 1] == 'B'){
        fret = 11;
      }
      else if(s[3 * i + 1] == 'C'){
        fret = 12;
      }
      else{
        fret = 13;
      }
    }
    char color = s[3 * i + 2];
    if(color != 'x' && fret != 0){
      // index in the LED array
      int index = 0;
      // offset changes based on which string needs to be lit
      switch(str){
        case 'E':
          index = (fret - 1) * LEDS_PER_ROW;
          break;
        case 'A':
          index = (fret - 1) * LEDS_PER_ROW + 1;
          break;
        case 'D':
          index = (fret - 1) * LEDS_PER_ROW + 2;
          break;
        case 'G':
          index = (fret - 1) * LEDS_PER_ROW + 3;
          break;
        case 'B':
          index = (fret - 1) * LEDS_PER_ROW + 4;
          break;
        case 'e':
          index = (fret - 1) * LEDS_PER_ROW + 5;
          break;
      }
      if(fullBrightness){
        // CRGB values change based on color we want
        switch(color){
          case 'r':
            led[index] = CRGB(255,0,0);
            break;
          case 'g':
            led[index] = CRGB(0,0,255);
            break;
          case 'b':
            led[index] = CRGB(0,255,0);
            break;
           case 'p':
            led[index] = CRGB(255,0,255);
            break;
        }
      }
      // halved brightness for next note
      else{
        // CRGB values change based on color we want
        switch(color){
          case 'r':
            led[index] = CRGB(75,0,0);
            break;
          case 'g':
            led[index] = CRGB(0,0,75);
            break;
          case 'b':
            led[index] = CRGB(0,75,0);
            break;
          case 'p':
            led[index] = CRGB(75,0,75);
            break;
        }
      }
    }
    // special case of an open string
      if(fret == 0){
        int offset = 0;
        switch(str){
        case 'E':
          offset = 0;
          break;
        case 'A':
          offset = 1;
          break;
        case 'D':
          offset = 2;
          break;
        case 'G':
          offset = 3;
          break;
        case 'B':
          offset = 4;
          break;
        case 'e':
          offset = 5;
          break;
        }
        if(fullBrightness){
          for(int i = 0; i< NUM_FRETS; i++){
            led[i * NUM_STRINGS + offset] = CRGB(255,255,255);
          }
        }
        else{
          for(int i = 0; i< NUM_FRETS; i++){
            led[i * NUM_STRINGS + offset] = CRGB(125,125,125);
          }
        }
      }
  }
  FastLED.show();
}

void DarkLED(String s){
  // for each string of the guitar in the chord
  for(int i = 0; i < NUM_STRINGS; i++){
    // get the string name, fret number, and LED color
    char str = s[3 * i];
    int fret = int(s[3 * i + 1]) - 48;
    if(fret != 0){
      // index in the LED array
      int index = 0;
      // offset changes based on which string needs to be lit
      switch(str){
        case 'E':
          index = (fret - 1) * LEDS_PER_ROW;
          break;
        case 'A':
          index = (fret - 1) * LEDS_PER_ROW + 1;
          break;
        case 'D':
          index = (fret - 1) * LEDS_PER_ROW + 2;
          break;
        case 'G':
          index = (fret - 1) * LEDS_PER_ROW + 3;
          break;
        case 'B':
          index = (fret - 1) * LEDS_PER_ROW + 4;
          break;
        case 'e':
          index = (fret - 1) * LEDS_PER_ROW + 5;
          break;
      }
      led[index] = CRGB(0,0,0);
    }
    // special case of an open string
    else{
      int offset = 0;
      switch(str){
        case 'E':
          offset = 0;
          break;
        case 'A':
          offset = 1;
          break;
        case 'D':
          offset = 2;
          break;
        case 'G':
          offset = 3;
          break;
        case 'B':
          offset = 4;
          break;
        case 'e':
          offset = 5;
          break;
      }
      for(int i = 0; i< NUM_FRETS; i++){
        led[i * NUM_STRINGS + offset] = CRGB(0,0,0);
      }
    }
  FastLED.show();
  }
}

void Quit(){
  songPosition = 0;
  for(int i = 0; i < NUM_ROWS; i++){
    for(int j = 0; j < LEDS_PER_ROW; j++){
      led[i * LEDS_PER_ROW + j] = CRGB(0, 0, 0);
    }
  }
  FastLED.show();
}
