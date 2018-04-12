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

int wifiState = 0;
byte uuidNumber[16];
String uuidStr = "";

void setup() {
  // put your setup code here, to run once:
  WifiSetup();
  FirebaseSetup();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial1.available() > 0){
  Firebase.setBool("joined",true);
  wifiState = Serial1.read();
    switch (wifiState){
      case 1: 
        //TX works
        uniqueIDgen();
        //RX Test
        Serial1.print(uuidStr);
        break;
      case 2: //Upload
        Serial.println("Uploading");
        break;
    }
    wifiState = 0;
  }
}

void WifiSetup(){
  Serial.begin(115200);
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
   timeClient.begin();
}

void FirebaseSetup(){
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.setBool("joined", false);
  Firebase.setBool("players/available", false);
  Firebase.setString("players/ID", "0");
}

void uniqueIDgen(){
  Firebase.setBool("players/available",true);
  ESP8266TrueRandom.uuid(uuidNumber);
  uuidStr = ESP8266TrueRandom.uuidToString(uuidNumber);
  Firebase.setString("players/ID", uuidStr);
}


 
