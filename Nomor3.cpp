#include <Arduino.h>
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Adafruit_NeoPixel.h>

char auth[] = "M57W54v4bzYC4c8qncLccTmBGsD2NfBp";       // You should get Auth Token in the Blynk App.
char ssid[] = "WeYaTa";                    // Your Wi-Fi Credentials
char pass[] = "lock170999";

#define LED_PIN 27
#define LED_COUNT 1
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int r = 0,g = 0,b = 0;

void setColor(){
    strip.setPixelColor(0,r,g,b);
    strip.show();
}


BLYNK_READ(V0)
{
  int sensorData = analogRead(36);
  Blynk.virtualWrite(V0, sensorData);

  if(sensorData > 0.8*1600){
      Blynk.notify("WARNING! Value exceeded 80%");
  }

  Serial.println("Phototransistor : "+ String(sensorData));
}

BLYNK_WRITE(V1){
    r = param[0].asInt();
    g = param[1].asInt();
    b = param[2].asInt();
    
}


void setup() {  
    Serial.begin(115200); 
    pinMode(LED_PIN, OUTPUT);
    Blynk.begin(auth, ssid, pass);
    strip.begin();
    strip.clear();
}

void loop(){
    setColor();
    Blynk.run();
}

