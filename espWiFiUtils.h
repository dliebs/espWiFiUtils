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

#ifndef espWiFiUtils_h
#define espWiFiUtils_h

/*----------  Libraries  ----------*/

#include "Arduino.h"
#include <ArduinoOTA.h>

#ifdef ESP8266
  #include <ESP8266WiFi.h>
  #include <ESP8266mDNS.h>
#endif

#ifdef ESP32
  #include <WiFi.h>
  #include <ESPmDNS.h>
#endif

// Connect WiFi, no LED indication
void connectWiFi(const char*, const char*, const char*);
// Connect WiFi, LED indication
void connectWiFi(const char*, const char*, const char*, int);
// Initialize OTA with hostname and password
void initializeOTA(const char*, const char*);

#endif
