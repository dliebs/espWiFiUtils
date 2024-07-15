//
//
//  espWiFiUtils - Version 1.0.2
//  This version was not deployed [2023.12.13]
//
//  ESP8266/32 Based
//    Wrapper for WiFi, mDNS, and OTA
//
//  Changes From Previous Version
//    Comments, cleanup
//
//

/*----------  Libraries  ----------*/

#include <espWiFiUtils.h>

/*----------  User Variables  ----------*/

// WiFi Credentials
#ifndef STASSID
#define STASSID "Your_WiFi_SSID"
#define STAPSK  "Your_WiFi_Pass"
#endif
#define WiFiHostname "espWiFiUtils"

/*----------  Program Variables  ----------*/


/*----------  Main Functions  ----------*/

void setup() {
  Serial.begin(115200);

  // Can remove agument for LED if not desired
  connectWiFi(STASSID, STAPSK, WiFiHostname, LED_BUILTIN);
  // InitializeOTA, using STAPSK as password
  initializeOTA(WiFiHostname, STAPSK);
}

void loop() {
  Serial.println(WiFi.localIP());

  // Arduino OTA, run once per loop
  ArduinoOTA.handle();

  // Let the ESP8266 do its thing
  yield();

  delay(1000);
}
