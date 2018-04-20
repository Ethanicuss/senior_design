//Wifi includes
#include <FirebaseArduino.h>
#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <ESP8266TrueRandom.h>

//*************WIFI Definitions************
//Wifi - Timing
#define NTP_OFFSET   60 * 60      // In seconds
#define NTP_INTERVAL 60 * 1000    // In miliseconds
//#define NTP_ADDRESS  "europe.pool.ntp.org"
#define NTP_ADDRESS "us.pool.ntp.org"

//Wifi - Network Info
#define WIFI_SSID "TK-Thinkpad"
#define WIFI_PASSWORD "meow1234"

//Wifi - Firebase
//#define FIREBASE_HOST "aurora-94c4f.firebaseio.com"
//#define FIREBASE_AUTH "p9tAD1bDo1I9ejE4i7PMmEDx9pQ75VXbd1awkRg9"

//Wifi - Firebase Test DB
#define FIREBASE_HOST "esptest-6b4a0.firebaseio.com"
#define FIREBASE_AUTH "2z4iDnzTjTrqsf0dQPIumekNl5IPYYFhpUuHWfDV"

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, NTP_ADDRESS, NTP_OFFSET, NTP_INTERVAL);

//String wifiState = "0";
int wifiState = 0;

byte uuidNumber[16];
String uuidStr = "";
bool outside = false;
bool inside = false;
int hasHappened = 0;
char readChar[1];
int firstDone = 0;
int done = 0;
int numNotes = 0;
String note = "";
int marker = 1;
int newLine = 0;
int finished = 0;

void setup() {
  // put your setup code here, to run once:
  WifiSetup();
  FirebaseSetup();
}


void loop(){
  //if data is stored in the buffer
  if (Serial.available() > 0){
    wifiState = Serial.readString().toInt();
    Serial.print(wifiState); //Send back to Arduino as proof check
    Serial.flush();
    Firebase.setInt("wifiState", wifiState); //Update Firebase as proff check
  }
  switch(wifiState){
    case 1: //Get Device ID
      Firebase.setString("players/ID", uuidStr);
      Serial.print(uuidStr);
      Serial.flush();
      break;
    case 2:
      //Wait until Song Length is sent by Ard.
      while(numNotes == 0){
        if(Serial.available() > 0){
          numNotes = Serial.readString().toInt();  
        }
        Firebase.set("songLen", numNotes);
      }
      Firebase.set("song/0", numNotes);
      //cear buffer
      Serial.print("passed");
      Serial.flush();
      //^^^^^^^^^^^^^^^^
      //Wait until Line is sent by Ard.
      for (int i = 1; i <= numNotes; i++){ //for each note in the song
        while(newLine == 0){ //while the line isn't new
          if(Serial.available() > 0){
            note = Serial.readString();
            newLine = 1;
            String entry = "song";
            entry = entry + "/";
            entry = entry + i;
            Firebase.setString("test", entry);
            Firebase.setString(entry, note);
          }
          else{
            Firebase.setString("test", "waiting");
          }
        }
        if (i < numNotes){
          Serial.print("added");
          Serial.flush();
        }
        else{
          Serial.print("done");
          Serial.flush();
        }
        newLine = 0; //reset newLine
      }
      /*
      while (finished == 0){
        if(Serial.available() > 0){
          finished = Serial.readString().toInt();
        }
        Firebase.setInt("finished", finished);
      }  
      Serial.print("done");
      Serial.flush();
      */
      break;
  }
  wifiState = 0;
  //finished = 0;
}
/*
void loop() {
  outside = !outside;
  Firebase.setBool("outside", outside);
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0){

  





  
  
  wifiState = Serial.readString().toInt();
  //readChar[0] = wifiState[0];
  
  //Firebase.set("wifiState", readChar[0]);
  Firebase.setInt("wifiState", wifiState);
  
  inside = !inside;
  Firebase.setBool("inside", inside);
  
  //Assign Device ID  
  if (readChar[0] == '1'){
    //uuidStr = Wifi.macAddress();
    //RX Test
    Firebase.setString("players/ID", uuidStr);
    
    Serial.print(uuidStr);
  }


  






  //Upload Recording
  if (hasHappened == 0){
    //if (readChar[0] == '2'){
    if (wifiState == 2){
      Firebase.setString("wifiState", "uploading");
      while (done == 0){
        if (Serial.available() > 0){
          if (firstDone == 0){
           numNotes = Serial.readString().toInt();
           delay(500);
           /*
           while (!Firebase.success()){
            Firebase.set("notenotReady", !inside); 
           }
           */

           /*
           firstDone = 1;
           Firebase.setInt("song/0", numNotes);   
          }
          if (firstDone == 1) {
            while (marker < numNotes){
              while (Serial.available() <= 0) {
                Firebase.setString("outside", "error");
              }
              note = Serial.readString();
              delay(500);
              String noteVal = "song/" + marker;
              Firebase.setString(noteVal, note);
              //if(Firebase.success()){
                marker++;
                Serial.print(marker);
                delay(500);
              //}
              }
            done = 1;
            hasHappened = 1;
            }
          }
        }
      }
    }

  //Download From Queue
  if (readChar[0] == '3'){
    
  }
  
  /*
    switch (wifiState){
      case "1": 
        //TX works
        if (hasHappened == 0){
          uniqueIDgen();
          hasHappened = 1;
        }
        //RX Test
        Serial.print(uuidStr);
        break;
      case "2": //Upload
        Serial.print("Uploading");
        break;
    }
    */

    /*
    //wifiState = "0";
    wifiState = 0;
    readChar[0] = 0;
  }
}

*/

void WifiSetup(){
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    //Serial.print(".");
    delay(500);
  }
  Serial.print("connected");
  Serial.flush();
  uuidStr = WiFi.macAddress();
  timeClient.begin();
}

void FirebaseSetup(){
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.setBool("inside", false);
  Firebase.setBool("players/available", false);
  Firebase.setString("players/ID", "0");
  Firebase.setBool("outside", outside);
  Firebase.setInt("wifiState", 0);
  Firebase.setInt("songLen", numNotes);
}
/*
void uniqueIDgen(){
  Firebase.setBool("players/available",true);
  ESP8266TrueRandom.uuid(uuidNumber);
  uuidStr = ESP8266TrueRandom.uuidToString(uuidNumber);
  Firebase.setString("players/ID", uuidStr);
}
*/

 
