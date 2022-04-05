#include <WiFi.h>
#include "time.h"

void StartWeeFee()
{

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, wifipw);
  Serial.println("Connecting Wifi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
}