// Touch screen library with X Y and Z (pressure) readings as well
// as oversampling to avoid 'bouncing'
// This demo code returns raw readings, public domain

#include <stdint.h>
#include "TouchScreen.h"
#include "State.h"

#define YP A11  // must be an analog pin, use "An" notation!
#define XM A10  // must be an analog pin, use "An" notation!
#define YM 7   // can be a digital pin
#define XP 8   // can be a digital pin

// For better pressure precision, we need to know the resistance
// between X+ and X- Use any multimeter to read it
// For the one we're using, its 300 ohms across the X plate
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 700);


TouchScreen getTS(){
  return ts;
}

void DisplayXYZ(void) {
  // a point object holds x y and z coordinates
  TSPoint p = ts.getPoint();
  
  // we have some minimum pressure we consider 'valid'
  // pressure of 0 means no pressing!
  if (p.z > ts.pressureThreshhold) {
   //  Serial.print("X = "); Serial.print(p.x);
   //  Serial.print("\tY = "); Serial.print(p.y);
     //Serial.print("\tPressure = "); Serial.println(p.z);
  }

  Ycoor = p.y;
  Xcoor = p.x;

  Serial.print("Ycoor = "); Serial.println(Ycoor);

  Serial.print("Xcoor = "); Serial.println(Xcoor);
  
  delay(50);
}

void assignPins(void){
  
}


