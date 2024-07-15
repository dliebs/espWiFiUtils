//
// espWiFiUtils v1.0.0
// 2023.12.13
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

  connectWiFi(STASSID, STAPSK, WiFiHostname);
  initializeOTA(WiFiHostname, STAPSK);
}

void loop() {
  Serial.println(WiFi.localIP());

  // Arduino OTA
  ArduinoOTA.handle();

  // Let the ESP8266 do its thing
  yield();

  delay(1000);
}
