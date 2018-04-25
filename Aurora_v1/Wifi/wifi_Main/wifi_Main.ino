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

int added = 0;

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
    case 3: // download the song
      //check to make sure that this user has a download queued
      //for testing (remove because the user should enter this info on the website):
      Firebase.setString("players/ID", uuidStr);
      //^^^^^
      //String deviceID = Firebase.getString("players/ID");
      String deviceID = uuidStr;
      int queue = Firebase.getInt("players/queue");
      if ((uuidStr == deviceID) && (queue == 1)){
        Serial.flush();
        Serial.print("queued");
        String DLsong = Firebase.getString("DLsong");
        String path = "song";
        path = path + "/";
        //path = path + "DLsong"; <-- ADD THIS LINE IN FINAL VERSION
        String numPath = path + "0"; //edit this line to finally point to first line of song
        int DLsongNotes = Firebase.getString(numPath).toInt();
        Serial.print(DLsongNotes);
        for(int i = 0; i < DLsongNotes; i++){
          String route = path + i;
          Serial.print(Firebase.getString(route));
          while(added == 0){
            if (Serial.available()){
              added = Serial.readString().toInt();
              Firebase.setInt("addedNote",added);
            }
          }
          Serial.print("added");
          added = 0;
        }
      }
      else {
        Firebase.setString("error", "ID doesn't match OR nothing in Queue");
      }
      break;
  }
  wifiState = 0;
}

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
  Firebase.setInt("players/queue", 1); //change baaac to 0 for finall.
  Firebase.setBool("outside", outside);
  Firebase.setInt("wifiState", 0);
  Firebase.setInt("songLen", numNotes);

  Firebase.setString("DLsong", "wonderwall");
}


 
