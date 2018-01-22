#include "stdio.h"
#include <FastLED.h>
#define LEDS_PER_ROW 6
#define NUM_ROWS 12
#define NUM_LEDS 72
#define LED_PIN 2

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

void lightLED(String s, int noteNumber){
  int position = noteNumber * 3;
  if(s[position + 1] != 'x'){
    char str = s[position];
    int fret = int(s[position + 1]);
    char color = s[position + 2];
    // todo: actually light up LED
  }
}

void darkLED(){
  for(int i = 0; i < NUM_ROWS; i++){
    for(int j = 0; j < LEDS_PER_ROW; j++){
      led[i * LEDS_PER_ROW + j] = CRGB(0, 0, 0);  
    }
  }
  FastLED.show();
}

