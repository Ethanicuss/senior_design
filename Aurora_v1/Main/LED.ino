#include "stdio.h"
#include <FastLED.h>
#define LEDS_PER_ROW 6
#define NUM_ROWS 12
#define NUM_LEDS 72
#define LED_PIN 2
#define NUM_FRETS 12
#define NUM_STRINGS 6

/* TODO: Any function that have "LED" in it.
 *       and LearnSong + PlaySong
 *  
 */


CRGB led[NUM_LEDS];

void setupLED() {
  FastLED.addLeds<NEOPIXEL, LED_PIN>(led, NUM_LEDS);
  for(int i = 0; i < NUM_ROWS; i++){
    for(int j = 0; j < LEDS_PER_ROW; j++){
      led[i * LEDS_PER_ROW + j] = CRGB(0, 0, 0);  
    }
  }
  FastLED.show();
}

void learnMode(String song[], int numNotes){
  
}

// example string would be: ExxA0wD2rG2gB2be0w
void lightLED(String s){
  // for each string
  for(int i = 0; i < NUM_STRINGS; i++){
    // get the string name, fret number, and LED color
    char str = s[3 * i];
    int fret = int(s[3 * i + 1]);
    char color = s[3 * i + 2];
    if(color != 'x' && fret < NUM_FRETS){
      // index in the LED array
      int index = 0;
      // offset changes based on which string needs to be lit
      switch(str){
        case 'E':
          index = fret * LEDS_PER_ROW;
        case 'A':
          index = fret * LEDS_PER_ROW + 1;
        case 'D':
          index = fret * LEDS_PER_ROW + 2;
        case 'G':
          index = fret * LEDS_PER_ROW + 3;
        case 'B':
          index = fret * LEDS_PER_ROW + 4;
        case 'e':
          index = fret * LEDS_PER_ROW + 5;
      }
      // CRGB values change based on color we want
      switch(color){
        case 'w':
          led[index] = CRGB(0,0,0);
        case 'r':
          led[index] = CRGB(255,0,0);
        case 'b':
          led[index] = CRGB(0,255,0);
        case 'g':
          led[index] = CRGB(0,0,255);
      }
    }
  }
  FastLED.show();
}

void darkLED(){
  for(int i = 0; i < NUM_ROWS; i++){
    for(int j = 0; j < LEDS_PER_ROW; j++){
      led[i * LEDS_PER_ROW + j] = CRGB(0, 0, 0);  
    }
  }
  FastLED.show();
}

void LearnSong(char* song, int numberOfNotes){
 for(int i = 0; i < numberOfNotes; i++){
//  LED_ON(song[i], song[i].length);
//  LED_ON(song[i], sizeof(song)/sizeof(song[0]));
 }

}

