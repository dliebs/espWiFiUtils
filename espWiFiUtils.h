//
// espWiFiUtils v1.0.0
// 2023.12.10
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

void connectWiFi(const char*, const char*, const char*);
void connectWiFi(const char*, const char*, const char*, int);
void initializeOTA(const char*, const char*);

#endif
