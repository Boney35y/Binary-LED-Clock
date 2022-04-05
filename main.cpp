#include <Arduino.h>
#include <BinaryClock-Temperature.h>
#include <WifiInit.h>
#include <BinaryClock-Time.h>


void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  StartWeeFee();
  Serial.println(WiFi.localIP());
  StartLED();
  SetTime();
}

void loop() 
{
  // put your main code here, to run repeatedly:
  GetTime();
  GetTemp();
  delay(1000);
}

 
  



